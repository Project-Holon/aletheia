/*
 * function: func_021E0068
 * address: 0x021E0068
 * packet: pkt_ov170_021E0068
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind the full party-count-plus-30 expression to an int local.
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021DE158 0x021DE158 thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021DD930 0x021DD930 thumb ov170
 *   func_021DE66C 0x021DE66C thumb ov170
 *   func_020061E4 0x020061E4 thumb
 */
extern unsigned func_0201AA18(void *p);
extern int func_021DE158(char *p, unsigned a, unsigned b);
extern void func_021ED6E4(char *p, int a);
extern int func_021DD930(char *p);
extern void func_021DE66C(char *p, void *a);
extern void func_020061E4(int a);
int func_021E0068(char *p)
{
    char *s;
    int count;
    s = *(char **)(p + 0x2C) + 0x58;
    switch (*(unsigned short *)(s + 12)) {
    case 0:
        count = func_0201AA18((*(void *** )p)[2]) + 30;
        func_021DE158(p, *(unsigned char *)(p + 0x16), count);
        func_021ED6E4(p, 0);
        (*(unsigned short *)(s + 12))++;
        break;
    case 1:
        if (func_021DD930(p) == 0) {
            func_021DE66C(p, *(void **)(s + 8));
            func_020061E4(0x667);
            *(unsigned short *)(s + 12) = 0;
            return 0;
        }
        break;
    }
    return 1;
}
