/*
 * function: SWEET_SCENT_FadeSetup
 * address:  0x021C62F0
 * packet:   pkt_ov021_021C62F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gSweetScentFadeBgPos     0x021DAAB4  data  a2
 *   func_02040588  0x02040588  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   FLD_VREQ_SetMainBlendAlpha  0x021D325C  thumb  ov021
 *   FLD_VREQ_SetBgVisible  0x021D3244  thumb  ov021
 */
#include "../include/Obj00458.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
} Pt;

extern const Pt gSweetScentFadeBgPos;
typedef unsigned int   u32;
struct St021D3244;
struct St021D325C;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_LoadPltt(u32 r7, void *r6, u32 r5, u32 r4);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void BG_SYS_SetTileEntry(int, int, int, int, int, int, int);
extern void BG_SYS_PushTile(u32 index);
extern void FLD_VREQ_SetMainBlendAlpha(struct St021D325C *p, u32 a, u32 b, u32 c, u32 d);
extern void FLD_VREQ_SetBgVisible(struct St021D3244 *p, int i, u8 v);

void SWEET_SCENT_FadeSetup(u8 *p)
{
    Pt pt;

    pt = gSweetScentFadeBgPos;
    func_02040588(p[0], 0);
    BG_SYS_LoadPltt(p[0], &pt, 8, 0x20);
    BG_SYS_Init(p[0], 1, 1, 0x100);
    BG_SYS_SetTileEntry(p[0], 0x100, 0, 0, 0x20, 0x20, 1);
    BG_SYS_PushTile(p[0]);
    FLD_VREQ_SetMainBlendAlpha(((struct Obj00458 *)p)->f4, 8, 0x37, p[1], 0x10 - p[1]);
    FLD_VREQ_SetBgVisible(((struct Obj00458 *)p)->f4, p[0], 1);
}
