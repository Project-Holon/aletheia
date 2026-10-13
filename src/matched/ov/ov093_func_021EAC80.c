/*
 * function: BTLV_CORE_ProcMoveForgetScreen
 * address: 0x021EAC80
 * packet: pkt_ov093_021EAC80
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-03 EXACT*: the calls go through Thumb-entry linker veneers
 *   (bx pc; nop; ldr ip,[pc]; bx ip; .word <ov095 function>), attested by the
 *   match.py `veneer` class. The listing extent includes the veneers.
 * extent: six veneers at 021EAD44..021EADA4, then six tail stubs
 *   021EADA4/ADB4/ADC4/ADD4/ADE4/ADF4. No C unit may span veneers.
 * symbols:
 *   func_021EAD44 0x021EAD44 thumb ov093
 *   func_021EAD54 0x021EAD54 thumb ov093
 *   func_021EAD64 0x021EAD64 thumb ov093
 *   func_021EAD74 0x021EAD74 thumb ov093
 *   func_021EAD84 0x021EAD84 thumb ov093
 *   func_021EAD94 0x021EAD94 thumb ov093
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0220F3E8 0x0220F3E8 thumb ov198
 *   ov196_id 0x000000C4 data
 *   ov198_id 0x000000C6 data
 */
#include "../include/Obj01694.h"
typedef unsigned char u8;
extern void func_021EAD44(void *, int);
extern int func_021EAD54(void *);
extern void func_021EAD64(void *);
extern void func_021EAD74(void *);
extern void func_021EAD84(void *);
extern int func_021EAD94(void *);
extern int func_02034AC4(signed int);
extern void func_02034A5C(int);
extern void func_0220F3E8(u8 *p);
extern u8 ov196_id[], ov198_id[];

int BTLV_CORE_ProcMoveForgetScreen(u8 *p, u8 *out)
{
    switch (p[0x174]) {
    case 0:
        func_021EAD44(((struct Obj01694 *)p)->f180, 0);
        func_02034AC4((int)ov196_id);
        p[0x174]++;
        break;
    case 1:
        if (func_021EAD54(((struct Obj01694 *)p)->f180)) {
            func_021EAD64(((struct Obj01694 *)p)->f180);
            func_02034AC4((int)ov198_id);
            func_0220F3E8(p + 0x10c);
            p[0x174]++;
        }
        break;
    case 2:
        if (p[0x158]) {
            func_02034A5C((int)ov198_id);
            func_021EAD74(((struct Obj01694 *)p)->f180);
            func_021EAD84(((struct Obj01694 *)p)->f180);
            p[0x174]++;
        }
        break;
    case 3:
        if (func_021EAD94(((struct Obj01694 *)p)->f180)) p[0x174]++;
        break;
    default:
        *out = p[0x157];
        func_02034A5C((int)ov196_id);
        p[0x174] = 0;
        return 1;
    }
    return 0;
}
