/*
 * function: FLDMMDL_MOVE_AttrEffectSpecial
 * address:  0x021638AC
 * packet:   pkt_021638AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * unblocked: FLDEFF_D06DENKI_StartSpark is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 28 bytes against 26 compiled: the unlabelled follower that
 *   precedes ov021's next entry (its bytes are the original's 2-byte pad).
 *
 * symbols:
 *   func_021AB3EC  0x021AB3EC  thumb
 *   FLDEFF_D06DENKI_StartSpark  0x021C8F7C  thumb  ov021
 */
#include "../include/Obj00110.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021AB3EC();
extern int FLDEFF_D06DENKI_StartSpark();

int FLDMMDL_MOVE_AttrEffectSpecial(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB3EC(a0);
loc_021638B8:
    if (a0 != 1) goto loc_021638C4;
loc_021638BC:
a1 = ((struct Obj00110 *)t4)->f14;
a0 = t5 + 0;
    a0 = FLDEFF_D06DENKI_StartSpark(a0, a1);
loc_021638C4:
    return a0;}
