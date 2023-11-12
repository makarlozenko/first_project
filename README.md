# first_project
Sistemos informacija:
| CPU                                       | RAM | SSD   | 
|-------------------------------------------|-----|-------|
| Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz | 8GB | 512GB |

# Instrukcija
Paleidus programą, atsiranda juodas langas:

(Toliau kiekvieną įvedimą baigiame su Enter paspaudimu)

1. Spaudžiame 1 - duomenys bus įvedami rankiniu būdu. Spaudžiame 0 - duomenis gausime iš failo.
   
   Jei pasirinkome rankiniu būdu:
   
   1.1. Spaudžiame 1 - bus skaižiuojamas pažymių vidurkis. Spaudžiame 0 - bus skaižiuojama pažymių mediana.
   
   1.2. Įvedame studentų skaičių.
   
   1.3. Spaudžiame 1 - kompiuteris generuoja pazymius atsitiktinai. Spaudžiame 0 - duomenys bus įvedami rankiniu būdu.

   1.4. Pasirinkus 1, įvedame studentų vardus ir pavardes bei pasririnkom, kiek norime sugeneruoti pažymių - galiusiai gausime norimus rezultatus. Pasirinkus 0, įvedame studentų vardus, pavardes, pažymius per 
   Space paspaudimą, baigiant įvedimą su -1 ir Enter paspaudimu, bei egzamino rezultatą - galiusiai gausime norimus rezultatus.

   Jei pasirinkome duomenis iš failo:

   2.1. 


# Su vector pagalba:
Buvo ištirtos 4 skirtingos strategijos:

Mano pradinė strategija:
| Testavimas               |     1000     |     10000    |    100000   |  1000000  |  10000000 |
|--------------------------|:------------:|:------------:|:-----------:|:---------:|:---------:|
| Failo   nuskaitymas      | 0.00578446 s  | 0.0522601 s    |  0.506964 s   |  5.07819 s | 51.577 s  |
| Funkcija sort            |  0.00438454 s |  0.0528577 s |  0.69525 s | 8.74361 s | 106.866 s |
| Išvedimas į   kietakius  | 0.0027923 s | 0.0218337 s  | 0.223655 s | 2.23034 s | 22.5428 s |
| Išvedimas į   vargšiukus |   0.00199626 s  | 0.0183487 s|  0.163962 s  | 1.66494 s | 16.8454  s |
| Bendras laikas           |  0.0149576 s|   0.1453 s   |  1.58983 s   | 17.7171 s  | 197.831 s |

