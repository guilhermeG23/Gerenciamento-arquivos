"""
Arquivo -> X
Escrever -> X
Fechar -> X
Ler -> X
deletar -> X
Append -> X
Seek
Get Atributs
Set Atributs
Rename -> X
"""

import os

def criar_arquivo():
    arquivo = str(input("Crie arquivo: "))
    open(arquivo, "w")

def escrever_arquivo():
    arquivo = str(input("Arquivo: "))
    texto = str(input("Texto: "))
    arquivo = open(arquivo, "w")
    arquivo.write(texto)
    arquivo.close()

def renomear():
    arquivo_original = str(input("Arquivo original: "))
    arquivo_renomeado = str(input("Arquivo renomeado: "))
    os.rename(arquivo_original, arquivo_renomeado)

def ler():
    arquivo = str(input("Arquivo: "))
    arquivo = open(arquivo, "r")
    for linha in arquivo:
        print(linha)

def apagar():
    arquivo = str(input("Arquivo: "))
    os.remove(arquivo)

if __name__ == "__main__":
    criar_arquivo()
    escrever_arquivo()
    renomear()
    ler()
    apagar()