/*
 * function: func_021D4930
 * address: 0x021D4930
 * packet: pkt_ov120_021D4930
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_02039338 0x02039338 arm
 *   func_02039ACC 0x02039ACC arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4864 0x021D4864 thumb ov120
 *   func_021D48F0 0x021D48F0 thumb ov120
 */
typedef unsigned char u8;
extern int func_021D7AF4(int);
typedef unsigned short u16;
extern u16 func_02039338(void);
extern int func_02039ACC(void);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D4864(int);
extern void func_021D48F0(int);
void func_021D4930(u8 *a)
{
    if (func_021D7AF4(*(int *)(a + 0x40)) != 0) {
        if (*(int *)(a + 0x14) > 0) {
            *(int *)(a + 0x14) = *(int *)(a + 0x14) - 1;
            return;
        }
        if (func_02039338() != 0) {
            if (func_02039ACC() != 0) {
                *(int *)(a + 0x14) = 0xb4;
                func_021D4244((int)a, func_021D4864, 0x33f);
                return;
            }
        } else {
            *(int *)(a + 0x14) = 0xb4;
            func_021D4244((int)a, func_021D48F0, 0x344);
        }
    }
}
