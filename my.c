#include<stdio.h>

const int KEY_LEN = 6;
int key[KEY_LEN] = {3, 5, 2, 6, 1, 4};

int main(int argc, char *argv[]){
    
    FILE *input_file = fopen(argv[0], 'r');

    if (input_file == NULL){
        perror("Не удалось открыть файл");
        return -1;
    }
    
    char block[KEY_LEN];

    while (fgets(block, KEY_LEN, input_file)) {
        

    }

    


}