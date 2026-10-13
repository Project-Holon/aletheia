/*
 * function: P_STATUS_DeleteObjResource
 * address: 0x021D4F24
 * packet: pkt_ov131_021D4F24
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two trailing zero alignment bytes at 0x021D4FBA.
 * symbols:
 *   P_STA_RIBBON_FreeArcGraphics 0x021D8904 thumb ov131
 *   P_STA_SKILL_Exit 0x021D9A04 thumb ov131
 *   P_STA_INFO_FreeResources 0x021D7BF0 thumb ov131
 *   P_STA_SUB_Exit 0x021D6808 thumb ov131
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj08143.h"
typedef unsigned char u8;
struct S;
extern void P_STA_RIBBON_FreeArcGraphics(void *a, struct S *s);
extern void P_STA_SKILL_Exit(u8 *a, u8 *p);
extern void P_STA_INFO_FreeResources(void *a, unsigned char *p);
extern void P_STA_SUB_Exit(void *,void *);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void P_STATUS_DeleteObjResource(char *p)
{
    u8 i;
    P_STA_RIBBON_FreeArcGraphics(p,((struct Obj08143 *)p)->f94);
    P_STA_SKILL_Exit((u8 *)p,((struct Obj08143 *)p)->f90);
    P_STA_INFO_FreeResources(p,((struct Obj08143 *)p)->f8C);
    P_STA_SUB_Exit(p,((struct Obj08143 *)p)->f88);
    for(i=0;i<=11;i++) CLACT_ReleasePalette((u32)(*(void **)(p+i*4+0x98)));
    for(i=12;i<=24;i++) CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+0x98)));
    for(i=25;i<=37;i++) CLACT_ReleaseCellAnim((u32)(*(void **)(p+i*4+0x98)));
    for(i=0;i<17;i++) CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+0x130)));
}
