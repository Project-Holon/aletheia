/*
 * function: PMSIV_CATEGORY_Setup
 * address: 0x021BB328
 * packet: pkt_ov110_021BB328
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: retain q=bytes/32 then recompute bytes/32 as BB3F4's argument; safe expand(q x1), no intervening write or call.
 * volatile: hardware RMW at 021BB3A8/021BB3B6 (WININ), 021BB3BA/021BB3C4 (WINOUT), 021BB3D6/021BB3E0 (DISPCNT); WIN0H/WIN0V hardware writes.
 * prototype: 02049658's live r0 is consumed; 02040618's legacy fourth input is neither read nor forwarded by its full 02042360 target.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`q
 * = bytes / 32;` before `q = (u32)PMSIV_CATEGORY_MakeCategoryButtons(p, (u8 *)(bytes / 32));`).
 * Game code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 *
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   func_02049658 0x02049658 arm
 *   PMSIV_CATEGORY_MakeCategoryButtons 0x021BB3F4 thumb ov110
 *   PMSIV_CATEGORY_MakeKanaWindow 0x021BB4F4 thumb ov110
 *   PMSIV_CATEGORY_MakeTitleWindow 0x021BB5A0 thumb ov110
 *   PMSIV_CATEGORY_MakeListWindow 0x021BB5E0 thumb ov110
 *   PMSIV_CATEGORY_CreateCursor 0x021BB61C thumb ov110
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   func_0207D658 0x0207D658 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u8 *PMSIV_CATEGORY_MakeCategoryButtons(u8 *, u8 *);
extern u8 *PMSIV_CATEGORY_MakeKanaWindow(u8 *, u8 *);
extern u8 *PMSIV_CATEGORY_MakeTitleWindow(u8 *, u8 *);
extern void PMSIV_CATEGORY_MakeListWindow(u8 *);
extern void PMSIV_CATEGORY_CreateCursor(u8 *);
extern void BG_SYS_FillScrollArea(u32, u32, u32);
extern void func_0207D658(u32, int, int);
extern void BG_SYS_PushTile(u32);
#define WININ (*(volatile u16 *)0x04000048)
#define WINOUT (*(volatile u16 *)0x0400004a)
static inline void inside(int wnd, int effect)
{
    u32 tmp;
    tmp = (WININ & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WININ = (u16)tmp;
}
static inline void outside(int wnd, int effect)
{
    u32 tmp;
    tmp = (WINOUT & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WINOUT = (u16)tmp;
}
void PMSIV_CATEGORY_Setup(u8 *p, u32 data)
{
    u32 bytes, q;
    func_020498F4((void *)data, 27, 1, 0, 0, 0, 42);
    bytes = func_02049658((void *)data, 15, 1, 0, 0, 0, 42);
    q = (u32)PMSIV_CATEGORY_MakeCategoryButtons(p, (u8 *)(bytes / 32));
    q = (u32)PMSIV_CATEGORY_MakeKanaWindow(p, (u8 *)q);
    PMSIV_CATEGORY_MakeTitleWindow(p, (u8 *)q);
    PMSIV_CATEGORY_MakeListWindow(p);
    BG_SYS_FillScrollArea(1, 0, -4);
    BG_SYS_FillScrollArea(1, 3, 16);
    PMSIV_CATEGORY_CreateCursor(p);
    func_0207D658(0x04000050, 2, -10);
    inside(31, 1);
    outside(29, 1);
    *(volatile u16 *)0x04000040 = 255;
    *(volatile u16 *)0x04000044 = 168;
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0xe000) | 0x2000;
    BG_SYS_PushTile(1);
}
