/*
 * file:     unit_0217AE20.c
 * unit:     yes
 * function: func_0217AE20, func_0217AE38, func_0217AE40, func_0217AED4, func_0217AEE8, func_0217AEFC, func_0217AF04, func_0217AF38, func_0217AF4C, func_0217AFB0, func_0217AFE4, func_0217B054, func_0217B098, func_0217B158, func_0217B1D0, func_0217B264, func_0217B370, func_0217B3EC, func_0217B440, func_0217B4C4, func_0217B5E0, func_0217B66C, func_0217B6B4, func_0217B75C, func_0217B798, func_0217B80C, func_0217B83C, func_0217B840, func_0217B8E4, func_0217B8F0, func_0217B908, func_0217B974, func_0217B9BC, func_0217B9CC, func_0217B9F4, func_0217BA10, func_0217BA48, func_0217BA6C, func_0217BAA8, func_0217BAF0, func_0217BB04, func_0217BB20, func_0217BB3C, func_0217BB70, func_0217BCDC, func_0217BD7C, func_0217BD80
 * address:  0x0217AE20
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012964  0x02012964  thumb
 *   func_02025C74  0x02025C74  thumb
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_0217FFF8     0x0217FFF8  data  ov019  a4
 *   d_0218001C     0x0218001C  data  ov019  a2
 *   d_0217FFE4     0x0217FFE4  data  ov019  a2
 *   func_0216DE94 0x0216DE94 thumb ov010
 *   func_02034714 0x02034714 arm
 *   d_021807E0 0x021807E0 data a1
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CE0  0x02188CE0  thumb  ov021
 *   func_0217F958  0x0217F958  thumb  ov019
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_0217F894  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 *   func_0217F948  0x0217F948  thumb  ov019
 *   memcmp  0x0203EFC8  arm
 *   func_02012114 0x02012114  thumb
 *   func_0217F93C 0x0217F93C  thumb  ov019
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0201283C  0x0201283C  thumb
 *   d_02180044  0x02180044  data  a4
 *   d_02180048  0x02180048  data  a4
 *   d_0218004C  0x0218004C  data  a4
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_0217F858  0x0217F858  thumb  ov019
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8 0x0216D5F8  thumb  ov010
 *   func_0216D548 0x0216D548  thumb  ov010
 *   func_0216D550 0x0216D550  thumb  ov010
 *   func_021BBA70 0x021BBA70  thumb  ov021
 *   func_021734A8 0x021734A8  thumb  ov012
 *   func_02012138 0x02012138 thumb
 *   func_02026474 0x02026474 thumb
 *   func_0217413C 0x0217413C thumb ov012
 *   d_02180074  0x02180074  data  a4
 *   d_02180078  0x02180078  data  a4
 *   d_0218007C  0x0218007C  data  a4
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBA8 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021807E4 0x021807E4 data a1
 *   func_0201A364 0x0201A364 thumb
 *   func_0200AEE8 0x0200AEE8 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201A090 0x0201A090 thumb
 *   func_021A2E44 0x021A2E44 thumb ov021
 *   func_0200FB24 0x0200FB24 thumb
 *   func_02173524 0x02173524 thumb ov012
 *   func_0217F074 0x0217F074 thumb ov019
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0217F7E4  0x0217F7E4  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_02012124  0x02012124  thumb
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02173420  0x02173420  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef signed int     s32;

typedef enum { FALSE, TRUE } BOOL;

typedef struct { s32 x, y, z; } VecFx32;
#include "../ov012/union_comm_types.h"
#include "unit_0217AE20_types.h"

struct GameData;
struct GameSystem;
struct Regulation;

void MI_CpuFill8(void *dstp, u8 data, u32 size);
int memcmp(const void *a, const void *b, int n);

extern u32 func_02012964(const struct GameData *gameData);
extern u32 func_02025C74(u32 trainerView);
extern void func_0216E618(void *header, u32 gridX, u32 gridZ, int gridY);
extern int func_0216CE60(int mmdlSys, void *header, int param);
extern void *func_0216DE94(void *mmdlSys, unsigned int objId);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0216DAC8(unsigned int *mmdl, unsigned int vanish);
extern void *func_0201210C(struct GameSystem *gameSystem);
extern u32 func_02188CE0(void *fieldMap);
extern void func_0217F958(char *markSys, u32 mmdl);
extern void func_0216CF2C(void *mmdl);
extern void func_02087C6C(void *ownMac);
extern int func_0217F894(void *wifiFriends, UnionBeaconPc *beaconPc);
extern int func_0200EDC4(void *metTrainers, u32 trainerId);
extern void func_0217F948(char *markSys, u32 mmdl, u32 kind);
extern unsigned int func_02012114(struct GameSystem *gameSystem);
extern void func_0217F93C(int markSys, int mmdl);
extern void *func_02012EBC(const struct GameData *gameData);
extern void *func_0200ED48(void *saveControl);
extern u32 func_0201283C(const struct GameData *gameData);
extern int func_0217F060(int status);
extern int func_0217F858(int status);
extern int func_0216D3CC(int mmdl);
extern void func_0216D410(void *mmdl, u16 acmd);
extern u16 func_0216D5A0(void *mmdl);
extern int func_0216E0E8(int mmdl, int moveCode);
extern void func_0216D828(int mmdl, s16 *pos);
extern int func_0216D454(int mmdl);
extern int func_0216D480(char *mmdl);
extern void *func_02188CB4(void *fieldMap);
extern void *func_021A3074(void *fieldPlayer);
extern u16 func_0216D5F8(void *mmdl);
extern u32 *func_0216D548(u32 *mmdl, u32 bit);
extern u32 *func_0216D550(u32 *mmdl, u32 bit);
extern void func_021BBA70(UnionRoomWork *work, UnionBeaconPc *beaconPc, u16 *outValue, u8 mode);
extern void func_021734A8(UnionRoomWork *work, u32 id, u32 value);
extern unsigned int func_02012138(struct GameSystem *gameSystem);
extern u32 func_02026474(void *gameComm);
extern int func_0217413C(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work);
extern void *func_0200BAC8(void *saveControl);
extern unsigned int func_0200BBA8(void *battleTeam);
extern void *func_0200BAF4(int battleTeam, int heapId);
extern u32 func_020307B0(void *p);
extern void func_0201A364(int regulationId, struct Regulation *regulation);
extern void func_0200AEE8(struct Regulation *regulation, u32 id, s32 value);
extern void *func_02012934(const struct GameData *gameData);
extern int func_0201A090(struct Regulation *regulation, void *party, unsigned int *violationMask);
extern void func_021A2E44(void *fieldMap, unsigned int busy);
extern unsigned int func_0200FB24(void);
extern void func_02173524(UnionRoomWork *work, UnionConnectInfo *connect);
extern void func_0217F074(UnionRoomWork *work);
extern void *func_02188C7C(void *fieldMap);
extern int func_021A3460(u32 fieldPlayer, u32 outGridX, u32 outGridY, u32 outGridZ);
extern void  func_02172D20(UnionRoomWork *work);
extern int   func_02172D68(UnionRoomWork *work);
extern u16   func_0216D588(void *mmdl);
extern void *func_0216DDC0(u32 mmdlSys, u32 gridX, u32 gridZ, u32 gridY);
extern int   func_0203D1B4(void);
extern u32   func_020362DC(void);
extern int func_0217F7E4(u32 fieldMap);
extern unsigned int func_0217F1EC(UnionRoomWork *work);
extern void func_02012124(struct GameSystem *gameSystem, u32 state);
extern void func_02172D38(UnionRoomWork *work);
extern void func_02173420(UnionRoomWork *work);
extern void func_02172D50(UnionRoomWork *work);
void func_0217AE20(UnionRoomWork *work);
int func_0217AE38(UnionCharaSlot *slot, char nextAction);
int func_0217AE40(UnionRoomWork *work, struct GameData *gameData, u16 trainerView, int objId);
u16 func_0217AED4(UnionBeaconPc *beaconPc, UnionCharaSlot *slot);
BOOL func_0217AEE8(u16 objId);
u16 func_0217AEFC(unsigned int objId);
int func_0217AF04(UnionRoomWork *work, u16 objId);
int func_0217AF38(u16 objId);
int func_0217AF4C(UnionRoomWork *work, u16 objId);
void *func_0217AFB0(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot);
UnionCharaSlot *func_0217AFE4(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionMember *member, int memberIndex, int visible, int *mmdlOut);
void func_0217B054(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot);
void func_0217B098(UnionRoomWork *work, u32 metTrainers, u32 wifiFriends, u32 markSys, UnionBeaconPc *beaconPc);
int func_0217B158(UnionRoomWork *work, UnionBeaconPc *ownerPc, u8 *mac);
int func_0217B1D0(UnionRoomWork *work, UnionBeaconPc *beaconPc);
void func_0217B264(UnionRoomWork *work, struct GameData *gameData, void *fieldMap);
int func_0217B370(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap);
int func_0217B3EC(UnionRoomWork *work, UnionBeaconPc *beaconPc);
void func_0217B440(UnionRoomWork *work, struct GameData *gameData, void *fieldMap);
int func_0217B4C4(UnionRoomWork *work, UnionCharaSlot *slot);
int func_0217B5E0(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step);
int func_0217B66C(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step);
int func_0217B6B4(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step);
void func_0217B75C(UnionRoomWork *work);
void func_0217B798(UnionRoomWork *work, UnionBeaconPc *beaconPc);
int func_0217B80C(struct GameSystem *gameSystem, void *fieldMap);
int func_0217B83C(void *gameSystem, void *pos);
int func_0217B840(UnionRoomWork *work, void *fieldMap);
int func_0217B8E4(UnionRoomWork *work, int playCategory);
int func_0217B8F0(UnionRoomWork *work, char playCategory);
int func_0217B908(int status);
int func_0217B974(int status);
int func_0217B9BC(unsigned int status);
void *func_0217B9CC(UnionRoomWork *work);
void func_0217B9F4(void *party);
void func_0217BA10(UnionRoomWork *work, int status);
int func_0217BA48(UnionRoomWork *work, unsigned int *violationMask);
int func_0217BA6C(UnionRoomWork *work, unsigned int *violationMask);
int func_0217BAA8(UnionRoomWork *work, int status, unsigned int *myPartyMask, unsigned int *battleTeamMask);
void func_0217BAF0(UnionRoomWork *work, void *fieldMap, unsigned int busy);
int func_0217BB04(UnionRoomWork *work);
int func_0217BB20(UnionRoomWork *work);
int func_0217BB3C(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap);
int func_0217BB70(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap);
int func_0217BCDC(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step);
extern const UnionCharaMmdlHeader d_0217FFF8;
extern const UnionGridPos d_0218001C[];
extern const UnionGridPos d_0217FFE4[];
extern const char d_021807E0[];
extern UnionCharaActionEntry d_02180044[];
extern UnionCharaActionEntry d_02180048[];
extern UnionCharaActionEntry d_0218004C[];
extern UnionOneselfActionEntry d_02180074[];
extern UnionOneselfActionEntry d_02180078[];
extern UnionOneselfActionEntry d_0218007C[];
extern const char d_021807E4[];






void func_0217AE20(UnionRoomWork *work)
{
    MI_CpuFill8(work->charaSlot, 0, sizeof(UnionCharaSlot) * UNION_CHARA_MAX);
}





int func_0217AE38(UnionCharaSlot *slot, char nextAction)
{
    slot->nextAction = nextAction;
    return 1;
}






/*
 * What closed it: the spilled third parameter is u16, not u32. As u32 the
 * scheduler hoists its reload (`ldr r0,[sp]`) above the `strh` of d into
 * the local; as u16 the reload stays after it (see
 * docs/notes/pkt_ov019_0217AE40.c.txt for the earlier near miss).
 */
