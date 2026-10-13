/*
 * function: INTRUDE_COMM_RecordResultOutcome
 * address:  0x02175E30
 * packet:   pkt_ov011_02175E30
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GAME_DATA_GetPlayerStatus  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   INTRUDE_COMM_NormalizeVersion  0x021584F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8 v : 6;
} Bf6;

typedef struct {
    u32 w0;
    u32 slot : 4;
} Rec;

extern void *GAME_DATA_GetLastBattleRecSlot(void *p);
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
extern struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int INTRUDE_COMM_NormalizeVersion(int a0, int a1);

void INTRUDE_COMM_RecordResultOutcome(void *a, u8 *b, Rec *c)
{
    u8 *d;
    u32 v;
    int r;
    int t;

    d = GAME_DATA_GetLastBattleRecSlot(a);
    t = (int)GAME_DATA_GetPlayerStatus(a, ((u8 *)c)[0x34]);
    v = ((Bf6 *)(b + ((u8 *)c)[0x34] * 0x1c + 0xa7))->v;
    r = INTRUDE_COMM_NormalizeVersion((u8)v, func_02008530((const struct Sub0200852CObj *)t));
    if (r == 0x14) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 1;
    } else if (r == 0x15) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 2;
    }
}
