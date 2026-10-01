/*
 * function: func_021B9FE4
 * address:  0x021B9FE4
 * packet:   pkt_ov088_021B9FE4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020310C4  0x020310C4  arm
 *   func_0204A600  0x0204A600  arm
 *   d_021BD63C     0x021BD63C  data  ov088  a4
 */

typedef int (*StateFn)(char *);

extern void func_020310C4(int);
extern void func_0204A600(void);
extern StateFn d_021BD63C[];

int func_021B9FE4(int a0, int a1, int a2, char *p)
{
    int s = d_021BD63C[*(int *)(p + 0x13c)](p);
    *(int *)(p + 0x13c) = s;
    if (s == 12) {
        return 1;
    }
    func_020310C4(*(int *)(p + 0x70));
    func_0204A600();
    return 0;
}
