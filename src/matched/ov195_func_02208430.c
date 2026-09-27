/*
 * function: func_02208430
 * address:  0x02208430
 * packet:   pkt_02208430
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0220826C 0x0220826C thumb ov195
 *   func_0220827C 0x0220827C thumb ov195
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

extern int func_0220826C(Fade *p, int x);
extern void func_0220827C(Fade *p, int x);

void func_02208430(Fade *p, int x)
{
    switch (p->state) {
    case 0:
    case 1:
        break;
    case 2:
        if (func_0220826C(p, x))
            p->state = 3;
        break;
    case 3:
    case 4:
        break;
    case 5:
        if (func_0220826C(p, x))
            p->state = 0;
        break;
    }
    func_0220827C(p, x);
}
