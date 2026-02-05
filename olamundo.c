#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 256

static void trim_newline(char *text) {
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}

static const char *pick_feature(const char *options[], size_t count) {
    size_t index = (size_t)(rand() % (int)count);
    return options[index];
}

static void generate_avatar(const char *name, const char *prompt) {
    const char *hair_options[] = {"cacheado", "liso", "ondulado", "crespo"};
    const char *eye_options[] = {"castanhos", "azuis", "verdes", "mel"};
    const char *skin_options[] = {"clara", "morena", "negra", "oliva"};
    const char *style_options[] = {"casual", "futurista", "corporativo", "artístico"};

    const char *hair = pick_feature(hair_options, sizeof(hair_options) / sizeof(hair_options[0]));
    const char *eyes = pick_feature(eye_options, sizeof(eye_options) / sizeof(eye_options[0]));
    const char *skin = pick_feature(skin_options, sizeof(skin_options) / sizeof(skin_options[0]));
    const char *style = pick_feature(style_options, sizeof(style_options) / sizeof(style_options[0]));

    printf("\n=== Avatar IA (Protótipo) ===\n");
    printf("Nome: %s\n", name);
    printf("Prompt: %s\n", prompt);
    printf("Características geradas:\n");
    printf("- Tom de pele: %s\n", skin);
    printf("- Cabelo: %s\n", hair);
    printf("- Olhos: %s\n", eyes);
    printf("- Estilo: %s\n", style);
    printf("\nSugestão de pipeline (simulada):\n");
    printf("1) Análise de prompt\n");
    printf("2) Geração de parâmetros faciais\n");
    printf("3) Renderização 2D/3D\n");
    printf("4) Pós-processamento\n");
    printf("\nObservação: este é um protótipo local simplificado.\n");
}

int main(void) {
    char name[MAX_INPUT];
    char prompt[MAX_INPUT];

    srand((unsigned int)time(NULL));

    printf("Protótipo de software de IA para criação de avatares humanos\n");
    printf("Digite o nome do avatar: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        fprintf(stderr, "Erro ao ler o nome.\n");
        return 1;
    }
    trim_newline(name);

    printf("Descreva o avatar desejado: ");
    if (fgets(prompt, sizeof(prompt), stdin) == NULL) {
        fprintf(stderr, "Erro ao ler a descrição.\n");
        return 1;
    }
    trim_newline(prompt);

    if (strlen(name) == 0 || strlen(prompt) == 0) {
        fprintf(stderr, "Nome e descrição não podem estar vazios.\n");
        return 1;
    }

    generate_avatar(name, prompt);
    return 0;
}
