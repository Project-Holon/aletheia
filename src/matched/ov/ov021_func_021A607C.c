/*
 * function: func_021A607C
 * address:  0x021A607C
 * packet:   pkt_ov021_021A607C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A60DC  0x021A60DC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D3CC(int a0);
extern u16 func_0216D5F8(void *p);
extern int func_021A60DC(void *a, void *b, int c, int d, int e, int f);

int func_021A607C(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 1) {
        if (e != 9) {
            if (e != func_0216D5F8(b) && f == 0) {
                return 3;
            }
            return func_021A60DC(a, b, c, d, e, f);
        }
        return 1;
    }
    return 0;
}
