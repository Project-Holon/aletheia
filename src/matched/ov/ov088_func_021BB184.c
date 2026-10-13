/*
 * function: STARTMENU_CreateActors
 * address:  0x021BB184
 * packet:   pkt_ov088_021BB184
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads two resource archives (0x1f and 0x23) and builds the sprite
 * resources and actors from them.  Twin: ov088_func_021B9EC4.c.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   func_02008550  0x02008550  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_021BD688     0x021BD688  data  a4
 *   d_021BD60C     0x021BD60C  data  a4
 *   d_021BD5DC     0x021BD5DC  data  a4
 *   d_021BD5E4     0x021BD5E4  data  a4
 *   d_021BD5D4     0x021BD5D4  data  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct T28 {
    u32 w[7];
} T28;

extern T28 d_021BD688;
extern char d_021BD60C[];
extern char d_021BD5DC[];
extern char d_021BD5E4[];
extern char d_021BD5D4[];

extern void *func_020490F4(u32 id, u32 heap);
typedef unsigned char  u8;
struct Bank;
struct Cfg;
struct Sub0200852CObj;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
typedef signed int     s32;
struct Obj;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *, u32);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void ARC_TOOL_DeleteHandle(void *);

void STARTMENU_CreateActors(int *p)
{
    T28 t;
    void *h;
    u32 i;

    t = d_021BD688;
    CLACT_InitSystem((const struct Cfg *)(&t), (u32)d_021BD60C, 0xb);
    h = func_020490F4(0x1f, 0x800b);
    if (func_02008550((const struct Sub0200852CObj *)p[1]) == 0) {
        p[13] = CLACT_RegisterCharacter(h, 5, 0, 0, 0xb);
        p[16] = CLACT_RegisterPalette(h, 4, 0, 0, 0xb);
        p[19] = CLACT_RegisterCellAnim(h, 0, 1, 0xb);
    } else {
        p[13] = CLACT_RegisterCharacter(h, 7, 0, 0, 0xb);
        p[16] = CLACT_RegisterPalette(h, 6, 0, 0, 0xb);
        p[19] = CLACT_RegisterCellAnim(h, 2, 3, 0xb);
    }
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(0x23, 0x800b);
    p[14] = CLACT_RegisterCharacter(h, 8, 1, 0, 0xb);
    p[17] = CLACT_RegisterPalette(h, 9, 0, 0x20, 0xb);
    p[20] = CLACT_RegisterCellAnim(h, 0xa, 0xb, 0xb);
    p[15] = CLACT_RegisterCharacter(h, 0xc, 1, 0, 0xb);
    p[18] = CLACT_RegisterPalette(h, 0xd, 0, 0x40, 0xb);
    p[21] = CLACT_RegisterCellAnim(h, 0xe, 0xf, 0xb);
    ARC_TOOL_DeleteHandle(h);
    p[6] = (int)CLACT_CreateUnit(6, 0, 0xb);
    p[7] = (int)CLACT_CreateActor((void *)p[6], p[13], p[16], p[19], d_021BD5DC, 0, 0xb);
    CLACT_SetActorDrawEnable((void *)p[7], 0);
    for (i = 1; i <= 4; i++) {
        p[7 + i] = (int)CLACT_CreateActor((void *)p[6], p[14], p[17], p[20], d_021BD5E4, 0, 0xb);
        CLACT_SetActorAutoAnim((struct Obj *)p[7 + i], 1);
        CLACT_SetActorDrawEnable((void *)p[7 + i], 0);
    }
    p[12] = (int)CLACT_CreateActor((void *)p[6], p[15], p[18], p[21], d_021BD5D4, 0, 0xb);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
