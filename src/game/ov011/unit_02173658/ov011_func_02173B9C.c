/*
 * function: func_02173B9C
 * address:  0x02173B9C
 * packet:   pkt_ov011_02173B9C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned int   u32;
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_02173B9C(int a, int b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((int)func_020399A8(), (unsigned char)a, 0x20A, 1, (u32)(&b), 0, 0, 0);
}
