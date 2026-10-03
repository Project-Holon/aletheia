/*
 * function: func_02071510
 * address:  0x02071510
 * packet:   pkt_020713C8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Flushes the object's dirty transform components to func_0206DDA4, one
 * call per component group, each gated by a bit of the flag word at +0x00.
 * Bits 3/4 (mask 0x18) select whether the rotation block is sent raw or the
 * translation is pre-scaled by the 1.12 factors at +0x4c; bit 2 suppresses
 * the scaled translation, bit 1 selects the long (0xc) over the short (9)
 * matrix push, and bit 0 suppresses the final component push.
 *
 * Pinned to ../2.0/sp2: see docs/FRONTEND-PINS.md, the "kept branches" tell.
 *
 * symbols:
 *   func_0206DDA4    0x0206DDA4  arm
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02071510.c \
 *       --func func_02071510 --addr 0x02071510 --cc ../2.0/sp2 --arm
 */

typedef unsigned int u32;

struct Obj {
    u32 flags;            /* +0x00 */
    int a[3];             /* +0x04 */
    int b[3];             /* +0x10 */
    int c[3];             /* +0x1c */
    int pad28[9];         /* +0x28 */
    volatile int s[3];    /* +0x4c */
};

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);

void func_02071510(struct Obj *o)
{
    int tmp[3];
    int flag = 0;
    int m;

    m = o->flags & 0x18;
    if (m == 0)
        func_0206DDA4(0x1b, &o->c[0], 3);

    if (!(o->flags & 4)) {
        if (m != 0) {
            flag = 1;
        } else {
            tmp[0] = (int)(((long long)o->s[0] * o->b[0]) >> 12);
            tmp[1] = (int)(((long long)o->s[1] * o->b[1]) >> 12);
            tmp[2] = (int)(((long long)o->s[2] * o->b[2]) >> 12);
            func_0206DDA4(0x1c, tmp, 3);
        }
    }

    if (!(o->flags & 2)) {
        if (flag) func_0206DDA4(0x19, &o->pad28[0], 0xc);
        else      func_0206DDA4(0x1a, &o->pad28[0], 9);
    } else if (flag) {
        func_0206DDA4(0x1c, (void *)&o->s[0], 3);
    }

    if (m == 0)
        func_0206DDA4(0x1b, &o->b[0], 3);

    if (!(o->flags & 1))
        func_0206DDA4(0x1b, &o->a[0], 3);
}
