/*
 * function: func_0219B2E8
 * address:  0x0219B2E8
 * packet:   pkt_ov021_0219B2E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_02164168  0x02164168  thumb  ov010
 *   func_0219B0C4  0x0219B0C4  thumb  ov021
 *   func_0216D63C  0x0216D63C  thumb  ov010
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 func_0216D5A8(u8 *p);
extern int func_02164168(int a);
extern int func_0219B0C4(void);
extern int func_0216D63C(char *a0, int a1);

int func_0219B2E8(int a, u8 *b)
{
    if (func_0216D5A8((u8 *)a) != 12) {
        return 1;
    }
    if (b[0] == 0) {
        if (func_02164168(a) == 0) {
            return 0;
        }
        if (func_0219B0C4() == 0) {
            return 0;
        }
        b[0] = func_0216D63C((char *)a, 1);
    }
    if (b[0] != 0) {
        b[0]--;
    }
    return 1;
}
