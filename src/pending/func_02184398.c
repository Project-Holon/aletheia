/*
 * function: func_02184398
 * address:  0x02184398
 * packet:   pkt_02184398
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Blocker: register allocation.  The original spills c to [sp+4] and keeps
 *   the 0x120 size in r6 through the two calls, deriving p[2] with
 *   `subs r6,#0x20`; mwcc constant-folds size - 0x20 and keeps c in r7.
 *
 * symbols:
 *   d_02184A20      0x02184A20  data
 *   func_02006CBC   0x02006CBC  thumb
 *   func_02006D94   0x02006D94  thumb
 *   func_02034F84   0x02034F84  arm
 *   func_02030734   0x02030734  arm
 *   func_02082BCC   0x02082BCC  arm
 *
 * Allocate a 0x120-byte work buffer through 0x2030734 and lay out the
 *   object that 0x218441C polls.
 */


extern unsigned char d_02184A20[];
extern void func_02006CBC(int);
extern int func_02006D94(void);
extern void func_02034F84(int);
extern int *func_02030734(int, int, int, void *, int);
extern void func_02082BCC(int *, int, int);

void func_02184398(int *p, int a, int b, int c)
{
    unsigned int size = 0x120;
    int n;
    func_02006CBC((unsigned short)a);
    func_02034F84(8);
    n = (int)func_02030734((unsigned short)a, size, 0, d_02184A20, 0x603);
    func_02082BCC((int *)n, 0, size);
    p[7] = n;
    p[0] = 0;
    p[1] = (n + 0x1f) & ~0x1f;
    p[3] = 0x1001;
    p[4] = 1;
    p[2] = size - 0x20;
    p[5] = b;
    p[6] = c;
    p[13] = func_02006D94();
}
