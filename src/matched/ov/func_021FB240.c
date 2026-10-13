/*
 * function: func_021FB240
 * address:  0x021FB240
 * packet:   pkt_021FB240
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_SAVE_IsSeen  0x0200D064  thumb
 *
 * Count the entries of a u16 table that the query accepts.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct Blk37;
extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);

int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end)
{
    int i;
    int n = 0;

    for (i = start; i < end; i++) {
        if (ZUKAN_SAVE_IsSeen((struct Blk37 *)item, list[i]) != 0) {
            n++;
        }
    }
    return n;
}

