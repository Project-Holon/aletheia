/*
 * function: func_021E1988
 * address: 0x021E1988
 * packet: pkt_ov170_021E1988
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EBFEC 0x021EBFEC thumb ov170
 *   func_021DEA3C 0x021DEA3C thumb ov170
 *   func_021DEAFC 0x021DEAFC thumb ov170
 */
extern int func_021EBFEC(char *, int);
extern void func_021DEA3C(unsigned char *, unsigned, unsigned, int);
extern int func_021DEAFC(unsigned char *);
int func_021E1988(unsigned char *p)
{
    char *w = *(char **)(p + 0x2C);
    char *b = w + 0x58;
    switch (*(unsigned short *)(b + 0xC)) {
    case 0:
        if (!func_021EBFEC(w, 10)) {
            unsigned old = p[0x16];
            p[0x16] = **(unsigned short **)(b + 8);
            func_021DEA3C(p, old, old, 1);
            *(unsigned short *)(b + 0xC) = 1;
        }
        break;
    case 1:
        if (!func_021DEAFC(p)) {
            *(unsigned short *)(b + 0xC) = 0;
            return 0;
        }
        break;
    }
    return 1;
}
