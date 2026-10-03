/*
 * function: func_02012444
 * address:  0x02012444
 * packet:   pkt_020123D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * sat at MATCH on the pool word at +0x2C, which holds 0x0201240D - the state
 * machine at 0x0201240C with its Thumb bit, handed to sub_020122C0 as a
 * callback.  That word is the only one in the image naming 0x0201240D, and no
 * branch reaches 0x0201240C from outside this range either, so the site needed
 * 0x0201240C to be an EXACT entry of its own; now that it is, the site
 * resolves through the `matched` class and this file needs no change.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012444.c \
 *       --func func_02012444 --addr 0x02012444 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Desc;

extern struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size);
extern u32 *sub_020124E8(struct Desc *d);
extern void func_02012374(void *evt, void **out);
extern int func_0201240C(void *o, u32 *state, u32 *item);

struct Obj {
    u8    pad_00[0x10];
    void *unk_10;
};

void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3)
{
    struct Desc *d;
    u32 *p;

    d = sub_020122C0(obj->unk_10, 0, func_0201240C, 0xc);
    p = sub_020124E8(d);
    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    func_02012374(obj, (void **)d);
}
