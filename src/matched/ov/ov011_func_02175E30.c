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
 *   func_020127B8  0x020127B8  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
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

extern void *func_020127B8(void *p);
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_021584F4(int a0, int a1);

void INTRUDE_COMM_RecordResultOutcome(void *a, u8 *b, Rec *c)
{
    u8 *d;
    u32 v;
    int r;
    int t;

    d = func_020127B8(a);
    t = (int)func_02012950(a, ((u8 *)c)[0x34]);
    v = ((Bf6 *)(b + ((u8 *)c)[0x34] * 0x1c + 0xa7))->v;
    r = func_021584F4((u8)v, func_02008530((const struct Sub0200852CObj *)t));
    if (r == 0x14) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 1;
    } else if (r == 0x15) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 2;
    }
}
