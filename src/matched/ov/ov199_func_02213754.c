/*
 * function: func_02213754
 * address: 0x02213754
 * packet: pkt_ov199_02213754
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: case 3 as if (h) { if (h(..) != 0) { f4 = 0; f1b = 4; } } else { f1b = 4; }
 * gives the lone branch to the next instruction; the case 1 second veneer
 * argument is written `f10 + 4 + (f1a << 4)` so its add follows the first load.
 * symbols:
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Push 0x02031348 arm
 */

typedef struct S {
    int f0;
    int f4;
    unsigned short f8;
    int fc;
    char *f10;
    int f14;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1a;
    unsigned char f1b;
    int f1c;
} S;

extern int PROCSYS_Main(int);
extern int PROCSYS_Push(int, int, int, int);

int func_02213754(S *s)
{
    switch (s->f1b) {
    case 0:
        s->f18 = s->f1a;
        s->f1a = s->f19;
        s->f1b = 1;
        break;
    case 1: {
        int (*r)(S *, int, int);
        r = *(int (**)(S *, int, int))((char *)s->f10 + (s->f1a << 4) + 8);
        if (r)
            s->f4 = r(s, s->f8, s->fc);
        else
            s->f4 = 0;
        PROCSYS_Push(s->f0,
                        *(int *)((char *)s->f10 + (s->f1a << 4)),
                        *(int *)((char *)s->f10 + 4 + (s->f1a << 4)),
                        s->f4);
        s->f1b = 2;
        break;
    }
    case 2:
        s->f1c = PROCSYS_Main(s->f0);
        if (s->f1c == 0)
            s->f1b = 3;
        break;
    case 3: {
        int (*h)(S *, int, int);
        h = *(int (**)(S *, int, int))((char *)s->f10 + (s->f1a << 4) + 0xc);
        if (h) {
            if (h(s, s->f4, s->fc) != 0) {
                s->f4 = 0;
                s->f1b = 4;
            }
        } else {
            s->f1b = 4;
        }
        break;
    }
    case 4:
        if (s->f19 == 0xff)
            s->f1b = 5;
        else
            s->f1b = 0;
        break;
    case 5:
        return 1;
    }
    return 0;
}
