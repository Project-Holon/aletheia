/*
 * function: func_02206908
 * address:  0x02206908
 * packet:   pkt_ov094_02206908
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef struct {
    unsigned int lo : 4;
    unsigned int b4 : 1;
} Bf;

int func_02206908(char *p, char *q, int i)
{
    int r;

    if (!((Bf *)(p + 0x68))->b4 || *(int *)(p + 0x58) != 1)
        return 1 & ((int *)*(int **)(q + 4))[i];
    r = (((int *)*(int **)(q + 4))[i] & 2) >> 1;
    if (r == 1)
        *(char *)(p + *(int *)(p + 0x27c) * 8 + 0x242 + *(int *)(p + 0x58)) = 0;
    return r;
}
