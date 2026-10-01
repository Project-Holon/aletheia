/*
 * function: func_021C928C
 * address:  0x021C928C
 * packet:   pkt_ov021_021C928C
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
typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E;
extern E *func_021AC1E0(u32 a);
extern int func_0204784C(u32 h, u16 i, u32 *out);
void func_021C928C(u32 a)
{
    u32 z;
    E *e;
    if (a != 0) {
        e = func_021AC1E0(a);
        if (e->f10 == 0) {
            z = 0;
            e->f10 = 1;
            func_0204784C(e->f14, 1, &z);
        }
    }
}
