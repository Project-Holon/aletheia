/*
 * function: func_02047B4C
 * address:  0x02047B4C
 * packet:   pkt_020479D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02047788  0x02047788  arm
 *   func_0204755C  0x0204755C  arm
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_02047C04  0x02047C04  arm
 *
 * Copy the six s16 of the sub-record at +0x18..0x22 into a local, register
 * it via func_0206DDA4 (the three-argument command/buffer/count shape of
 * src/matched/func_0206A884.c), broadcast the +0x24 word into a three-word
 * buffer, hand the halfword block to func_02047C04, and report failure as
 * zero.  The `+ 0x14` is folded with a null test on the owning pointer, so
 * a null owner leaves the base at zero rather than at 0x14.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
typedef signed short   s16;

struct Rec {
    u32 pad_00[6];
    s16 f18;
    s16 f1a;
    s16 f1c;
    s16 f1e;
    s16 f20;
    s16 f22;
    u32 f24;
};

struct Owner {
    u32 pad_00;
    struct Rec *rec;
};

struct Block {
    s16 f00;
    s16 f02;
    s16 f04;
    s16 f06;
    s16 f08;
    s16 f0a;
};

extern void         *func_02047788(void *p);
extern struct Owner *func_0204755C(void *p);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern int           func_02047C04(void *p);

int func_02047B4C(void *a0)
{
    struct Block blk;
    u32 buf[3];
    int one;
    struct Rec *r;
    char *p;
    int ret;

    ret = 1;
    p = (char *)func_0204755C(func_02047788(a0))->rec;
    r = (struct Rec *)(p != 0 ? p + 0x14 : 0);

    blk.f00 = r->f18;
    blk.f02 = r->f1a;
    blk.f04 = r->f1c;
    blk.f06 = r->f1e;
    blk.f08 = r->f20;
    blk.f0a = r->f22;
    func_0206DDA4(0x11, 0, 0);

    buf[0] = r->f24;
    buf[1] = buf[0];
    buf[2] = buf[0];
    func_0206DDA4(0x1B, buf, 3);

    if (func_02047C04(&blk) == 0) {
        ret = 0;
    }

    one = 1;
    func_0206DDA4(0x12, &one, 1);
    return ret;
}
