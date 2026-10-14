/*
 * function: RESEARCH_COMMON_Exit
 * address:  0x021C0AA4
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
 *   RESEARCH_COMMON_ExitClact  0x021C0AF0  thumb  ov217
 *   RESEARCH_COMMON_ReleaseResources  0x021C0B74  thumb  ov217
 *   RESEARCH_COMMON_DeleteClactUnit  0x021C0BA8  thumb  ov217
 *   RESEARCH_COMMON_DeleteActor  0x021C0C2C  thumb  ov217
 *   RESEARCH_COMMON_DeletePalAnm  0x021C0C50  thumb  ov217
 *   RESEARCH_COMMON_FreeSlotBuffers  0x021C0CC8  thumb  ov217
 *   RESEARCH_COMMON_DestroyPaletteAnime  0x021C0D08  thumb  ov217
 *   RESEARCH_COMMON_ExitPaletteAnime  0x021C0D2C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_COMMON_ExitClact();
extern u32 RESEARCH_COMMON_ReleaseResources(u32 a0);
extern void RESEARCH_COMMON_DeleteClactUnit(u8 *a0);
extern void RESEARCH_COMMON_DeleteActor(u8 *a0);
extern void RESEARCH_COMMON_DeletePalAnm(u8 *a0);
extern void RESEARCH_COMMON_FreeSlotBuffers(int *p);
extern void RESEARCH_COMMON_DestroyPaletteAnime(u8 *a0);
extern void RESEARCH_COMMON_ExitPaletteAnime(u8 *);
u32 RESEARCH_COMMON_Exit(u32 a0)
{
    RESEARCH_COMMON_ExitPaletteAnime((u8 *)a0);
    RESEARCH_COMMON_DestroyPaletteAnime((u8 *)a0);
    RESEARCH_COMMON_FreeSlotBuffers((int *)a0);
    RESEARCH_COMMON_DeletePalAnm((u8 *)a0);
    RESEARCH_COMMON_DeleteActor((u8 *)a0);
    RESEARCH_COMMON_DeleteClactUnit((u8 *)a0);
    RESEARCH_COMMON_ReleaseResources(a0);
    return RESEARCH_COMMON_ExitClact(a0);
}

