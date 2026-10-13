/*
 * function: TOWNMAP_GRH_InitSprites
 * address:  0x021BB9B8
 * packet:   pkt_ov072_021BB9B8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   sTownMapGrhClactInit     0x021BBC0C  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Rect;

typedef struct { u32 w[7]; } Tbl;

typedef struct {
    u32 res;
    u32 obj[4];
    u32 f14;
    u32 chr;
    u32 cell;
    u32 pal;
} Gfx;

extern void MI_CpuFill8(void *p, int v, int n);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
struct Obj;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
typedef signed int     s32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 CLACT_RegisterPalette(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 CLACT_RegisterCharacter(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern u32 CLACT_CreateActor(u32, u32, u32, u32, Rect *, u32, u32);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int v);
extern const Tbl sTownMapGrhClactInit;

void TOWNMAP_GRH_InitSprites(Gfx *o, u32 mode, u32 heap)
{
    int i;
    void *h;
    Tbl t;
    Rect s;

    i = 0;
    MI_CpuFill8(o, 0, 0x24);
    t = sTownMapGrhClactInit;
    CLACT_InitSystem((const struct Cfg *)(&t), mode, heap);
    o->res = (u32)CLACT_CreateUnit(0x80, 0, heap);
    CLACT_SetUnitDefaultRenderer((struct Bank *)o->res);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    h = func_020490F4(0x55, heap);
    o->pal = CLACT_RegisterPalette(h, 2, 0, 0, heap);
    o->chr = CLACT_RegisterCharacter(h, 8, 0, 0, heap);
    o->cell = CLACT_RegisterCellAnim(h, 0xc, 0x13, heap);
    ARC_TOOL_DeleteHandle(h);
    MI_CpuFill8(&s, 0, 8);
    for (; i < 4; i++) {
        o->obj[i] = CLACT_CreateActor(o->res, o->chr, o->pal, o->cell, &s, 1, heap);
    }
    CLACT_SetActorAnimSeq((struct Obj *)o->obj[0], 0);
    CLACT_SetActorAnimSeq((struct Obj *)o->obj[1], 4);
    CLACT_SetActorAnimSeq((struct Obj *)o->obj[2], 5);
    CLACT_SetActorAnimSeq((struct Obj *)o->obj[3], 6);
    for (i = 0; i < 4; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)o->obj[i], 0);
    }
}
