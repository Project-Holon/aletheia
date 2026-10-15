/*
 * function: TRIAL_HOUSE_DeliveryTaskMain
 * address:  0x021D0C58
 * packet:   pkt_ov021_021D0C58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   DELIVERY_BEACON_Create  0x021576D0  thumb  ov010
 *   DELIVERY_BEACON_Start  0x021578A0  thumb  ov010
 *   KEY_GetTrg  0x020362DC  arm
 *   DELIVERY_BEACON_RunStep  0x02157928  thumb  ov010
 *   DELIVERY_BEACON_HasAnyPiece  0x021578F0  thumb  ov010
 *   DELIVERY_BEACON_TryComplete  0x02157910  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 *   BATTLE_EXAMINATION_GetDeliveryId  0x0200E5E4  thumb
 *   BATTLE_EXAMINATION_IsDeliveryValid  0x0200E5A0  thumb
 *   TRIAL_HOUSE_IsDeliveryIdReceived  0x021D1058  thumb  ov021
 *   TRIAL_HOUSE_MarkDeliveryIdReceived  0x021D1080  thumb  ov021
 *   BATTLE_EXAMINATION_LoadDelivery  0x0200E608  thumb
 *   DELIVERY_BEACON_Delete  0x02157938  thumb  ov010
 *   GFL_NET_IsIdle  0x0203D210  arm
 *   TRIAL_HOUSE_LoadDeliveryState  0x021D09D0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20300.h"
#include "../include/Obj20301.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x7c];
    u32 f7c;
    u32 f80;
    u8 *f84;
    u16 *f88;
    int f8c;
} W;

struct Flags;
extern void *DELIVERY_BEACON_Create(u8 *p);
struct Big;
struct Ctx;
struct Flags;
extern int DELIVERY_BEACON_Start(u32 *p);
extern u32 KEY_GetTrg(void);
extern void DELIVERY_BEACON_RunStep(u8 *p);
extern int DELIVERY_BEACON_HasAnyPiece(void *p);
extern int DELIVERY_BEACON_TryComplete(u8 *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200E8F8(void *sys);
extern u16 BATTLE_EXAMINATION_GetDeliveryId(void *p);
extern int BATTLE_EXAMINATION_IsDeliveryValid(void *a0);
extern u8 TRIAL_HOUSE_IsDeliveryIdReceived(struct Flags *p, u32 n);
extern void TRIAL_HOUSE_MarkDeliveryIdReceived(struct Flags *p, u32 n);
extern void BATTLE_EXAMINATION_LoadDelivery(void *sys, void *dst, u32 heap);
extern int DELIVERY_BEACON_Delete(void *a0);
extern u32 GFL_NET_IsIdle(void);
extern void TRIAL_HOUSE_LoadDeliveryState(int a, char *out);

int TRIAL_HOUSE_DeliveryTaskMain(u32 unused, u32 *state, W *w)
{
    u32 x;
    u32 h, sv;
    u8 *rec;
    int n, ok, r;

    x = w->f80;
    switch (*state) {
    case 0:
        w->f7c = (u32)DELIVERY_BEACON_Create((u8 *)w);
        if (DELIVERY_BEACON_Start((u32 *)w->f7c) == 0) {
            *w->f88 = 0;
            *state = 4;
        } else {
            *state = 1;
        }
        break;
    case 1:
        if (KEY_GetTrg() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        DELIVERY_BEACON_RunStep((u8 *)w->f7c);
        if (++w->f8c > 120) {
            *state = 2;
        }
        break;
    case 2:
        if (KEY_GetTrg() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        DELIVERY_BEACON_RunStep((u8 *)w->f7c);
        if (DELIVERY_BEACON_HasAnyPiece((void *)w->f7c)) {
            *state = 3;
        } else {
            *w->f88 = 0;
            *state = 4;
        }
        break;
    case 3:
        if (KEY_GetTrg() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        DELIVERY_BEACON_RunStep((u8 *)w->f7c);
        if (DELIVERY_BEACON_TryComplete((u8 *)w->f7c) == 0) {
            break;
        }
        h = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)x);
        rec = func_0200E8F8(GAME_DATA_GetSaveControl((struct Big *)h));
        sv = ((struct Obj20300 *)(w->f84))->f14C;
        n = BATTLE_EXAMINATION_GetDeliveryId((void *)sv);
        ok = BATTLE_EXAMINATION_IsDeliveryValid((void *)sv);
        r = TRIAL_HOUSE_IsDeliveryIdReceived((struct Flags *)rec, n);
        if (ok != 0 && (r == 0 || n == 0)) {
            TRIAL_HOUSE_MarkDeliveryIdReceived((struct Flags *)rec, n);
            BATTLE_EXAMINATION_LoadDelivery((void *)h, (void *)(((struct Obj20301 *)(w->f84))->f14C), 0x8004);
            *w->f88 = 1;
        } else if (r != 0) {
            *w->f88 = 2;
        } else {
            *w->f88 = 0;
        }
        *state = 4;
        break;
    case 4:
        DELIVERY_BEACON_Delete((void *)w->f7c);
        *state = 5;
        break;
    case 5:
        if (GFL_NET_IsIdle()) {
            *state = 6;
        }
        break;
    case 6:
        TRIAL_HOUSE_LoadDeliveryState(x, (char *)w->f84);
        return 1;
    }
    return 0;
}
