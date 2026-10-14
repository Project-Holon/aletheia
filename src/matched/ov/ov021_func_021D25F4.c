/*
 * function: SCRCMD_POKE_ICON_CreateIcon
 * address:  0x021D25F4
 * packet:   pkt_ov021_021D25F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The pooled 0x8015 is the heap id as a plain literal: it is too wide for a
 * Thumb movs, so the compiler pools it by itself; no symbol is needed. int
 * params were the fix for register allocation.
 *
 * symbols:
 *   CLACT_CreateUnit  0x0204B100  arm
 *   POKEGRA_OpenHandle  0x0202D7C8  thumb
 *   POKEGRA_RegisterCgr  0x0202D81C  thumb
 *   POKEGRA_RegisterPalette  0x0202D7D8  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   POKEGRA_RegisterCellAnim  0x0202D898  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   gPokeIconActorParam     0x021DD710  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a, b, c, d;
} Pos;

typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern int POKEGRA_OpenHandle(int a0);
extern u32 POKEGRA_RegisterCgr(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 heap);
extern int POKEGRA_RegisterPalette(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern void ARC_TOOL_DeleteHandle(u32 a);
extern u32 POKEGRA_RegisterCellAnim(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 heap);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern Pos gPokeIconActorParam;

void SCRCMD_POKE_ICON_CreateIcon(u32 *p, int a, int b, int c, int s0, int s1)
{
    Pos loc;
    u32 t;

    p[1] = (u32)CLACT_CreateUnit(1, 0, 0x8015);
    t = POKEGRA_OpenHandle(0x8015);
    p[3] = POKEGRA_RegisterCgr(t, a, b, c, s0, 0, 0, s1, 0, 0x8015);
    p[4] = (u32)POKEGRA_RegisterPalette((u32)t, (u32)a, (u32)b, (u32)c, (u32)s0, (u32)0, (u32)0, (u32)0, (u32)0, (u32)0x8015);
    ARC_TOOL_DeleteHandle(t);
    p[5] = POKEGRA_RegisterCellAnim(a, b, c, s0, 0, 0, 1, 0, 0x8015);
    loc = gPokeIconActorParam;
    p[2] = (u32)CLACT_CreateActor((void *)p[1], p[3], p[4], p[5], &loc, 0, 0x8015);
}
