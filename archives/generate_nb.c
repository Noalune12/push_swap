#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_unique_random_numbers(int n, int max) {
    int numbers[max];
    for (int i = 0; i < max; i++) {
        numbers[i] = 0;
    }

    int count = 0;
    srand(time(0));

    while (count < n) {
        int rand_num = rand() % max + 1;

        if (numbers[rand_num - 1] == 0) {
            numbers[rand_num - 1] = 1;
            printf("%d ", rand_num);
            count++;
        }
    }
}

int main() {
    int n, max;

    printf("Entrez le nombre de nombres à générer: ");
    scanf("%d", &n);

    printf("Entrez la valeur maximale des nombres: ");
    scanf("%d", &max);

    if (n > max) {
        printf("Erreur : Vous ne pouvez pas générer plus de nombres que la plage maximale.\n");
        return 1;
    }

    printf("Nombres générés : \n");
    generate_unique_random_numbers(n, max);

    return 0;
}
