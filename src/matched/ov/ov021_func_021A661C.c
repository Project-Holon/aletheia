/*
 * function: func_021A661C
 * address:  0x021A661C
 * packet:   pkt_ov021_021A661C
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
 *   func_021A652C  0x021A652C  thumb  ov021
 *   func_021A658C  0x021A658C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D3CC(void *p);
extern int func_021A652C(void *a, void *b, int c, int d, int e, int f);
extern int func_021A658C(void *a, void *b, int c, int d, int e, int f);

int func_021A661C(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC(b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A652C(a, b, c, d, e, f);
    }
    return func_021A658C(a, b, c, d, e, f);
}
