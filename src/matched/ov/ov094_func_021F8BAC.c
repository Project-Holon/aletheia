/*
 * function: func_021F8BAC
 * address:  0x021F8BAC
 * packet:   pkt_ov094_021F8BAC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   func_021FFDB4 0x021FFDB4 thumb ov094
 *   func_021FF374 0x021FF374 thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
extern char *d_0220AF20;
extern void func_021FFDB4(void *, int, u8, u8, s8, u32);
extern void func_021FF374(void *, int, int);
extern void func_021F89BC(void *);

void func_021F8BAC(void *h, int *p)
{
    if (p[3] != 0) {
        p[3]--;
        return;
    }
    switch (p[1]) {
    case 0:
        if (p[5] == 0)
            func_021FFDB4(*(void **)(d_0220AF20 + 0x190), p[0], 16, 16, 0, p[4]);
        p[3] = 3;
        p[1] = 1;
        break;
    case 1:
        if (p[5] == 0)
            func_021FF374(*(void **)(d_0220AF20 + 0x190), p[0], 1);
        p[3] = 3;
        p[1] = 2;
        break;
    case 2:
        p[1] = 0;
        if (p[5] == 0) {
            func_021FF374(*(void **)(d_0220AF20 + 0x190), p[0], 0);
            func_021FFDB4(*(void **)(d_0220AF20 + 0x190), p[0], 0, 0, 0, 0x7fff);
        }
        p[3] = 3;
        if (--p[2] == 0)
            func_021F89BC(h);
        break;
    }
}
