/*
 * function: func_021F5B8C
 * address:  0x021F5B8C
 * packet:   pkt_021F5B8C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   func_021F6C48  0x021F6C48  thumb
 *   func_021F6BA4  0x021F6BA4  thumb
 *   func_021F6B40  0x021F6B40  thumb
 *   func_021F6CDC  0x021F6CDC  thumb
 *   func_022025E4  0x022025E4  thumb
 *   func_021F663C  0x021F663C  thumb
 *   func_021F4E98  0x021F4E98  thumb
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
    u8 pad0[0xF0];
    u8 want[0x128 - 0xF0];
} Entry;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x28 - 4];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    u8 padC8[0xD4 - 0xC8];
    int sel;
    u8 padD8[0x20C - 0xD8];
    Entry list[1];
    u8 pad334[0xB68 - 0x334];
    void *msg;
    u8 padB6C[0xBFC - 0xB6C];
    u32 cursor;
} Work;

extern void func_0204B3DC(u32 obj, int on);
extern void func_0204B9A0(u32 v);
extern void func_020061E4(u32 se);
extern int func_021F6C48(void *party, void *save, int box, int slot);
extern int func_021F6BA4(void *party, void *save, int box, int slot);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern int func_021F6CDC(void *mon, void *want);
extern void func_022025E4(void *msg, u32 idx, void *mon);
extern void func_021F663C(Work *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
extern void func_021F4E98(Work *p, u32 a, u32 b);

void func_021F5B8C(Work *p)
{
    void *mon;

    if (p->slot == 0x1E) {
        func_0204B3DC(p->cursor, 1);
        func_0204B9A0(p->cursor);
        p->state = 0x11;
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (func_021F6C48(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6CDC(mon, p->list[p->sel].want) != 0) {
            if (func_021F6BA4(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
                func_022025E4(p->msg, 0, mon);
                func_021F663C(p, 0x12, 1, 0, 0xF0F, 0);
                func_021F4E98(p, 3, 9);
                func_020061E4(0x54C);
            } else {
                func_021F663C(p, 0x1A, 1, 0, 0xF0F, 1);
                func_021F4E98(p, 4, 1);
            }
        } else {
            func_020061E4(0x551);
        }
        break;
    case 0:
    case 2:
        func_020061E4(0x551);
        break;
    }
}
