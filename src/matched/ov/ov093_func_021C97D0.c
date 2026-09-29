/*
 * function: func_021C97D0
 * address:  0x021C97D0
 * packet:   pkt_ov093_021C97D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7BA8  0x021C7BA8  thumb  ov093
 *   func_021C9818  0x021C9818  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
    u32 w8;
    u8 b12;
};

extern void func_021C7BA8(void *w, u8 id, u32 a, u32 b, u32 *out);
extern int func_021C9818(u32 b, u32 a, u32 v);
extern int func_021C99A0(void *w, const void *c);

int func_021C97D0(void *w, const struct Cmd *c)
{
    u32 v;
    void *pv;
    v = c->w8;
    pv = &v;
    func_021C7BA8(w, c->id, c->w4, c->b12, pv);
    if (func_021C9818(c->b12, c->w4, *(u32 *)pv) != 0) {
        func_021C99A0(w, (u8 *)c + 0x10);
        return 1;
    }
    return 0;
}
