/*
 * function: func_0216F244
 * address:  0x0216F244
 * packet:   pkt_ov010_0216F244
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

int func_0216F244(char *a, char *b)
{
    char *q;

    switch (*(int *)(b + 0x14)) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 5;
    case 0:
    default:
        q = **(char ***)(a + 0x18);
        if (*(u8 *)(q + 0x33) == 0 && *(int *)(q + 0x1c) != 0)
            return 5;
        return 1;
    }
}
