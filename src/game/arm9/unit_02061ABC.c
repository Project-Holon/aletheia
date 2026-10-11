/*
 * file:     unit_02061ABC.c
 * unit:     yes
 * function: func_02061ABC, func_02061AE8, func_02061B14, func_02061B20
 * address:  0x02061ABC
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

extern void func_0207F6A8(void);
extern void func_0207F6C0(u32 a, u32 b, u32 c);
extern void func_0207F754(void);
extern void func_0207F5B0(void);
extern void func_0207F5C8(u32 a, u32 b, u32 c);
extern void func_0207F65C(void);
void func_02061ABC(u32 a, u32 b, u32 c);
void func_02061AE8(u32 a, u32 b, u32 c);
extern void func_0207E708(u32 a, u32 b, u32 c);
extern void func_0207E804(u32 a, u32 b, u32 c);
void func_02061B14(u32 a, u32 b, u32 c);
void func_02061B20(u32 a, u32 b, u32 c);


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061ABC.c \
 *       --func func_02061ABC --addr 0x02061ABC --arm --cc 1.1p1
 */
void func_02061ABC(u32 a, u32 b, u32 c)
{
    func_0207F6A8();
    func_0207F6C0(a, b, c);
    func_0207F754();
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061AE8.c \
 *       --func func_02061AE8 --addr 0x02061AE8 --arm --cc 1.1p1
 */
void func_02061AE8(u32 a, u32 b, u32 c)
{
    func_0207F5B0();
    func_0207F5C8(a, b, c);
    func_0207F65C();
}


void func_02061B14(u32 a, u32 b, u32 c)
{
    func_0207E708(a, b, c);
}


void func_02061B20(u32 a, u32 b, u32 c)
{
    func_0207E804(a, b, c);
}