Atminties informacija 1000000 ir 10000000 failų atvėjuose:
![image](https://github.com/makarlozenko/first_project/assets/145557353/f23340cb-24ba-4a8e-a493-82cc8affcfb7)
![image](https://github.com/makarlozenko/first_project/assets/145557353/61af6db4-879a-40fc-8a16-d5f5826fa0b2)


1 strategija:
| Testavimas               |     1000     |     10000    |    100000   |  1000000  |  10000000 |
|--------------------------|:------------:|:------------:|:-----------:|:---------:|:---------:|
| Failo   nuskaitymas      | 0.00578302 s  | 0.0521313 s    |  0.502739 s   |  5.04545 s |  51.9489 s  |
| Funkcija sort            |   0.00518904 s |   0.0577269 s |   0.749958 s | 9.30362 s | 115.679 s |
| Išvedimas į   kietakius  | 0.00322656 s | 0.0218755 s  | 0.214084 s | 2.09009 s | 20.7948 s |
| Išvedimas į   vargšiukus |   0.00259632 s  |  0.0168975 s|   0.152457 s  |  1.61211 s | 15.0351 s |
| Bendras laikas           |  0.0167949 s|   0.148631 s   |  1.61924 s   | 18.0513 s  | 203.458 s|

Atminties informacija 1000000 ir 10000000 failų atvėjuose:
![image](https://github.com/makarlozenko/first_project/assets/145557353/e014f1f5-0239-4f53-9024-f44dd7bdb5d7)
![image](https://github.com/makarlozenko/first_project/assets/145557353/5b10ad03-89eb-484e-8c9d-f4b459c869da)

2 strategija:
| Testavimas               |     1000     |     10000    |    100000   |  1000000  |  10000000 |
|--------------------------|:------------:|:------------:|:-----------:|:---------:|:---------:|
| Failo   nuskaitymas      | 0.0062489 s  |  0.052367 s    |  0.520939 s   |  5.06549 s |  51.0306 s  |
| Funkcija sort            |    0.0039886 s |   0.0542086 s |   0.752332 s | 8.94664 s | 107.902 s |
| Išvedimas į   kietakius  |  0.00263278 s | 0.0213522 s  | 0.294148 s | 2.13861 s | 20.9753 s|
| Išvedimas į   vargšiukus |    0.0022718 s  |  0.0159612 s|   0.191023 s  |  1.49192 s | 15.2137 s |
| Bendras laikas           |   0.0151421 s|    0.143889 s   |  1.75844 s   | 17.6427 s  | 195.121 s|

Atminties informacija 1000000 ir 10000000 failų atvėjuose:
![image](https://github.com/makarlozenko/first_project/assets/145557353/5eb5d218-5b55-4714-b51e-15c5077cbf9f)
![image](https://github.com/makarlozenko/first_project/assets/145557353/5367fbac-64c4-4e8a-9de1-de1e30860582)


3 strategija:
| Testavimas               |     1000     |     10000    |    100000   |  1000000  |  10000000 |
|--------------------------|:------------:|:------------:|:-----------:|:---------:|:---------:|
| Failo   nuskaitymas      | 0.00598198 s  |   0.0526165 s    |  0.557935 s   |  5.10567 s |  51.0646 s  |
| Funkcija sort            |    0.00399045 s |    0.0519115 s |   0.796763 s | 8.82247 s | 104.392 s |
| Išvedimas į   kietakius  |  0.00326228 s |  0.0212438 s  | 0.239548 s | 2.1281 s | 21.233 s|
| Išvedimas į   vargšiukus |   0.00224495 s  |   0.0162563 s|   0.167003 s  |   1.5299 s | 14.8614 s |
| Bendras laikas           |   0.0154797 s|     0.142028 s  |  1.76125 s   | 17.5861 s  | 191.551 s|

Atminties informacija 1000000 ir 10000000 failų atvėjuose:
![image](https://github.com/makarlozenko/first_project/assets/145557353/80f5ea43-938d-4198-932f-30be64f5f81c)
![image](https://github.com/makarlozenko/first_project/assets/145557353/9928329c-ad16-491d-9f8f-27a4891498e8)


# Su list pagalba:
Buvo ištirtos 4 skirtingos strategijos:

Mano pradinė strategija:
| Testavimas               |     1000     |     10000    |    100000   |  1000000  |  10000000 |
|--------------------------|:------------:|:------------:|:-----------:|:---------:|:---------:|
| Failo   nuskaitymas      | 0.00578446 s  | 0.135417 s    |  0.503226 s   |  13.669 s | 137.125 s  |
| Funkcija sort            |  0.00438454 s |   0.00411717 s |  0.683994 s |  0.986695 s | 14.7913 s|
| Išvedimas į   kietakius  | 0.0027923 s | 0.0349688 s  |  0.216273 s |  3.78637 s | 103.341 s |
| Išvedimas į   vargšiukus |   0.00199626 s  | 0.0309929 s|  0.161346 s  | 3.21893 s | 33.5491 s |
| Bendras laikas           |  0.0149576 s|   0.205496 s   |  1.56484 s   | 21.661 s  | 288.806 s |

Atminties informacija 1000000 ir 10000000 failų atvėjuose:
![image](https://github.com/makarlozenko/first_project/assets/145557353/157ce69b-4ed0-4a90-b690-ccc9ea678400)
![image](https://github.com/makarlozenko/first_project/assets/145557353/11571e68-aa9b-4cb4-87e2-82e62d6df485)

1 strategija:
| Testavimas               |     1000     |     10000    |    100000   |  1000000  |  10000000 |
|--------------------------|:------------:|:------------:|:-----------:|:---------:|:---------:|
| Failo   nuskaitymas      | 0.0150242 s  | 0.136058 s    |  1.36741 s   |   13.5291 s | 138.108 s  |
| Funkcija sort            |  0.00324002 s |   0.0299738 s |   0.356669 s |  3.821 s | 305.751 s|
| Išvedimas į   kietakius  |  0.00334412 s | 0.0282086 s  |  0.275868 s |  2.77653 s | 65.1643 s |
| Išvedimas į   vargšiukus |   0.00315454 s  | 0.0208223 s|  0.198226 s  | 2.01122 s | 28.5851 s |
| Bendras laikas           |  0.0247629 s|  0.215063 s  |  2.19817 s   | 22.1379 s  | 537.608 s |

Atminties informacija 1000000 ir 10000000 failų atvėjuose:
![image](https://github.com/makarlozenko/first_project/assets/145557353/6c8b1e51-cc0d-4520-831f-c1092af79feb)
![image](https://github.com/makarlozenko/first_project/assets/145557353/aea78268-4910-4a33-b1cf-07106abb9074)

2 strategija:
| Testavimas               |     1000     |     10000    |    100000   |  1000000  |  10000000 |
|--------------------------|:------------:|:------------:|:-----------:|:---------:|:---------:|
| Failo   nuskaitymas      | 0.0148683 s  | 0.136807 s    |  1.35602 s   |   13.4458 s | 136.323 s  |
| Funkcija sort            |  0.0012477 s |   0.0249354 s |   0.271271 s |  3.03185 s | 61.226 s|
| Išvedimas į   kietakius  |  0.00363985 s |0.0311195 s  |  0.294841 s |  2.94861 s | 46.2706 s |
| Išvedimas į   vargšiukus |   0.00249293 s  | 0.0212426 s|  0.208165 s  | 2.07228 s | 55.2058 s |
| Bendras laikas           |  0.0222488 s|  0.214105 s  |  2.1303 s   | 21.4985 s  | 299.026 s |

Atminties informacija 1000000 ir 10000000 failų atvėjuose:
![image](https://github.com/makarlozenko/first_project/assets/145557353/6af4d7d6-076c-48a6-89ab-54a65f101ab4)
![image](https://github.com/makarlozenko/first_project/assets/145557353/40d72343-7a93-4d91-a3fb-53bece932440)

3 strategija:
| Testavimas               |     1000     |     10000    |    100000   |  1000000  |  10000000 |
|--------------------------|:------------:|:------------:|:-----------:|:---------:|:---------:|
| Failo   nuskaitymas      | 0.0147247 s  | 0.136197 s   |  1.37031 s   |   13.5737 s | 136.721 s  |
| Funkcija sort            |  0.00265993 s |   0.0133458 s |   0.158257 s |   1.90772 s | 50.5523 s|
| Išvedimas į   kietakius  |  0.00322187 s |0.031052 s  |  0.306218 s |  3.14378 s | 47.8015 s |
| Išvedimas į   vargšiukus |   0.002631 s  | 0.0216922 s|   0.210801 s  | 2.24965 s | 51.8523 s|
| Bendras laikas           |  0.0232375 s|  0.202287 s |  2.04559 s  | 20.8748 s  | 286.927 s |

Atminties informacija 1000000 ir 10000000 failų atvėjuose:
![image](https://github.com/makarlozenko/first_project/assets/145557353/d710ce1b-11d8-4157-89e2-4b66b1e3dd3d)
![image](https://github.com/makarlozenko/first_project/assets/145557353/0d6753d2-e623-44b5-94fe-127837f291e1)






 









