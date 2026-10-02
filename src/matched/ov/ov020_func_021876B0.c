/*
 * function: func_021876B0
 * address: 0x021876B0
 * packet: pkt_ov020_021876B0
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 *   d_02187ECC 0x02187ECC data ov020 a4
 */
typedef unsigned short u16;
typedef struct { int index; char *base; } Pair;
extern int d_02187ECC[];
extern void func_02061CA4(int a, void *dst, int data, int size);
void func_021876B0(Pair *p, int tick)
{
    func_02061CA4(1, p->base + (u16)p->index * 8, d_02187ECC[(tick & 31) / 8], 8);
}
