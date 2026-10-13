/*
 * function: ARC_TOOL_SeekHandle
 * address:  0x0204960C
 * packet:   pkt_0204960C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02078B44 0x02078B44 arm
 */

struct FSFile;
extern int func_02078B44(struct FSFile *file, long offset, int origin);

int ARC_TOOL_SeekHandle(struct FSFile *file, long offset)
{
    return func_02078B44(file, offset, 0);
}
