/*
 * function: func_02173D2C
 * address:  0x02173D2C
 * packet:   pkt_ov011_02173D2C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb  ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */

typedef unsigned short u16;

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned int   u32;
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);

int func_02173D2C(int a0, int a1)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return func_0203D3A8(func_020399A8(), 0x20E, 4, (u32)(&a1));
}
