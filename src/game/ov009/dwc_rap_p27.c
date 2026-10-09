/*
 * file:     dwc_rap_p27.c
 * unit:     yes
 * function: func_02156C60, func_02156C84, func_02156C98, func_02156CAC, func_02156CD0
 * address:  0x02156C60
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
 *   func_02156BD8  0x02156BD8  thumb  ov009
 *   d_021A8264 0x021A8264 data ov009 a4
 */
#include "../../matched/include/G__anon_Work.h"
#include "../../matched/include/Obj18655.h"

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void func_02156BD8(u32 i);
void func_02156C60(void);
/* * Byte at +0x7a2 of the block the module pointer holds. */ unsigned char func_02156C84(void);
/* * leaf: sole unresolved overlay blocker of concrete-correct ov115/021D43CC; * no ARM9 blocker. Parent confirmed no active assignment owns this leaf. * Caller leaves its previous integer result in r0; parameter retained. */ void func_02156C98(int unused);
int func_02156CAC(void);
int func_02156CD0(void);
extern struct _anon_Work *g_021A8264;
extern u8 *d_021A8264;



/*
 * Resets the two slots and marks the flag at +0x7a6.
 */
void func_02156C60(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_02156BD8(i);
    }

    *(unsigned char *)(((char *)g_021A8264) + 0x7a6) = 1;
}




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


/*
 * Recursive MATCH unblocker: callee of func_021DA434 (ov175) +0002. Coherent
 * Thumb code only in ov009 (ov010 holds the tail of another function), so the
 * ov009 shard makes that site attest as `matched`.
 */
int func_02156CD0(void)
{
    int *p = (int *)g_021A8264;

    if (p != 0) {
        if ((u32)(((struct Obj18655 *)p)->f754 - 9) <= 1)
            return 1;
    }
    return 0;
}
