/*
 * function: B_PLIST_MAIN_ApplyMode4
 * address:  0x022101FC
 * packet:   pkt_022101FC
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   B_PLIST_MAIN_ApplyMode 0x02210C88 thumb
 */
#include "../include/Obj03351.h"
#include "../include/Obj25233.h"

typedef unsigned char  u8;
extern int B_PLIST_MAIN_ApplyMode(u8 *p, unsigned mode);

int B_PLIST_MAIN_ApplyMode4(char *p)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)p, 4) == 0)
    {
        return 0xf;
    }
    if (((struct Obj25233 *)((char *)((struct Obj03351 *)p)->f0))->f1F == 5)
    {
        return 0x1e;
    }
    return 7;
}
