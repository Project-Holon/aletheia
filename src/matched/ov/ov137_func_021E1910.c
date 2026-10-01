/*
 * function: func_021E1910
 * address: 0x021E1910
 * packet: pkt_ov137_021E1910
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E18CC 0x021E18CC thumb ov137
 *   func_021E1768 0x021E1768 thumb ov137
 *   func_021DCE00 0x021DCE00 thumb ov137
 */
extern int func_021E18CC(void *);
extern int func_021E1768(char *, int);
extern void *func_021DCE00(char *, int);
int func_021E1910(char *p)
{
    int i;
    if (func_021E18CC(*(void **)(p + 0x24)) == 1)
        return 1;
    for (i = 0; i < 5; i++) {
        if (func_021E1768(p, i) != 0 && func_021E18CC(func_021DCE00(*(char **)(p + 0xdc), i)) == 1)
            return 1;
    }
    return 0;
}
