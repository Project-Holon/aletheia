/*
 * function: func_021C54FC
 * address:  0x021C54FC
 * packet:   pkt_ov093_021C54FC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D62D8  0x021D62D8  thumb  ov093
 *   func_021C5480  0x021C5480  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct UtilSlots;
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern void func_021C5480(u8 *p, u8 *a, int b);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);

void func_021C54FC(u8 *p, u8 *a)
{
    u8 v = func_021D62D8((struct UtilSlots *)a, 7);
    func_021C5480(p, a, 0x25C);
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x14d, func_021D5440(a), v, 0xffff0000);
}
