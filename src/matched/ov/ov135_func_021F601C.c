/*
 * function: func_021F601C
 * address:  0x021F601C
 * packet:   pkt_021F601C
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
 *   func_021F4E30  0x021F4E30  thumb
 *   func_021F4E64  0x021F4E64  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 *   func_021F6B40  0x021F6B40  thumb
 *   func_021F6BC4  0x021F6BC4  thumb
 *   func_021F663C  0x021F663C  thumb
 *   func_021F4E98  0x021F4E98  thumb
 *   func_021F6BFC  0x021F6BFC  thumb
 *   func_021F6C28  0x021F6C28  thumb
 *   func_021F6B34  0x021F6B34  thumb
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
    u8 padD0[0xD40 - 0xD0];
    void *d40;
    u8 padD44[0xDE8 - 0xD44];
    void *de8;
} Work;

extern u32 func_021F4E30(u8 *p);
extern void func_021F4E64(u8 *p);
extern u32 func_0201F868(void *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern u32 func_021F6BC4(void *mon);
extern void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern int func_021F6BFC(u32 handle);
extern int func_021F6C28(u32 handle);
extern int func_021F6B34(int v);
extern void *func_0201AB28(void *p, u32 idx);

int func_021F601C(Work *p)
{
    void *mon;

    switch (func_021F4E30((u8 *)p)) {
    case 1:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 2;
        func_021F4EC0((u8 *)p, 8, 5);
        break;
    case 2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6BC4(mon) != 0) {
            func_021F663C((u8 *)p, 0x2B, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6BFC((u32)mon) != 0) {
            if (func_021F6BFC((u32)mon) == 1) {
                func_021F663C((u8 *)p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                func_021F663C((u8 *)p, 0xC0, 1, 0, 0xF0F, 1);
            }
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6C28((u32)mon) != 0) {
            func_021F663C((u8 *)p, 0xC1, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else {
            if (func_021F6B34(p->box) != 0) {
                func_0201AB28(p->ctx->party, p->slot);
            }
            p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
            p->state = 2;
            func_021F4EC0((u8 *)p, 6, 0);
        }
        break;
    case 3:
    case (u32)-2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}
