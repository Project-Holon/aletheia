/*
 * file:     dwc_rap_p25.c
 * unit:     yes
 * function: func_02156B70, func_02156B8C
 * address:  0x02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 */
#include "../../matched/include/G__anon_Work.h"
#include "../../matched/include/Obj18652.h"

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

s16 func_02156B70(void);
int func_02156B8C(void);
extern struct _anon_Work *g_021A8264;


/*
 * Reads the signed halfword at +0x782 of the ov009 work block held in the
 * bss pointer at 0x021A8264, or 0 when no block is allocated.  A leaf with
 * no lr-saving prologue whose only caller is in arm9 (sub_0200F698), so
 * the listing emits it as data words.
 */
s16 func_02156B70(void)
{
    if (g_021A8264 != 0)
        return g_021A8264->val;
    return 0;
}


/*
 * Recursive MATCH unblocker: callee of func_021BF050 (ov099) +0002. Coherent
 * Thumb code only in ov009 (ov010 holds the tail of another function), so the
 * ov009 shard makes that site attest as `matched`.
 */
int func_02156B8C(void)
{
    int *p = (int *)g_021A8264;

    if (p != 0)
        return ((struct Obj18652 *)p)->f774;
    return 0;
}
