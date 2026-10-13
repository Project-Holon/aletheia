/*
 * function: PARTY_SELECT_LIST_LoadMonIconResources
 * address:  0x021CC8DC
 * packet:   pkt_ov021_021CC8DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *f4;
    void *f8;
    u16 heap;
    u16 padE[(0x7C - 0xE) / 2];
    u16 f7C;
    u16 f7E;
    u16 f80[6];
    u16 f8C[6];
} Obj;

extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern int func_0201BC3C(void);
extern int CLACT_RegisterPaletteCompressed(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_Dummy(void *p);
extern u32 func_0201BA68(void *mon);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *h);

void PARTY_SELECT_LIST_LoadMonIconResources(Obj *p)
{
    void *arc;
    int i;
    int n;

    arc = func_020490F4(7, p->heap);
    p->f7C = CLACT_RegisterPaletteCompressed(arc, func_0201BC3C(), 0, 0x60, p->heap);
    p->f7E = CLACT_RegisterCellAnim(arc, func_0201BC40(), func_0201BCB4(), p->heap);
    n = func_0201AA18(p->f4);
    for (i = 0; i < n; i++) {
        p->f80[i] = CLACT_RegisterCharacter(arc, func_0201BA68((void *)POKE_TOOL_Dummy(func_0201AB28(p->f4, i))), 0, 0, p->heap);
    }
    if (p->f8 != 0) {
        n = func_0201AA18(p->f8);
        for (i = 0; i < n; i++) {
            p->f8C[i] = CLACT_RegisterCharacter(arc, func_0201BA68((void *)POKE_TOOL_Dummy(func_0201AB28(p->f8, i))), 0, 0, p->heap);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
}
