/*
 * unit:     no
 * function: sub_0204D2DC
 * address:  0x0204D2DC
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   sub_02066B38  0x02066B38  arm
 *   sub_02082BCC  0x02082BCC  arm
 *
 * Destructor for one variant of the 0x7c-byte 0x0204Cxxx/0x0204Dxxx
 * object: release the sub-resource whose handle lives at +0x64, then wipe
 * the whole record.  0x02082BCC is the SDK's byte fill (dest, value,
 * length); the 0x7c length is the object's own size, which the sibling
 * sub_0204D300 repeats verbatim for the +0x78 variant.
 *
 * Byte-correct, capped at MATCH: the PC24 site at +0x0c names 0x02066B38
 * and this is that address's only branch site anywhere in the image, so
 * `label` has nothing to point at and no split can create one from a
 * single function.  It unsticks when 0x02066B38 is itself decompiled to
 * EXACT and becomes a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D2DC.c \
 *       --func sub_0204D2DC --addr 0x0204D2DC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8    pad_00[0x64];
    void *unk_64;
};

extern void sub_02066B38(void *p);
extern void sub_02082BCC(void *dst, int value, u32 len);

void sub_0204D2DC(struct Obj *o)
{
    sub_02066B38(o->unk_64);
    sub_02082BCC(o, 0, 0x7c);
}
