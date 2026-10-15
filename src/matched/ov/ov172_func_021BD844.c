/*
 * function: CTVT_CALL_InitGraphics
 * address: 0x021BD844
 * packet: pkt_ov172_021BD844
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-02: closed. The draft read pal->raw through one extra load (the out
 *   parameter of ARC_UTIL_LoadPaletteBlockFromHandle is a palette-data pointer; raw is at +0xc), and the
 *   last call is written per arm (literal 7/6 in each arm); a shared ternary or
 *   sel variable lets the compiler CSE the constant 7 into a stack temp.
 * symbols:
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   COMM_TVT_SYS_GetClactUnit 0x021BE024 thumb ov172
 *   COMM_TVT_SYS_GetResId 0x021BE018 thumb ov172
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Sub0200852CObj;
struct PltData { u32 fmt; u32 ext; u32 size; u8 *raw; };
struct CellCfg { u16 a; u16 b; u16 c; u8 d; u8 e; };
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020490F4(u32 id, u32 heap);
struct Obj;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 index);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern u32 COMM_TVT_SYS_GetClactUnit(void *p);
extern u32 COMM_TVT_SYS_GetResId(void *p, int i);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *e, unsigned short f, unsigned short g);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);

#define W(o) (*(u32 *)(p + (o)))
#define BG (*(void **)(p + 0x17c))
#define HEAP (*(u16 *)p)
void CTVT_CALL_InitGraphics(u8 *p)
{
    struct Sub0200852CObj *t;
    void *dev;
    u32 o;
    u32 i0;
    u32 i1;
    u32 i2;
    int z;
    struct CellCfg cfg;
    struct PltData *pal;
    t = (struct Sub0200852CObj *)GAME_DATA_GetMyStatus(*(void **)W(0x1f8));
    BG = func_020490F4(0xac, HEAP);
    if (func_02008550(t) == 0) {
        func_02049B68(BG, 7, 4, 0, 0xc0, HEAP);
    } else {
        func_02049B68(BG, 6, 4, 0, 0xc0, HEAP);
    }
    z = 0;
    func_02049658(BG, 0xb, 7, 0, z, z, HEAP);
    func_020498F4(BG, 0xe, 7, 0, z, z, HEAP);
    func_020409B4(7);
    func_02049B68(BG, 0, 0, 0x20, 0x20, HEAP);
    func_02049658(BG, 8, 1, 0, z, z, HEAP);
    func_020498F4(BG, 0xd, 1, 0, z, z, HEAP);
    func_020409B4(1);
    W(0x180) = CLACT_RegisterPaletteCompressed(BG, 3, 0, 0, HEAP);
    W(0x190) = CLACT_RegisterCharacter(BG, 0x18, 0, 0, HEAP);
    W(0x1a0) = CLACT_RegisterCellAnim(BG, 0x14, 0x16, HEAP);
    W(0x184) = CLACT_RegisterPaletteCompressed(BG, 3, 1, 0, HEAP);
    W(0x194) = CLACT_RegisterCharacter(BG, 0x17, 0, 1, HEAP);
    W(0x1a4) = CLACT_RegisterCellAnim(BG, 0x13, 0x15, HEAP);
    dev = func_020490F4(func_020275E4(), HEAP);
    func_02049B68(dev, func_02027624(), 0, 0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 0, 0, z, z, HEAP);
    func_02049B68(dev, func_02027624(), 4, 0xc0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 5, z, z, z, HEAP);
    func_020498F4(dev, func_0202762C(), 5, z, z, z, HEAP);
    BG_SYS_FillTileMap(5, z, 0x15, 0x20, 3, 6);
    func_020409B4(5);
    W(0x18c) = CLACT_RegisterPaletteEx(dev, func_02027614(), z, 0xe0, z, 3, HEAP);
    W(0x19c) = CLACT_RegisterCharacter(dev, func_02027618(), z, z, HEAP);
    W(0x188) = CLACT_RegisterPaletteEx(dev, func_02027614(), 1, 0xe0, z, 3, HEAP);
    W(0x198) = CLACT_RegisterCharacter(dev, func_02027618(), z, 1, HEAP);
    W(0x1a8) = CLACT_RegisterCellAnim(dev, func_0202761C(2), func_02027620(2), HEAP);
    ARC_TOOL_DeleteHandle(dev);
    cfg.a = z;
    cfg.b = z;
    cfg.c = z;
    cfg.d = z;
    cfg.e = z;
    o = COMM_TVT_SYS_GetClactUnit(p);
    i0 = COMM_TVT_SYS_GetResId(p, 4);
    i1 = COMM_TVT_SYS_GetResId(p, z);
    i2 = COMM_TVT_SYS_GetResId(p, 8);
    W(0x1b0) = (u32)CLACT_CreateActor((void *)o, i0, i1, i2, &cfg, z, HEAP);
    CLACT_SetActorDrawEnable((void *)W(0x1b0), z);
    CLACT_SetActorAutoAnim((void *)W(0x1b0), 1);
    if (func_02008550(t) == 0) {
        dev = ARC_UTIL_LoadPaletteBlockFromHandle(BG, 7, (u32)(&pal), HEAP);
    } else {
        dev = ARC_UTIL_LoadPaletteBlockFromHandle(BG, 6, (u32)(&pal), HEAP);
    }
    MIi_CpuCopy32(pal->raw + 0xc0, p + 0x3c, 0x140);
    func_020307B0(dev);
}
