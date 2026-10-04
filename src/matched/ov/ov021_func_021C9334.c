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
extern int func_02047910(void *a, int idx, int amount);
extern int func_020478B8(void *a, int idx, int amount);
void func_021C9334(void *task, E *e)
{
    func_02047910((void *)e->f14, 0, 0x1000);
    if (e->f10 == 1 && func_020478B8((void *)e->f14, 1, 0x1000) == 0)
        e->f10 = 0;
}
