/*
 * function: GF_STANDARD_SeedLcg64
 * address:  0x0203F258
 * packet:   pkt_0203F258
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02088168  0x02088168  arm
 *   sub_020813D8  0x020813D8  arm
 *   sub_0208142C  0x0208142C  arm
 *   sub_020814C0  0x020814C0  arm
 *   sub_02082D44  0x02082D44  arm
 *
 * gf_standard.c: seed a 64-bit LCG from a hash of fresh entropy
 * (docs/families/gf_standard.h).  The output record is THREE u64s, not six
 * u32s: { x, mul = 0x5D588B656C078965, add = 0x269EC3 }, the standard
 * 64-bit LCG constants.  Written as four u32 stores the constants are
 * coloured r1/r0 instead of r0/r1 (the 8-byte residue of
 * docs/notes/pkt_0203F258.c.txt); written as two u64 stores the compiler
 * pairs each low/high half and it is byte-exact.  Reached only as a
 * function pointer (pool word 0x020056CC).
 */
#include "../include/Obj16002.h"
typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned long long u64;

struct Lcg64 {
    u64 x;
    u64 mul;
    u64 add;
};

extern void sub_02088168(u32 *buffer);
extern void sub_020813D8(void *p);
extern void sub_0208142C(void *ctx, void *buf, u32 n);
extern void sub_020814C0(void *ctx, void *out);
extern void sub_02082D44(void *in, void *out, u32 n);

void GF_STANDARD_SeedLcg64(struct Lcg64 *out)
{
    u8 a[8];
    u8 c[0x20];
    u8 b[0x14];
    u8 d[0x60];

    sub_02088168((u32 *)c);
    sub_020813D8(d);
    sub_0208142C(d, b, 0x14);
    sub_0208142C(d, c, 0x20);
    sub_020814C0(d, b);
    sub_02082D44(b, a, 8);
    out->x = ((struct Obj16002 *)a)->f0;
    out->mul = 0x5D588B656C078965ULL;
    out->add = 0x269EC3;
}
