#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
  c = toupper(c);
    static const char lookupTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', // A, B, C, D, E, F, G, H
        '0', '2', '2', '4', '5', '5', '0', '1', // I, J, K, L, M, N, O, P
        '2', '6', '2', '3', '0', '1', '0', '2', // Q, R, S, T, U, V, W, X
        '0', '2'                                // Y, Z
    };

    return lookupTable[c-65]; 
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
