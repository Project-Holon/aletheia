/*
 * function: EVENT_WIFICLUB_SetupBattle
 * address:  0x021542C0
 * packet:   pkt_ov006_021542C0
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   REGULATION_SetRuleValue  0x0200AEE8  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetupCommDouble  0x020137C0  thumb
 *   BTL_SETUP_SetupCommTriple  0x02013864  thumb
 *   BTL_SETUP_SetupCommRotation  0x02013894  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   BTL_SETUP_ApplyRegulation  0x02013160  thumb
 *   POKE_REGULATION_AdjustPartyLevels  0x0201A2A8  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 */
#include "../include/Obj01027.h"
#include "../include/Obj18627.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef signed int     s32;
struct Ctx;
struct Reg;
struct ZoneData;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void REGULATION_SetRuleValue(struct Reg *p, u32 id, s32 value);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned short u16;
extern void BTL_SETUP_SetupCommSingle(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommDouble(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommTriple(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommRotation(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_AllocRecordBuffer(struct ZoneData *o, u32 heap);
extern void BTL_SETUP_ApplyRegulation(u8 *o, void *a1, u32 a2);
extern void POKE_REGULATION_AdjustPartyLevels(void *a0, void *a1);
extern void *GAME_DATA_GetTrainerRecord(int *p);

typedef struct Sub {
    u32 f00[5];
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  pad20[0x28];
    u8  f48;
} Sub;

void EVENT_WIFICLUB_SetupBattle(char *obj, int idx)
{
    u32 h;
    u8 flag;
    int v;

    h = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj01027 *)obj)->f4));
    flag = (*(Sub * *)&((struct Obj01027 *)obj)->f5C)->f48;
    if (flag)
        REGULATION_SetRuleValue((struct Reg *)((*(Sub * *)&((struct Obj01027 *)obj)->f5C)->f1c), 0xd, 1);
    else
        REGULATION_SetRuleValue((struct Reg *)((*(Sub * *)&((struct Obj01027 *)obj)->f5C)->f1c), 0xd, 0);

    switch (idx) {
    case 8:
        v = 1;
        if (flag)
            v = 3;
        break;
    case 7:
        v = 0;
        if (flag)
            v = 2;
        break;
    case 10:
        v = 5;
        if (flag)
            v = 7;
        break;
    case 9:
        v = 4;
        if (flag)
            v = 6;
        break;
    case 12:
        v = 9;
        if (flag)
            v = 0xb;
        break;
    case 11:
        v = 8;
        if (flag)
            v = 0xa;
        break;
    case 14:
        v = 0xd;
        if (flag)
            v = 0xf;
        break;
    case 13:
        v = 0xc;
        if (flag)
            v = 0xe;
        break;
    }
    ((struct Obj01027 *)obj)->f144 = v;
    ((struct Obj01027 *)obj)->f148 = 0;

    switch (idx) {
    case 7:
    case 8:
        BTL_SETUP_SetupCommSingle(*(u32 *)&((struct Obj01027 *)obj)->fDC, h, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 9:
    case 10:
        BTL_SETUP_SetupCommDouble(*(u32 *)&((struct Obj01027 *)obj)->fDC, h, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 11:
    case 12:
        BTL_SETUP_SetupCommTriple(*(u32 *)&((struct Obj01027 *)obj)->fDC, h, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 13:
    case 14:
        BTL_SETUP_SetupCommRotation(*(u32 *)&((struct Obj01027 *)obj)->fDC, h, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    }
    BTL_SETUP_AllocRecordBuffer((struct ZoneData *)(*(u32 *)&((struct Obj01027 *)obj)->fDC), 1);
    BTL_SETUP_ApplyRegulation((u8 *)(*(u32 *)&((struct Obj01027 *)obj)->fDC), (void *)((*(Sub * *)&((struct Obj01027 *)obj)->f5C)->f1c), 4);
    POKE_REGULATION_AdjustPartyLevels((void *)((*(Sub * *)&((struct Obj01027 *)obj)->f5C)->f1c), (void *)((*(Sub * *)&((struct Obj01027 *)obj)->f5C)->f14));
    POKE_REGULATION_AdjustPartyLevels((void *)((*(Sub * *)&((struct Obj01027 *)obj)->f5C)->f1c), (void *)((*(Sub * *)&((struct Obj01027 *)obj)->f5C)->f18));
    ((struct Obj18627 *)(*(char * *)&((struct Obj01027 *)obj)->fDC))->f6C = (u32)GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj01027 *)obj)->f4)));
}
