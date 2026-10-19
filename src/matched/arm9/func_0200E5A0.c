/*
 * function: BATTLE_EXAMINATION_IsDeliveryValid
 * address:  0x0200E5A0
 * packet:   pkt_0200E5A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The two tests share one exit, so they have to be one conjunction with the
 * `return 0` written after it; as two separate `if (...) return 0;` statements
 * the compiler emits two copies of the `movs r0, #0; pop` pair and lands 28
 * bytes wrong.  EXACT*: the listing extent runs to the next label at
 * 0x0200E688, over three unlabelled followers.
 *
 * symbols:
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 */
#include "../include/Obj11237.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);

int BATTLE_EXAMINATION_IsDeliveryValid(void *a0)
{
    if (((struct Obj11237 *)a0)->f5C6 == GF_STANDARD_CalcCrc16(a0, 0x5c6) &&
        ((struct Obj11237 *)a0)->f5C2 == 0xd68)
        return 1;
    return 0;
}
