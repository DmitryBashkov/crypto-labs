#include<stdio.h>
#include<stdbool.h>
#include <uchar.h>

const int ALPHABET_COUNT = 5;
const int ALPHABET_LENGTH = 68;


/* исходный алфавит*/
const char16_t source[ALPHABET_LENGTH + 1] = {
    u"абвгдеёжзийклмнопрстуфхцчшщъьыэюя abcdefghijklmnopqrstuvwxyz .,!:;?-"
};

/* подстановочные алфавиты */
const char16_t wild_c[ALPHABET_COUNT][ALPHABET_LENGTH + 1] = {
    /* 1 */
    u"БЮГЫЕЬЗШЙЦЛФНТПРСОУМХКЧИЩЖЪДЭВЯ АЁVWXYZ .,!:;?-KLMNOPQRSTUABCDEFGHIJ",

    /* 2 */
    u"СОУМКХЧИЩЖЬЛЭВЯАБЮГ ЕЪЗШЙЦЁФНТПРЫЛCDABHIJEFGOPQRKLMNUVW:STZ XY;?.-,!",

    /* 3 */
    u"ОПМНХЛИЙЖЗДЕВГАБЮЯЫЭЬ ШЩЦЧФКТУРСЪЁZ .XY,!ST:;QR?-NOPLMKOPABCDEFGHIJK",

    /* 4 */
    u"ЮЯЫЭЬЪШЩЦЧФХТУРСОПМНКЛ ЙЖЗДЕВГАБЁИCDABHIJEFGOPQRKLMNUVW:STZ XY;?.-,!",

    /* 5 */
    u"МНОПРСТУФХЦЧШЩЪЬЫЭЮЯ АБВГДЕЁЖЗИЙКЛVWXYZ .,!:;?-KLMNOPQRSTUABCDEFGHIJ"
};


static bool is_lower_letter(char16_t c){
    return (c >= u'a' && c <= u'z') || (c >= u'а' && c <= u'я') || c == u'ё';
}



int main(int argc, char *argv[]){

    if (argc == 0){
        perror("В качестве аргумента напишите имя файла для шифровки");
    }
    
    FILE *input_file = fopen(argv[0], 'r');

    if (input_file == NULL){
        perror("Не удалось открыть файл");
        return -1;
    }


    
    char block[ALPHABET_COUNT];

    while (fgets(block, ALPHABET_COUNT, input_file)) {

        for (int i = 0; i <= ALPHABET_COUNT; i++){
            if (is_lower_letter(block[i])) {
                
            }
        }



    }

    


}