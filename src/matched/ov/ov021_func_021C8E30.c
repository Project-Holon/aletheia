/*
 * function: FIELD_TILE_MOVE_SlidePlayLoopSe
 * address:  0x021C8E30
 * packet:   pkt_ov021_021C8E30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005C64  0x02005C64  thumb
 *   func_0200616C  0x0200616C  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;
extern int func_02005C64(void);
extern int GFL_USE_IsSeSlotBusy(u32 h);
extern void func_0200616C(void *arg, int i);
void FIELD_TILE_MOVE_SlidePlayLoopSe(P *p)
{
    if (func_02005C64() == 0 && p->f18 == 0 && GFL_USE_IsSeSlotBusy(p->f24) == 0)
        func_0200616C((void *)0x769, p->f24);
}
