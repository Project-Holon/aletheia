/*
 * function: func_021A658C
 * address:  0x021A658C
 * packet:   pkt_ov021_021A658C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A5B6C  0x021A5B6C  thumb  ov021
 *   func_021A652C  0x021A652C  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D3CC(int a0);
extern int func_021A5B6C(void *a, void *b, int c, int *d);
extern int func_021A652C(void *a, void *b, int c, int d, u16 e, int f);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);

int func_021A658C(void *a, void *b, int c, int d, u16 e, int f)
{
    int r;
    int loc;
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A652C(a, b, c, d, e, f);
    }
    r = func_021A5B6C(a, b, e, &loc);
    if (f == 1 && r != 0 && (r & 0x10) == 0) {
        r = 0;
    }
    if (loc != -1) {
        int t;
        func_021AB0F0(loc);
        t = func_021AB0F8(loc);
        if (r == 0) {
            if (t & 2) {
                return 2;
            }
            if (f == 1) {
                return 2;
            }
        }
    }
    return 4;
}
