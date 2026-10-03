/*
 * function: func_021DF640
 * address:  0x021DF640
 * packet:   pkt_ov093_021DF640
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Word { u32 v; } Word;

typedef struct Rec {
    int f00;
    int f04;
    Word f08;
    u8 f0c;
    u8 pad0d[2];
    u8 id;
    u8 pad10[4];
    u8 f14[8];
    u32 f1c;
} Rec;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern Word func_021D7D18(int x);
extern u16 func_021D70A8(void *p);

void func_021DF640(void *self, void *q, int id)
{
    Rec *r;

    if (id != func_021D775C(2))
        return;
    r = (Rec *)func_021C88A4(q, 12, id);
    r->f04 = 4;
    r->f08 = func_021D7D18(4);
    r->f0c = 0;
    r->id = id;
    r->f1c = func_021D70A8(self);
    func_021C8838(r->f14, 2, 0x102);
    func_021C8860(r->f14, id);
    func_021C8860(r->f14, func_021D70A8(self));
    func_021C88C8(q, r);
}
