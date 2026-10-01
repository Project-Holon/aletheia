/*
 * function: func_021C9314
 * address:  0x021C9314
 * packet:   pkt_ov021_021C9314
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047504  0x02047504  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E;
extern void func_0204762C(u32 h);
extern void func_02047738(u32 h);
extern void func_02047504(u32 h);
void func_021C9314(void *task, E *e)
{
    func_0204762C(e->f18);
    func_0204762C(e->f1C);
    func_02047738(e->f14);
    func_02047504(e->f20);
}
