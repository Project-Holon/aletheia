/*
 * function: func_021C70EC
 * address:  0x021C70EC
 * packet:   pkt_ov136_021C70EC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B98C   0x0204B98C  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Actor;
extern u32 func_0204B98C(struct Actor *a);
int func_021C70EC(u8 *p)
{
    if (func_0204B98C(*(void **)(*(u8 **)(p + 8) + 0x20C)) == 0) {
        *(u32 *)(*(u8 **)(p + 4) + 4) = 1;
        return *(u32 *)(p + 0x28);
    }
    return 0x19;
}
