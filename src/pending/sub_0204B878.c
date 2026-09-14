/*
 * function: sub_0204B878
 * address:  0x0204B878
 * packet:   pkt_0204B84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_0204D324  0x0204D324  arm
 *   func_0204B95C  0x0204B95C  arm
 *
 * Stores a 16-bit value at +0x5a of the object, then runs the sub-object at
 * +0x68 through func_0204D324 and re-runs the owner through func_0204B95C.
 * The same +0x68 sub-object is the one sub_0204B3B4 hands to func_0204D104.
 *
 * Blocked at MATCH: every concrete byte is right, but the PC24 site at
 * +0x10 (func_0204D324) has no witness.  sub_0204B878 is the only caller of
 * 0x0204D324 anywhere in the image, so `label` is unavailable, and the two
 * are not contiguous, so no unit can make the site `local`.  The remaining
 * route, an EXACT entry for 0x0204D324 itself as a `matched` witness, is
 * also closed: that function is
 *
 *     push {r3,lr}; ldr r3,[r0]; ldr r2,[pc,#8]
 *     ldr r2,[r2,r3,lsl #2]; blx r2; pop {r3,pc}; .word 0x020A13B8
 *
 * a handler-table dispatch whose table address 0x020A13B8 appears in no
 * other literal pool, so it can never be attested either.  Needs a second
 * caller of 0x0204D324 to appear (an overlay, most likely) before this can
 * become EXACT.  Its register allocation (r3/r2 rather than r2/r1) also
 * says it takes a second, forwarded argument in r1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Obj {
    u8  pad_00[0x5a];
    u16 unk_5a;
    u8  pad_5c[0x0c];
    u8  unk_68;
};

extern void func_0204D324(void *sub);
extern void func_0204B95C(struct Obj *p);

void sub_0204B878(struct Obj *p, u16 value)
{
    p->unk_5a = value;
    func_0204D324(&p->unk_68);
    func_0204B95C(p);
}
