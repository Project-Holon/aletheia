/*
 * function: func_021C2C44
 * address:  0x021C2C44
 * packet:   pkt_ov208_021C2C44
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: 2026-10-05 (wave D4 lane 02): the loop back edge in the image goes to the memset call,
 *         so the memset is the first statement of the loop body. The loop-invariant &pos
 *         (add r7, sp, #0x10) is then hoisted into the preheader, before the call.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   data_021C8704  0x021C8704  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} ObjPos;

extern const u8 data_021C8704[7][9];
struct Actor;
struct Obj;
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(int a);
extern void MI_CpuFill8(void *dst, int v, u32 n);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

struct S {
    u32 f0;
    u8 pad4[0x80];
    int a84[6];
    u32 a9c[7];
};

void func_021C2C44(u16 *heap, struct S *st, int a2)
{
    int arc;
    u8 i;
    ObjPos pos;

    arc = (int)func_020490F4(0x9f, *heap);
    i = 0;
    st->a84[1] = CLACT_RegisterPaletteEx((void *)arc, 3, 0, 0, 0, 4, *heap);
    st->a84[0] = CLACT_RegisterCharacter((void *)arc, 0xd, 0, 0, *heap);
    st->a84[2] = CLACT_RegisterCellAnim((void *)arc, 0x1b, 0x2c, *heap);
    st->a84[4] = CLACT_RegisterPaletteEx((void *)arc, 8, 1, 0x40, 0, 1, *heap);
    st->a84[3] = CLACT_RegisterCharacter((void *)arc, 0x18, 0, 1, *heap);
    st->a84[5] = CLACT_RegisterCellAnim((void *)arc, 0x1e, 0x2f, *heap);
    ARC_TOOL_DeleteHandle(arc);
    do {
        const u8 *e;
        MI_CpuFill8(&pos, 0, 8);
        e = data_021C8704[i];
        pos.a = e[0];
        pos.b = e[1];
        pos.c = e[2];
        pos.d = e[3];
        pos.e = e[4];
        st->a9c[i] = (u32)CLACT_CreateActor((void *)st->f0, st->a84[e[5]], st->a84[e[6]], st->a84[e[7]], &pos, e[8], *heap);
        CLACT_SetActorDrawEnable((struct Obj *)st->a9c[i], 1);
        CLACT_SetActorObjMode((struct Actor *)st->a9c[i], 1);
        i++;
    } while (i < 7);
    CLACT_SetActorAutoAnim((struct Obj *)st->a9c[6], 1);
}
