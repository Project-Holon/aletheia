/*
 * function: func_02186694
 * address: 0x02186694
 * packet: pkt_ov023_02186694
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x021866C2.
 * symbols:
 *   func_02027858 0x02027858 thumb
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 */
#include "../include/Obj03625.h"
struct TaskMenu;
struct TaskMenuState;
extern void func_02027858(struct TaskMenu *);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 func_02027FD8(struct TaskMenuState *s);
void func_02186694(char *p)
{
    func_02027858(*(struct TaskMenu * *)&((struct Obj03625 *)p)->f178);
    func_02045808(((struct Obj03625 *)p)->f188);
    func_02045808(((struct Obj03625 *)p)->f17C);
    func_02027FD8(*(struct TaskMenuState * *)&((struct Obj03625 *)p)->f174);
    *(int *)&((struct Obj03625 *)p)->f178 = 0;
}
