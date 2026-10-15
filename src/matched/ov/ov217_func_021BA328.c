/*
 * function: RESEARCH_TOP_ShowEntryActor
 * address:  0x021BA328
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_TOP_GetEntryIconSource  0x021BA3E0  thumb  ov217
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern u32 CLACT_SetActorAnimFrame();
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
struct Actor;
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern u32 RESEARCH_TOP_GetEntryIconSource(void *p, u32 i);
u32 RESEARCH_TOP_ShowEntryActor(u32 a0)
{
    u32 v1 = RESEARCH_TOP_GetEntryIconSource((void *)a0, 0);
    CLACT_SetActorDrawEnable((struct Obj *)v1, 1);
    CLACT_SetActorAutoAnim((struct Obj *)v1, 1);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)v1, 4096);
    return CLACT_SetActorAnimFrame(v1, 0);
}

