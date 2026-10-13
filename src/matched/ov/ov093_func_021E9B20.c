/*
 * function: BTLV_CORE_PollPartyMenu
 * address: 0x021E9B20
 * packet: pkt_ov093_021E9B20
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-03 EXACT*: the calls go through Thumb-entry linker veneers
 *   (bx pc; nop; ldr ip,[pc]; bx ip; .word <ov095 function>), attested by the
 *   match.py `veneer` class. The listing extent includes the veneers.
 * extent: lead is 320 bytes; eight 16-byte Thumb veneers follow.
 * symbols:
 *   func_021E9C60 0x021E9C60 thumb ov093
 *   func_021E9C70 0x021E9C70 thumb ov093
 *   func_021E9C80 0x021E9C80 thumb ov093
 *   func_021E9C90 0x021E9C90 thumb ov093
 *   func_021E9CA0 0x021E9CA0 thumb ov093
 *   func_021E9CB0 0x021E9CB0 thumb ov093
 *   func_021E9CC0 0x021E9CC0 thumb ov093
 *   func_021E9CD0 0x021E9CD0 thumb ov093
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0220F3E8 0x0220F3E8 thumb ov198
 *   ov196_id 0x000000C4 data
 *   ov198_id 0x000000C6 data
 */
#include "../include/Obj00891.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021E9C60(void *, int);
extern int func_021E9C70(void *);
extern void func_021E9C80(void *);
extern void func_021E9C90(void *, u8, u8);
extern void func_021E9CA0(void *);
extern void func_021E9CB0(void *);
extern void func_021E9CC0(void *);
extern int func_021E9CD0(void *);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void func_0220F3E8(u8 *p);
extern u8 ov196_id[], ov198_id[];

int BTLV_CORE_PollPartyMenu(u8 *p)
{
    u32 i;
    switch (p[0x174]) {
    case 0:
        if ((u8)(p[0x12b] + 0xff) <= 1) func_021E9C60(((struct Obj00891 *)p)->f180, 0);
        else func_021E9C60(((struct Obj00891 *)p)->f180, 1);
        func_02034AC4((int)ov196_id);
        p[0x174]++;
        break;
    case 1:
        if (func_021E9C70(((struct Obj00891 *)p)->f180)) {
            func_021E9C80(((struct Obj00891 *)p)->f180);
            func_02034AC4((int)ov198_id);
            func_0220F3E8(p + 0x10c);
            p[0x174]++;
        }
        break;
    case 2:
        if (p[0x158]) {
            if (p[0x12b] != 5 && ((struct Obj00891 *)p)->f13C == 0) {
                for (i = 0; i < 3; i++) {
                    if (p[i + 0x154] != 0xff) {
                        func_021E9C90(((struct Obj00891 *)p)->f15C, i, p[i + 0x154]);
                        func_021E9CA0(((struct Obj00891 *)p)->f15C);
                        (*(u8 **)(p + 0x15c))[8] = 0;
                    }
                }
            }
            func_02034A5C((int)ov198_id);
            func_021E9CB0(((struct Obj00891 *)p)->f180);
            func_021E9CC0(((struct Obj00891 *)p)->f180);
            p[0x174]++;
        }
        break;
    case 3:
        if (func_021E9CD0(((struct Obj00891 *)p)->f180)) p[0x174]++;
        break;
    default:
        func_02034A5C((int)ov196_id);
        p[0x174] = 0;
        return 1;
    }
    return 0;
}
