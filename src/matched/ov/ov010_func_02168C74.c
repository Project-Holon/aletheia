/*
 * function: func_02168C74
 * address:  0x02168C74
 * packet:   pkt_ov010_02168C74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Battle state step: state 0 starts the request and moves to state 1; state 1 releases the
 * object and stores the result flag. The flag store is written in each arm of the if/else
 * (2026-10-05 recoup), which keeps the store before the epilogue add sp.
 *
 * symbols:
 *   func_02167EF4  0x02167EF4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 *fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    u32 f30;
} C;

extern int func_02167EF4(int, int, int, int, int, int *, int *, int *, int);
extern void func_02012374(int, int);
extern void func_020307B0(int);


int func_02168C74(int a, int *b, C *c)
{
    int r0 = c->f0;
    switch (*b) {
    case 0: {
        int t = func_02167EF4(r0, c->f10, 0x17, c->f14, c->f18, &c->f28, &c->f20, &c->f24, *(int *)(c->f30 + 0x128));
        func_02012374(a, t);
        *b = 1;
        break;
    }
    case 1:
        if (c->f1c != 0)
            func_020307B0(c->f1c);
        if (c->f24 != 0 || (u32)(c->f20 - 7) <= 1)
            *c->fc = 0;
        else
            *c->fc = 1;
        return 1;
    }
    return 0;
}
