=== Program Operasi Aritmatika Bilangan Kompleks === [Bahasa Indonesia]

Program ini menjalankan perhitungan aritmatika dasar penjumlahan, pengurangan, perkalian, dan pembagian dua bilangan kompleks.

|---------------------------------------------------------------------------------------------------------------------------------
|
|   Format Input:
|
|   Masukkan bilangan pertama (tanpa spasi): (Z1)
|   Z1 = ... contoh: 2+3i 
|
|   Masukkan bilangan kedua (tanpa spasi): (Z2)
|   Z2 = ... contoh: 0.76497-90.8758i
|
|   Untuk a adalah komponen real dari input bilangan kompleks dan b adalah komponen imajiner dari input bilangan kompleks.
|
|   Constraints:
|       -10^150 ≤ a, b ≤ 10^150
|   dengan:
|       a ≠ 0, b ≠ 0
|       Z1 + Z2 < 1,8 x 10^308
|       Z1 - Z2 > -1,8 x 10^308
|       Z1 X Z2 < 1,8 x 10^308
|       Z1 X Z2 > -1,8 x 10^308
|       Z1 : Z2 < 1,8 x 10^308
|
|-----------------------------------------------------------------------------------------------------------------------------


|---------------------------------------------------------------------------------------------------------------------------------
|
|   Format output:
|   
|   <nama_operasi>:
|   Z1 [operator] Z2 
|
|   Hasilnya Z = ...
|
|----------------------------------------------------------------------------------------------------------------------------------


    ## Rumus yang digunakan

let Z1 = a + bi
let Z2 = c + di

f_penjumlahan(Z1, Z2) = (a + c) + (b + d)i
f_pengurangan(Z1, Z2) = (a - c) + (b - d)i
f_perkalian(Z1, Z2) = (ac - bd) + (ad + bc)i
f_pembagian(Z1, Z2) = ((ac + bd)/(c^2 + d^2)) + ((bc - ad)/(c^2 + d^2))i


    ## Implementasi Bilangan
Program menerima salah satu dari jenis bilangan berikut:
1. Bilangan asli / natural dapat langsung diterima dengan syarat tanpa spasi dan koma dengan titik.
2. Bilangan bulat / integer dapat langsung diterima dengan syarat tanpa spasi dan koma dengan titik.
3. Bilangan rasional / irasional harus dinyatakan dalam bentuk desimal. misal 2/9 dinyatakan dengan 0.222222
4. Bilangan imajiner dapat langsung diterima dengan syarat koefisiennya memenuhi syarat no. 1 s.d. 3 di atas.
5. User dapat menginput karakter i ataupun tidak selama inputnya dalam format a+b dengan a bil. real dan b bilangan kompleks.