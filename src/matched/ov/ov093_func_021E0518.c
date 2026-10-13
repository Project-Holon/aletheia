/*
 * function: func_021E0518
 * address:  0x021E0518
 * packet:   pkt_ov093_021E0518
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8174  0x021C8174  thumb  ov093
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13504.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int BTL_EVENT_GetVar(int key);
extern int func_021C8174(int *p);
extern u16 BTLV_CORE_PackByteTwice(int c);
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetTypePair(void *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E0518(int a, int *b, int c)
{
    int t;
    u16 v;
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        switch (func_021C8174(b)) {
        case 1: case 2: case 3: case 8: case 9: case 15:
            t = 4;
            break;
        case 4: case 14:
        default:
            t = 0;
            break;
        case 10:
            t = 5;
            break;
        case 0: case 5:
            t = 0xb;
            break;
        case 6: case 11: case 12:
            t = 0xa;
            break;
        case 7: case 13:
            t = 0xe;
            break;
        }
        v = BTLV_CORE_PackByteTwice(t);
        if (v != BTL_POKEPARAM_GetTypePair(func_021C7CF4(b, c))) {
            p = func_021C88A4((char *)b, 0x14, c);
            ((struct Obj13504 *)p)->f4 = v;
            ((struct Obj13504 *)p)->f6 = c;
            func_021C88C8(b, p);
        }
    }
}