int func_0217AE40(UnionRoomWork *work, struct GameData *gameData, u16 trainerView, int objId)
{
    int mmdlSys;
    u16 beaconIndex, memberIndex;
    UnionCharaMmdlHeader header;

    mmdlSys = func_02012964(gameData);
    beaconIndex = (u16)(objId >> 8);
    memberIndex = (u16)((objId & 0xff) - 0x20);
    header = d_0217FFF8;
    header.f.objId = objId;
    header.f.graphicsId = func_02025C74(trainerView);
    if (memberIndex != 0)
        header.f.moveCode = 15;
    func_0216E618(&header, (u16)(d_0218001C[beaconIndex].x + d_0217FFE4[memberIndex].x),
                  (u16)(d_0218001C[beaconIndex].z + d_0217FFE4[memberIndex].z), 0);
    return func_0216CE60(mmdlSys, &header, 422);
}





u16 func_0217AED4(UnionBeaconPc *beaconPc, UnionCharaSlot *slot) { return (beaconPc->index << 8) | (slot->memberIndex + 0x20); }





BOOL func_0217AEE8(u16 objId) { if ((u16)((unsigned char)objId - 0x20) == 0) return FALSE; else return TRUE; }






u16 func_0217AEFC(unsigned int objId)
{
    return (u16)(objId >> 8);
}





