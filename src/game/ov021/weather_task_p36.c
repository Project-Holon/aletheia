/*
 * file:     weather_task_p36.c
 * unit:     yes
 * function: func_021A394C, func_021A395C, func_021A3960, func_021A3964
 * address:  0x021A394C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012B30  0x02012B30  thumb
 */
#include "../../matched/include/Obj19777.h"
#include "../../matched/include/Obj18035.h"
#include "../../matched/include/Obj18036.h"
#include "../../matched/include/Obj18037.h"

struct Rec44;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void func_02012B30(struct Rec44 *p, u16 v);
void func_021A394C(u8 *p);
u32 func_021A395C(u8 *p);
void *func_021A3960(u8 *p);
void func_021A3964(u8 *p, u32 v);


/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov021 func_021A322C (itself a blocker of
 * ov018 func_0217BCDC): tail call on the object's word at +0xC.
 */
void func_021A394C(u8 *p)
{
    func_02012B30((struct Rec44 *)(((struct Obj19777 *)p)->fC), 0xFFFF);
}


/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021A395C(u8 *p)
{
    return ((struct Obj18035 *)p)->f8;
}


/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
void *func_021A3960(u8 *p)
{
    return ((struct Obj18036 *)p)->f1C;
}


/*
 * Field setter at +0x14.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3964(u8 *p, u32 v)
{
    ((struct Obj18037 *)p)->f14 = v;
}
