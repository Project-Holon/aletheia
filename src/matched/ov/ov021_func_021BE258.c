/*
 * function: func_021BE258
 * address:  0x021BE258
 * packet:   pkt_ov021_021BE258
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   d_021D9E74  0x021D9E74  data
 */

typedef void (*Handler)(void *p);

extern void *func_02188C80(void *p);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 func_0200B3AC(struct Rec94 *p);
extern Handler d_021D9E74[];

void func_021BE258(void *p)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(p))));
    if (i != -1 && d_021D9E74[i] != 0)
        d_021D9E74[i](p);
}
