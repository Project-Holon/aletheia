/*
 * function: RESEARCH_TOP_ReleaseProc
 * address:  0x021B9600
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
 *   RESEARCH_TOP_DestroyCommon  0x021B9884  thumb  ov217
 *   RESEARCH_TOP_DestroyListView  0x021B98A8  thumb  ov217
 *   RESEARCH_TOP_ExitBackgrounds  0x021B990C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Proc;
extern void func_020315D4(struct Proc *);
extern u32 RESEARCH_TOP_DestroyCommon(u32 a0);
extern u32 RESEARCH_TOP_DestroyListView(u32 a0);
extern u32 RESEARCH_TOP_ExitBackgrounds();
u32 RESEARCH_TOP_ReleaseProc(u32 a0, u32 a1, u32 a2, u32 a3)
{
    RESEARCH_TOP_DestroyListView(a3);
    RESEARCH_TOP_DestroyCommon(a3);
    RESEARCH_TOP_ExitBackgrounds();
    func_020315D4((struct Proc *)a0);
    return 1;
}

