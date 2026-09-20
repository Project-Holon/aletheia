/*
 * function: func_02062B30
 * address:  0x02062B30
 * packet:   pkt_02062B30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062B64  0x02062B64  arm
 */

extern char *func_02062B64(void *, int);

int func_02062B30(void *r0, char **r1)
{
    char *res = func_02062B64(r0, 0x5343524E);
    if (res == 0) {
        *r1 = 0;
        return 0;
    }
    *r1 = res + 8;
    return 1;
}
