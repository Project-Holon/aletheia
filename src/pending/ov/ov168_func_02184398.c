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
 * Blocker: one register-pair colouring, 18 bytes.  The plain `unsigned int
 *   size = 0x120;` lets mwcc constant-fold `size - 0x20` and drop the live
 *   size register, so c stays in r7 and no stack spill appears (104/93 out).
 *   Typing size as an enum (typedef enum { SIZE_0 = 0x120 } SizeE) keeps it
 *   out of constant folding: the compile now emits `subs rN, #0x20` and
 *   compiles to the image's 112 bytes.  The only residue left is which of the
 *   two callee-saved webs gets r4: the image puts the narrowed `a`/`n` in r4
 *   and size in r6, mwcc does the mirror (a/n r6, size r4).  Everything else,
 *   including both `(unsigned short)a` narrowings (func_02006CBC and
 *   func_02030734 declared with an unsigned short first parameter), is exact.
 *   Tried: size function-scope vs block-scope, before/after n, const size,
 *   const a, u16 a parameter -- all hold the r4/r6 swap or worse.
 *
 * Re-verified 2026-09-27 (region ov168 / Thumb confirmed): still 112/112 with
 *   the same 18 bytes, i.e. the one r4/r6 web swap plus the four tail bytes.
 *   The detailed near-miss note is docs/notes/func_02184398.c.txt.
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
extern void func_02006CBC(unsigned short);
extern int func_02006D94(void);
extern void func_02034F84(int);
extern int *func_02030734(unsigned short, int, int, void *, int);
extern void func_02082BCC(int *, int, int);

typedef enum { SIZE_0 = 0x120 } SizeE;

void func_02184398(int *p, int a, int b, int c)
{
    func_02006CBC(a);
    func_02034F84(8);
    {
        int n;
        SizeE size = SIZE_0;
        n = (int)func_02030734((unsigned short)a, size, 0, d_02184A20, 0x603);
        func_02082BCC((int *)n, 0, size);
        p[7] = n;
        p[0] = 0;
        p[1] = (n + 0x1f) & ~0x1f;
        p[3] = 0x1001;
        p[4] = 1;
        p[2] = size - 0x20;
    }
    p[5] = b;
    p[6] = c;
    p[13] = func_02006D94();
}
