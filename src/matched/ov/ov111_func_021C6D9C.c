/*
 * function: VIEWER_TEXT_InitActors
 * address:  0x021C6D9C
 * packet:   pkt_ov111_021C6D9C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   gClActorInitParam     0x020A1448  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0xB8 - 8];
    u32 fB8;
    u32 fBC;
    u32 fC0;
    u32 fC4;
    u32 fC8;
    u32 fCC;
} Anim;

extern void *func_020490F4(u32 id, u32 heap);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern const u8 gClActorInitParam[];
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern u32 func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void VIEWER_TEXT_InitActors(Anim *a, u32 x)
{
    void *h;

    h = func_020490F4(0x28, a->heap);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, x, a->heap);
    a->f4 = (u32)CLACT_CreateUnit(0x23, 0, a->heap);
    a->fB8 = CLACT_RegisterPaletteEx(h, 0xC, 1, 0, 0, 5, a->heap);
    a->fBC = CLACT_RegisterCharacter(h, 0x1D, 0, 1, a->heap);
    a->fC0 = CLACT_RegisterCellAnim(h, 0x2E, 0x30, a->heap);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(func_020275E4(), a->heap);
    a->fC4 = CLACT_RegisterPalette(h, func_02027614(), 1, 0xA0, a->heap);
    a->fC8 = CLACT_RegisterCharacter(h, func_02027618(), 0, 1, a->heap);
    a->fCC = CLACT_RegisterCellAnim(h, func_0202761C(0), func_02027620(0), a->heap);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
