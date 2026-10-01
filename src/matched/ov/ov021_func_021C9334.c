/*
 * function: func_021C9334
 * address:  0x021C9334
 * packet:   pkt_ov021_021C9334
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020478B8  0x020478B8  arm
 *   func_02047910  0x02047910  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E;
extern void func_02047910(u32 h, u32 a, u32 b);
extern int func_020478B8(u32 h, u32 a, u32 b);
void func_021C9334(void *task, E *e)
{
    func_02047910(e->f14, 0, 0x1000);
    if (e->f10 == 1 && func_020478B8(e->f14, 1, 0x1000) == 0)
        e->f10 = 0;
}
