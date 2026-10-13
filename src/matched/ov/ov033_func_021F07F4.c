/*
 * function: DOWSING_CreateParts
 * address:  0x021F07F4
 * packet:   pkt_ov033_021F07F4
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the four `strh #0` at the loop top are `Local s = {0};` declared
 *           in the loop body (field-by-field zeroing ends in two strb), and
 *           `pt` lives in its own block after the loop so it takes the
 *           lower slot (sp+0x10) below `s` (sp+0x14).
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B688 0x0204B688 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0204B404 0x0204B404 arm
 *   sDowsingPartIds 0x021F0DBC data ov033 a1
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
} Local;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Ids;

typedef struct {
    u32 chr;
    u32 cell;
    u32 obj;
} Rec;

typedef struct {
    u16 heap;
    u16 heap2;
    u8 pad4[0x8];
    u32 fC;
    u8 pad10[0x1C];
    u32 f2C;
    Rec rec[4];
} Obj;

extern const Ids sDowsingPartIds[];
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
struct Actor;
extern void func_0204B688(struct Actor *actor, u32 value);
extern void ARC_TOOL_DeleteHandle(void *);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void DOWSING_CreateParts(Obj *p)
{
    void *arc;
    u8 i;

    arc = func_020490F4(0xC3, p->heap2);
    p->f2C = CLACT_RegisterPaletteEx(arc, 1, 1, 0, 0, 1, p->heap);
    for (i = 0; i < 4; i++) {
        Local s = {0};
        if (i == 1) {
            p->rec[i].chr = p->rec[0].chr;
            p->rec[i].cell = p->rec[0].cell;
        } else {
            p->rec[i].chr = CLACT_RegisterCharacter(arc, sDowsingPartIds[i].a, 0, 1, p->heap);
            p->rec[i].cell = CLACT_RegisterCellAnim(arc, sDowsingPartIds[i].b, sDowsingPartIds[i].c, p->heap);
        }
        s.d = i;
        p->rec[i].obj = (u32)CLACT_CreateActor((void *)p->fC, p->rec[i].chr, p->f2C, p->rec[i].cell, &s, 1, p->heap);
        func_0204B92C((struct Obj *)p->rec[i].obj, 1);
        func_0204B688((struct Actor *)p->rec[i].obj, 1);
    }
    ARC_TOOL_DeleteHandle(arc);
    {
        Pos pt;

        pt.x = 0x50;
        pt.y = 0x60;
        func_0204B404((struct Obj *)p->rec[0].obj, (const struct Vec2 *)(&pt), 1);
        pt.x = 0xB0;
        pt.y = 0x60;
        func_0204B404((struct Obj *)p->rec[1].obj, (const struct Vec2 *)(&pt), 1);
        pt.x = 0x80;
        pt.y = 0x60;
        func_0204B404((struct Obj *)p->rec[3].obj, (const struct Vec2 *)(&pt), 1);
    }
}
