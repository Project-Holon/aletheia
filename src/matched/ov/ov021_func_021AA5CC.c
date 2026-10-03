/*
 * function: func_021AA5CC
 * address:  0x021AA5CC
 * packet:   pkt_ov021_021AA5CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020130C4  0x020130C4  thumb
 *   func_0202A230  0x0202A230  thumb
 *   func_0202A420  0x0202A420  thumb
 *   func_02013734  0x02013734  thumb
 *   func_02013644  0x02013644  thumb
 *   func_020136E0  0x020136E0  thumb
 *   func_02013610  0x02013610  thumb
 *   func_02013678  0x02013678  thumb
 *   func_020136AC  0x020136AC  thumb
 *   func_021AA304  0x021AA304  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ctx { void *f00; u8 pad04[4]; void *f08; };
struct Info { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

extern void func_020130C4(u8 *p);
extern u32 func_0202A230(void *a, u32 idx);
extern u32 func_0202A420(u32 key);
extern void func_021AA304(struct Info *out, void *a1, void *a2);
extern void func_02013734(void *o, void *a1, struct Info *a2, u32 a3, void *a4, u32 a5, u16 a6);
extern void func_020136E0(void *o, void *a1, struct Info *a2, void *a3, u32 a4, u16 a5);
extern void func_02013644(void *p, void *a, struct Info *b, void *c, u16 d);
extern void func_02013610(void *p, void *a, struct Info *b, void *c, u16 d);
extern void func_02013678(void *p, void *a, struct Info *b, void *c, u16 d);
extern void func_020136AC(void *p, void *a, struct Info *b, void *c, u16 d);

void func_021AA5CC(struct Ctx *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap)
{
    struct Info info;
    void *x = ctx->f08;
    u32 r;

    func_020130C4(a1);
    func_021AA304(&info, ctx->f08, ctx->f00);
    r = func_0202A420(func_0202A230(mon, 1));
    if (r != 0x11) {
        info.f04 = r;
    }
    switch (mode) {
    case 1:
        if (flag) {
            func_02013734(a1, x, &info, flag, mon, a5, heap);
        } else {
            func_02013644(a1, x, &info, mon, heap);
        }
        return;
    case 0:
        if (a5) {
            func_020136E0(a1, x, &info, mon, a5, heap);
        } else {
            func_02013610(a1, x, &info, mon, heap);
        }
        return;
    case 2:
        func_02013678(a1, x, &info, mon, heap);
        return;
    case 3:
        func_020136AC(a1, x, &info, mon, heap);
        return;
    }
}
