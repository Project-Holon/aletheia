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
 * blocker:  func_0203EA9C, func_0203DC70, func_02039D94, func_02037C10 (label,
 *           all four) -- each has no witness outside 0203CF5C..0203CFA0; every
 *           branch to them in the image is this function's own call. Four of
 *           the eight sites resolve. Every concrete byte of the body
 *           reproduces. Note the chain is two levels deep: func_0203B1D8,
 *           also called here, is itself a documented DIFF
 *           (docs/notes/pkt_0203B1D8.c.txt) and func_02037154 is a pending
 *           MATCH park.
 * symbols:
 *   func_0203D788 0x0203D788  arm
 *   func_0203EA9C 0x0203EA9C  arm
 *   func_0203DC70 0x0203DC70  arm
 *   func_0203B1D8 0x0203B1D8  arm
 *   func_02037154 0x02037154  arm
 *   func_02039D94 0x02039D94  arm
 *   func_02037C10 0x02037C10  arm
 *   func_02039594 0x02039594  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8  *func_0203D788(void);
extern void func_0203EA9C(void);
extern void func_0203DC70(void);
extern int  func_0203B1D8(void);
extern void func_02037154(void);
extern void func_02039D94(void);
extern void func_02037C10(void);
extern u32  func_02039594(void);

u32 func_0203CF5C(void)
{
    u8 *p = func_0203D788();

    func_0203EA9C();
    func_0203DC70();
    if (func_0203B1D8() != 0) {
        return 1;
    }
    if (p == 0) {
        return 1;
    }
    func_02037154();
    func_02039D94();
    func_02037C10();
    return func_02039594();
}
