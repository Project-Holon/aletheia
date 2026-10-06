/*
 * file:     unit_02072374_p04.c
 * unit:     yes
 * function: func_02072894, func_020728E8
 * address:  0x02072894
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214BAC0   0x0214BAC0  data
 *   g_0214BB00   0x0214BB00  data
 *   func_0208A0A4 0x0208A0A4  arm
 */
struct SNDDriverInfo;
struct SNDTrackInfo;
typedef unsigned char  u8;

typedef signed char    s8;

typedef unsigned int   u32;

extern int func_0208A0A4(struct SNDDriverInfo *, int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);
extern void func_02073EE4(void);
extern void func_020894DC(u32 a, u32 b, u32 c, u32 d);
extern u32  func_02089D40(void);
extern void func_02089B38(u32 a);
extern void func_02089CD4(u32 a);
void func_020728E8(void);
extern s8  g_0214BAC0[];
extern u8  g_0214BB00[];


/*
 *           and it is this function, so no branch outside 0x02072894..0x020728E8
 *           witnesses it.  Every concrete byte reproduces.
 *
 * r1 (b) is parked in lr as soon as it is read, because the predicated
 * `ldrge r1, [pc]` that materialises the table base clobbers r1 before the
 * call; the fourth argument (c) is copied into r3 first for the same reason,
 * r2 being needed for b again at the call.
 */
int func_02072894(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo)
{
    s8 idx = g_0214BAC0[0];
    u8 *p;

    if (idx < 0) p = 0;
    else         p = g_0214BB00 + idx * 0x11E0;
    if (p == 0) return 0;
    return func_0208A0A4((struct SNDDriverInfo *)p, playerNo, trackNo, trackInfo);
}


void func_020728E8(void)
{
    u32 res;

    func_02073EE4();
    func_020894DC(0, 0, 0, 0);
    res = func_02089D40();
    func_02089B38(1);
    func_02089CD4(res);
}
