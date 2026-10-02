/*
 * function: func_021A4224
 * address:  0x021A4224
 * packet:   pkt_ov021_021A4224
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3AC4  0x021A3AC4  thumb  ov021
 *   func_021A536C  0x021A536C  thumb  ov021
 *   func_021A530C  0x021A530C  thumb  ov021
 *   func_021A5360  0x021A5360  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 pad0;
    int mode;
    u32 pad8;
    u32 h;
    u8 pad10[0xC];
    u32 x1c;
} Obj021A4224;

typedef struct {
    u32 pad0;
    u32 v;
} Arg021A4224;

void func_021A3AC4(u32 a, u32 b);
void func_021A536C(Obj021A4224 *p);
void func_021A530C(Obj021A4224 *p, int a);
void func_021A5360(Obj021A4224 *p);

void func_021A4224(Obj021A4224 *p, int mode, const Arg021A4224 *q)
{
    p->mode = mode;
    func_021A3AC4(p->h, q->v);
    func_021A536C(p);
    func_021A530C(p, 0x20);
    if (mode == 2)
        func_021A5360(p);
    p->x1c = 0;
}
