/*
 * function: func_021CA270
 * address:  0x021CA270
 * packet:   pkt_ov093_021CA270
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5FA4  0x021D5FA4  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 *   func_021BDA00  0x021BDA00  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 pad;
    u8 b4;
    u8 b5;
    u16 h6;
};

extern u8 *func_021B9934(char *p, int i);
struct Unk021D5FA4;
extern void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
extern void func_021CD4B0(void *w, u32 id, ...);
extern int func_021C99A0(void *w, void *c);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern int func_021B8DDC(u8 i);
extern int func_021B8DEC(void *p, int s);
extern void func_021BD9D4(void *w, int a, int b, int c, int d);
extern void func_021BDA00(void *w);

int func_021CA270(u8 *w, const struct Cmd *c)
{
    int s;
    int a;
    int b;
    func_021D5FA4((struct Unk021D5FA4 *)func_021B9934(*(char **)(w + 8), c->b4), c->h6);
    func_021CD4B0(*(void **)(w + 0xC), 2, c->b4, c->h6);
    *(u8 *)(w + c->b4 + 0x7A9) = 0;
    func_021C99A0(w, (u8 *)c + 8);
    s = func_021B8D8C(*(void **)(w + 4), *(void **)(w + 8), c->b4);
    if (s != 6) {
        a = func_021B8DDC(c->b4);
        b = func_021B8DEC(*(void **)(w + 4), s);
        func_021BD9D4(w, a, b, b, 1);
        func_021BDA00(w);
    }
    return 1;
}
