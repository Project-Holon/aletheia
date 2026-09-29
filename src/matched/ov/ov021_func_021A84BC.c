/*
 * function: func_021A84BC
 * address:  0x021A84BC
 * packet:   pkt_ov021_021A84BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A926C  0x021A926C  thumb  ov021
 *   func_021A84A8  0x021A84A8  thumb  ov021
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_02040618  0x02040618  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;

typedef struct Obj {
    u8 pad00[0x34];
    Item items[7];
    u8 padF8[0x104 - 0xF8];
    void *f104;
    void *f108;
    void *f10C;
    void *f110;
    void *f114;
    void *f118;
    void *f11C;
    void *f120;
    void *f124;
    void *f128;
    void *f12C;
    void *f130;
} Obj;

extern void func_021A926C(Obj *p, Item *it);
extern void func_021A84A8(Obj *p);
extern void func_02030EAC(void *p);
extern void func_0204B3B4(void *p);
extern void func_0204B084(void *p);
extern void func_0204B1CC(void *p);
extern void func_0204AFD8(void *p);
extern void func_0204A8D4(void *p);
extern void func_0204ADA4(void *p);
extern void func_02040618(int a, int b, int c);
extern void func_020403F4(int a);
extern void func_0201C6EC(void *p);
extern void func_0201C4C0(void *p);
extern void func_020307B0(void *p);

void func_021A84BC(Obj *p)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        func_021A926C(p, &p->items[i]);
    }
    func_021A84A8(p);
    func_02030EAC(p->f130);
    func_0204B3B4(p->f128);
    func_0204B3B4(p->f124);
    func_0204B084(p->f120);
    func_0204B1CC(p->f11C);
    func_0204AFD8(p->f10C);
    func_0204A8D4(p->f108);
    func_0204ADA4(p->f104);
    func_0204AFD8(p->f118);
    func_0204A8D4(p->f114);
    func_0204ADA4(p->f110);
    func_02040618(6, 3, 0);
    func_020403F4(7);
    func_020403F4(5);
    func_020403F4(6);
    func_0201C6EC(p->f12C);
    func_0201C4C0(p->f12C);
    func_020307B0(p);
}
