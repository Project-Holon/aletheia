/*
 * function: func_021F5A7C
 * address:  0x021F5A7C
 * packet:   pkt_021F5A7C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
 * symbols:
 *   func_021F6C48  0x021F6C48  thumb
 *   func_021F6BA4  0x021F6BA4  thumb
 *   func_021F6B40  0x021F6B40  thumb
 *   func_022025E4  0x022025E4  thumb
 *   func_021F663C  0x021F663C  thumb
 *   func_021F4E98  0x021F4E98  thumb
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[8];
    void *party;
    void *save;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x28 - 4];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    u8 padC8[0xB68 - 0xC8];
    void *msg;
    u8 padB6C[0xBFC - 0xB6C];
    u32 cursor;
} Work;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
struct Actor;
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern int func_021F6C48(void *party, void *save, int box, int slot);
extern int func_021F6BA4(void *party, void *save, int box, int slot);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern void func_022025E4(u32 a, u32 b, u32 c);
extern void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
extern void func_021F4E98(u8 *p, u32 a, u32 b);

void func_021F5A7C(Work *p)
{
    if (p->slot == 0x1E) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_RestartActorAnim((struct Actor *)p->cursor);
        p->state = 0x11;
        GFL_USE_PlaySeDefaultVolume(0x551);
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (func_021F6C48(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (func_021F6BA4(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
            func_022025E4((u32)p->msg, 0, (u32)func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot));
            func_021F663C((u8 *)p, 0x16, 1, 0, 0xF0F, 0);
            func_021F4E98((u8 *)p, 3, 7);
        } else {
            func_021F663C((u8 *)p, 0x1A, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        func_021F663C((u8 *)p, 0x21, 1, 0, 0xF0F, 1);
        func_021F4E98((u8 *)p, 4, 1);
        break;
    }
}
