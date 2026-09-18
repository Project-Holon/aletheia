/*
 * function: func_0204F5E4
 * address:  0x0204F5E4
 * packet:   pkt_0204F344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Read the record's low-14-bit field out to the caller's halfword.  Its
 * lsl #18 / lsr #18 pair is the same 14-bit bitfield as func_0204F5A8.
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it.
 *
 * symbols:
 *   none (no external calls, no data references)
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 lo : 14;
    u16 hi : 2;
};

void func_0204F5E4(void *p, u32 idx, u16 *dst)
{
    struct Rec *r = (struct Rec *)(*(u8 **)((u8 *)p + 8) + idx * 0x1c);

    *dst = r->lo;
}
