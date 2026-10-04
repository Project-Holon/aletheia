/*
 * function: func_021C6F4C
 * address:  0x021C6F4C
 * packet:   pkt_ov111_021C6F4C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} ResSet;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0xB8 - 8];
    ResSet res[2];
} Anim;

extern void func_0204ADA4(u32 r);
extern void func_0204A8D4(u32 r);
extern void func_0204AFD8(u32 r);
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);

void func_021C6F4C(Anim *a)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        func_0204ADA4(a->res[i].a);
        func_0204A8D4(a->res[i].b);
        func_0204AFD8(a->res[i].c);
    }
    func_0204B1CC((struct Bank *)a->f4);
    func_0204A5AC();
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x300010) | 0x10;
}
