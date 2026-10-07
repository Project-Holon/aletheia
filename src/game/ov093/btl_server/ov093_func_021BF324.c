/*
 * function: func_021BF324
 * address:  0x021BF324
 * packet:   pkt_ov093_021BF324
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021BF3B8  0x021BF3B8  thumb  ov093
 *   func_021BF3C8  0x021BF3C8  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D62D8  0x021D62D8  thumb  ov093
 */
#include "../../../matched/include/Obj07752.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 func_021D5440(u8 *p);
extern int func_021BF3B8(u8 *q, int k, u32 n);
extern int func_021BF3C8(u8 *q, int k, u32 n);
extern int func_021D59B4(u8 *p, int k);
struct Unk021D62A8;
struct UtilSlots;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u16 func_021D62D8(struct UtilSlots *p, int i);

int func_021BF324(u8 *p, u8 *a, u8 *b)
{
    u8 t;
    if (func_021BF3B8(p + 0x1ab8, *(int *)&((struct Obj07752 *)p)->f4, func_021D5440(a)) != 0) {
        if (func_021D59B4(a, 0x11) == 0x63)
            return 1;
    }
    if (func_021BF3C8(p + 0x1ab8, *(int *)&((struct Obj07752 *)p)->f4, func_021D5440(b)) != 0) {
        if (func_021D59B4(b, 0x11) == 0x63)
            return 1;
    }
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x1c) != 0)
        return 1;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x1d) != 0) {
        t = func_021D62D8((struct UtilSlots *)a, 0x1d);
        if (t == func_021D5440(b))
            return 1;
    }
    return 0;
}
