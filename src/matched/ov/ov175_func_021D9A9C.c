/*
 * function: WIFIBATTLEMATCH_NET_CopyCompSave
 * address:  0x021D9A9C
 * packet:   pkt_ov175_021D9A9C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   func_0200E6E8  0x0200E6E8  thumb
 *   MISC_SAVEDATA_CopyQuadRecord  0x0200E6FC  thumb
 *   WIFIBATTLEMATCH_NET_GetNetId  0x021DC194  thumb  ov175
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   WIFILIST_GetGsProfileId  0x02009CC0  thumb
 *   REGULATION_Card_GetValue  0x0200B078  thumb
 *   REGULATION_Card_CalcCrc  0x0200B1C4  thumb
 *
 * Fills a profile record from the save data reached through +0x104: name, a 0x38 record, three words of the +0x34 block, the +0x34 id, a derived word and two values of the +0x108 block.
 *
 * Blocker: byte-correct (MATCH*); 0x02008494 is an unlabelled arm9 Thumb thunk
 *     (MI_CpuCopy8 with size 0x20) with no witness. Seed and match it and this
 *     file is EXACT.
 */
#include "../include/Obj00013.h"
#include "../include/Obj01067.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Save {
    u8  pad_00[8];
    u32 *sav;
    u8  pad_0c[0x28];
    u32 *blk;
};

typedef signed int     s32;
struct Big;
struct BigObj;
struct Rec0200E6FC;
struct Reg2;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MYSTATUS_Copy(void *src, void *dst);
extern void *func_0200E6E8(u32 a);
extern void MISC_SAVEDATA_CopyQuadRecord(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32 WIFIBATTLEMATCH_NET_GetNetId(char *obj);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern int WIFILIST_GetGsProfileId(void *a0);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern u16 REGULATION_Card_CalcCrc(struct Reg2 *p);

void WIFIBATTLEMATCH_NET_CopyCompSave(char *dst, char *obj)
{
    u32 st = (u32)GAME_DATA_GetSaveControl((struct Big *)(*(*(struct Save * *)&((struct Obj00013 *)obj)->f104)->sav));
    u32 h;

    MYSTATUS_Copy(GAME_DATA_GetMyStatus((void *)(*(*(struct Save * *)&((struct Obj00013 *)obj)->f104)->sav)), dst);
    MISC_SAVEDATA_CopyQuadRecord(func_0200E6E8(st), 0, (struct Rec0200E6FC *)(dst + 0x38));
    {
        const struct Save *s = *(struct Save * *)&((struct Obj00013 *)obj)->f104;
        ((struct Obj01067 *)dst)->f28 = s->blk[2];
        ((struct Obj01067 *)dst)->f2C = s->blk[3];
        ((struct Obj01067 *)dst)->f34 = s->blk[4];
    }
    ((struct Obj01067 *)dst)->f4C = WIFIBATTLEMATCH_NET_GetNetId((char *)(*(u32 *)&((struct Obj00013 *)obj)->f34));
    ((struct Obj01067 *)dst)->f48 = WIFILIST_GetGsProfileId((void *)GAME_DATA_GetWifiList((const struct BigObj *)(*(*(struct Save * *)&((struct Obj00013 *)obj)->f104)->sav)));
    h = ((struct Obj00013 *)obj)->f108;
    ((struct Obj01067 *)dst)->f40 = REGULATION_Card_GetValue((struct Reg2 *)h, 2);
    ((struct Obj01067 *)dst)->f50 = REGULATION_Card_CalcCrc((struct Reg2 *)h);
}
