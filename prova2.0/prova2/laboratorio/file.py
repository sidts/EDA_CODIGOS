import csv


#USEI POIS MEU COMPUTADOR NÂO SUPORTA O ARQUIVO DAQUELE TAMANHO

# Defina o caminho do arquivo de entrada e de saída
arquivo_entrada = 'C:/Users/enric/OneDrive/Documentos/Programas/EDA_CODIGOS/prova2.0/prova2/laboratorio/output/Airlines.csv'
arquivo_saida = 'metade.csv'

# Abre o arquivo de entrada no modo leitura
with open(arquivo_entrada, mode='r', newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=';')  # Defina o delimitador conforme seu arquivo CSV

    # Abre o arquivo de saída no modo escrita
    with open(arquivo_saida, mode='w', newline='') as outfile:
        writer = csv.writer(outfile, delimiter=';')  # Defina o delimitador para o arquivo de saída

        # Lê as 90 primeiras linhas do arquivo de entrada e escreve no arquivo de saída
        for idx, row in enumerate(reader):
            if idx < 90:
                writer.writerow(row)

print(f'As 90 primeiras linhas de {arquivo_entrada} foram salvas em {arquivo_saida}.')
