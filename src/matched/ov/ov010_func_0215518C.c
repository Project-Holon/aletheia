/*
 * function: func_0215518C
 * address:  0x0215518C
 * packet:   pkt_ov010_0215518C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Rebuilds the list at +0x38: either from the party list at +0 (skipping
 * entries whose field 0x4c is set) or from a fresh six-slot list, then
 * refreshes it. func_0200BAC8 is a tail-calling wrapper whose result is
 * used here, so this unit declares it returning a value.
 *
 * symbols:
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0201BA34  0x0201BA34  thumb
 *   func_02155160  0x02155160  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx {
    void *f00;
    u8 pad04[0x34];
    void *f38;
    u8 pad3c[0x10];
    void *f4c;
};

extern int func_0200BAC8(void *p);
struct BigObj;
struct Party;
struct PartyMon;
struct Rec534;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_0200BAF4(int a, int b);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_020307B0(void *p);
extern void func_0201BA34(void *p);
extern void func_02155160(void *list);

void func_0215518C(int mode, struct Ctx *ctx)
{
    int t;
    void *e;
    int i;
    void *list;
    void *h;
    t = func_0200BAC8(ctx->f4c);
    if (mode == 0) {
        list = func_02012934(func_020120F4(ctx->f00));
        for (i = 0; i < (int)func_0201AA18(list); i++) {
            e = func_0201AB28(list, i);
            if (func_02017E1C(e, 0x4c, 0) == 0)
                func_0201A98C(ctx->f38, e);
        }
    } else {
        h = func_0200BAF4(t, 4);
        func_0201AC2C(h, ctx->f38);
        func_020307B0(h);
    }
    func_0201BA34(ctx->f38);
    func_02155160(ctx->f38);
}
