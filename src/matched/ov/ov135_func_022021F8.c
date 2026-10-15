/*
 * function: WORLDTRADE_ADAPTER_RemovePartyMon
 * address: 0x022021F8
 * packet: pkt_ov135_022021F8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 022022B6..022022B8 zero alignment padding.
 * symbols:
 *   WORLDTRADE_ADAPTER_AllocHeapBuf 0x02202608 thumb ov135
 *   func_02007A18 0x02007A18 thumb
 *   WORLDTRADE_ADAPTER_CopyBoxMon 0x022026A0 thumb ov135
 *   WORLDTRADE_SetPokemon 0x0200ADB8 thumb
 *   func_02007664 0x02007664 thumb
 *   func_020307B0 0x020307B0 arm
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKEPARTY_RemoveMember 0x0201A9C8 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetBoxSave 0x02012F98 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   func_02007C34 0x02007C34 thumb
 *   WORLDTRADE_SetIsDeposited 0x0200AD94 thumb
 */
#include "../include/Obj01260.h"
#include "../include/Obj23460.h"
#include "../include/Obj23461.h"
#include "../include/Obj23462.h"
#include "../include/Obj23463.h"
#include "../include/Obj23464.h"
#include "../include/Obj23465.h"
#include "../include/Obj23466.h"
#include "../include/Obj23467.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *WORLDTRADE_ADAPTER_AllocHeapBuf(unsigned);
typedef signed int     s32;
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Party;
struct PerapVoice;
struct Rec0200AD94;
struct Sub020079BCEntry;
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void WORLDTRADE_ADAPTER_CopyBoxMon(u8 *p, u32 k);
extern void WORLDTRADE_SetPokemon(void *dest, const void *src, u32 a2);
extern void func_02007664(void *, unsigned, unsigned);
extern u32 func_020307B0(void *p);
extern void *POKEPARTY_GetMember(void *, unsigned);
extern u32 POKEPARTY_RemoveMember(struct Party *p, s32 idx);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Sub02007AC8Entry;
extern struct Sub02007AC8Entry *GAME_DATA_GetBoxSave(void *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void func_02007C34(struct PerapVoice *p, void *a);
extern void WORLDTRADE_SetIsDeposited(struct Rec0200AD94 *p, u16 v);
void WORLDTRADE_ADAPTER_RemovePartyMon(u8 *p, int flag)
{
    void *mon;
    void *save;
    void *box;
    if (((struct Obj01260 *)p)->fC4 != 0xFF) {
        mon = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
        WORLDTRADE_ADAPTER_CopyBoxMon((u8 *)func_02007A18(((struct Obj23460 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->fC, ((struct Obj01260 *)p)->fC4, ((struct Obj01260 *)p)->fC6), (u32)mon);
        if (flag) WORLDTRADE_SetPokemon(((struct Obj23461 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, mon, ((struct Obj01260 *)p)->fC4);
        func_02007664(((struct Obj23462 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->fC, ((struct Obj01260 *)p)->fC4, ((struct Obj01260 *)p)->fC6);
        func_020307B0(mon);
    } else {
        mon = POKEPARTY_GetMember(((struct Obj23463 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f8, ((struct Obj01260 *)p)->fC6);
        if (flag) WORLDTRADE_SetPokemon(((struct Obj23464 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, mon, ((struct Obj01260 *)p)->fC4);
        POKEPARTY_RemoveMember(((struct Obj23465 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f8, ((struct Obj01260 *)p)->fC6);
        save = GAMESYSTEM_GetGameData(((struct Obj23466 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f40);
        box = GAME_DATA_GetBoxSave(save);
        func_02007C34(box, GAME_DATA_GetMyParty(save));
    }
    if (flag) WORLDTRADE_SetIsDeposited(((struct Obj23467 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, 1);
}
