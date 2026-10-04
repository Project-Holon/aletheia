/*
 * function: func_02196ACC
 * address:  0x02196ACC
 * packet:   pkt_ov021_02196ACC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State step: picks the next handler from the state word and a status query.
 *
 * symbols:
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196E04  0x02196E04  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 *   func_02196C68  0x02196C68  thumb  ov021
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12632.h"
#include "../include/Obj19635.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_02196E04(u8 *p);
extern void func_02196804(u8 *p);
extern void func_02196C68(u8 *p);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);

void func_02196ACC(u8 *p)
{
    if (((struct Obj12632 *)p)->f8 == 5) {
        if (func_0200BBA8(func_0200BAC8(((struct Obj19635 *)(*(u8 * *)&((struct Obj12632 *)p)->f2E4))->f4C)) != 0) {
            func_02196034(p, func_02196E04, 0x443);
        } else {
            func_02196034(p, func_02196804, 0x446);
        }
    } else {
        func_02196034(p, func_02196C68, 0x44D);
    }
}
