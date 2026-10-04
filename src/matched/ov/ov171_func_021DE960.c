/*
 * function: func_021DE960
 * address: 0x021DE960
 * packet: pkt_ov171_021DE960
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Four signed bounds are computed before clamping; the guarded do loop
 *   saves start only after its unsigned entry guard. Separate sentinel and
 *   explicit selection arms retain the original best-index register web.
 *   Listing after the 228-byte function and pool is rodata from 021DEA44.
 * symbols:
 *   func_021DE0E4  0x021DE0E4  thumb ov171
 *   func_021DE5F4  0x021DE5F4  thumb ov171
 *   func_02035D20  0x02035D20  arm
 *   func_0209C0A4  0x0209C0A4  arm
 */

typedef unsigned short u16;
typedef signed short s16;

extern unsigned int func_02035D20(unsigned int *, unsigned int *);
extern int func_021DE5F4(char *);
extern void func_021DE0E4(unsigned char *, int, s16 *, s16 *);
extern int func_0209C0A4(int, int);

int func_021DE960(char *obj)
{
    unsigned int out1;
    unsigned int out2;
    s16 win[2];
    s16 p1;
    s16 p2;
    s16 bestX;
    int start;
    int best;
    int sentinel;
    unsigned int end;
    int i;

    if (func_02035D20(&out1, &out2) == 0)
        return 0xff;

    i = (s16)func_021DE5F4(obj);
    best = -1;
    sentinel = -1;
    end = i + 6;

    if ((unsigned int)i < end) {
        start = i;
        do {
            if (*(int *)(obj + 0x0b74 + i * 4) != 0) {
                func_021DE0E4((unsigned char *)obj, i, &win[1], &win[0]);

                p1 = win[1];

                {
                    s16 lo, hi, ylo, yhi;

                    lo = p1 - 0x30;
                    hi = p1 + 0x30;
                    p2 = win[0];
                    ylo = p2 - 0x30;
                    yhi = p2 + 0x30;
                    if (lo < 0) lo = 0;
                    if (hi > 0xff) hi = 0xff;
                    if (ylo < 0) ylo = 0;
                    if (yhi > 0xff) yhi = 0xff;

                    if (out1 < lo) continue;
                    if (out1 >= hi) continue;

                    if (out2 < ylo) continue;
                    if (out2 >= yhi) continue;
                }

                if (best == sentinel) {
                    bestX = p2;
                    best = (s16)(i - start);
                } else if (p2 > bestX) {
                    bestX = p2;
                    best = (s16)(i - start);
                }
            }
        } while ((unsigned int)++i < end);
    }

    if (best != -1)
        return (best % 6) + 5;
    else
        return 0xff;
}
