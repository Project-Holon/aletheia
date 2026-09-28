/*
 * function: func_0203FC6C
 * address:  0x0203FC6C
 * packet:   pkt_0203FC6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_0207D518  0x0207D518  arm
 *
 * bg_sys.c, the two-way forwarder that sits immediately above
 * func_0203FCA0.  Both arms are a single nested call whose result is
 * handed straight on and then dropped, so the function is void and
 * needs no callee-saved register: `push {r3, lr}` is the eight-byte
 * stack alignment pad, not a saved argument.
 *
 * The `ldm r2, {r0, r1}` in the first arm is two adjacent fields loaded
 * as two consecutive arguments, not a struct copy; writing the two
 * field reads as separate arguments to the same call is what folds them
 * into the load-multiple.
 */

typedef unsigned int u32;

struct BgVramReq {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

extern u32 func_0207D4B0(u32 a, u32 b, u32 c);
extern u32 func_0207D518(u32 a);
extern void func_020434CC(u32 handle);
extern void func_02043588(u32 handle);

void func_0203FC6C(const struct BgVramReq *req, u32 which)
{
    if (which == 0) {
        func_020434CC(func_0207D4B0(req->unk_00, req->unk_04, req->unk_0c));
    } else {
        func_02043588(func_0207D518(req->unk_08));
    }
}