int func_0217AF04(UnionRoomWork *work, u16 objId) { int i; UnionCharaSlot *slot; slot = work->charaSlot; for(i=0;i<UNION_CHARA_MAX;i++,slot++) { if(slot->inUse == 1 && slot->beaconPc != 0 && objId == func_0217AED4(slot->beaconPc,slot)) return slot->sex; } return 0; }





int func_0217AF38(u16 objId) { unsigned int memberKey; memberKey = (unsigned char)objId; if ((u16)memberKey >= 0x20) return 1; else return 0; }






int func_0217AF4C(UnionRoomWork *work, u16 objId)
{
    UnionCharaSlot *slot;
    int i;

    slot = work->charaSlot;
    for (i = 0; i < UNION_CHARA_MAX; i++, slot++) {
        if (slot->inUse == 1 && slot->beaconPc != 0 && slot->beaconPc->life != 0
            && objId == ((slot->beaconPc->index << 8) | (slot->memberIndex + 0x20))) {
            if (slot->action == 2 || slot->action == 1 || (u8)(slot->nextAction + 0xff) <= 1)
                return 0;
            return 1;
        }
    }
    return 0;
}





void *func_0217AFB0(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot) { u16 objId; void *mmdl; objId = func_0217AED4(beaconPc,slot); mmdl = func_0216DE94((void *)func_02012964(work->parent->gameData),objId); if(mmdl == 0) func_02034714(d_021807E0,0,d_021807E0); return mmdl; }






