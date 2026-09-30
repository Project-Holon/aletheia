/*
 * function: func_021D4584
 * address: 0x021D4584
 * packet: pkt_ov120_021D4584
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_021D880C 0x021D880C thumb ov120
 *   func_021D74B0 0x021D74B0 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4544 0x021D4544 thumb ov120
 */
typedef unsigned char u8;
extern int func_0203CD98(void);
extern int func_02012944(int);
extern int func_02008530(int);
extern int func_02008554(int);
extern void func_021D880C(int, int, int);
extern void func_021D74B0(int, int);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D4544(int);
void func_021D4584(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x48);
    int value;
    int mode = 2;
    if (func_0203CD98() == 0) {
        value = func_02012944(*(int *)q);
    } else {
        value = *(int *)(q + 0x18);
        mode = *(int *)(p + 0x17c);
        *(int *)(q + *(int *)(q + 0x1ac) * 4 + 0x1c) = func_02008530(value);
        *(int *)(q + 0x1ac) = *(int *)(q + 0x1ac) + 1;
        if (*(int *)(q + 0x1ac) >= 100)
            *(int *)(q + 0x1ac) = 0;
    }
    func_021D880C(*(int *)(p + 0x40), value, mode);
    func_021D74B0(*(int *)(p + 0x3c), func_02008554(value));
    *(int *)(p + 0x14) = 0xb4;
    func_021D4244((int)p, func_021D4544, 0x265);
}
