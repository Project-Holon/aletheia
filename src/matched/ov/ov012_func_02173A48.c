/*
 * function: func_02173A48
 * address:  0x02173A48
 * packet:   pkt_ov012_02173A48
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *
 * Varargs function whose listing label (func_02173A4A) sits after the
 * push {r0-r3} home area; ov019 calls it at 0x02173A48.
 */

typedef unsigned short u16;

struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned int   u32;
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);

int func_02173A48(int a, int b, int c, int d)
{
    return func_0203D3A8(func_020399A8(), 0x1402, 4, (u32)(&a));
}
