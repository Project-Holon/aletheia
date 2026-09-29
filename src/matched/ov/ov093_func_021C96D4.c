/*
 * function: func_021C96D4
 * address:  0x021C96D4
 * packet:   pkt_ov093_021C96D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021C5A34  0x021C5A34  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 10;
    u32 flag : 1;
};

extern int func_021B9934(char *p, int i);
extern void func_021C5A1C(void *w, int x);
extern void func_021C5A34(void *w, int x);
extern int func_021C99A0(void *w, void *c);

int func_021C96D4(char *w, struct Cmd *c)
{
    int r = 0;
    int id = c->id;
    if (id != 0x1F) {
        r = func_021B9934(*(char **)(w + 8), (u8)id);
    }
    if (c->flag && r) func_021C5A1C(w, r);
    func_021C99A0(w, (u8 *)c + 4);
    if (c->flag && r) func_021C5A34(w, r);
    return 1;
}
