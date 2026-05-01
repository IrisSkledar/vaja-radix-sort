
# Uporabi uradno GCC podobo za prevajanje C++ kode
FROM gcc:latest

# Ustvari mapo v usr
WORKDIR /usr/src/myapp

# Kopira vse datoteke iz mojega repozitorija v usr
COPY . .

# Prevede moj main.cpp v izvršljivo datoteko radix_sort
RUN g++ -o radix_sort main.cpp

# Ob zagonu usr se izpiše navodilo (ker program potrebuje vhodno datoteko)
CMD ["./radix_sort"]
