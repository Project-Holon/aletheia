/*
 * function: func_0200BA68
 * address:  0x0200BA68
 * packet:   pkt_0200BA68
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unloads overlay 188 (0xBC), the pair of func_0200BA58: a Thumb tail call
 * to the ARM unloader through `ldr r3; bx r3`, the id as the overlay-id
 * symbol.  Filed as the call witness for the ov021 script dispatcher
 * 0x021CA5C4 (also unblocks the pending ov187 0x0220B164 and ov199
 * 0x022132C4).
 *
 * symbols:
 *   GF_OVERLAY_Unload   0x02034A5C  arm
 *   ov188_id       0x000000BC  data  a1
 */

typedef unsigned int u32;

extern char ov188_id[];
typedef signed int     s32;
extern void GF_OVERLAY_Unload(s32 handle);

void func_0200BA68(void)
{
    GF_OVERLAY_Unload((u32)ov188_id);
}