UnionCharaSlot *func_0217AFE4(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionMember *member, int memberIndex, int visible, int *mmdlOut)
{
    UnionCharaSlot *slot;
    int i;
    int mmdl;

    slot = work->charaSlot;
    for (i = 0; i < UNION_CHARA_MAX; i++, slot++) {
        if (slot->inUse == 0) {
            slot->beaconPc = beaconPc;
            slot->trainerView = member->trainerView;
            slot->sex = member->sex;
            slot->memberIndex = memberIndex;
            slot->inUse = 1;
            mmdl = func_0217AED4(beaconPc, slot);
            mmdl = func_0217AE40(work, work->parent->gameData, member->trainerView, mmdl);
            if (visible == 0)
                func_0216DAC8((unsigned int *)mmdl, 1);
            *mmdlOut = mmdl;
            return slot;
        }
    }
    func_02034714(d_021807E0, 0, d_021807E0);
    return 0;
}







void func_0217B054(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot)
{
    void *fieldMap;
    void *mmdl;

    fieldMap = func_0201210C(work->parent->gameSystem);
    mmdl = func_0217AFB0(work, beaconPc, slot);
    if (fieldMap != 0 && mmdl != 0)
        func_0217F958((char *)func_02188CE0(fieldMap), (u32)mmdl);
    func_0216CF2C(mmdl);
    MI_CpuFill8(slot, 0, sizeof(UnionCharaSlot));
}







void func_0217B098(UnionRoomWork *work, u32 metTrainers, u32 wifiFriends, u32 markSys, UnionBeaconPc *beaconPc)
{
    int mmdl;
    u8 ownMac[8];
    int i;

    if (beaconPc->life == 0)
        return;
    func_02087C6C(ownMac);
    for (i = 0; i < UNION_MEMBER_MAX; i++) {
        if (beaconPc->charaSlot[i] == 0 && beaconPc->beacon.group.member[i].valid == 1
            && memcmp(ownMac, (const u8 *)(&beaconPc->beacon.group.member[i]), 6) != 0
            && func_0217B158(work, beaconPc, (u8 *)(&beaconPc->beacon.group.member[i])) != 0) {
            beaconPc->charaSlot[i] = func_0217AFE4(work, beaconPc, &beaconPc->beacon.group.member[i], i, 0, &mmdl);
            beaconPc->charaSlot[i]->action = 1;
            func_0217AE38(beaconPc->charaSlot[i], 0);
            if (i == 0) {
                if (func_0217F894((void *)wifiFriends, beaconPc) == 1)
                    func_0217F948((char *)markSys, mmdl, 0);
                else if (func_0200EDC4((void *)metTrainers, beaconPc->beacon.trainerId) == 1)
                    func_0217F948((char *)markSys, mmdl, 1);
            }
        }
    }
}






int func_0217B158(UnionRoomWork *work, UnionBeaconPc *ownerPc, u8 *mac)
{
    UnionBeaconPc *pc = work->beaconPc;
    int i;
    int j;

    for (i = 0; i < UNION_BEACON_PC_MAX; i++, pc++) {
        if (pc == ownerPc || pc->beacon.valid != 1) {
            continue;
        }
        for (j = 0; j < UNION_MEMBER_MAX; j++) {
            if (pc->beacon.group.member[j].valid == 1 && memcmp(mac, pc->beacon.group.member[j].mac, 6) == 0) {
                if (pc->life != 0) {
                    pc->life = 1;
                }
                return 0;
            }
        }
    }
    return 1;
}






int func_0217B1D0(UnionRoomWork *work, UnionBeaconPc *beaconPc)
{
    int i;
    UnionCharaSlot *slot;
    int markSys;
    int objId;

    for (i = 0; i < UNION_MEMBER_MAX; i++) {
        slot = beaconPc->charaSlot[i];
        if (slot == 0 || beaconPc->beacon.group.member[i].valid != 1) {
            continue;
        }
        if (memcmp(beaconPc->beacon.group.member[i].mac, work->mySituation.focusMac, 6) != 0) {
            continue;
        }
        if (func_02012114(work->parent->gameSystem) == 1) {
            markSys = func_02188CE0(func_0201210C(work->parent->gameSystem));
            if (markSys != 0) {
                objId = func_0217AED4(beaconPc, slot);
                objId = (int)func_0216DE94((void *)func_02012964(work->parent->gameData), objId);
                if (objId != 0) {
                    func_0217F93C(markSys, objId);
                }
            }
        }
        MI_CpuFill8(work->mySituation.focusMac, 0, 6);
        return 1;
    }
    return 0;
}






/*
 * Addresses are Black-image addresses.
 */
