#!/bin/bash

lista="ips.txt"
log="resultado.log"

> $log

# Le cada linha do arquivo de ips
while read ip; do

    ping -c 4 $ip > /dev/null

    # Verifica se o ping funcionou
    if [ $? -eq 0 ]; then
        echo "A maquina $ip esta online e respondendo ao ping." | tee -a $log
    else
        echo "A maquina $ip nao esta respondendo ao ping." | tee -a $log
    fi

done < $lista

echo ""
echo "Resultado salvo em $log"
