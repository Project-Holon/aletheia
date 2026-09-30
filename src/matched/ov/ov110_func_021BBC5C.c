/*
 * function: func_021BBC5C
 * address: 0x021BBC5C
 * packet: pkt_ov110_021BBC5C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C3C58 0x021C3C58 data a1
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02020D18 0x02020D18 thumb
 *   func_0202C9B4 0x0202C9B4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern const char d_021C3C58[];
extern u8 *func_021BF6D4(u8 *);
extern void *func_020457B0(unsigned, unsigned);
extern void *func_02045B38(unsigned, unsigned, unsigned, unsigned);
extern void *func_02020D18(unsigned);
extern void *func_0202C9B4(unsigned, unsigned, unsigned);
u8 *func_021BBC5C(void *a, u8 *b, void *c)
{
    u8 *p;
    p = func_02030734(42, 444, 1, d_021C3C58, 211);
    *(void **)(p + 0) = a;
    *(u8 **)(p + 4) = b;
    *(void **)(p + 8) = c;
    *(u8 **)(p + 0x1a0) = func_021BF6D4(b);
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1a4) = 0;
    *(void **)(p + 0x30) = func_020457B0(128, 42);
    *(void **)(p + 0x2c) = func_02045B38(0, 2, 146, 42);
    *(void **)(p + 0x34) = func_02020D18(42);
    *(u16 *)(p + 0x198) = 0;
    *(u16 *)(p + 0x19a) = 0;
    *(int *)(p + 0x1a8) = 0;
    *(int *)(p + 0x1ac) = 0;
    *(int *)(p + 0x1b0) = 0;
    *(void **)(p + 0x1b4) = func_0202C9B4(1, 1, 42);
    return p;
}
