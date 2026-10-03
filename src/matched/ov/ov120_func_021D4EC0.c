/*
 * function: func_021D4EC0
 * address: 0x021D4EC0
 * packet: pkt_ov120_021D4EC0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B64D0 0x021B64D0 thumb ov067
 *   func_021D7D3C 0x021D7D3C thumb ov120
 *   func_021D6814 0x021D6814 thumb ov120
 *   func_021D444C 0x021D444C thumb ov120
 *   func_021D7DC8 0x021D7DC8 thumb ov120
 *   func_021D4C98 0x021D4C98 thumb ov120
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D7ECC 0x021D7ECC thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4D28 0x021D4D28 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_021D6988(void *);
extern void func_021B64D0(u8 *, u32);
typedef unsigned short u16;
struct Obj;
extern void func_021D7D3C(char *p);
extern void func_021D6814(u8 *p);
extern void func_021D444C(int);
extern void func_021D4C98(int, int, int);
extern void func_021D7DC8(void *, void (*)(int,int,int), void *, int, int, int);
extern void func_021D79F4(u8 *p, u16 n);
extern void *func_021D7ECC(char *p, u16 n);
extern u8 func_020355C4(void);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_02041B6C(u32 bit);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D4D28(int);
void func_021D4EC0(u8 *p)
{
    *(int *)(p + 0x138) = 0;
    func_021B64D0(func_021D6988(*(void **)(p + 0x3c)), 1);
    func_021D7D3C(*(void **)(p + 0x40));
    func_021D6814(*(void **)(p + 0x3c));
    *(void (**)(int))(p + 4) = func_021D444C;
    func_021D7DC8(*(void **)(p + 0x40), func_021D4C98, p, *(int *)(p + 0x144), *(int *)(p + 0x13c), *(int *)(p + 0x140));
    func_021D79F4(*(void **)(p + 0x40), 20);
    *(void **)(p + 0x34) = func_021D7ECC(*(void **)(p + 0x40), 18);
    if (func_020355C4() == 0) {
        func_021D69F4(*(void **)(p + 0x3c), 0, *(int *)(p + 0x160));
        if (*(int *)(p + 0x160) == 5)
            func_02028218(*(void **)(p + 0x34), 1);
    } else {
        func_021D69F4(*(void **)(p + 0x3c), 0, 9);
    }
    func_02041B6C(6);
    func_021D4244((int)p, func_021D4D28, 0x537);
}
