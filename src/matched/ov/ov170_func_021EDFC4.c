/*
 * function: func_021EDFC4
 * address: 0x021EDFC4
 * packet: pkt_ov170_021EDFC4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021EFCD8 0x021EFCD8 data a2
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_0202590C 0x0202590C thumb
 *   func_02025774 0x02025774 thumb
 */
extern const short d_021EFCD8[];
extern void func_021EC08C(char *, int, short, short, short);
extern void func_021EC000(char *, int, int);
typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Grid;
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern void func_02025774(u8 *g, u32 a);
void func_021EDFC4(char *p, int i)
{
    short y = d_021EFCD8[i];
    func_021EC08C(*(char **)(p + 0x2c), 3, 0xce, y, 0);
    func_021EC000(*(char **)(p + 0x2c), 3, 1);
    func_0202590C(*(void **)(*(char **)(p + 0x2c) + 4), 0x9e, y - 8);
    func_02025774(*(void **)(*(char **)(p + 0x2c) + 4), 1);
}
