/*
 * function: func_02047674
 * address:  0x02047674
 * packet:   pkt_02047674
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf getter: return the word at +4.  disasm.py never
 * traced a func_ start here (the listing emits these bytes as data words),
 * so the caller func_021BE748 in ov021 had no witness for its bl; this
 * entry supplies the `matched` class.
 */
#include "../include/Obj16042.h"

int func_02047674(int p)
{
    return ((struct Obj16042 *)p)->f4;
}
