/*
 * function: func_0200BA58
 * address:  0x0200BA58
 * packet:   pkt_0200BA58
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads overlay 188 (0xBC): a Thumb tail call to the ARM loader through
 * `ldr r3; bx r3`.  The id is a pool word, so it is the overlay-id symbol,
 * not an integer literal (0xBC would fit a movs).  Filed as the call witness
 * for the ov021 script dispatcher 0x021CA5C4 (also unblocks the pending
 * ov187 0x0220B164 and ov199 0x022132C4).
 *
 * symbols:
 *   GF_OVERLAY_Load   0x02034AC4  arm
 *   ov188_id       0x000000BC  data  a1
 */

typedef unsigned int u32;

extern char ov188_id[];
typedef signed int     s32;
extern int GF_OVERLAY_Load(s32 handle);

void func_0200BA58(void)
{
    GF_OVERLAY_Load((u32)ov188_id);
}
