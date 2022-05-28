Am folosit urmatoarele design pattern-uri:
  1. Singleton pentru citirea si scrierea in fisierele proiectului - in main.cpp
  2. Decorator pattern in cazul in care masina/motocicleta este unul/una de tip exotic(am adaugat campul valoare pentru vehiculele cu pret mare) - in fisierul ValoareVehicul.h
  3. Prototype pattern in cazul in care masina/motocicleta este a politiei - in main.cpp
  4. Factory pattern cu ajutorul caruia imi creez o masina/motocicleta noua - in main.cpp
 
Functia template se afla in Vehicul.h si compara doua vehicule in functie de puterea fiecaruia.