void func_0217B264(UnionRoomWork *work, struct GameData *gameData, void *fieldMap)
{
    int i;
    int focusPending;
    u32 metTrainers;
    u32 wifiFriends;
    u32 markSys;
    UnionBeaconPc *beaconPc;
    u8 zeroMac[6] = {0, 0, 0, 0, 0, 0};

    focusPending = 0;
    metTrainers = (u32)func_0200ED48(func_02012EBC(gameData));
    wifiFriends = func_0201283C(gameData);
    markSys = func_02188CE0(fieldMap);
    func_02012964(gameData);
    if (memcmp(zeroMac, work->mySituation.focusMac, 6) != 0) {
        focusPending = 1;
    }
    beaconPc = work->beaconPc;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++, beaconPc++) {
        if (beaconPc->beacon.valid == 1) {
            int freeCount;
            int j;
            UnionCharaSlot *slot;

            func_0217B3EC(work, beaconPc);
            func_0217B098(work, metTrainers, wifiFriends, markSys, beaconPc);
            if (focusPending == 1) {
                if (func_0217B1D0(work, beaconPc) == 1) {
                    focusPending = 0;
                }
            }
            freeCount = 0;
            for (j = 0; j < UNION_MEMBER_MAX; j++) {
                slot = beaconPc->charaSlot[j];
                if (slot != 0) {
                    if (func_0217B370(work, slot, fieldMap) == 0) {
                        func_0217B054(work, beaconPc, slot);
                        beaconPc->charaSlot[j] = 0;
                        freeCount++;
                    }
                } else {
                    freeCount++;
                }
            }
            if (freeCount >= 5 && beaconPc->life == 0) {
                MI_CpuFill8(beaconPc, 0, sizeof(UnionBeaconPc));
            }
        }
    }
    MI_CpuFill8(work->mySituation.focusMac, 0, 6);
}






int func_0217B370(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap)
{
    int result = 1;
    UnionCharaActionFunc func;

    switch (slot->phase) {
    case 0:
        func = d_02180044[slot->action].func;
        break;
    case 1:
        func = d_02180048[slot->action].func;
        break;
    case 2:
        func = d_0218004C[slot->action].func;
        break;
    }
    if (func != 0) {
        result = func(work, slot, fieldMap, &slot->step);
    }
    if (result == 1) {
        slot->step = 0;
        slot->phase = slot->phase + 1;
        if (slot->phase > 2) {
            if (slot->action == 2) {
                return 0;
            }
            slot->phase = 0;
            slot->action = slot->nextAction;
            slot->nextAction = 0;
        }
    }
    return 1;
}






int func_0217B3EC(UnionRoomWork *work, UnionBeaconPc *beaconPc)
{
    UnionMySituation *situation = (&work->mySituation);
    if ((UnionBeaconPc *)situation->connect.talkParam == beaconPc || situation->connect.talkPc == beaconPc ||
        (UnionBeaconPc *)situation->connect.connectParam == beaconPc || situation->connect.connectPc == beaconPc) {
        if (beaconPc->life == 0) {
            beaconPc->life = 1;
        }
        return 1;
    }
    if (beaconPc->life == 0) {
        return 0;
    }
    beaconPc->life -= 1;
    return 1;
}






void func_0217B440(UnionRoomWork *work, struct GameData *gameData, void *fieldMap)
{
    UnionBeaconPc *beaconPc;
    int metTrainers;
    int wifiFriends;
    int markSys;
    int mmdl;
    int i;

    metTrainers = (int)func_0200ED48(func_02012EBC(gameData));
    wifiFriends = func_0201283C(gameData);
    markSys = func_02188CE0(fieldMap);
    beaconPc = work->beaconPc;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++, beaconPc++) {
        if (beaconPc->beacon.valid == 1 && beaconPc->charaSlot[0] != 0) {
            mmdl = (int)func_0217AFB0(work, beaconPc->charaSlot[0]->beaconPc, beaconPc->charaSlot[0]);
            if (mmdl != 0) {
                if (func_0217F894((void *)wifiFriends, beaconPc) == 1) {
                    func_0217F948((char *)markSys, mmdl, 0);
                } else if (func_0200EDC4((void *)metTrainers, beaconPc->beacon.trainerId) == 1) {
                    func_0217F948((char *)markSys, mmdl, 1);
                }
            }
        }
    }
}






