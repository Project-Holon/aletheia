/*
 * file:     br_util_p08.c
 * unit:     yes
 * function: func_021FD940, func_021FD964
 * address:  0x021FD940
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../../matched/include/Obj24847.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0204B878(struct Obj *,u16);
extern void func_0204B3DC(struct Obj *,u32);
void func_021FD940(u8 *p,u32 value);
void func_021FD964(void *unused,int *state,u8 *p);

/*
 * lever: Set the counter before narrowing value; its initialization splits the two shifts.
 */
void func_021FD940(u8 *p,u32 value)
{
    int i;
    u16 narrow;
    i=0;
    narrow=value;
    for(;i<12;i++)func_0204B878(*(struct Obj **)((u32)p+(u32)i*4+0x1f8),narrow);
}

void func_021FD964(void *unused,int *state,u8 *p)
{
    int i;
    switch(*state) {
    case 0:
        for(i=0;i<12;i++)func_0204B3DC(*(struct Obj **)((u32)p+(u32)i*4+0x1f8),0);
        ((struct Obj24847 *)p)->f22C=1;
        *state=1;
        break;
    case 1:break;
    }
}
