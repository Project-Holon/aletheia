/*
 * function: func_021D6B04
 * address:  0x021D6B04
 * packet:   pkt_ov016_021D6B04
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      DWCi_TPlCheckATrigger (libdwcutil.TWL.HYB.a input.o)
 *
 * symbols:
 *   func_021D696C  0x021D696C  arm  ov016
 */

typedef struct tagAREA { unsigned short x, y, w, h; } AREA;
typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

extern int func_021D696C(RECT *r);

static inline void InputRect(RECT *r, int l, int t, int rr, int b)
{
    r->l = l;
    r->t = t;
    r->r = rr;
    r->b = b;
}

static inline void Area2Rect(AREA *a, RECT *r)
{
    r->l = a->x;
    r->t = a->y;
    r->r = a->x + a->w;
    r->b = a->y + a->h;
}

int func_021D6B04(AREA *a)
{
    RECT r;

    if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
        return 0;
    {
    int x = a->x;
    int y = a->y;
    int w = a->w;
    int h = a->h;
    InputRect(&r, x, y, x + w, y + h);
    }
    return func_021D696C(&r);
}
