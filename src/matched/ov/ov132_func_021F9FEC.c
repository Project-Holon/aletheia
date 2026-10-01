/*
 * function: func_021F9FEC
 * address: 0x021F9FEC
 * packet: pkt_ov132_021F9FEC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021FA0D0 0x021FA0D0 thumb ov132
 *   func_021FA0D8 0x021FA0D8 thumb ov132
 *   d_021FDCC4 0x021FDCC4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void func_021FA0D0(char *);
extern void func_021FA0D8(char *, unsigned);
extern const char d_021FDCC4[];
char *func_021F9FEC(unsigned heap, void *a, unsigned b)
{
    u8 i = 0;
    char *p = func_02030734(heap, 0x3e4, 0, d_021FDCC4, 115);
    *(u16 *)p = heap;
    func_021FA0D0(p);
    func_021FA0D8(p, b);
    *(void **)(p + 0x1e8) = a;
    *(int *)(p + 0x200) = 0;
    for (; i < 4; i++) *(int *)(p + i * 4 + 0x1ec) = 0;
    *(u8 *)(p + 0x1fc) = 255;
    return p;
}
