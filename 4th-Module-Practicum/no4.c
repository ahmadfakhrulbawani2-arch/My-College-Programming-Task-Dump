#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////////////////////
/// TIDAK WAJIB MENGGUNAKAN TEMPLATE                           ///
/// Jika ingin, silahkan modifikasi sesuatu kebutuhan untuk AC ///
/// Jika tidak, silahkan diabaikan saja :)                     ///
//////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// IT IS NOT REQUIRED TO USE THIS TEMPLATE                             ///
/// If you want, feel free to modify something to fit your needs for AC ///
/// If not, feel free to ignore it :)                                   ///
///////////////////////////////////////////////////////////////////////////

int size = 0;

typedef struct
{
    // Kapasitas yang dialokasikan untuk array
    // The allocated capacity of the array
    int size;

    // Jumlah elemen yang saat ini ada di array
    // The number of elements currently in the array
    int index;

    int *array;
} Data;

// Untuk membebaskan memori dari heap
// To free memory from the heap
// MODIFIKASI KE FUNGSI INI HARUS SESUAI DENGAN STRUKTUR ANDA
// MODIFY THIS FUNCTION TO FIT YOUR STRUCTURE
void free_data(Data *data, int size)
{
    if (!data)
        return;
    for (int i = 0; i < size; i++)
    {
        // free() aman dipanggil pada NULL
        // free() is safe to call on NULL
        free(data[i].array);
    }
    free(data);
}

// Untuk mengalokasi ulang array yang tidak cukup besar
// To reallocate an inner array that is not large enough
void resize(Data *data, int idx)
{
    if (data[idx].size == 0)
    {
        data[idx].size = 2;
        data[idx].array = (int *)malloc(data[idx].size * sizeof(int));
        data[idx].index = 0;
        return;
    }

    if (data[idx].index >= data[idx].size)
    {
        data[idx].size *= 2;
        int *new_arr = (int *)realloc(data[idx].array, data[idx].size * sizeof(int));
        if (!new_arr)
        {
            free(data[idx].array);
            exit(1);
        }
        data[idx].array = new_arr;
    }
}


// Untuk menyimpan data jembatan Pulau A dan Pulau B ke 2D array
// To store bridge data between Island A and Island B into a 2D array
void insert(Data **data_ptr, int a, int b)
{
    int max_idx = (a > b) ? a : b;

    // Pada inisialisasi program, max_idx >= 0
    // On program initialization, max_idx >= 0
    if (max_idx >= size)
    {
        int old_size = size;
        int new_size = max_idx + 1;
        Data *new_array = (Data *)realloc(*data_ptr, new_size * sizeof(Data));
        if (!new_array)
        {
            free_data(*data_ptr, old_size);
            exit(1);
        }

        for (int i = old_size; i < new_size; i++)
        {
            new_array[i].size = 0;
            new_array[i].index = 0;

            // !!! IMPORTANT !!! //
            // resize() perlu menangani alokasi untuk row baru
            // resize() needs to  handle allocation for new rows
            new_array[i].array = NULL;
        }
        *data_ptr = new_array;
        size = new_size;
    }

    if ((*data_ptr)[a].index >= (*data_ptr)[a].size)
    {
        resize(*data_ptr, a);
    }
    if ((*data_ptr)[b].index >= (*data_ptr)[b].size)
    {
        resize(*data_ptr, b);
    }

    (*data_ptr)[a].array[(*data_ptr)[a].index++] = b;
    (*data_ptr)[b].array[(*data_ptr)[b].index++] = a;
}

void print(Data *data)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i].index == 0) continue;

        printf("Pulau %d:", i);

        for (int j = 0; j < data[i].index; j++)
        {
            printf(" %d", data[i].array[j]);
        }

        printf("\n");
    }
}

int main()
{
    int size = 0;
    Data *data = NULL;

    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
    {
        insert(&data, a, b);
    }

    print(data);

    free_data(data, size);

    return 0;
}