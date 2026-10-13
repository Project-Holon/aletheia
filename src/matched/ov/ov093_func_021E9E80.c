/*
 * function: BTLV_CORE_PollBagMenu
 * address: 0x021E9E80
 * packet: pkt_ov093_021E9E80
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-03 EXACT*: the calls go through Thumb-entry linker veneers
 *   (bx pc; nop; ldr ip,[pc]; bx ip; .word <ov095 function>), attested by the
 *   match.py `veneer` class. The listing extent includes the veneers.
 * extent: lead is 300 bytes; seven 16-byte Thumb veneers follow.
 * symbols:
 *   func_021E9FAC 0x021E9FAC thumb ov093
 *   func_021E9FBC 0x021E9FBC thumb ov093
 *   func_021E9FCC 0x021E9FCC thumb ov093
 *   func_021E9FDC 0x021E9FDC thumb ov093
 *   func_021E9FEC 0x021E9FEC thumb ov093
 *   func_021E9FFC 0x021E9FFC thumb ov093
 *   func_021EA00C 0x021EA00C thumb ov093
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0220C834 0x0220C834 thumb ov197
 *   func_0220F3E8 0x0220F3E8 thumb ov198
 *   ov196_id 0x000000C4 data
 *   ov197_id 0x000000C5 data
 *   ov198_id 0x000000C6 data
 */
#include "../include/Obj00665.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021E9FAC(void *, int);
extern int func_021E9FBC(void *);
extern void func_021E9FCC(void *);
extern int func_021E9FDC(u16, u8);
extern void func_021E9FEC(void *);
extern void func_021E9FFC(void *);
extern int func_021EA00C(void *);
extern int func_02034AC4(int);
extern void func_02034A5C(int handle);
extern void func_0220C834(u8 *arg);
extern void func_0220F3E8(u8 *p);
extern u8 ov196_id[], ov197_id[], ov198_id[];

int BTLV_CORE_PollBagMenu(u8 *p)
{
    switch (p[0x174]) {
    case 0: break;
    case 1:
        func_021E9FAC(((struct Obj00665 *)p)->f180, 1);
        func_02034AC4((int)ov196_id);
        p[0x174] = 2;
        break;
    case 2:
        if (func_021E9FBC(((struct Obj00665 *)p)->f180)) {
            func_021E9FCC(((struct Obj00665 *)p)->f180);
            func_02034AC4((int)ov197_id);
            func_0220C834(p + 0xc8);
            p[0x174] = 3;
        }
        break;
    case 3:
        if (p[0xe1]) {
            func_02034A5C((int)ov197_id);
            if (((struct Obj00665 *)p)->fE8 == 0) p[0x174] = 4;
            else p[0x174] = 6;
        }
        break;
    case 4:
        if (((struct Obj00665 *)p)->fDE && p[0xf2] != 2 && !func_021E9FDC(((struct Obj00665 *)p)->fDE, p[0xf2])) {
            ((struct Obj00665 *)p)->f130 = ((struct Obj00665 *)p)->fDE;
            func_02034AC4((int)ov198_id);
            func_0220F3E8(p + 0x10c);
            p[0x174] = 5;
        } else p[0x174] = 6;
        break;
    case 5:
        if (p[0x158]) {
            func_02034A5C((int)ov198_id);
            p[0x174] = 6;
        }
        break;
    case 6:
        func_021E9FEC(((struct Obj00665 *)p)->f180);
        func_021E9FFC(((struct Obj00665 *)p)->f180);
        p[0x174] = 7;
        break;
    case 7:
        if (func_021EA00C(((struct Obj00665 *)p)->f180)) {
            func_02034A5C((int)ov196_id);
            p[0x174] = 0;
            return 1;
        }
        break;
    }
    return 0;
}
