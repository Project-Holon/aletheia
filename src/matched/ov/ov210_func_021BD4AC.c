/*
 * function: func_021BD4AC
 * address: 0x021BD4AC
 * packet: pkt_ov210_021BD4AC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C00FC 0x021C00FC thumb ov210
 *   func_021BCCA8 0x021BCCA8 thumb ov210
 *   func_021BE7E4 0x021BE7E4 thumb ov210
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   func_021BCF0C 0x021BCF0C thumb ov210
 */
#include "../include/Obj03936.h"
#include "../include/Obj14677.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C00FC(u8 *);
extern void func_021BCCA8(char *);
extern void func_021BE7E4(u8 *);
extern u8 func_020355C4(void);
typedef unsigned int   u32;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void func_021BCF0C(u8 *);
int func_021BD4AC(u8 *p)
{
    if (func_021C00FC(p) == 1) {
        u8 *head = *(u8 * *)&((struct Obj03936 *)p)->f0;
        if (((struct Obj14677 *)head)->f14 != 0) {
            ((struct Obj14677 *)head)->fC = 0;
            return 26;
        }
        func_021BCCA8((char *)p);
        func_021BE7E4(p);
        if (func_020355C4() == 1)
            CURSOR_MOVE_SetState(((struct Obj03936 *)p)->f2B0, 0);
        else
            CURSOR_MOVE_SetState(((struct Obj03936 *)p)->f2B0, 1);
        func_021BCF0C(p);
        return 4;
    }
    return 8;
}
