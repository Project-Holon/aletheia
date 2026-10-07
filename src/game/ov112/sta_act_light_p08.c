/*
 * file:     sta_act_light_p08.c
 * unit:     yes
 * function: func_021F8044, func_021F8054, func_021F8068
 * address:  0x021F8044
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj08033.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

void func_021F8044(void *unused,u32 *p,u32 *q);
void func_021F8054(void *unused,u32 *p,const u32 *q);
void func_021F8068(int self, char *p, u16 v);

/*
 * extent: two zero alignment bytes follow code.
 */
void func_021F8044(void *unused,u32 *p,u32 *q) { q[0]=p[6]; q[1]=p[7]; q[2]=p[8]; }

void func_021F8054(void *unused,u32 *p,const u32 *q) { p[6]=q[0]; p[7]=q[1]; p[8]=q[2]; p[1]=1; }


/*
 * note: unlabelled leaf in ov112 (the listing emits it as a .word run), filed
 * to witness the bl from src/pending/ov132_func_021FBA14.c.  The first
 * argument is ignored; the original moves r1 into r0, so the pointer is the
 * second parameter.
 */
void func_021F8068(int self, char *p, u16 v)
{
    ((struct Obj08033 *)p)->f48 = v;
    if (((struct Obj08033 *)p)->f10 == 1)
        ((struct Obj08033 *)p)->f48 = 0;
    ((struct Obj08033 *)p)->f4 = 1;
}
