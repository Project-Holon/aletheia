/*
 * function: FRAME_LIST_StartJump
 * address:  0x021B8DF0
 * packet:   pkt_ov067_021B8DF0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FRAME_LIST_GetScrollRoom  0x021B841C  thumb
 *   FRAME_LIST_StartScroll  0x021B8434  thumb
 *
 * Note: the second parameter of FRAME_LIST_StartScroll is declared int here (its own
 * file has u8): the original passes the muls result untruncated.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct S {
    u8 _0[0xb];
    s8 fb;
    s8 fc;
    s8 fd;
    s8 fe;
    u8 _f[0x62 - 0xf];
    s16 f62;
    u16 f64;
    u8 _66[0x85 - 0x66];
    s8 f85;
    u8 _86;
    u8 f87;
};

extern int FRAME_LIST_GetScrollRoom(u8 *p, int n);
extern void FRAME_LIST_StartScroll(u8 *p, int a, u8 b, u16 c, u32 d);

int FRAME_LIST_StartJump(struct S *s, int a1)
{
    int d;
    int v;
    u32 lim;

    d = s->f87 - a1;
    if ((d < 0 && s->f85 > 0) || (d > 0 && s->f85 < 0))
        return 0;
    if ((s->f85 < 0 && s->f62 == 0) || (s->f85 > 0 && s->f62 == s->f64))
        return 0;
    if (d < 0)
        d = -d;
    if (d == 0)
        return 0;
    if (d == 1)
        v = s->fe;
    else if (d == 2)
        v = s->fd;
    else if (d == 3)
        v = s->fc;
    else
        v = s->fb;
    if (a1 > s->f87)
        v *= -1;
    lim = FRAME_LIST_GetScrollRoom((u8 *)s, v);
    if (lim != 0) {
        if (lim < d)
            d = lim;
        FRAME_LIST_StartScroll((u8 *)s, v, d, 3, 1);
        s->f87 = a1;
        return 1;
    }
    return 0;
}
