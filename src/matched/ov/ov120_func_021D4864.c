/*
 * function: func_021D4864
 * address: 0x021D4864
 * packet: pkt_ov120_021D4864
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_0203CD98 0x0203CD98 arm
 *   func_020399EC 0x020399EC arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02009EA8 0x02009EA8 thumb
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4808 0x021D4808 thumb ov120
 */
typedef unsigned char u8;
extern int func_021D7AF4(int);
extern int func_0203CD98(void);
extern int func_020399EC(void);
extern int func_020399A8(void);
extern void func_02039C68(int, int, int);
extern int func_0200E6E8(int);
extern void func_0200E6FC(int, int, void *);
extern int func_02012F14(int);
extern int func_02009EA8(int);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D4808(int);
void func_021D4864(u8 *p)
{
    u8 *q;
    int value;
    if (func_021D7AF4(*(int *)(p + 0x40))) {
        if (func_0203CD98() == 0) {
            func_021D4244((int)p, func_021D4808, 0x2fe);
            return;
        }
        if (*(int *)(p + 0x14) > 0) {
            *(int *)(p + 0x14) = *(int *)(p + 0x14) - 1;
            return;
        }
        if (func_020399EC() == 2) {
            q = *(u8 **)(p + 0x48);
            value = func_0200E6E8(*(int *)(p + 0x30));
            *(int *)(q + 4) = *(int *)(p + 0x144);
            *(int *)(q + 8) = *(int *)(p + 0x13c);
            func_0200E6FC(value, 0, p + 0x168);
            *(int *)(p + 0x170) = func_02009EA8(func_02012F14(*(int *)(p + 0x2c)));
            func_02039C68(func_020399A8(), 2, 0x22);
            func_021D4244((int)p, func_021D4808, 0x314);
        }
    }
}
