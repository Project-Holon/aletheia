/*
 * function: SHINKA_DEMO_VIEW_IsGridFadeDone
 * address:  0x0220826C
 * packet:   pkt_0220826C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

int SHINKA_DEMO_VIEW_IsGridFadeDone(Fade *p, int x)
{
    if (p->step == 0)
        return 1;
    return 0;
}
