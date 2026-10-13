/*
 * function: FRAME_LIST_StepScrollBarDrag
 * address:  0x021B8B74
 * packet:   pkt_ov067_021B8B74
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The listing extent runs on into an unlabelled leaf at 0x021B8C14 (filed
 * separately). The byte at +0xB is u8: the negated arm loads it with ldrb and
 * narrows to s8 after the negate, the other arm reads it as (s8) (ldrsb).
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   FRAME_LIST_GetScrollBarRow  0x021B8A44  thumb  ov067
 *   FRAME_LIST_StartScroll  0x021B8434  thumb  ov067
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct S {
    u8 _0[0xb];
    u8 fb;
    u8 _c[0x34 - 0xc];
    int f34;
    u8 _38[0x48 - 0x38];
    u8 f48;
    u8 _49[0x4e - 0x49];
    u16 f4e;
    u8 _50[0x62 - 0x50];
    s16 f62;
    u8 _64[0x74 - 0x64];
    u32 f74;
    u8 _78[0x7f - 0x78];
    u8 f7f;
    int f80;
};

struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int TOUCHPANEL_HitCont(const void *p);
extern u32 FRAME_LIST_GetScrollBarRow(struct S *s);
extern void FRAME_LIST_StartScroll(u8 *p, int a, u8 b, u16 c, u32 d);

int FRAME_LIST_StepScrollBarDrag(struct S *s)
{
    u32 x;
    u32 d;

    if (func_0201C6B4((const struct PrintSys *)s->f34) == 0)
        return 1;
    if (TOUCHPANEL_HitCont(&s->f74) == -1 && s->f80 == -1) {
        s->f7f = 0;
        s->f4e = 0;
        return 0;
    }
    x = FRAME_LIST_GetScrollBarRow(s);
    d = s->f62 - x;
    if ((int)d < 0)
        d = -d;
    if (d > s->f48)
        d = s->f48;
    if (s->f62 > x) {
        s->f62 = x + d;
        FRAME_LIST_StartScroll((u8 *)s, (s8)(-s->fb), d, 2, 1);
    } else if (s->f62 < x) {
        s->f62 = x - d;
        FRAME_LIST_StartScroll((u8 *)s, (s8)s->fb, d, 2, 1);
    }
    return 1;
}
