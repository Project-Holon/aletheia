/*
 * file:     unit_021EAC54_p01.c
 * unit:     yes
 * function: func_021EAC54, func_021EAC64, func_021EAC80
 * address:  0x021EAC54
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689B5CC   0x0689B5CC  thumb  ov095
 *   func_021E9984  0x021E9984  thumb  ov093
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
#include "../../matched/include/Obj01694.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y);
extern void func_021EAD44(void *, int);
extern int func_021EAD54(void *);
extern void func_021EAD64(void *);
extern void func_021EAD74(void *);
extern void func_021EAD84(void *);
extern int func_021EAD94(void *);
extern int func_02034AC4(signed int);
extern void func_02034A5C(int);
extern void func_0220F3E8(u8 *p);
void func_021EAC54(E64 *p, u32 a2);
void func_021EAC64(u8 *p, u8 a, int c);
int func_021EAC80(u8 *p, u8 *out);
extern u8 ov196_id[], ov198_id[];



/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
void func_021EAC54(E64 *p, u32 a2) { func_0689B5CC(p[0x6].f0, a2); }



void func_021EAC64(u8 *p, u8 a, int c)
{
    func_021E9984(p, p + 0x10c, 4, a, c);
    p[0x174] = 0;
}


/*
 * note: 2026-10-03 EXACT*: the calls go through Thumb-entry linker veneers
 *   (bx pc; nop; ldr ip,[pc]; bx ip; .word <ov095 function>), attested by the
 *   match.py `veneer` class. The listing extent includes the veneers.
 * extent: six veneers at 021EAD44..021EADA4, then six tail stubs
 *   021EADA4/ADB4/ADC4/ADD4/ADE4/ADF4. No C unit may span veneers.
 */
int func_021EAC80(u8 *p, u8 *out)
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
