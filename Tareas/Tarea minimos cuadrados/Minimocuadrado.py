    column_mapping = {
        'Water activity': 'aw',
        'Moisture content (% dry basis)': 'Xe_dry',
        'Moisture content (% wet basis)': 'Xe_wet', 
        'Temperature': 'temp',
        'Type': 'type'
    }
    
    df = df.rename(columns=column_mapping)
    
    datos_organizados = {}
    
    for tipo in df['type'].unique():
        datos_organizados[tipo] = {}
        for temp in df[df['type'] == tipo]['temp'].unique():
            mask = (df['type'] == tipo) & (df['temp'] == temp)
            subset = df[mask]
            
            aw_values = subset['aw'].values
            Xe_values = subset['Xe_dry'].values
            
            datos_organizados[tipo][temp] = {
                'aw': aw_values,
                'Xe': Xe_values,
                'nombre': f"{tipo} ({temp}°C)"
            }
    
    return datos_organizados

def main(archivo_datos):
    print("=" * 80)
    print("CARGANDO Y ORGANIZANDO DATOS")
    print("=" * 80)
    
    datos = cargar_datos(archivo_datos)
    
    print("\n" + "=" * 80)
    print("AJUSTE DE MODELOS POR CHI-CUADRADA")
    print("=" * 80)

    todos_resultados = {}
    
    tipos = list(datos.keys())
    n_tipos = len(tipos)
    fig, axes = plt.subplots(n_tipos, 3, figsize=(18, 5*n_tipos))
    if n_tipos == 1:
        axes = axes.reshape(1, -1)
    
    fig.suptitle('Ajuste de Modelos: Datos Experimentales vs Predicciones', fontsize=16)

    for i, tipo in enumerate(tipos):
        temperaturas = list(datos[tipo].keys())
        
        for j, temp in enumerate(temperaturas):
            if j >= 3:
                break
                
            dataset = datos[tipo][temp]
            aw, Xe, nombre = dataset['aw'], dataset['Xe'], dataset['nombre']
            
            res = ajustar_modelos(aw, Xe, nombre)
            todos_resultados[nombre] = res
            
            ax = axes[i, j]
            
            ax.scatter(aw, Xe, color='black', s=40, marker='s', label='Experimental', zorder=5)
            
            aw_fit = np.linspace(aw.min(), aw.max(), 300)
            
            b_p = res['peleg']['b']
            Xe_fit_p = modelo_peleg(aw_fit, b_p)
            ax.plot(aw_fit, Xe_fit_p, '--', color='blue', 
                    label=f'Peleg (χ²={res["peleg"]["chi2"]:.4f})')
            
            b_d = res['dlp']['b']
            Xe_fit_d = modelo_dlp(aw_fit, b_d)
            ax.plot(aw_fit, Xe_fit_d, '-', color='red', 
                    label=f'DLP (χ²={res["dlp"]["chi2"]:.4f})')
            
            ax.set_xlabel('$a_w$')
            ax.set_ylabel('$X_e$ (% d.b.)')
            ax.set_title(nombre, fontsize=10)
            ax.grid(True, linestyle=':', alpha=0.6)
            ax.legend(fontsize=8)

    plt.tight_layout(rect=[0, 0, 1, 0.96])
    plt.savefig('ajustes_comparativos.png', dpi=150, bbox_inches='tight')
    plt.show()

    print("\n" + "=" * 60)
    print("MEJOR MODELO PARA CADA CASO")
    print("=" * 60)
    for nombre, res in todos_resultados.items():
        chi_peleg = res['peleg']['chi2']
        chi_dlp = res['dlp']['chi2']
        mejor = "Peleg" if chi_peleg < chi_dlp else "DLP"
        print(f"{nombre:<30} -> {mejor:>6} (Peleg: {chi_peleg:.6f}, DLP: {chi_dlp:.6f})")
    
    return todos_resultados

if __name__ == "__main__":
    archivo = "/content/Experimental water adsorption isotherms.xlsx"
    resultados = main(archivo)
