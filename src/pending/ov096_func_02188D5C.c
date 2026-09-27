/*
 * function: func_02188D5C
 * address:  0x02188D5C
 * packet:   pkt_ov096_02188D5C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Blocker: codegen only, argument scheduling.  With the connection read
 *          through a struct (`Conn`) the compiler no longer CSEs the
 *          b+0xb4 address across the func_021D54C0 call, so the t web stays
 *          in r6 and r in r7 (frame 0x10, 164-byte shape, 162 bytes) instead
 *          of spilling r and growing the frame to 0x18 (168 bytes).  What is
 *          left is a two-instruction swap at +0x72 in the loop's second
 *          func_021C7E14 call: the original stores the 6th arg t to [sp,#4]
 *          *before* starting the b+0xb4 address computation, mwcc starts the
 *          address first and stores t one instruction later.  The first
 *          func_021C7E14 call schedules it the original way, so this is a
 *          context-dependent scheduler tie, not a source-shape residue.
 *          Tried: swapping the t/r declarations (no change), int vs unsigned
 *          item.  [re-verified 2026-09-27]
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021C7E14  0x021C7E14  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00;
    u8 f1;
    u16 f2;
    u8 pad04[0x38 - 4];
    int f38;
    u8 pad3C[0xb4 - 0x3c];
    int fb4;
    u8 padB8[0xbc - 0xb8];
    int fbc;
    int fc0;
    int fc4;
} Conn;

extern int func_0201134C(int);
extern int func_021D5440(int);
extern int func_021D5448(int);
extern int func_021D54C0(int, int);
extern int func_021C7E14(int, int, int, int, int, int);

int func_02188D5C(int a, Conn *b)
{
    int t;
    int y;
    int z;
    unsigned int r;
    int i;

    t = func_0201134C(a);
    y = func_021D5440(b->fbc);
    z = func_021D5440(b->fc0);
    r = func_021C7E14(b->fb4, y, z, b->f2, 1, t);
    if (r == 0) {
        b->f38 = 0;
    } else {
        b->f38 = 2;
        for (i = 0; i < func_021D5448(b->fbc); i++) {
            unsigned int item = func_021D54C0(b->fbc, (unsigned char)i);

            if (i == b->f1)
                continue;
            if (func_021C7E14(b->fb4, y, z, item, 1, t) > r) {
                b->f38 = 1;
                break;
            }
        }
    }
    return b->fc4;
}
