/*
 * function: MAILTOOL_CreateArgsFromPartyMon
 * address: 0x021C3D44
 * packet: pkt_ov136_021C3D44
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MAIL_Create 0x02008F08 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   d_021C7EE0 0x021C7EE0 data a1
 */
#include "../include/Obj01163.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_021C7EE0[];
typedef unsigned int   u32;
struct Big;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuClearFast(unsigned, void *, unsigned);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MAIL_Create(int a0);
extern unsigned POKE_TOOL_GetPartyValue(void *, unsigned, unsigned);
void *MAILTOOL_CreateArgsFromPartyMon(void *a, void *b, unsigned heap)
{
    u8 *p;
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x97);
    MIi_CpuClearFast(0, p, 0x1C);
    ((struct Obj01163 *)p)->f0 = 0;
    ((struct Obj01163 *)p)->f10 = GAME_DATA_GetSaveControl(a);
    ((struct Obj01163 *)p)->f14 = MAIL_Create((unsigned)((u16)heap));
    POKE_TOOL_GetPartyValue(b, 0xA7, (u32)((struct Obj01163 *)p)->f14);
    return p;
}
