/*
 * function: func_0220093C
 * address: 0x0220093C
 * packet: pkt_ov135_0220093C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: struct window array avoids hoisting its base; initialize i before q.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02200A7C 0x02200A7C thumb ov135
 *   d_022038FC 0x022038FC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_022038FC[][3];
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32, u32);
extern void func_02200A7C(u32, u32, u32, u32, u32, void *, u16);
typedef struct {
    u8 pad0[0x32];
    u16 index;
    u8 pad34[0xb6c - 0x34];
    u32 bank;
    u8 padb70[0xd50 - 0xb70];
    u32 win[3];
    u8 padd5c[0xfa0 - 0xd5c];
    u8 queue[1];
} Work;
void func_0220093C(Work *p)
{
    void *q;
    const u32 *t;
    int i;
    t = d_022038FC[p->index];
    i = 0;
    q = p->queue;
    for (; i < 3; i++) {
        func_02043B5C((u32)func_02045770((struct Descriptor *)p->win[i]), 1);
        func_02200A7C(p->win[i], p->bank, 0, t[i], 0, q, 0x3dc1);
    }
}
