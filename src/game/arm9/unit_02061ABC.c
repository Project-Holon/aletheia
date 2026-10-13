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
extern void func_0207F6C0(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207F754(void);
extern void func_0207F5B0(void);
extern void func_0207F5C8(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207F65C(void);
void func_02061ABC(const void *pSrc, u32 offset, u32 szByte);
void func_02061AE8(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207E708(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207E804(const void *pSrc, u32 offset, u32 szByte);
void func_02061B14(const void *pSrc, u32 offset, u32 szByte);
void func_02061B20(const void *pSrc, u32 offset, u32 szByte);


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061ABC.c \
 *       --func func_02061ABC --addr 0x02061ABC --arm --cc 1.1p1
 */
void func_02061ABC(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207F6A8();
    func_0207F6C0(pSrc, offset, szByte);
    func_0207F754();
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061AE8.c \
 *       --func func_02061AE8 --addr 0x02061AE8 --arm --cc 1.1p1
 */
void func_02061AE8(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207F5B0();
    func_0207F5C8(pSrc, offset, szByte);
    func_0207F65C();
}


void func_02061B14(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207E708(pSrc, offset, szByte);
}


void func_02061B20(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207E804(pSrc, offset, szByte);
}
