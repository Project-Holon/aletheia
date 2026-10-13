/*
 * function: func_021F7374
 * address:  0x021F7374
 * packet:   pkt_021F7374
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F7338  0x021F7338  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0220262C  0x0220262C  thumb
 *   func_02007664  0x02007664  thumb
 *   func_020076D0  0x020076D0  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_0200752C  0x0200752C  thumb
 *
 * Fill the slot record for the current kind (+0x20). A +0xDC source of
 * 0xFF copies party member +0xE0 into it (func_0220262C); otherwise the
 * box/slot pair (+0xDC, +0xE0) is looked up in the storage at +0xC of
 * the context and the found entry is written into the record.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[8];
    void *party;
    u32 storage;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[0xDC - 0x24];
    u32 box;
    u32 slot;
} Obj;

extern u32 func_021F7338(Obj *p, int kind);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0220262C(u32 a, u32 b);
struct Sub02007454Entry;
extern void func_02007664(void *save, u32 box, u32 slot);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern void *POKE_TOOL_GetBoxParam(void *p);
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);

void func_021F7374(Obj *p)
{
    u32 e = func_021F7338(p, p->kind);

    if (p->box == 0xff) {
        func_0220262C(e, (u32)func_0201AB28(p->ctx->party, p->slot));
    } else {
        u32 a;
        u32 b;

        a = 0;
        b = 0;
        func_02007664((void *)p->ctx->storage, p->box, p->slot);
        func_020076D0((void *)p->ctx->storage, (int *)(&a), (int *)(&b));
        func_0200752C((void **)p->ctx->storage, a, (const struct Sub02007454Entry *)((u32)POKE_TOOL_GetBoxParam((void *)e)));
    }
}
