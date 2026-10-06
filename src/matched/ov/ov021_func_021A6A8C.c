/*
 * function: func_021A6A8C
 * address:  0x021A6A8C
 * packet:   pkt_ov021_021A6A8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A6908  0x021A6908  thumb
 *   func_021A6774  0x021A6774  thumb
 */

typedef struct S S;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021A6908(u8 *p, u32 a1);
extern void func_021A6774(void *a);

int func_021A6A8C(S *a, int b, int c)
{
    int r = func_021A6908((u8 *)a, b);
    func_021A6774(a);
    return r;
}
