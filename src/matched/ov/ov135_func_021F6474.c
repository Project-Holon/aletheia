/*
 * function: func_021F6474
 * address:  0x021F6474
 * packet:   pkt_021F6474
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
 *   func_021F6DE8  0x021F6DE8  thumb
 *   func_021F663C  0x021F663C  thumb
 *   func_021F4E98  0x021F4E98  thumb
 *   func_021F6B40  0x021F6B40  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 *   func_021F6D14  0x021F6D14  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
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
    u8 padC8[0xCC - 0xC8];
    void *mon;
    u32 d0;
    int sel;
    u8 padD8[0xE4 - 0xD8];
    u8 deposit[0x20C - 0xE4];
    u8 list[1][0x128];
    u8 pad334[0xEB4 - 0x334];
    u32 eb4;
} Work;

extern int func_021F6DE8(u32 handle);
extern u32 POKEPARTY_GetCount(void *p);
extern void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021F6D14(void *dst, Work *p);

int func_021F6474(Work *p)
{
    if (func_021F6DE8((u32)p->list[p->sel]) != 0 && p->box != 0xFF
        && POKEPARTY_GetCount(p->ctx->party) == 6) {
        func_021F663C((u8 *)p, 0x29, 1, 0, 0xF0F, 1);
        func_021F4E98((u8 *)p, 4, 1);
        return 0;
    }
    p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
    p->state = 2;
    p->eb4 = 1;
    func_021F4EC0((u8 *)p, 7, 9);
    func_021F6D14(p->deposit, p);
    p->d0 = 0;
    return 1;
}
