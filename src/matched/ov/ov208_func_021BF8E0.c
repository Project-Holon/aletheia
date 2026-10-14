/*
 * function: ZUKAN_DETAIL_AREA_Exit
 * address: 0x021BF8E0
 * packet: pkt_ov208_021BF8E0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov072_id 0x00000048 data a1
 *   ZUKAN_DETAIL_AREA_FreeAreaEntryData 0x021C1F44 thumb ov208
 *   ZUKAN_DETAIL_AREA_DeletePokemonIcon 0x021C0C00 thumb ov208
 *   ZUKAN_DETAIL_AREA_ReleaseMarkerResources 0x021C0B58 thumb ov208
 *   ZUKAN_DETAIL_AREA_ApplySubScreenScroll 0x021C0950 thumb ov208
 *   ZUKAN_DETAIL_AREA_DeleteTextWindows 0x021C0898 thumb ov208
 *   ZUKAN_DETAIL_COMMON_FreeBgPalette 0x021BC97C thumb ov208
 *   ZUKAN_DETAIL_AREA_DeleteTownMarkerActors 0x021C06A0 thumb ov208
 *   ZUKAN_DETAIL_AREA_DeleteTownIconActors 0x021C0524 thumb ov208
 *   ZUKAN_DETAIL_AREA_DeleteMapActors 0x021C03C4 thumb ov208
 *   ZUKAN_DETAIL_COMMON_DeletePaletteAnim 0x021BC61C thumb ov208
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork 0x021BC464 thumb ov208
 *   ZUKAN_DETAIL_AREA_DeletePrintQueues 0x021C06EC thumb ov208
 *   TOWNMAP_GRH_FreeTownInfo 0x021BBB34 thumb ov072
 *   ZUKAN_DETAIL_PROCSYS_FreeBuffer 0x021BC34C thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02034A5C 0x02034A5C arm
 */
#include "../include/Obj03933.h"
#include "../include/Obj08396.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Node;
extern void ZUKAN_DETAIL_AREA_FreeAreaEntryData(int a);
extern void ZUKAN_DETAIL_AREA_DeletePokemonIcon(void *a, void *b);
extern void ZUKAN_DETAIL_AREA_ReleaseMarkerResources(void *, char *, void *);
extern void ZUKAN_DETAIL_AREA_ApplySubScreenScroll(void *unused, u8 *p, void *a2);
extern void ZUKAN_DETAIL_AREA_DeleteTextWindows(void *, char *, void *);
extern void ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(void *, char *, void *);
extern void ZUKAN_DETAIL_AREA_DeleteTownIconActors(void *, char *, void *);
extern void ZUKAN_DETAIL_AREA_DeleteMapActors(void *, char *, void *);
extern void ZUKAN_DETAIL_AREA_DeletePrintQueues(void *, char *, void *);
extern void ZUKAN_DETAIL_COMMON_FreeBgPalette(char *p);
extern void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(char *p);
extern void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *);
extern void TOWNMAP_GRH_FreeTownInfo(void *);
extern void ZUKAN_DETAIL_PROCSYS_FreeBuffer(char *p);
extern void func_02030EAC(struct Node *n);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02034A5C(int);
extern u8 ov072_id[];
/* Caller explicitly loads r2 for the three-argument teardown helpers. */
u32 ZUKAN_DETAIL_AREA_Exit(void *a0, u32 a1, void *a2, char *p, void *a4)
{
    u8 i;
    ZUKAN_DETAIL_AREA_FreeAreaEntryData(((struct Obj03933 *)p)->f94);
    for (i = 0; i < 2; i++) {
        char *q = p + i * 4;
        if (((struct Obj08396 *)q)->f5C != 0) ZUKAN_DETAIL_AREA_DeletePokemonIcon((void *)(((struct Obj08396 *)q)->f4C), (void *)(((struct Obj08396 *)q)->f5C));
        ((struct Obj08396 *)q)->f5C = 0;
    }
    ZUKAN_DETAIL_AREA_ReleaseMarkerResources(a2, p, a4);
    ZUKAN_DETAIL_AREA_ApplySubScreenScroll(a2, (u8 *)p, a4);
    ZUKAN_DETAIL_AREA_DeleteTextWindows(a2, p, a4);
    ZUKAN_DETAIL_COMMON_FreeBgPalette(((struct Obj03933 *)p)->f8);
    ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(a2, p, a4);
    ZUKAN_DETAIL_AREA_DeleteTownIconActors(a2, p, a4);
    ZUKAN_DETAIL_AREA_DeleteMapActors(a2, p, a4);
    ZUKAN_DETAIL_COMMON_DeletePaletteAnim(((struct Obj03933 *)p)->f420);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(((struct Obj03933 *)p)->f41C);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(((struct Obj03933 *)p)->f418);
    ZUKAN_DETAIL_AREA_DeletePrintQueues(a2, p, a4);
    func_02030EAC(((struct Obj03933 *)p)->f410);
    ARC_TOOL_DeleteHandle(((struct Obj03933 *)p)->f40C);
    TOWNMAP_GRH_FreeTownInfo(((struct Obj03933 *)p)->f3C8);
    ZUKAN_DETAIL_PROCSYS_FreeBuffer(a0);
    func_02034A5C((int)ov072_id);
    return 1;
}
