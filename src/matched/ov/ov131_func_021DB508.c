/*
 * function: P_STA_SKILL_SwapMoves
 * address: 0x021DB508
 * packet: pkt_ov131_021DB508
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: the final two bytes at 021DB612 are zero alignment padding.
 * semantic: selectors and slot indices preserve every input word. Selector
 *   additions and index*24/address additions are u32 wrap, with pointer
 *   conversion only after address arithmetic; no asserted slot bound.
 *   Six getter results and four selectors are assigned before use.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`apid=a;` before `apid=a+58U;`; `auid=a;` before `auid=a+62U;` and 2
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 *
 * symbols:
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STATUS_SetFastMode 0x021D60D4 thumb ov131
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   POKE_TOOL_SetBoxMoveSlot 0x020181FC thumb
 *   POKE_TOOL_SetBoxValue 0x02017E64 thumb
 *   P_STA_OAM_SwapInts 0x021DBE98 thumb ov131
 *   P_STA_SKILL_RefreshMoveDetail 0x021D9EE8 thumb ov131
 */
#include "../include/Obj23171.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *P_STATUS_GetPokePara(u8 *);
extern void P_STATUS_SetFastMode(u8 *,int);
extern u32 POKE_TOOL_GetBoxValue(void *,u32,u32);
extern void POKE_TOOL_SetBoxMoveSlot(void *,u16,u32);
extern void POKE_TOOL_SetBoxValue(void *,u32,u32);
extern void P_STA_OAM_SwapInts(int *a, int *b);
extern void P_STA_SKILL_RefreshMoveDetail(u8 *,u8 *);
void P_STA_SKILL_SwapMoves(u8 *p,u8 *q,u32 a,u32 b)
{
    void *m;
    u32 am,app,au,bm,bpp,bu;
    u32 apid,auid,bpid,buid;
    m=P_STATUS_GetPokePara(p);
    P_STATUS_SetFastMode(p,1);
    am=POKE_TOOL_GetBoxValue(m,a+54U,0);
    apid=a+58U;
    app=POKE_TOOL_GetBoxValue(m,apid,0);
    auid=a+62U;
    au=POKE_TOOL_GetBoxValue(m,auid,0);
    bm=POKE_TOOL_GetBoxValue(m,b+54U,0);
    bpid=b+58U;
    bpp=POKE_TOOL_GetBoxValue(m,bpid,0);
    buid=b+62U;
    bu=POKE_TOOL_GetBoxValue(m,buid,0);
    POKE_TOOL_SetBoxMoveSlot(m,bm,a);
    POKE_TOOL_SetBoxMoveSlot(m,am,b);
    POKE_TOOL_SetBoxValue(m,apid,bpp);
    POKE_TOOL_SetBoxValue(m,auid,bu);
    POKE_TOOL_SetBoxValue(m,bpid,app);
    POKE_TOOL_SetBoxValue(m,buid,au);
    P_STATUS_SetFastMode(p,0);
    P_STA_OAM_SwapInts(*(void **)((u32)q+a*24U+196U),*(void **)((u32)q+b*24U+196U));
    *(u32 *)((u32)q+a*24U+180U)=1;
    *(u32 *)((u32)q+b*24U+180U)=1;
    P_STA_SKILL_RefreshMoveDetail(p,q);
    ((struct Obj23171 *)q)->f10=1;
}
