/*
 * function: BOX2_SEQ_LoadBoxScreen
 * address:  0x021ECDF4
 * packet:   pkt_ov170_021ECDF4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_020275F8 0x020275F8 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_020275E8 0x020275E8 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   func_0202774C 0x0202774C thumb
 *   func_02027750 0x02027750 thumb
 *   func_02027754 0x02027754 thumb
 *   func_02027748 0x02027748 thumb
 *   func_0202776C 0x0202776C thumb
 *   func_02027770 0x02027770 thumb
 *   func_02027774 0x02027774 thumb
 *   func_02027768 0x02027768 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *
 * Loads the box screen graphics from the shared archive into the work
 * slots at 0xA094 (seventeen palettes) and 0xA0FC..0xA160 (character,
 * cell and animation resources), then closes the archive.
 */

typedef unsigned short u16;

extern unsigned func_020275E4(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned int func_020275F8(unsigned int a);
extern signed int CLACT_RegisterCharacter(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
typedef unsigned int   u32;
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern signed int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern unsigned func_020275E8(void);
typedef signed int     s32;
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_0202774C(int a);
extern int func_02027750(int a);
extern int func_02027754(int a);
extern int func_02027748(void);
extern int func_0202776C(int a);
extern int func_02027770(int a);
extern int func_02027774(int a);
extern int func_02027768(void);
extern void ARC_TOOL_DeleteHandle(void *h);

#define SLOT(w, o) (*(void **)((w) + (o)))

void BOX2_SEQ_LoadBoxScreen(char *w)
{
    void *h;
    unsigned i;

    h = func_020490F4(func_020275E4(), 0x804C);
    for (i = 0; i < 0x11; i++)
        *(void **)(w + i * 4 + 0xA094) = (void *)CLACT_RegisterCharacter(h, func_020275F8((unsigned char)i), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA144) = (void *)CLACT_RegisterCellAnim(h, func_020275FC(2), func_02027600(2), 0x4C);
    SLOT(w, 0xA118) = (void *)CLACT_RegisterPalette(h, func_020275E8(), 1, 0, 0x4C);
    SLOT(w, 0xA100) = (void *)CLACT_RegisterCharacter(h, func_0202774C(2), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA15C) = (void *)CLACT_RegisterCellAnim(h, func_02027750(2), func_02027754(2), 0x4C);
    SLOT(w, 0xA12C) = (void *)CLACT_RegisterPalette(h, func_02027748(), 1, 0xA0, 0x4C);
    SLOT(w, 0xA104) = (void *)CLACT_RegisterCharacter(h, func_0202776C(2), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA160) = (void *)CLACT_RegisterCellAnim(h, func_02027770(2), func_02027774(2), 0x4C);
    SLOT(w, 0xA130) = (void *)CLACT_RegisterPalette(h, func_02027768(), 1, 0xC0, 0x4C);
    SLOT(w, 0xA0FC) = (void *)CLACT_RegisterCharacter(h, func_0202774C(2), (int)0, (int)0, (unsigned)0x4C);
    SLOT(w, 0xA158) = (void *)CLACT_RegisterCellAnim(h, func_02027750(2), func_02027754(2), 0x4C);
    SLOT(w, 0xA128) = (void *)CLACT_RegisterPalette(h, func_02027748(), 0, 0x1A0, 0x4C);
    ARC_TOOL_DeleteHandle(h);
}
