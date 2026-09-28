/*
 * unit:     no
 * function: sub_0204D300
 * address:  0x0204D300
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020307B0  0x020307B0  arm
 *   sub_02082BCC  0x02082BCC  arm
 *
 * The sibling of sub_0204D2DC: same destructor shape for the variant whose
 * owned resource hangs off +0x78 and is freed through the heap entry point
 * at 0x020307B0 rather than 0x02066B38.  The trailing wipe is the same
 * 0x7c-byte object fill.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D300.c \
 *       --func sub_0204D300 --addr 0x0204D300 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8    pad_00[0x78];
    void *unk_78;
};

extern void sub_020307B0(void *p);
extern void sub_02082BCC(void *dst, int value, u32 len);

void sub_0204D300(struct Obj *o)
{
    sub_020307B0(o->unk_78);
    sub_02082BCC(o, 0, 0x7c);
}
