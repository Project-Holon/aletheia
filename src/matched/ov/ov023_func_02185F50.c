/*
 * function: func_02185F50
 * address: 0x02185F50
 * packet: pkt_ov023_02185F50
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: index declared before count places i in r4 and n in r5.
 * symbols:
 *   func_02184180 0x02184180 thumb ov022
 */
typedef unsigned char u8;
extern char *func_02184180(u8 *, u8);
int func_02185F50(char *p)
{
    int i;
    int n;
    n = 0;
    for (i = 0; i < 5; i++) {
        if (func_02184180(**(u8 ***)(p + 4), (u8)i) != 0)
            n++;
    }
    return n;
}
