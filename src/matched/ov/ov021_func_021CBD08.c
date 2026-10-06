/*
 * function: func_021CBD08
 * address:  0x021CBD08
 * packet:   pkt_ov021_021CBD08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a party list from the selected slots and runs the ov010 summary on it.
 *
 * symbols:
 *   func_0201A920  0x0201A920  thumb
 *   func_021CA210  0x021CA210  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_021681C8  0x021681C8  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 lo  : 5;
    u16 sel : 3;
    u16 hi  : 8;
} Sel;

typedef signed int     s32;
struct Party;
struct PartyMon;
extern struct Party *func_0201A920(u32 heap);
extern void *func_021CA210(u8 *p);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
struct Bs;
struct Rec;
extern struct Bs *func_021681C8(void *sys, void *partyA, u32 mode0, struct Rec *recA, struct Rec *recB, int n);
extern u32 func_020307B0(void *p);

u32 func_021CBD08(u8 *p, int a)
{
    void *list = func_0201A920(0x8004);
    void *h = func_021CA210(p);
    int i;
    u32 r;

    func_0201A954(list, p[8]);
    for (i = 0; i < p[8]; i++)
        func_0201A98C(list, func_0201AB28(h, p[0x1e + i]));
    r = (u32)func_021681C8((void *)a, list, p[9], (struct Rec *)(p + 0x88), (struct Rec *)(p + 0x2c8 + ((Sel *)p)->sel * 0x120), p[8]);
    func_020307B0(list);
    return r;
}
