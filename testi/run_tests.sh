#!/bin/bash

echo "--- ZAGANJAM TESTE ---"

# 1. Ustvari testno vhodno datoteko s številkami med 0 in 255
echo "10 55 200 2 8 150" > test_vhod.txt
echo "Ustvarjena testna datoteka: test_vhod.txt"

# 2. Prevede program (da preveri, če se sploh prevede)
g++ -o testni_bin main.cpp
if [ $? -ne 0 ]; then
    echo "NAPAKA: Prevajanje ni uspelo!"
    exit 1
fi

# 3. Požene program s testno datoteko
./testni_bin test_vhod.txt

# 4. Preveri če je nastala datoteka out.txt (kot zahteva main.cpp)
if [ -f out.txt ]; then
    echo "TEST USPEŠEN: Datoteka out.txt je bila ustvarjena."
    echo "Vsebina izhoda: $(cat out.txt)"
    exit 0
else
    echo "TEST NEUSPEŠEN: Izhodna datoteka out.txt ne obstaja!"
    exit 1
fi

