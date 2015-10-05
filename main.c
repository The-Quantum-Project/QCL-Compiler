#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *rawCode;
    char *compCode;
} Script;

// You must free the result if result is non-NULL.
char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep
    int len_with; // length of with
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    if (!orig)
        return NULL;
    if (!rep)
        rep = "";
    len_rep = strlen(rep);
    if (!with)
        with = "";
    len_with = strlen(with);

    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

void compile(Script *script, char *string);

int main() {
    printf("Hello World\n");
    Script script;
    compile(&script, "System.out.println(\"Hello there\");");
    compile(&script, "System.err.println(\"Howdy Pardener\");");
    printf(script.rawCode);
    return 0;
}

void compile(Script *script, char *string) {
    char *str3 = (char *) malloc(1 + strlen(script->rawCode) + strlen(string) + strlen("\n"));
    strcpy(str3, script->rawCode);
    strcat(str3, string);
    strcat(str3, "\n");
    str3 = str_replace(str3, " ", "\\s");
    script->rawCode = str3;
}
