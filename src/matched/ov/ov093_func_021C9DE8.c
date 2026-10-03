/*
 * function: func_021C9DE8
 * address:  0x021C9DE8
 * packet:   pkt_ov093_021C9DE8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021C2128  0x021C2128  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 f0 : 1;
    u32 f1 : 1;
};

extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *p);
extern int func_021D5B48(u8 *p);
extern int func_021C2128(u8 *p, u8 *a);

int func_021C9DE8(u8 *w, struct Cmd *c)
{
    u8 *r = func_021B9934(*(char **)(w + 8), (u8)c->id);
    if (func_021D5B68(r) == 0 || c->f1) {
        if (c->f0 && func_021D5B48(r) != 0) return 0;
        if (func_021C2128(w, r) != 0) return 1;
    }
    return 0;
}
