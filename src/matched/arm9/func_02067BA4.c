/*
 * function: NNS_G2dRndCoreBeginRendering
 * address:  0x02067BA4
 * packet:   pkt_02067BA4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PIN: ../2.0/sp2, the "kept constants" tell.  The image rematerialises the
 * index-0 argument fresh at each of the four table calls (`mov r1, #0` at
 * 0x02067BC8, 0x02067C18, 0x02067C2C, 0x02067C4C) and stores each call's
 * result straight from r0 (`str r0, [r4, #0x14]` / `str r0, [r4, #0x18]`),
 * which is why the frame is `push {r3, r4, r5, lr}` (`38 40 2d e9`).
 * 1.1p1 -O4,p CSEs the zero into a callee-saved register, needing a fourth
 * (`push {r4, r5, r6, lr}`) and spending `mov r4, r0` / `mov r6, r0` copies
 * before each store: 276 bytes against the original's 268, 191 concrete out
 * with the whole tail shifted by eight.  Under the pin the same C is 268
 * bytes, 0 mismatches.
 *
 * symbols:
 *   sRndCoreInstance    0x02148B48  data
 *   func_020637BC 0x020637BC  arm
 *   func_020637B4 0x020637B4  arm
 *   func_0206380C 0x0206380C  arm
 *   func_02063800 0x02063800  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Inner {
    int x;        /* 0x00 */
    int y;        /* 0x04 */
    u8  pad_08[0x0c];
    int mode;     /* 0x14 */
};

struct Ctx {
    struct Inner *inner;  /* 0x00 */
    u8   pad_04[4];
    void *ta;             /* 0x08 */
    void *tb;             /* 0x0c */
    int  out10;           /* 0x10 */
    int  out14;           /* 0x14 */
    int  out18;           /* 0x18 */
    u8   pad_1c[4];
    int  shcfg;           /* 0x20 */
};

extern struct Ctx *sRndCoreInstance;

extern int func_020637BC(const u32 *p, u32 i);
extern int func_020637B4(int *p, int i);
extern int func_0206380C(char *p, int i);
extern int func_02063800(char *p, int i);

void NNS_G2dRndCoreBeginRendering(struct Ctx *c)
{
    volatile u32 *reg = (volatile u32 *)0x04000440;
    struct Ctx *p = c;
    int n;

    sRndCoreInstance = p;

    n = p->inner->mode;
    if (n == 0) {
        struct Inner *in;
        void *ta, *tb;

        reg[0] = 0;
        reg[1] = 0;
        in = p->inner;
        {
            int x = in->x;
            int y = in->y;
            reg[12] = -x;
            reg[12] = -y;
        }
        reg[12] = 0;
        reg[0] = 1;

        ta = sRndCoreInstance->ta;
        p->out14 = func_020637BC(ta, 0) ? func_020637B4(ta, 0) : 0;

        tb = sRndCoreInstance->tb;
        p->out18 = func_0206380C(tb, 0) ? func_02063800(tb, 0) : 0;
    } else {
        struct Ctx *t = (struct Ctx *)p->ta;
        int r;

        if (func_020637BC((const u32 *)t, n)) {
            r = func_020637B4((int *)t, n);
            r = (int)((u32)r >> ((int)((t->shcfg & 0x700000) >> 20) + 5));
        } else {
            r = 0;
        }
        sRndCoreInstance->out10 = r;
    }
}
