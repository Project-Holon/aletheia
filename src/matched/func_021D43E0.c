/*
 * function: func_021D43E0
 * address:  0x021D43E0
 * packet:   pkt_021D43E0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr prologue, hidden in the pool run after
 * func_021D43B8).  Copies a 32-byte aggregate into the object at
 * d_021F3B88+0x18 once, gated on byte +0xa.
 *
 * symbols:
 *   d_021F3B88  0x021F3B88  data
 */

typedef struct {
    int w[8];
} S32;

extern int d_021F3B88;

void func_021D43E0(int unused0, int unused1, S32 *src)
{
    char *p = (char *)d_021F3B88;

    if (*(unsigned char *)(p + 0xa) == 0) {
        *(S32 *)(p + 0x18) = *src;
        *(unsigned char *)(p + 0xa) = 1;
    }
}
