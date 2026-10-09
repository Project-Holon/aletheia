/*
 * file:     btl_server_p82.c
 * unit:     yes
 * function: func_021C8588, func_021C859C, func_021C85B8, func_021C85D4
 * address:  0x021C8588
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
 *   func_021C87A0 0x021C87A0 thumb ov093
 *   func_021C87B0 0x021C87B0 thumb ov093
 *   func_021C87C0 0x021C87C0 thumb ov093
 *   func_021C87D0 0x021C87D0 thumb ov093
 *   func_021C87E0 0x021C87E0 thumb ov093
 *   func_021C87F0 0x021C87F0 thumb ov093
 *   func_021C8800 0x021C8800 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj00294.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

struct Flags { u8 low : 3; u8 a : 1; u8 b : 1; u8 high : 3; };

struct Unk021BD1E0 {
    u16 f0; u8 f2; u8 f3; u8 f4;
    u8 b0 : 1; u8 b1 : 1; u8 rest : 6;
};

extern void func_021C87A0(void *);
extern void func_021C87B0(void *);
extern void func_021C87C0(void *);
extern void func_021C87D0(void *);
extern void func_021C87E0(void *);
extern void func_021C87F0(void *);
extern void func_021C8800(void *);
extern void func_021BD1E0(struct Unk021BD1E0 *);
extern void func_02082BCC(void *, int, u32);
void func_021C8588(unsigned char *p);
void func_021C859C(u8 *p);
void func_021C85B8(u8 *p);
void func_021C85D4(u8 *p, int index, int clear);

void func_021C8588(unsigned char *p)
{
    *(int *)&((struct Obj00294 *)p)->f1A64 = 0;
    func_021C85D4(p, 0, 1);
}

void func_021C859C(u8 *p)
{
    if (((struct Obj00294 *)p)->f1A64 < 6) {
        ++((struct Obj00294 *)p)->f1A64;
        func_021C85D4(p, ((struct Obj00294 *)p)->f1A64, 1);
    }
}

void func_021C85B8(u8 *p)
{
    if (((struct Obj00294 *)p)->f1A64 != 0) {
        --((struct Obj00294 *)p)->f1A64;
        func_021C85D4(p, ((struct Obj00294 *)p)->f1A64, 0);
    }
}


void func_021C85D4(u8 *p, int index, int clear)
{
    u8 *q = p + 0x874 + index * 0x290;
    *(u8 * *)&((struct Obj00294 *)p)->f850 = q;
    *(u8 * *)&((struct Obj00294 *)p)->f854 = q + 0x48;
    *(u8 * *)&((struct Obj00294 *)p)->f858 = q + 0x90;
    *(u8 * *)&((struct Obj00294 *)p)->f85C = q + 0xd8;
    *(u8 * *)&((struct Obj00294 *)p)->f860 = q + 0x120;
    *(u8 * *)&((struct Obj00294 *)p)->f864 = q + 0x168;
    *(u8 * *)&((struct Obj00294 *)p)->f868 = q + 0x1b0;
    *(u8 * *)&((struct Obj00294 *)p)->f4A8 = q + 0x1f8;
    *(u8 * *)&((struct Obj00294 *)p)->f1AB0 = q + 0x200;
    *(u8 * *)&((struct Obj00294 *)p)->f1AB4 = q + 0x214;
    *(u8 * *)&((struct Obj00294 *)p)->f4B4 = q + 0x228;
    *(u8 * *)&((struct Obj00294 *)p)->f4AC = q + 0x22e;
    *(u8 * *)&((struct Obj00294 *)p)->f4B0 = q + 0x241;
    *(u8 * *)&((struct Obj00294 *)p)->f86C = q + 0x254;
    *(u8 * *)&((struct Obj00294 *)p)->f870 = q + 0x270;
    p[0x77f] = q[0x28c];
    ((struct Flags *)(p + 0x78a))->a = q[0x28d];
    ((struct Flags *)(p + 0x78a))->b = q[0x28e];
    if (clear) {
        func_021C87A0(q);
        func_021C87B0(((struct Obj00294 *)p)->f854);
        func_021C87C0(((struct Obj00294 *)p)->f858);
        func_021C87D0(((struct Obj00294 *)p)->f85C);
        func_021C87E0(((struct Obj00294 *)p)->f860);
        func_021C87F0(((struct Obj00294 *)p)->f864);
        func_021C8800(((struct Obj00294 *)p)->f868);
        func_021BD1E0(*(struct Unk021BD1E0 * *)&((struct Obj00294 *)p)->f4A8);
        func_02082BCC(((struct Obj00294 *)p)->f1AB0, 0, 0x14);
        func_02082BCC(((struct Obj00294 *)p)->f1AB4, 0, 0x14);
        func_02082BCC(((struct Obj00294 *)p)->f4B4, 0, 6);
        func_02082BCC(((struct Obj00294 *)p)->f4AC, 0, 0x13);
        func_02082BCC(((struct Obj00294 *)p)->f4B0, 0, 0x13);
        func_02082BCC(((struct Obj00294 *)p)->f86C, 0, 0x1c);
        func_02082BCC(((struct Obj00294 *)p)->f870, 0, 0x1c);
        p[0x77f] = 6;
        ((struct Flags *)(p + 0x78a))->a = 0;
        ((struct Flags *)(p + 0x78a))->b = 0;
    }
}
