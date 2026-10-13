/*
 * function: EVENT_COMM_COMMON_ChangeTalkedGreetingTargetEvent
 * address: 0x02182080
 * packet: pkt_ov018_02182080
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_EVENT_Change 0x0201232C thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   EVENT_COMM_COMMON_TalkedGreetingTargetEventMain 0x021820A4 thumb ov018
 * Interface: callback payload passed as pointer; owner body stores unchanged word at +4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern void GAME_EVENT_Change(char *p, int a1, int a2);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(void *, void *, int);
extern void EVENT_COMM_COMMON_TalkedGreetingTargetEventMain(void);
void EVENT_COMM_COMMON_ChangeTalkedGreetingTargetEvent(void *a, void *b) { GAME_EVENT_Change(a,(int)((void *)EVENT_COMM_COMMON_TalkedGreetingTargetEventMain),0x9c); func_02082D44(b,func_020124E8(a),0x98); }
