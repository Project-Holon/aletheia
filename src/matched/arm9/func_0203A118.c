/*
 * function: func_0203A118
 * address:  0x0203A118
 * packet:   pkt_0203A118
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Conditional state repair: when the context's +0x352 flag is clear the
 * object's +0x4A state is only pushed to 7 if it is not already 5, otherwise
 * 7 is stored unconditionally.  The `!= 0` arm is the branch and the `== 0`
 * arm is the fall-through, so that polarity is the source order; the inner
 * store is the conditional `movne`/`strbne` pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A118.c \
 *       --func func_0203A118 --addr 0x0203A118 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);

void func_0203A118(u8 *p)
{
    if (*(u8 *)((char *)func_0203D788() + 0x352) == 0) {
        if (p[0x4A] != 5)
            p[0x4A] = 7;
    } else {
        p[0x4A] = 7;
    }
}
