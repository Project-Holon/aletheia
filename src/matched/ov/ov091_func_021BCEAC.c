/*
 * function: func_021BCEAC
 * address: 0x021BCEAC
 * packet: pkt_ov091_021BCEAC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027694 0x02027694 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_02027698 0x02027698 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02082A60 0x02082A60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern u32 func_02027694(void);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern u32 func_02027698(void);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02082A60(void *, void *, unsigned long);
#define H (*(u16 *)p)
#define W(o) (*(u32 *)(p + (o)))
#define F(o) (*(int *)(W(0x280) + (o)))
void func_021BCEAC(u8 *p)
{
    void *h, *h2;
    h = func_020490F4(0x4c, H);
    func_02049BDC((void *)((u32)h), 1, 4, 0x20, 0x20, 0x20, H);
    func_02049B68(h, 0, 4, 0x1a0, 0x20, H);
    func_02049658((void *)((u32)h), 9, 6, 0, 0, 0, H);
    if (F(0x8c) == 1) {
        switch (F(0x64)) {
        case 1: func_020498F4((void *)((u32)h), 0x11, 6, 0, 0, 0, H); break;
        case 2: func_020498F4((void *)((u32)h), 0x10, 6, 0, 0, 0, H); break;
        }
    }
    func_02049238(h);
    h2 = func_020490F4(func_020275E4(), H);
    W(0x184) = func_0204ABF0((void *)h, func_02027694(), 1, 0x60, H);
    W(0x1a8) = func_0204A6C8((void *)((u32)h), func_02027698(), 0, 1, H);
    W(0x1c4) = func_0204AF28((void *)((u32)h), func_0202769C(2), func_020276A0(2), H);
    if (F(0x90) == 1) {
        func_02049B68(h, func_02027624(), 4, 0x40, 0x20, H);
        func_02049658((void *)((u32)h), func_02027628(), 5, 0, 0, 0, H);
        func_020498F4((void *)((u32)h), func_0202762C(), 5, 0, 0, 0, H);
        func_020413B0(5, 0, 0, 0x20, 0x20, 2);
        func_02041B6C(5);
    }
    func_02049238(h2);
    h = func_020490F4(7, H);
    W(0x194) = func_0204ACEC((void *)((u32)h), func_0201BC3C(), 1, 0xc0, H);
    func_02049238(h);
    func_02082A60((void *)0x05000440, p + 0x20e, 0x20);
}
