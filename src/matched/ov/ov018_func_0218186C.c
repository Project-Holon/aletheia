/*
 * function: EVENT_COMM_COMMON_ChangeTalkedBattleAsTargetEvent
 * address:  0x0218186C
 * packet:   pkt_ov018_0218186C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAME_EVENT_Change  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   EVENT_COMM_COMMON_BattleRequestEventMain  0x0218123C  thumb  ov018
 */
#include "../include/Obj04963.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x40];
    u8 f40;
    u8 pad41[0x17];
    u16 f58;
} Ov018Src;

struct Obj;
void *func_020124E4(struct Obj *p);
void GAME_EVENT_Change(char *p, int a1, int a2);
void *func_020124E8(struct Obj *p);
void func_02082D44(void *, void *, int);
void EVENT_COMM_COMMON_BattleRequestEventMain(void);

void EVENT_COMM_COMMON_ChangeTalkedBattleAsTargetEvent(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    GAME_EVENT_Change(a, (int)EVENT_COMM_COMMON_BattleRequestEventMain, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj04963 *)t)->fA4 = 1;
    ((struct Obj04963 *)t)->f9C = r;
    t[0xA0] = t[0x40];
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}
