/*
 * function: TRIAL_HOUSE_CreateDeliveryTask
 * address:  0x021D0BE4
 * packet:   pkt_ov021_021D0BE4
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   BATTLE_EXAMINATION_GetBlockSize  0x0200E588  thumb
 *   TRIAL_HOUSE_DeliveryTaskMain  0x021D0C58  thumb  ov021
 *   GAME_LANGUAGE_Code     0x0209DF0C  data  a1
 */
#include "../include/Obj20294.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Work {
    int f00;
    u8 f04;
    u8 pad05;
    u16 f06;
    int f08;
    int f0C;
    int f10;
    int f14;
    u8 pad18[0x78 - 0x18];
    int f78;
    u8 pad7C[0x80 - 0x7C];
    int f80;
    u8 *f84;
    u16 *f88;
    int f8C;
} Work;

struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
typedef unsigned int   u32;
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern u32 BATTLE_EXAMINATION_GetBlockSize(void);
extern void TRIAL_HOUSE_DeliveryTaskMain(void);
extern u8 GAME_LANGUAGE_Code;

void *TRIAL_HOUSE_CreateDeliveryTask(void *a, u8 *b, u16 *c)
{
    void *task;
    Work *w;

    task = func_020122C0(a, 0, TRIAL_HOUSE_DeliveryTaskMain, 0x90);
    w = func_020124E8(task);
    w->f80 = (int)a;
    w->f88 = c;
    w->f84 = b;
    w->f8C = 0;
    w->f00 = 0x2E;
    w->f08 = BATTLE_EXAMINATION_GetBlockSize();
    w->f0C = ((struct Obj20294 *)b)->f14C;
    w->f10 = GAME_LANGUAGE_Code;
    w->f14 = 0x200000;
    w->f78 = 1;
    w->f04 = 0;
    w->f06 = 0x8015;
    return task;
}
