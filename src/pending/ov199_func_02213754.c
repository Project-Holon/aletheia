/*
 * function: func_02213754
 * address:  0x02213754
 * packet:   pkt_02213754
 * region:   ov199
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   veneer_02031330  0x02031330  arm
 *   veneer_02031348  0x02031348  arm
 *
 * blocker: codegen only, same 172-byte size, 82 concrete bytes differ. All
 *   relocations resolve. The original keeps the state byte's switch value in
 *   r1 and the dispatch index in r1/r2; this source gets r0/r1 because the
 *   dead argument register r0 is reused. Case 1's base pointer then lands in
 *   r5 instead of r2, shifting every later register, and the early `return 0`
 *   is duplicated rather than shared. Blocked on that first register choice.
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

extern int veneer_02031330(int);
extern int veneer_02031348(int, int, int, int);

int func_02213754(S *s)
{
    switch (s->f1b) {
    case 0:
        s->f18 = s->f1a;
        s->f1a = s->f19;
        s->f1b = 1;
        break;
    case 1: {
        int (*r)(int, int);
        int *e;
        int v;
        r = *(int (**)(int, int))((char *)s->f10 + (s->f1a << 4) + 8);
        if (r)
            v = r(s->f8, s->fc);
        else
            v = 0;
        s->f4 = v;
        e = (int *)((char *)s->f10 + (s->f1a << 4));
        veneer_02031348(s->f0, e[0], e[1], s->f4);
        s->f1b = 2;
        break;
    }
    case 2:
        s->f1c = veneer_02031330(s->f0);
        if (s->f1c == 0)
            s->f1b = 3;
        break;
    case 3: {
        int (*h)(int, int);
        h = *(int (**)(int, int))((char *)s->f10 + (s->f1a << 4) + 0xc);
        if (h) {
            if (h(s->f4, s->fc) == 0)
                return 0;
            s->f4 = 0;
        }
        s->f1b = 4;
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
