/*
 * function: func_021FA5B0
 * address: 0x021FA5B0
 * packet: pkt_ov132_021FA5B0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware register reads and writes at 021FA5FA..021FA634.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021FA7E0 0x021FA7E0 thumb ov132
 *   d_021FDCD8 0x021FDCD8 data a4
 */
typedef unsigned short u16;
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void func_021FA7E0(void *);
extern const char d_021FDCD8[];
static inline void inside(int wnd, int effect)
{
    unsigned tmp = (*(volatile u16 *)0x04001048 & ~63) | (unsigned)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x04001048 = tmp;
}
static inline void outside(int wnd, int effect)
{
    unsigned tmp = (*(volatile u16 *)0x0400104a & ~63) | (unsigned)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400104a = tmp;
}
char *func_021FA5B0(unsigned heap, void *a, char *b)
{
    char *p = func_02030734(heap, 0x60, 0, d_021FDCD8, 87);
    *(u16 *)p = heap;
    *(void **)(p + 4) = a;
    *(char **)(p + 8) = b;
    *(int *)(p + 0xc) = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 2;
    *(u16 *)(p + 0x48) = *(u16 *)(b + 0x3e);
    *(u16 *)(p + 0x4a) = *(u16 *)(*(char **)(p + 8) + 0x44);
    *(int *)(p + 0x40) = 0;
    *(int *)(p + 0x44) = 0;
    func_021FA7E0(p);
    *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xe000) | 0x2000;
    inside(31, 1);
    outside(31, 0);
    *(volatile u16 *)0x04001040 = 255;
    *(volatile u16 *)0x04001044 = 0x80c0;
    return p;
}
