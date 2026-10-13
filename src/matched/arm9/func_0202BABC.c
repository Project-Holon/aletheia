/*
 * function: ISS_3DS_SYS_EnterImpl
 * address:  0x0202BABC
 * packet:   pkt_0202B9F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * status:   EXACT*
 *
 * Closed by the `matched` class: 0x0202B9F0 became an EXACT shard entry
 * (pkt_0202B9F0) in this wave.  The listing extent runs to 0x0202BAF4
 * because the follower at 0x0202BAE6 is unlabelled, so the verdict is EXACT*.
 * symbols:
 *   ISS_3DS_SYS_SetTableIndex  0x0202B9E0  thumb
 *   ISS_3DS_SYS_FindTableIndex  0x0202B9F0  thumb
 *   func_0202BB48  0x0202BB48  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *
 */
#include "../include/Obj02601.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern u16 GFL_USE_GetBgmNo(void);
struct Obj;
extern u8 ISS_3DS_SYS_FindTableIndex(const struct Obj *p, u32 key);
extern int ISS_3DS_SYS_SetTableIndex(int a0, int a1);
extern int func_0202BB48(int a0);

void ISS_3DS_SYS_EnterImpl(u8 *o)
{
    if (((struct Obj02601 *)o)->f4 != 0) {
        return;
    }
    ((struct Obj02601 *)o)->f4 = 1;
    ISS_3DS_SYS_SetTableIndex((int)o, ISS_3DS_SYS_FindTableIndex((const struct Obj *)o, GFL_USE_GetBgmNo()));
    func_0202BB48((int)o);
}
