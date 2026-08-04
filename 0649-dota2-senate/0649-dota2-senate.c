#include <stdlib.h>
#include <string.h>

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);

    int *radiant = malloc(2 * n * sizeof(int));
    int *dire = malloc(2 * n * sizeof(int));

    int rFront = 0, rRear = 0;
    int dFront = 0, dRear = 0;

    // Put indices into respective queues
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R')
            radiant[rRear++] = i;
        else
            dire[dRear++] = i;
    }

    while (rFront < rRear && dFront < dRear) {
        int r = radiant[rFront++];
        int d = dire[dFront++];

        if (r < d) {
            // R acts first, bans D
            radiant[rRear++] = r + n;
        } else {
            // D acts first, bans R
            dire[dRear++] = d + n;
        }
    }

    char *ans = malloc(8 * sizeof(char));

    if (rFront < rRear)
        strcpy(ans, "Radiant");
    else
        strcpy(ans, "Dire");

    free(radiant);
    free(dire);

    return ans;
}