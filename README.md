# first_project
Sistemos informacija:
| CPU                                       | RAM | SSD   | 
|-------------------------------------------|-----|-------|
| Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz | 8GB | 512GB |




Su list pagalba:
| Testavimas               |     1000     |     10000    |    100000   |  1000000  |  10000000 |
|--------------------------|:------------:|:------------:|:-----------:|:---------:|:---------:|
| Failo   nuskaitymas      | 0.0294929 s  | 0.1829 s     | 1.78584 s   | 15.9916 s | 160.531 s  |
| Funkcija sort            | 0.00079958 s | 0.00628592 s | 0.0886389 s | 1.18419 s | 18.1277 s|
| Išvedimas į   kietakius  | 0.00705416 s | 0.0496732 s  | 0.476569 s  | 4.38624 s | 85.8532 s |
| Išvedimas į   vargšiukus | 0.0056076 s  | 0.0406545 s  | 0.400662 s  | 3.697 s | 39.7111 s |
| Bendras laikas           | 0.0429543 s  | 0.279514 s   | 2.75171 s   | 25.259 s  |  303.756 s |


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




