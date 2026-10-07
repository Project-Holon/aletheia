/*
 * file:     dwc_rap_p20.c
 * unit:     yes
 * function: func_02156BA8, func_02156BC4
 * address:  0x02156BA8
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
 *   g_021A8264 0x021A8264 data ov009
 */
#include "../../matched/include/Obj18653.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

int func_02156BA8(void);
void func_02156BC4(int v);
extern char *g_021A8264;

/*
 * evidence: BL sites in ov099021BF6E0 target this Thumb word-run start;
 *   full body reads nullable global +0x780 as a signed halfword, else -1.
 */
int func_02156BA8(void)
{
    char *p=g_021A8264;
    if(p)return ((struct Obj18653 *)p)->f780;
    return -1;
}


/*
 * Recursive MATCH unblocker: callee of the ov099 veneer func_021C0C7C +0008.
 * Coherent Thumb code only in ov009 (ov010 decodes to a pop with no push), so
 * the ov009 shard makes that site attest as `matched`.
 */
void func_02156BC4(int v)
{
    *(u16 *)((char *)(int *)g_021A8264 + 0x782) = v;
}
