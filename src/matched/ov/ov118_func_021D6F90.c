/*
 * function: func_021D6F90
 * address:  0x021D6F90
 * packet:   pkt_ov118_021D6F90
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DC720  0x021DC720  thumb
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021E3E40  0x021E3E40  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   func_021E5284  0x021E5284  thumb
 *   func_021D8AA8  0x021D8AA8  thumb ov119
 *   func_021D8FA4  0x021D8FA4  thumb
 *   func_021E35A0  0x021E35A0  thumb ov119
 *   func_021E36C8  0x021E36C8  thumb  ov119
 *   func_02015C94  0x02015C94  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_021E2F34  0x021E2F34  thumb
 *   func_021E2FB0  0x021E2FB0  thumb ov119
 *   func_021E2D70  0x021E2D70  thumb
 *   func_021D6738  0x021D6738  thumb
 *   func_021D8E84  0x021D8E84  thumb
 *   func_021D7100  0x021D7100  thumb
 *   d_021D866C  0x021D866C  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_021DC720(void *p);
extern void func_0204A5AC(void);
extern void func_021E3E40(void *p);
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021E5284(void *p, int a);
extern int func_021D8AA8(void *p);
extern void *func_021D8FA4(void *, int);
extern void func_021E35A0(void *p, int a, int b, void *mon, int c);
extern void func_021E36C8(void *p, int a, int b, void *mon, int c);
extern void func_02015C94(void *p, u32 *out);
extern void func_02015EA0(void *p);
extern void func_021E2F34(void *w);
extern void func_021E2FB0(void *w);
extern void func_021E2D70(void *w, int a);
extern void func_021D6738(u8 *p, u32 v);
extern void func_021D8E84(void *p, int next);
extern void func_021D7100(u8 *p);
extern const char d_021D866C[];

#define HEAP (*(u16 *)(p + 0x5F4))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define WORK (*(u8 **)(p + 0xc))

void func_021D6F90(u8 *p)
{
    func_021DC720(p);
    func_0204A5AC();
    func_021E3E40(p);
    *(int *)(p + 0x9C4) = (int)func_0204B100(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D866C, 0x9D);
    *(u16 *)(WORK + 0xBA) = HEAP;
    func_021E5284(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    if (func_021D8AA8(p)) {
        func_021E35A0(p, 1, 0, func_021D8FA4(p, 1), 0);
        func_021E35A0(p, 2, 0, func_021D8FA4(p, 0), 0);
        func_021E35A0(p, 3, 1, func_021D8FA4(p, 1), 0);
    } else {
        func_021E36C8(p, 1, 0, func_021D8FA4(p, 1), 0);
        func_021E36C8(p, 2, 0, func_021D8FA4(p, 0), 0);
        func_021E36C8(p, 3, 1, func_021D8FA4(p, 1), 0);
    }
    func_02015C94((void *)OBJ(0), (u32 *)(WORK + 0x60));
    func_02015C94((void *)OBJ(1), (u32 *)(WORK + 0x6C));
    func_02015C94((void *)OBJ(2), (u32 *)(WORK + 0x78));
    func_02015C94((void *)OBJ(3), (u32 *)(WORK + 0x84));
    func_02015EA0((void *)OBJ(1));
    func_02015EA0((void *)OBJ(2));
    func_02015EA0((void *)OBJ(3));
    func_021E2F34(WORK);
    func_021E2FB0(WORK);
    func_021E2D70(WORK, 0);
    func_021D6738(p, 0);
    func_021D8E84(p, (int)func_021D7100);
}
