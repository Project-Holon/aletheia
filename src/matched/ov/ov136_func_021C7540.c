/*
 * function: MB_SEQ_FinishMailTool
 * address: 0x021C7540
 * packet: pkt_ov136_021C7540
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 021C758A halfword is zero alignment padding.
 * symbols:
 *   MAILTOOL_HasMail 0x021C3E00 thumb ov136
 *   MAILTOOL_StoreMailToPartyMon 0x021C3E04 thumb ov136
 *   MAILTOOL_DeleteArgs 0x021C3E24 thumb ov136
 *   GAME_DATA_GetMyItem  0x0201292C  thumb  arm9
 *   GAME_DATA_GetMyParty  0x02012934  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 */
#include "../include/Obj03838.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Flags { u8 index : 7; u8 flag : 1; };
extern u32 MAILTOOL_HasMail(u32 *p);
extern int MAILTOOL_StoreMailToPartyMon(u32 *p, void *q);
extern void MAILTOOL_DeleteArgs(u8 *);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *, u32);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
int MB_SEQ_FinishMailTool(u8 *p)
{
    ((struct Obj03838 *)p)->f24 = MAILTOOL_HasMail((u32 *)(*(u8 * *)&((struct Obj03838 *)p)->f10));
    if (((struct Obj03838 *)p)->f24 == 1) {
        MAILTOOL_StoreMailToPartyMon((u32 *)(*(u8 * *)&((struct Obj03838 *)p)->f10), POKEPARTY_GetMember(GAME_DATA_GetMyParty(**(void ** *)&((struct Obj03838 *)p)->f4), ((struct Flags *)(p + 0x21))->index));
        func_02007F1C(GAME_DATA_GetMyItem(**(void ** *)&((struct Obj03838 *)p)->f4), ((struct Obj03838 *)p)->f22, 1, 0x65);
    }
    MAILTOOL_DeleteArgs(*(u8 * *)&((struct Obj03838 *)p)->f10);
    return 0;
}
