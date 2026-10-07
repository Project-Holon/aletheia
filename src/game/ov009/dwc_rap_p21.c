/*
 * file:     dwc_rap_p21.c
 * unit:     yes
 * function: func_02156C84, func_02156C98, func_02156CAC
 * address:  0x02156C84
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
 *   d_021A8264 0x021A8264 data ov009 a4
 */
#include "../../matched/include/G__anon_Work.h"

typedef unsigned char u8;

unsigned char func_02156C84(void);
void func_02156C98(int unused);
int func_02156CAC(void);
extern struct _anon_Work *g_021A8264;
extern u8 *d_021A8264;


/*
 * Byte at +0x7a2 of the block the module pointer holds.
 */
unsigned char func_02156C84(void)
{
    return *(unsigned char *)(((char *)g_021A8264) + 0x7a2);
}

/*
 * leaf: sole unresolved overlay blocker of concrete-correct ov115/021D43CC;
 * no ARM9 blocker. Parent confirmed no active assignment owns this leaf.
 * Caller leaves its previous integer result in r0; parameter retained.
 */
void func_02156C98(int unused) { ((unsigned char *)g_021A8264)[0x7A2]=0; }

int func_02156CAC(void)
{
    if (d_021A8264) {
        if (*(int *)(d_021A8264 + 0x754) == 6) return 1;
        return 0;
    }
    return 0;
}
