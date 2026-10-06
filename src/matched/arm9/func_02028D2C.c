/*
 * unit:     yes
 * function: func_02028D2C
 * address:  0x02028D2C
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c: drain and re-arm.  Runs func_020293D8 until the
 * pending counter at +0x20 falls to zero, closes the frame with
 * func_02005D28, and then re-initialises the system from the descriptor the
 * caller passed, through the same func_02028CD4 the constructor uses.
 *
 * Nothing branches to this function anywhere in the image; its only reference
 * is the pool word of the forwarder at 0x02028A50, so the `label` class
 * cannot see it and src/matched/func_02028A50.c is EXACT only because this
 * file is a `matched` witness for it.
 *
 * symbols:
 *   func_020293D8  0x020293D8  thumb
 *   func_02005D28  0x02005D28  thumb
 *   func_02028CD4  0x02028CD4  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028D2C.c \
 *       --func func_02028D2C --addr 0x02028D2C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sys {
    u8  pad_00[0x20];
    u32 pending;   /* 0x20 */
};

struct T;
extern void func_020293D8(struct T *p);
extern void func_02005D28(void);
extern void func_02028CD4(u8 *p, u32 v);

void func_02028D2C(struct Sys *s, void *desc)
{
    while (s->pending != 0) {
        func_020293D8((struct T *)s);
    }
    func_02005D28();
    func_02028CD4((u8 *)s, (u32)desc);
}
