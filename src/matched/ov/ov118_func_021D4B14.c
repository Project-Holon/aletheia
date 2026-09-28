/*
 * function: func_021D4B14
 * address:  0x021D4B14
 * packet:   pkt_ov118_021D4B14
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
 *   func_021E3208  0x021E3208  thumb
 *   func_021D8FA4  0x021D8FA4  thumb
 *   func_021E36C8  0x021E36C8  thumb  ov119
 *   func_02015EA0  0x02015EA0  thumb
 *   func_021E2F34  0x021E2F34  thumb
 *   func_021E2FB0  0x021E2FB0  thumb ov119
 *   func_021E2D70  0x021E2D70  thumb
 *   func_021D4484  0x021D4484  thumb
 *   func_021D8E84  0x021D8E84  thumb
 *   func_021D4C08  0x021D4C08  thumb
 *   d_021D7FD4  0x021D7FD4  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_021DC720(void *p);
extern void func_0204A5AC(void);
extern void func_021E3E40(void *p);
extern int func_0204B100(int, int, int);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_021E5284(void *p, int a);
extern void func_021E3208(void *p, int a);
extern u32 func_021D8FA4(void *, int);
extern void func_021E36C8(void *p, int a, int b, u32 mon, int c);
extern void func_02015EA0(u32);
extern void func_021E2F34(void *w);
extern void func_021E2FB0(void *w);
extern void func_021E2D70(void *w, int a);
extern void func_021D4484(void *p, int a);
extern void func_021D8E84(void *p, int next);
extern void func_021D4C08(u8 *p);
extern const char d_021D7FD4[];

#define HEAP (*(u16 *)(p + 0x5F4))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define WORK (*(u8 **)(p + 0xc))

void func_021D4B14(u8 *p)
{
    func_021DC720(p);
    func_0204A5AC();
    func_021E3E40(p);
    *(int *)(p + 0x9C4) = func_0204B100(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D7FD4, 0x98);
    *(u16 *)(WORK + 0xBA) = HEAP;
    func_021E5284(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    func_021E3208(p, 3);
    func_021E36C8(p, 1, 0, func_021D8FA4(p, 1), 1);
    func_021E36C8(p, 2, 0, func_021D8FA4(p, 0), 1);
    func_021E36C8(p, 3, 1, func_021D8FA4(p, 1), 1);
    func_02015EA0(OBJ(1));
    func_02015EA0(OBJ(2));
    func_02015EA0(OBJ(3));
    func_021E2F34(WORK);
    func_021E2FB0(WORK);
    func_021E2D70(WORK, 1);
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D4C08);
}
