/*
 * function: func_021FB4CC
 * address:  0x021FB4CC
 * packet:   pkt_ov186_021FB4CC
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Recursive MATCH unblocker: unresolved callee named by the parked
 * func_021FAD04.  Expands p[0] through the arm9 helper 0x0204B454 into two
 * signed shorts and tests the incoming ranges against p[5] and the +/-16
 * window around tmp[1].  The scratch is a raw 4-byte buffer so the two reads
 * stay register-addressed off sp.
 *
 * 2026-10-05: decoded the original as two unsigned range tests (u32)(v-lo) <= (u32)(hi-lo) with hi,lo unfolded: (a1-x) <= ((x+p5)-x) and (a2-(y-16)) <= ((y+16)-(y-16)), flag r7=0 set before the loads (its zero is reused as the ldrsh index). A static inline in_range(v,lo,hi) with s16 t[2] read at the use gives the unfolded second test but loads t[1] first and puts a2/a1 in the wrong registers; locals x,y fold the second test to cmp #0x20. Not closed.
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;

extern void func_0204B454(int, s16 *, int);

int func_021FB4CC(u32 *p, int a1, int a2)
{
    u8 tmp[4];
    int r7;
    int r0;

    func_0204B454(p[0], (s16 *)tmp, (u16)p[4]);
    r7 = ((a1 - *(s16 *)tmp) <= (int)p[5]) ? 1 : 0;
    r0 = ((a2 - (*(s16 *)(tmp + 2) - 16)) <= 32) ? 1 : 0;
    return r0 & r7;
}