int func_0217B4C4(UnionRoomWork *work, UnionCharaSlot *slot)
{
    UnionBeaconPc *beaconPc;
    UnionMySituation *situation;
    int groupCategory;
    int appealNo;
    void *mmdl;

    situation = (&work->mySituation);
    beaconPc = slot->beaconPc;
    if (beaconPc->life == 0) {
        func_0217AE38(slot, 2);
        return 1;
    }
    if (!beaconPc->beacon.group.member[slot->memberIndex].valid || slot->trainerView != beaconPc->beacon.group.member[slot->memberIndex].trainerView) {
        func_0217AE38(slot, 2);
        return 1;
    }
    groupCategory = func_0217F858(beaconPc->beacon.status);
    if (situation->connect.requestId == func_0217AED4(slot->beaconPc, slot)) {
        func_0217AE38(slot, 3);
        return 1;
    }
    appealNo = situation->appealNo;
    if (appealNo != 0 && (appealNo == groupCategory || (groupCategory == 0 && appealNo == beaconPc->beacon.appealNo)) && slot->memberIndex == 0
        && func_0217F060(beaconPc->beacon.status) > beaconPc->beacon.connectNum) {
        mmdl = func_0217AFB0(work, slot->beaconPc, slot);
        if (func_0216D3CC((int)mmdl) == 1) {
            func_0216D410(mmdl, 0x31);
        }
    } else if (slot->memberIndex == 0 && beaconPc->beacon.connectNum > 1) {
        mmdl = func_0217AFB0(work, slot->beaconPc, slot);
        if (func_0216D5A0(mmdl) == 2) {
            func_0216E0E8((int)mmdl, 0xF);
        }
    } else if (slot->memberIndex == 0 && beaconPc->beacon.connectNum <= 1) {
        mmdl = func_0217AFB0(work, slot->beaconPc, slot);
        if (func_0216D5A0(mmdl) == 0xF) {
            func_0216E0E8((int)mmdl, 2);
        }
    }
    return 0;
}






int func_0217B5E0(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step)
{
    s16 pos[8];
    int mmdl = (int)func_0217AFB0(work, slot->beaconPc, slot);
    switch (*step) {
    case 0:
        if (func_0216D3CC(mmdl) == 1) {
            func_0216D828((int)func_021A3074(func_02188CB4(fieldMap)), pos);
            func_0216D828(mmdl, pos + 4);
            if (pos[4] != pos[0] || pos[6] != pos[2]) {
                func_0216D410((void *)mmdl, 0x44);
                func_0216DAC8((unsigned int *)mmdl, 0);
                *step = *step + 1;
            }
        }
        break;
    case 1:
        if (func_0216D454(mmdl) == 1) { func_0216D480((char *)mmdl); return 1; }
        break;
    }
    return 0;
}






int func_0217B66C(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step)
{
    int mmdl = (int)func_0217AFB0(work, slot->beaconPc, slot);
    switch (*step) {
    case 0:
        if (func_0216D3CC(mmdl) == 1) { func_0216D410((void *)mmdl, 0x43); *step = *step + 1; }
        break;
    case 1:
        if (func_0216D454(mmdl) == 1) { func_0216D480((char *)mmdl); return 1; }
        break;
    }
    return 0;
}







