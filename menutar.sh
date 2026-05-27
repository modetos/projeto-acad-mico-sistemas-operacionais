#!/bin/bash

mkdir -p /home/restore

while true; do

    # Menu
    echo ""
    echo "1 - Compactar arquivos"
    echo "2 - Descompactar arquivo tar.gz"
    echo "3 - Descompactar um unico arquivo de um tar.gz"
    echo "4 - Sair"
    echo ""
    read -p "Escolha uma opcao: " opcao

    case $opcao in

        1)
            read -p "Nome do arquivo de saida (ex: backup.tar.gz): " saida
            read -p "Arquivos/pasta a compactar (ex: /home/scripts/*): " arquivos
            tar -zcvf $saida $arquivos
            echo "Compactado com sucesso!"
            ;;

        2)
            read -p "Nome do arquivo tar.gz a descompactar: " arquivo
            tar -zxvf $arquivo -C /home/restore
            echo "Arquivos extraidos para /home/restore"
            ;;

        3)
            read -p "Nome do arquivo tar.gz: " arquivo
            read -p "Arquivo a extrair de dentro do tar.gz: " alvo
            tar -zxvf $arquivo $alvo
            echo "Arquivo extraido com sucesso!"
            ;;

        4)
            echo "Saindo..."
            break
            ;;

        *)
            echo "Opcao invalida! Tente novamente."
            ;;

    esac

done
