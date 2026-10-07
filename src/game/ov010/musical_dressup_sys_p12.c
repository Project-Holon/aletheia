/*
 * file:     musical_dressup_sys_p12.c
 * unit:     yes
 * function: func_02156F98, func_02156FC4
 * address:  0x02156F98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj17620.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct Obj {
    u32 kind;
} Obj;

typedef struct Stage {
    void *f00;          /* 0x00 */
    Obj *f04[4];        /* 0x04 */
} Stage;

extern u32 func_020307B0(void *p);
void func_02156F98(Stage *s);
int func_02156FC4(int a0, int a1, int a2);


void func_02156F98(Stage *s)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (s->f04[i] != 0 && s->f04[i]->kind == 2)
            func_020307B0(s->f04[i]);
    }
    func_020307B0(s);
}




int func_02156FC4(int a0, int a1, int a2)
{
    int a3;

a3 = a0 + 4;
a0 = a1 << 2;
*(int *)((char *)a3 + a0) = a2;
a0 = 0;
((struct Obj17620 *)((char *)a2))->f0 = a0;
    return a0;}
