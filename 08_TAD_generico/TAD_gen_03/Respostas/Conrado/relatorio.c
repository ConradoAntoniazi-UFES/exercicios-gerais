#include "relatorio.h"
#include "aluno.h"
#include <stdio.h>

void ImprimeRelatorio(Vector *alunos) {
    float media_notas = 0, p_aprovados = 0, p_masc = 0, p_fem = 0, p_others = 0;
    int num_alunos = VectorSize(alunos);
    char p = '%';

    for(int i = 0; i < num_alunos; i++) {
        float nota = GetNotaAluno(VectorGet(alunos, i));
        media_notas += nota;
        if(nota >= 6) p_aprovados += 1;
        char gen = GetGeneroAluno(VectorGet(alunos, i));
        if(gen == 'M') p_masc++;
        else if(gen == 'F') p_fem++;
        else if(gen == 'O') p_others++;
    }

    media_notas = media_notas / num_alunos;
    p_aprovados = p_aprovados * 100 / num_alunos;
    p_masc = p_masc * 100 / num_alunos;
    p_fem= p_fem* 100 / num_alunos;    
    p_others = p_others * 100 / num_alunos;

    printf("Media das notas: %.2f\n", media_notas);
    printf("Porcentagem de alunos aprovados: %.2f%c\n", p_aprovados, p);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%c\n", p_masc, p);
    printf("Feminino: %.2f%c\n", p_fem, p);
    printf("Outro: %.2f%c", p_others, p);
}