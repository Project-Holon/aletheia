/*
 * file:     unit_020619BC.c
 * unit:     yes
 * function: func_020619BC, func_020619E8
 * address:  0x020619BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

extern void func_0207F47C(void);
extern void func_0207F4C4(u32 a, u32 b, u32 c);
extern void func_0207F560(void);
extern void func_0207F308(void);
extern void func_0207F394(u32 a, u32 b, u32 c);
extern void func_0207F428(void);
void func_020619BC(u32 a, u32 b, u32 c);
void func_020619E8(u32 a, u32 b, u32 c);


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020619BC.c \
 *       --func func_020619BC --addr 0x020619BC --arm --cc 1.1p1
 */
void func_020619BC(u32 a, u32 b, u32 c)
{
    func_0207F47C();
    func_0207F4C4(a, b, c);
    func_0207F560();
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020619E8.c \
 *       --func func_020619E8 --addr 0x020619E8 --arm --cc 1.1p1
 */
void func_020619E8(u32 a, u32 b, u32 c)
{
    func_0207F308();
    func_0207F394(a, b, c);
    func_0207F428();
}
