/*
 * function: func_021C295C
 * address:  0x021C295C
 * packet:   pkt_021C295C
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294 0x0204B294 arm
 */

struct arg_021C295C {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
};

extern int func_0204B294(int, int, int, int, struct arg_021C295C *, int, int);

void func_021C295C(unsigned char *p)
{
    struct arg_021C295C s;
    int *q = (int *)(p + 0x20);
    int i;

    s.a = 0;
    s.b = 0;
    s.c = 0;
    s.d = 0;
    s.e = 0;
    for (i = 0; i < 4; i++) {
        *(int *)(p + 0x10 + i * 4) =
            func_0204B294(*(int *)(p + 0xc), q[0], q[1], q[2], &s,
                          *(unsigned short *)((unsigned char *)q + 0xc),
                          *(unsigned short *)p);
    }
}
