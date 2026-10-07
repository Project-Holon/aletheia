/*
 * file:     unit_021B7560_p06.c
 * unit:     yes
 * function: func_021B870C, func_021B8724, func_021B8794, func_021B879C
 * address:  0x021B870C
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045730 0x02045730 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02041EE4 0x02041EE4 arm
 */
#include "../../matched/include/Obj13729.h"
#include "../../matched/include/Obj07978.h"
#include "../../matched/include/Obj22167.h"

struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u8 func_02045730(struct Descriptor *p);
extern void func_020413B0(u32, u8, u8, u8, u8, u8);
extern void func_020409B4(u32);
extern void func_02082BCC(void *, int, u32);
extern void func_02041EE4(u32,u32,u32);
int func_021B870C(u8 *p, int *out);
void func_021B8724(u8 *p);
void func_021B8794(u16 value, int flag, u8 *p);
void func_021B879C(void *p, u32 a1);

int func_021B870C(u8 *p, int *out) { if(((struct Obj13729 *)p)->f32) { if(out)*out=((struct Obj13729 *)p)->f30; return 1; } return 0; }

void func_021B8724(u8 *p)
{
    int i;
    u32 win;
    u8 palette;
    u8 a, b, c, d;
    u16 *row;
    ((struct Obj07978 *)p)->f34 = 0;
    ((struct Obj07978 *)p)->f32 = 0;
    for (i = 0; i < ((struct Obj07978 *)p)->f2C; i++) {
        win = func_02045730((struct Descriptor *)(*(int *)(p + i * 4 + 4)));
        row = (u16 *)(*(u8 * *)&((struct Obj07978 *)p)->f28 + i * 12);
        a = row[1];
        b = row[2];
        c = row[3];
        d = row[4];
        switch (i) {
        case 0: palette = 11; break;
        case 1: palette = 4; break;
        }
        func_020413B0(win, a, b, c, d, palette);
        func_020409B4(win);
    }
}

/*
 * extent: includes the 8-byte setter follower at 021B8794.
 */
void func_021B8794(u16 value, int flag, u8 *p)
{
    if (flag == 0) ((struct Obj22167 *)p)->f30 = value;
}

void func_021B879C(void *p, u32 a1) { func_02082BCC(p,0,28); func_02041EE4(4,3,88); func_02041EE4(7,3,88); }
