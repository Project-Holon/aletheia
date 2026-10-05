/*
 * function: func_0203F6D8
 * address:  0x0203F6D8
 * packet:   pkt_0203F540
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   tbl_020A1B38   0x020A1B38  data
 *
 * The odd-halfword twin of func_0203F684: same signed `x % 360`, same
 * fixed-point multiply by 0xFFFF against the same 360, same `>> 4`, but the
 * table index is `2 * i + 1` instead of `2 * i`.  That difference shows up as
 * `lsl r0, r0, #1 / add r1, r0, #1 / lsl r1, r1, #1` before the `ldrsh`,
 * which is the shape of an index into a flat signed-halfword array, not of a
 * struct field access.
 *
 * EXACT*: every byte compares equal; the extent runs long only because the
 * follower is unlabelled (the listing's 144-byte extent covers this body,
 * the shared pool and the next function).  The table pointer resolves as
 * `literal` (x113).
 *
 * Addresses are Black-image addresses.
 */

typedef short s16;
typedef int   s32;

extern s16 tbl_020A1B38[];

s16 func_0203F6D8(s32 x)
{
    return tbl_020A1B38[2 * ((((x % 360) * 0xFFFF) / 360) >> 4) + 1];
}
