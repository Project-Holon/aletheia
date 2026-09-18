/*
 * function: func_0203CF5C
 * address:  0x0203CF5C
 * packet:   pkt_0203CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * PARKED AT MATCH.  Every concrete byte is right.  Four sites are open,
 * 0x0203EA9C, 0x0203DC70, 0x02039D94 and 0x02037C10, and this function is
 * the only caller of each in the whole image, so no cut of the range can
 * give any of them a witness.  All four are outside this packet (0x02037C10
 * is outside the window entirely), so none can be matched from here.
 *   blocker: single-caller callees 0x0203EA9C, 0x0203DC70, 0x02039D94,
 *            0x02037C10 - each needs to be matched, or to gain a caller
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CF5C.c \
 *       --func func_0203CF5C --addr 0x0203CF5C --cc 1.1p1 --arm
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *func_0203D788(void);
extern void func_0203EA9C(void);
extern void func_0203DC70(void);
extern u32 func_0203B1D8(void);
extern void func_02037154(void);
extern void func_02039D94(void);
extern void func_02037C10(void);
extern void func_02039594(void);

int func_0203CF5C(void)
{
    u8 *s = func_0203D788();

    func_0203EA9C();
    func_0203DC70();

    if (func_0203B1D8() != 0)
        return 1;
    if (s == 0)
        return 1;

    func_02037154();
    func_02039D94();
    func_02037C10();
    func_02039594();
}
