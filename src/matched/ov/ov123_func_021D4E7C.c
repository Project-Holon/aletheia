/*
 * function: func_021D4E7C
 * address: 0x021D4E7C
 * packet: pkt_ov123_021D4E7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj00626.h"
typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
struct Rec;
struct Rec3;
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern void func_020061E4(u32 a);
int func_021D4E7C(char *p)
{
    if (((struct Obj00626 *)p)->f228) {
        if (((struct Obj00626 *)p)->f224)
            func_020286C4(((struct Obj00626 *)p)->f22C, ((struct Obj00626 *)p)->f228, ((struct Obj00626 *)p)->f224);
        switch (func_0201CE30(((struct Obj00626 *)p)->f228)) {
        case 2:
            func_0201CE48(((struct Obj00626 *)p)->f228);
            ((struct Obj00626 *)p)->f228 = 0;
            break;
        case 1:
            if (func_02035C60()) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj00626 *)p)->f228);
            }
            break;
        case 0:
            if (func_02035C38()) func_0201CE5C(((struct Obj00626 *)p)->f228, 0);
            break;
        }
        return 0;
    }
    return 1;
}
