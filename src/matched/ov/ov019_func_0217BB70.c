/*
 * function: UNION_ONESELF_IdleMain
 * address:  0x0217BB70
 * packet:   pkt_ov019_0217BB70
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   UNION_COMM_RequestRestart  0x02172D20  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   UNION_COMM_SetSituationParam  0x021734A8  thumb  ov012
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   UNION_CHARA_IsChildObjId  0x0217AEE8  thumb  ov019
 *   UNION_CHARA_GetBeaconIndex  0x0217AEFC  thumb  ov019
 *   UNION_CHARA_IsUnionObjId  0x0217AF38  thumb  ov019
 *   UNION_CHARA_CheckTalkable  0x0217AF4C  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_ONESELF_SetFieldBusy  0x0217BAF0  thumb  ov019
 *   UNION_ONESELF_HandleNetError  0x0217BB04  thumb  ov019
 *   UNION_ONESELF_IsPlayerAtReceptionSpot  0x0217F7E4  thumb  ov019
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07382.h"
#include "../include/Obj12522.h"

typedef unsigned char  u8;
typedef short          s16;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Entry {
    u8 pad0[0xB];
    u8 bB;
    u8 padC[0x8C - 0xC];
} Entry;

typedef struct Work {
    u8    pad0[0x2910];
    Entry entries[10];
} Work;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern void  UNION_COMM_RequestRestart(u8 *w);
extern int   UNION_COMM_IsResetting(u8 *w);
extern void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);
extern u16   FLDMMDL_GetObjId(void *p);
extern void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);
extern int   GFL_NET_GetNegotiationNum(void);
extern u32   KEY_GetTrg(void);
extern int   UNION_CHARA_IsChildObjId(u16 t);
extern u16   UNION_CHARA_GetBeaconIndex(u32 t);
extern int   UNION_CHARA_IsUnionObjId(u16 t);
extern int UNION_CHARA_CheckTalkable(char *a, u16 key);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
extern int UNION_ONESELF_HandleNetError(char *p);
extern int UNION_ONESELF_IsPlayerAtReceptionSpot(u32 arg);

int UNION_ONESELF_IdleMain(u8 *w, u8 *obj, void *q)
{
    void *a;
    void *b;
    void *r;
    u16 t;
    u16 n;
    s16 x;
    s16 y;
    s16 z;

    a = FIELDMAP_GetFieldPlayer(q);
    b = FIELDMAP_GetMmdlSys(q);
    if (UNION_ONESELF_HandleNetError((char *)w) == 1) {
        return 1;
    }
    if (UNION_COMM_IsResetting(w) == 1) {
        return 0;
    }
    if (obj[0x71] != 0) {
        return 1;
    }
    if (GFL_NET_GetNegotiationNum() > 1) {
        UNION_COMM_RequestRestart(w);
        return 0;
    }
    if (KEY_GetTrg() & 1) {
        FIELD_PLAYER_GetFrontGridPos((u32)a, (u32)(&x), (u32)(&y), (u32)(&z));
        r = FLDMMDL_SysSearchGridPos((u32)b, x, z, 0);
        if (r == 0) {
            return 0;
        }
        t = FLDMMDL_GetObjId(r);
        if (UNION_CHARA_IsUnionObjId(t) == 0 || UNION_CHARA_CheckTalkable((char *)w, t) == 0) {
            return 0;
        }
        ((struct Obj12522 *)obj)->f58 = t;
        n = UNION_CHARA_GetBeaconIndex(t);
        UNION_COMM_SetSituationParam(w, 0, (u32)(&((Work *)w)->entries[n]));
        if (UNION_CHARA_IsChildObjId(t) == 0) {
            if (((Work *)w)->entries[n].bB == 0) {
                UNION_COMM_SetSituationParam(w, 1, (u32)(&((Work *)w)->entries[n]));
                UNION_ONESELF_SetNextPlayCategory((char *)w, 5);
            } else {
                UNION_ONESELF_SetNextPlayCategory((char *)w, 0xB);
            }
        } else {
            UNION_ONESELF_SetNextPlayCategory((char *)w, 0xC);
        }
        UNION_ONESELF_SetFieldBusy((char *)w, (int)q, 1);
        return 1;
    }
    if (w[0x282E] == 1) {
        UNION_ONESELF_SetNextPlayCategory((char *)w, 4);
        return 1;
    }
    if (UNION_ONESELF_IsPlayerAtReceptionSpot((u32)q) == 1) {
        if (((struct Obj07382 *)w)->f3564 == 1) {
            UNION_ONESELF_SetFieldBusy((char *)w, (int)q, 1);
            UNION_ONESELF_SetNextPlayCategory((char *)w, 3);
        }
    } else {
        ((struct Obj07382 *)w)->f3564 = 1;
    }
    return 0;
}
