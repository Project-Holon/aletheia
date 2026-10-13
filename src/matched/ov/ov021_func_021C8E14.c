/*
 * function: FIELD_TILE_MOVE_SlidePlayBumpEffectSe
 * address:  0x021C8E14
 * packet:   pkt_ov021_021C8E14
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;
extern int func_02005C64(void);
extern void func_0200616C(void *arg, int i);
void FIELD_TILE_MOVE_SlidePlayBumpEffectSe(P *p)
{
    if (func_02005C64() == 0)
        func_0200616C((void *)0x6e2, p->f20);
}
