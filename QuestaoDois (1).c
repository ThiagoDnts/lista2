#include <stdio.h>


char validaSexo() {
    char sexo;
    while (1) {
        printf("Informe o sexo do assalariado (M/F): ");
        scanf(" %c", &sexo);
        if (sexo == 'M' || sexo == 'F') {
            return sexo;
        } else {
            printf("Sexo inválido. Por favor, informe M para masculino ou F para feminino.\n");
        }
    }
}


float validaSalario() {
    float salario;
    while (1) {
        printf("Informe o salário do assalariado: ");
        scanf("%f", &salario);
        if (salario > 1.00) {
            return salario;
        } else {
            printf("Salário inválido. Deve ser maior que R$1,00.\n");
        }
    }
}

void classificaSalario(float salario, float salarioMinimo) {
    if (salario > salarioMinimo) {
        printf("Classificação em relação ao salário mínimo: Acima do salário mínimo\n");
    } else if (salario < salarioMinimo) {
        printf("Classificação em relação ao salário mínimo: Abaixo do salário mínimo\n");
    } else {
        printf("Classificação em relação ao salário mínimo: Igual ao salário mínimo\n");
    }
}

void mostraClassifica(float salario, float salarioMinimo, char sexo) {
    printf("Salário: R$%.2f\n", salario);

    if (sexo == 'M') {
        printf("Sexo: Masculino\n");
    } else {
        printf("Sexo: Feminino\n");
    }

    classificaSalario(salario, salarioMinimo);
}

int main() {
    float salarioMinimo = 1400.00;
    int abaixoSalarioMinimo = 0;
    int acimaSalarioMinimo = 0;
    int totalAssalariados;

    printf("Quantos assalariados deseja cadastrar? ");
    scanf("%d", &totalAssalariados);

    for (int i = 0; i < totalAssalariados; ++i) {
        printf("\nAssalariado %d:\n", i + 1);

        char sexo = validaSexo();
        float salario = validaSalario();

        if (salario < salarioMinimo) {
            abaixoSalarioMinimo++;
        } else if (salario > salarioMinimo) {
            acimaSalarioMinimo++;
        }

        mostraClassifica(salario, salarioMinimo, sexo);
    }

    printf("\nQuantidade de assalariados abaixo do salário mínimo: %d\n", abaixoSalarioMinimo);
    printf("Quantidade de assalariados acima do salário mínimo: %d\n", acimaSalarioMinimo);

    return 0;
}
