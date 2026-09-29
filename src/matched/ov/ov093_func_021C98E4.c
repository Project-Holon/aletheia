/*
 * function: func_021C98E4
 * address:  0x021C98E4
 * packet:   pkt_ov093_021C98E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C3B8C  0x021C3B8C  thumb  ov093
 *   func_021C3BB8  0x021C3BB8  thumb  ov093
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021C5A34  0x021C5A34  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C7BF8  0x021C7BF8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 3;
    u32 pad2 : 7;
    u32 flag : 1;
    u32 pad3 : 8;
    u8 b4;
    u8 b5;
    u8 b6;
};

extern int func_021B9934(char *p, u8 i);
extern int func_021C3B8C(void *w, u32 a, u32 b);
extern void func_021C3BB8(void *w, u32 a, u32 b);
extern void func_021C5A1C(void *w, int x);
extern void func_021C5A34(void *w, int x);
extern int func_021C99A0(void *w, void *c);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C7BF8(void *w);
extern void func_021CC95C(void *lock, u32 v, int line);

u8 func_021C98E4(u8 *w, struct Cmd *c)
{
    int id = func_021B9934(*(char **)(w + 8), c->id);
    int r = 0;
    u32 s;
    if (c->b4 != 0) {
        if (func_021C3B8C(w, c->b4, c->b5) != 0) {
            if (c->flag) func_021C5A1C(w, id);
            func_021C3BB8(w, c->b4, c->b5);
            func_021C99A0(w, (u8 *)c + 8);
            r = 1;
            if (c->flag) func_021C5A34(w, id);
        }
    } else if (c->b6 != 0) {
        if (c->flag) func_021C5A1C(w, id);
        func_021C99A0(w, (u8 *)c + 8);
        s = func_021CC8D8(w + 0x1D74, 15467);
        func_021C7BF8(w);
        func_021CC95C(w + 0x1D74, s, 15469);
        r = 1;
        if (c->flag) func_021C5A34(w, id);
    }
    return r;
}
