/*
 * function: func_021C9ECC
 * address:  0x021C9ECC
 * packet:   pkt_ov093_021C9ECC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C60D4  0x021C60D4  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C2250  0x021C2250  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
};

extern int func_021B9934(char *p, u8 i);
extern void func_021C60D4(void *w, int x);
extern int func_021C99A0(void *w, void *c);
extern void func_021C2250(void *w, int x, int a, int b);

int func_021C9ECC(u8 *w, struct Cmd *c)
{
    int r = func_021B9934(*(char **)(w + 8), c->id);
    if (c->w4 == 0) {
        func_021C60D4(w, r);
        func_021C99A0(w, (u8 *)c + 8);
    }
    func_021C2250(w, r, 0, 1);
    return 1;
}
