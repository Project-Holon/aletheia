/*
 * function: SHINKA_DEMO_VIEW_StepGridFade
 * address:  0x0220827C
 * packet:   pkt_0220827C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHINKA_DEMO_VIEW_ApplyGridPalette 0x022082DC thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Fade {
    u8 f00[0x28];
    int state;
    u16 pal[16];
    u16 color;
    s16 cur;
    s16 end;
    s16 wait;
    s16 step;
    s16 level;
    s16 count;
} Fade;

extern void SHINKA_DEMO_VIEW_ApplyGridPalette(Fade *p, int x);

void SHINKA_DEMO_VIEW_StepGridFade(Fade *p, int x)
{
    s16 step = p->step;
    s16 v;

    if (step == 0)
        return;
    if (p->count > 0) {
        p->count = p->count - 1;
        return;
    }
    p->level = p->level + step;
    v = p->level;
    if (v > 31)
        v = 31;
    else if (v < 0)
        v = 0;
    p->level = v;
    if (p->level == p->end)
        p->step = 0;
    else
        p->count = p->wait;
    SHINKA_DEMO_VIEW_ApplyGridPalette(p, x);
}
