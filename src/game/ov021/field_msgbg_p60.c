/*
 * file:     field_msgbg_p60.c
 * unit:     yes
 * function: func_02190938, func_02190960
 * address:  0x02190938
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
 *   func_02190860  0x02190860  thumb  ov021
 */
#include "../../matched/include/Obj19589.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

typedef struct Handle {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle;

extern Handle *func_02190860(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u16 f, u32 g, u32 h, u32 i);
Handle *func_02190938(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u32 g, u32 h, u32 i);
Handle *func_02190960(u16 *a, const u8 *b, u32 c, u16 d, u16 e);


/*
 * Addresses are Black-image addresses.
 */
Handle *func_02190938(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u32 g, u32 h, u32 i)
{
    a[3] = 0xe;
    return func_02190860(a, b, c, d, e, a[3], g, h, i);
}


Handle *func_02190960(u16 *a, const u8 *b, u32 c, u16 d, u16 e)
{
    return func_02190938(a, b, c, d, e, 0, ((struct Obj19589 *)b)->f1C, 0);
}
