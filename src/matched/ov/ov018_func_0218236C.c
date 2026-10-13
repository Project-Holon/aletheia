/*
 * function: EVENT_COMM_COMMON_ChangeTalkItemSaleEvent
 * address: 0x0218236C
 * packet: pkt_ov018_0218236C
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
 *   EVENT_COMM_COMMON_ItemSaleEventMain 0x021823A8 thumb ov018
 *   INTRUDE_COMM_IsValidProfileCode 0x021756D0 thumb ov011
 * Interface: callback payload passed as pointer; owner body stores unchanged word at +4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern void GAME_EVENT_Change(char *p, int a1, int a2);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(void *, void *, int);
typedef unsigned int   u32;
struct Outer;
extern int EVENT_COMM_COMMON_ItemSaleEventMain(void *a, int *state, struct Outer *c);
extern int INTRUDE_COMM_IsValidProfileCode(u32 x);
void EVENT_COMM_COMMON_ChangeTalkItemSaleEvent(void *a, void *b) { u16 *h; GAME_EVENT_Change(a,(int)((void *)EVENT_COMM_COMMON_ItemSaleEventMain),0xa4); a = func_020124E8(a); func_02082D44(b,a,0x98); h = (u16 *)((u8 *)a+0x58); if (INTRUDE_COMM_IsValidProfileCode(*h) == 0) *h = 17; }
