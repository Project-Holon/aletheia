/*
 * function: FRAME_LIST_StartFlick
 * address:  0x021B8EA0
 * packet:   pkt_ov067_021B8EA0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * pass 2 2026-10-06 P2L28: EXACT (was DIFF 14/256 in X8 and G4L7). The fix is the callee
 *   declaration that the matched ov067 callers 021B8B74 and 021B806C use: FRAME_LIST_StartScroll takes
 *   `s8 a`, and v is an s8 local. With `int a` the 1 for the stack argument was placed after
 *   the u8 narrowing of d; with s8 it is stored first, as in the image. EXACT in c99 and c.
 *
 * symbols:
 *   FRAME_LIST_GetScrollRoom  0x021B841C  thumb  ov067
 *   FRAME_LIST_StartScroll  0x021B8434  thumb  ov067
 *   gFrameListFlickSteps     0x021B94F8  data   ov067  a1
 *   gFrameListFlickThresholds     0x021B94FE  data   ov067  a1
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 _0[0xb];
    s8 fb[6];
    u8 _11[0x70 - 0x11];
    u32 f70;
    u8 _74[0x85 - 0x74];
    s8 f85;
    u8 f86 : 5;
    u8 f86_5 : 3;
    u8 _87[0x89 - 0x87];
    u8 f89;
    u8 _8a[0x8c - 0x8a];
    u32 f8c;
    u32 f90;
};

extern const u8 gFrameListFlickSteps[6];
extern const u8 gFrameListFlickThresholds[][6];

extern int FRAME_LIST_GetScrollRoom(u8 *p, int n);
extern void FRAME_LIST_StartScroll(struct S *s, s8 a, u8 b, u16 c, u32 d);

int FRAME_LIST_StartFlick(struct S *s)
{
    u32 d;
    s8 v;
    int lim;

    if ((s->f85 < 0 && s->f90 > s->f8c) || (s->f85 > 0 && s->f90 < s->f8c))
        return 0;
    d = s->f90 - s->f8c;
    if ((int)d < 0)
        d = -d;
    if (d == 0)
        return 0;
    for (s->f89 = 0; s->f89 < 6; s->f89++) {
        if (d >= gFrameListFlickThresholds[s->f86][s->f89]) {
            v = s->fb[s->f89];
            d = gFrameListFlickSteps[s->f89];
            break;
        }
    }
    if (s->f89 == 6)
        return 0;
    if (s->f8c > s->f90)
        v *= -1;
    lim = FRAME_LIST_GetScrollRoom((u8 *)s, v);
    if (lim != 0) {
        if (lim < d)
            d = lim;
        FRAME_LIST_StartScroll(s, v, d, 3, 1);
        s->f70 = 1;
        return 1;
    }
    return 0;
}
