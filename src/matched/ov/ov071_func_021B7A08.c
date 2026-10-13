/*
 * function: MONOLITH_TOOL_SLOT_SELECT_IsMessageDone
 * address:  0x021B7A08
 * packet:   pkt_ov071_021B7A08
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02028484  0x02028484  thumb
 */

typedef signed int     s32;
struct Blk;
extern s32 func_02028484(struct Blk *blk, void *h);
int MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(char *p, char *q) { return func_02028484((struct Blk *)(p + 0x38), (void *)(*(int *)(q + 8))); }
