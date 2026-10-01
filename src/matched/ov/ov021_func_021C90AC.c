/*
 * function: func_021C90AC
 * address:  0x021C90AC
 * packet:   pkt_ov021_021C90AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204784C  0x0204784C  arm
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u8 pad[0x15]; u8 f15; u8 f16; u8 f17; u32 f18; } E;
extern E *func_021AC1E0(u32 a);
extern int func_0204784C(u32 h, u16 i, u32 *out);
void func_021C90AC(u32 a)
{
    u32 z;
    E *e;
    if (a != 0) {
        z = 0;
        e = func_021AC1E0(a);
        e->f15 = 1;
        e->f16 = 0;
        func_0204784C(e->f18, 1, &z);
    }
}
