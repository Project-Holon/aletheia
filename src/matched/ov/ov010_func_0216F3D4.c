/*
 * function: func_0216F3D4
 * address:  0x0216F3D4
 * packet:   pkt_ov010_0216F3D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sums func_02008DFC over one seven-entry row of a u16 table (rows of 14
 * bytes at 0x02172620), stopping at the first zero entry and clamping the
 * running sum to cap.
 *
 * symbols:
 *   func_02008DFC  0x02008DFC  thumb
 *   d_02172620     0x02172620  data  a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Sub02008C20Obj;
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);
extern u16 d_02172620[][7];

u32 func_0216F3D4(void *p, int idx, u32 cap)
{
    u32 sum;
    int i;

    sum = 0;
    for (i = 0; i < 7; i++) {
        if (d_02172620[idx][i] == 0)
            break;
        sum += func_02008DFC(p, d_02172620[idx][i]);
        if (sum > cap)
            sum = cap;
    }
    return sum;
}
