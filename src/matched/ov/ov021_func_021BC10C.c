/*
 * function: func_021BC10C
 * address:  0x021BC10C
 * packet:   pkt_ov021_021BC10C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_021BC138  0x021BC138  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad[0x10];
    u8 b10;
    char pad2[0xB];
    void *f1C;
    char pad3[0xA];
    u16 h2A;
    char f2C[1];
} Obj;

extern int func_0216E1C4(int a0, int a1);
extern void func_021BC138(u16 id, Obj *p);

void func_021BC10C(int a0, Obj *p)
{
    if (func_0216E1C4((int)p->f1C, (int)p->f2C) == 1 && p->b10 != 0 && p->h2A != 0xFFFF) {
        func_021BC138(p->h2A, p);
    }
}
