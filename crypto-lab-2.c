#include <stdio.h>
#include <stdint.h>

int gcd(uint64_t a, uint64_t b){
    /* Вычисляем НОД алгоритмом Евклида */

    printf("Computing gcd...%\n");

    while(b != 0){
        int r = a % b;

        printf("%d, %d, %d\n", a, b, r);

        a = b;
        b = r;
    }

    return(a);

}

int min_e(uint64_t p, uint64_t q){

    uint64_t e = 2;
    uint64_t phi = (p - 1) * (q - 1 );

    while (e < phi){
        if (gcd(e, phi) == 1){
            return e;
        }

        e++;
    }

    perror("couldn't find e");





    

}

int main(){


    uint64_t p, q;
    char text[20 * 2 + 1 + 2]; /* два числа по 20 байт + зпт + \n\0 */

    char temp;

    print("Please, enter p and q vaules:");
    
    if (
        !fgets(text, sizeof text, stdin) || 
        sscanf(text, " %d , %d %c", &p, &q, &temp) != 2
        
    ) {
            perror("<uint64>, <uint64> expected");
            return(1);
    }

    /* Проверка, что числа положительные */
    if (p <= 0 || q <= 0){
        perror("p and q must be unsigned values > 0");
        return(1);
    } 

    /* Проверка, что числа не равны */
    if (p == q) {
        perror("p and q could not be equal");
        return(1);
    }

    /* Проверка, что произведение p и q не вылезет за пределы uint64*/
    if (UINT64_MAX / p < q) {
        perror("p and q multiplication is more than uint64");
        return(1);
    }

    

    if {
        return(1);
    }


}
