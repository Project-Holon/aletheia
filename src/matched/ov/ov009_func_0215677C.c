/*
 * function: func_0215677C
 * address: 0x0215677C
 * packet: pkt_ov009_0215677C
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021A8264 0x021A8264 data ov009 a4
 *   func_02059F18 0x02059F18 arm
 *   func_0216AD50 0x0216AD50 arm ov009
 *   func_0205CC20 0x0205CC20 arm
 *   func_02156400 0x02156400 thumb ov009
 *   func_021554A0 0x021554A0 thumb ov009
 */
typedef unsigned char u8;
extern u8 *g_021A8264;
extern void func_02059F18(void);
extern void func_0216AD50(void);
extern void func_0205CC20(void);
extern void func_02156400(void);
extern void func_021554A0(void);
void func_0215677C(void)
{
    if (g_021A8264 != 0) {
        func_02059F18();
        if (g_021A8264[0x7a9] != 0)
            func_0216AD50();
        g_021A8264[0x7a9] = 0;
        func_0205CC20();
        func_02156400();
        func_021554A0();
    }
}