int func_0217B6B4(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step)
{
    UnionMySituation *situation = (&work->mySituation);
    int mmdl;
    u16 acmd;

    mmdl = (int)func_0217AFB0(work, slot->beaconPc, slot);
    switch (*step) {
    case 0:
        if (func_0216D3CC(mmdl) == 1) {
            switch (func_0216D5F8(func_021A3074(func_02188CB4(fieldMap)))) {
            case 0:
                acmd = 1;
                break;
            case 1:
                acmd = 0;
                break;
            case 2:
                acmd = 3;
                break;
            case 3:
            default:
                acmd = 2;
                break;
            }
            func_0216D410((void *)mmdl, acmd);
            *step = *step + 1;
        }
        break;
    case 1:
        if (func_0216D480((char *)mmdl) == 1) {
            func_0216D548((u32 *)mmdl, 8);
            *step = *step + 1;
        }
        break;
    case 2:
        if (situation->connect.requestId != func_0217AED4(slot->beaconPc, slot)) {
            func_0216D550((u32 *)mmdl, 8);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * lever: the bit at byte 7, bit 4 is a one-bit unsigned char field;
 * integer masks instead produce asrs/movs/ands and grow the body by 4 bytes.
 */
void func_0217B75C(UnionRoomWork *work)
{
    int i;
    UnionBeaconPc *beaconPc;
    beaconPc = work->beaconPc;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++, beaconPc++) {
        if (beaconPc->beacon.valid == 1 && beaconPc->updateState != 0) {
            func_0217B798(work, beaconPc);
            beaconPc->updateState = 0;
        }
    }
}







void func_0217B798(UnionRoomWork *work, UnionBeaconPc *beaconPc)
{
    UnionMySituation *situation = (&work->mySituation);
    u8 ownMac[6];

    func_021BBA70(work, beaconPc, 0, 0);
    if (situation->playCategory == 0 && situation->nextPlayCategory == 0 && beaconPc->beacon.playCategory == 5 && beaconPc->life != 0) {
        func_02087C6C(ownMac);
        if (memcmp(beaconPc->beacon.mac, ownMac, 6) == 0 && func_0217B8F0(work, 6) == 1) {
            func_021734A8(work, 2, (u32)beaconPc);
            func_021734A8(work, 0, (u32)beaconPc);
        }
    }
}






/*
 * extent: follower 0217B83C already has its own source and shard.
 */
int func_0217B80C(struct GameSystem *gameSystem, void *fieldMap)
{
    UnionRoomWork *work;
    UnionSubEvent *subEvent;
    int result;
    work = (UnionRoomWork *)func_02026474((void *)func_02012138(gameSystem));
    result = 0;
    subEvent = &work->subEvent;
    if (subEvent->id != 0 && subEvent->active == 0) result = func_0217413C(gameSystem, fieldMap, work);
    return result;
}






/*
 * Unlabelled leaf (a .word after a pool in the ov019 listing): returns 0.
 * Callee of ov021 func_0218A0E4, which passes (sys, pos).
 * Addresses are Black-image addresses.
 */
int func_0217B83C(void *gameSystem, void *pos)
{
    return 0;
}







int func_0217B840(UnionRoomWork *work, void *fieldMap)
{
    UnionMySituation *situation = (&work->mySituation);
    int result = 1;
    UnionOneselfActionFunc func;

    switch (situation->phase) {
    case 0:
        func = d_02180074[situation->playCategory].func;
        break;
    case 1:
        func = d_02180078[situation->playCategory].func;
        break;
    case 2:
        func = d_0218007C[situation->playCategory].func;
        break;
    }
    if (func != 0) {
        result = func(work, situation, fieldMap, &situation->step);
    }
    if (result == 1) {
        situation->step = 0;
        situation->phase = situation->phase + 1;
        if (situation->phase > 2) {
            situation->phase = 0;
            situation->prevPlayCategory = situation->playCategory;
            situation->playCategory = situation->nextPlayCategory;
            situation->nextPlayCategory = 0;
        }
    }
    return situation->playCategory;
}






int func_0217B8E4(UnionRoomWork *work, int playCategory)
{
    (&work->mySituation)->nextPlayCategory = playCategory;
    return 1;
}






int func_0217B8F0(UnionRoomWork *work, char playCategory)
{
    if ((&work->mySituation)->phase == 1) return func_0217B8E4(work, playCategory);
    return 0;
}






int func_0217B908(int status)
{
    switch (status) {
    case 0: case 1: case 2: case 3:
        break;
    case 4: case 5:
        return 5;
    case 6: case 7:
        return 0x18;
    case 8: case 9:
        return 6;
    case 10: case 11:
        return 0x19;
    case 12: case 13:
        return 7;
    case 14: case 15:
        return 0x1a;
    case 16: case 17:
        return 8;
    case 18: case 19:
        return 0x1b;
    case 20: case 21:
        return 9;
    case 22: case 23:
        return 0x1c;
    }
    return 5;
}






int func_0217B974(int status)
{
    switch (status) {
    case 0: case 1: case 2: case 3:
    case 5: case 7: case 9: case 11: case 13: case 15:
    case 17: case 19: case 21:
        break;
    case 4: case 6: case 8: case 10: case 12: case 14:
    case 16: case 18: case 20: case 22:
        return 1;
    }
    return 0;
}






int func_0217B9BC(unsigned int status)
{
    if (status < 4 || status > 23) return 0;
    return 1;
}






/*
 * Return from the legacy void tail forwarder 0200BAC8 is used by this caller.
 */
void *func_0217B9CC(UnionRoomWork *work)
{
    void *battleTeam;
    battleTeam = func_0200BAC8(func_02012EBC(work->parent->gameData));
    if (func_0200BBA8(battleTeam) == 0) return 0;
    return func_0200BAF4((int)battleTeam, UNION_HEAP_ID);
}






void func_0217B9F4(void *party)
{
    if (!party) func_02034714(d_021807E4, 0, d_021807E4);
    func_020307B0(party);
}






/*
 * Interface evidence: stub at 0201A364 moves r0 to r2, r1 to r0,
 * sets r1=0x69, then jumps through pool 02048F4C. the integrator owns it.
 */
void func_0217BA10(UnionRoomWork *work, int status)
{
    func_0201A364(func_0217B908(status), work->regulation);
    if (func_0217B974(status) == 1) func_0200AEE8(work->regulation, 13, 1);
    else func_0200AEE8(work->regulation, 13, 0);
}






int func_0217BA48(UnionRoomWork *work, unsigned int *violationMask)
{
    void *party;
    *violationMask = 0;
    party = func_02012934(work->parent->gameData);
    return func_0201A090(work->regulation, party, violationMask);
}






int func_0217BA6C(UnionRoomWork *work, unsigned int *violationMask)
{
    void *party;
    int result;
    party = func_0217B9CC(work);
    *violationMask = 0;
    if (party != 0) {
        result = func_0201A090(work->regulation, party, violationMask);
        func_0217B9F4(party);
    } else {
        *violationMask = -1;
        result = 5;
    }
    return result;
}







int func_0217BAA8(UnionRoomWork *work, int status, unsigned int *myPartyMask, unsigned int *battleTeamMask)
{
    int myPartyResult, battleTeamResult;
    *myPartyMask = 0;
    *battleTeamMask = 0;
    if (func_0217B9BC(status) == 0)
        return 1;
    func_0217BA10(work, status);
    myPartyResult = func_0217BA48(work, myPartyMask);
    battleTeamResult = func_0217BA6C(work, battleTeamMask);
    if (myPartyResult == 0 || battleTeamResult == 0)
        return 1;
    return 0;
}





void func_0217BAF0(UnionRoomWork *work, void *fieldMap, unsigned int busy)
{
    work->fieldBusy = busy;
    func_021A2E44(fieldMap, busy);
}





int func_0217BB04(UnionRoomWork *work)
{
    if (func_0200FB24() != 0) {
        func_0217B8E4(work, 1);
        return 1;
    }
    return 0;
}





int func_0217BB20(UnionRoomWork *work)
{
    if (func_0217BB04(work) == 1) {
        func_0217B8E4(work, 50);
        return 1;
    }
    return 0;
}



int func_0217BB3C(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap)
{
    func_02173524(work, &situation->connect);
    func_021734A8(work, 4, 0);
    func_0217F074(work);
    func_0217BAF0(work, fieldMap, 0);
    work->talkCancel = 0;
    return 1;
}



int func_0217BB70(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap)
{
    void *fieldPlayer;
    void *mmdlSys;
    void *mmdl;
    u16 objId;
    u16 beaconIndex;
    s16 gridX;
    s16 gridY;
    s16 gridZ;

    fieldPlayer = func_02188CB4(fieldMap);
    mmdlSys = func_02188C7C(fieldMap);
    if (func_0217BB04(work) == 1) {
        return 1;
    }
    if (func_02172D68(work) == 1) {
        return 0;
    }
    if (situation->nextPlayCategory != 0) {
        return 1;
    }
    if (func_0203D1B4() > 1) {
        func_02172D20(work);
        return 0;
    }
    if (func_020362DC() & 1) {
        func_021A3460((u32)fieldPlayer, (u32)(&gridX), (u32)(&gridY), (u32)(&gridZ));
        mmdl = func_0216DDC0((u32)mmdlSys, gridX, gridZ, 0);
        if (mmdl == 0) {
            return 0;
        }
        objId = func_0216D588(mmdl);
        if (func_0217AF38(objId) == 0 || func_0217AF4C(work, objId) == 0) {
            return 0;
        }
        situation->connect.requestId = objId;
        beaconIndex = func_0217AEFC(objId);
        func_021734A8(work, 0, (u32)(&work->beaconPc[beaconIndex]));
        if (func_0217AEE8(objId) == 0) {
            if (work->beaconPc[beaconIndex].beacon.status == 0) {
                func_021734A8(work, 1, (u32)(&work->beaconPc[beaconIndex]));
                func_0217B8E4(work, 5);
            } else {
                func_0217B8E4(work, 0xB);
            }
        } else {
            func_0217B8E4(work, 0xC);
        }
        func_0217BAF0(work, fieldMap, 1);
        return 1;
    }
    if (work->talkCancel == 1) {
        func_0217B8E4(work, 4);
        return 1;
    }
    if (func_0217F7E4((u32)fieldMap) == 1) {
        if (work->fieldRequestArmed == 1) {
            func_0217BAF0(work, fieldMap, 1);
            func_0217B8E4(work, 3);
        }
    } else {
        work->fieldRequestArmed = 1;
    }
    return 0;
}



int func_0217BCDC(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step)
{
    switch (*step) {
    case 0:
        func_0217BAF0(work, fieldMap, 1);
        (*step)++;
        break;
    case 1:
        if (func_0217F1EC(work) == 1) {
            func_0217F074(work);
            (*step)++;
        }
        break;
    case 2:
        if (func_0200FB24() != 0) {
            func_02012124(work->parent->gameSystem, 1);
            return 0;
        }
        func_02172D38(work);
        (*step)++;
        break;
    case 3:
        if (func_02172D68(work) == 0)
            (*step)++;
        break;
    case 4:
        func_02173420(work);
        func_02173524(work, &situation->connect);
        func_02172D50(work);
        (*step)++;
        break;
    case 5:
        if (func_02172D68(work) == 0)
            (*step)++;
        break;
    default:
        func_0217B8E4(work, 0);
        return 1;
    }
    return 0;
}


int func_0217BD7C(void)
{
    return 1;
}


int func_0217BD80(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step)
{
    if (*step == 0) {
        work->fieldRequest = 1;
        (*step)++;
    }
    return 0;
}
