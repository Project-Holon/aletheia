/*
 * function: func_021C1FE8
 * address:  0x021C1FE8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Adds d to each halfword of the w x h block at +0x0C, where w and h are
 * the two header halfwords at +0 and +2 shifted right by three.
 *
 * The register split is a source-shape fact, not allocator taste.  Reading
 * the header into named u16 locals first (`w0 = p[0]; h0 = p[1];`) and only
 * then shifting into the int sizes (`(u32)w0 >> 3`) is what gives the
 * image's two-instruction prologue tail - the raw halfwords stay in r1/r0
 * while the shifts write fresh r3/r7, and r1 is then free for the i
 * counter.  Shifting straight off `p[0] >> 3` reuses r1 for the width and
 * pushes i into r2, seven register-name residues over 14 bytes.
 * The (u32) cast on the shifted operand is required for `lsrs` (a bare
 * u16-promoted shift gives `asrs`), and the int counters keep the two
 * signed `ble`/`blt` the image has.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

void func_021C1FE8(u16 *p, u16 d)
{
    u16 *q = (u16 *)((u8 *)p + 0xC);
    u16 w0 = p[0];
    u16 h0 = p[1];
    int i, j;
    int w = (u32)w0 >> 3;
    int h = (u32)h0 >> 3;

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            q[i * w + j] += d;
        }
    }
}
