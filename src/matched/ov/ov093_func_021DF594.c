/*
 * function: func_021DF594
 * address:  0x021DF594
 * packet:   pkt_ov093_021DF594
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021E8A58  0x021E8A58  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Rec {
    int f00;
    int f04;
    u32 f08;
    u8 f0c;
    u8 pad0d[2];
    u8 id;
} Rec;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern u32 func_021E8A58(void);
extern u16 func_021D70A8(void *p);

void func_021DF594(void *self, void *q, int id)
{
    Rec *r;

    if (id != func_021D775C(2))
        return;
    r = (Rec *)func_021C88A4(q, 12, id);
    r->f04 = 5;
    r->f08 = func_021E8A58();
    r->f0c = 0;
    r->id = id;
    func_021C8838((u8 *)r + 0x14, 2, 0xf0);
    func_021C8860((u8 *)r + 0x14, id);
    func_021C8860((u8 *)r + 0x14, func_021D70A8(self));
    func_021C88C8(q, r);
}
