/*
 * function: func_021CA158
 * address:  0x021CA158
 * packet:   pkt_ov093_021CA158
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021BC2B0  0x021BC2B0  thumb  ov093
 *   func_021C8374  0x021C8374  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021BDD00  0x021BDD00  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021BB930  0x021BB930  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u8 pad[0x4C];
    u8 b4c;
    u8 b4d;
};

extern u8 *func_021B9934(char *p, int i);
extern int func_021BC2B0(void *w);
extern int func_021C8374(void *w, u8 i);
extern int func_021C99A0(void *w, void *c);
extern int func_021BDD00(void *w, u8 *r, u8 b);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021BB930(void *p, int x);

int func_021CA158(u8 *w, struct Cmd *c)
{
    u8 *r = func_021B9934(*(char **)(w + 8), c->b4c);
    if (func_021BC2B0(w) == 0 && func_021C8374(w, c->b4c) == 0 && *(int *)(w + 0x14) == 0) {
        func_021C99A0(w, (u8 *)c + 4);
        if (func_021BDD00(w, r, c->b4d) != 0) {
            func_021BB930(*(void **)w, func_021B8D8C(*(void **)(w + 4), *(void **)(w + 8), c->b4c));
            func_021C99A0(w, (u8 *)c + 0x28);
            *(int *)(w + 0x14) = 1;
            return 1;
        }
    }
    return 0;
}
