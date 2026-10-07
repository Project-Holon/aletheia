/*
 * file:     beacon_detail_gra_p04.c
 * unit:     yes
 * function: func_021BC650, func_021BC6B4
 * address:  0x021BC650
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BCA38 0x021BCA38 thumb ov216
 *   func_021BC614 0x021BC614 thumb ov216
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../../matched/include/Obj00366.h"

struct Obj;
typedef unsigned int   u32;

struct S021BC6B4
{
    char pad[0x264];
    void *slots[2];
};

extern void *func_021BCA38(char *p);
extern unsigned func_021BC614(unsigned short *p, unsigned manager, unsigned *r, short x, short y, unsigned char z, unsigned char a, unsigned char b, unsigned short flag);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
void func_021BC650(char *p);
void func_021BC6B4(struct S021BC6B4 *p);

void func_021BC650(char *p)
{
    void *q=func_021BCA38(((struct Obj00366 *)p)->f50);
    void *a=(void *)func_021BC614((short unsigned int *)p,(unsigned int)q,(unsigned int *)(p+0x80),128,120,0,0,2,0);
    ((struct Obj00366 *)p)->f264=a;
    func_0204B6F4(a,0,1);
    ((struct Obj00366 *)p)->f268=(void *)func_021BC614((short unsigned int *)p,(unsigned int)q,(unsigned int *)(p+0x5c),96,120,0,1,2,0);
}


void func_021BC6B4(struct S021BC6B4 *p)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        func_0204B3DC(p->slots[i], 0);
        func_0204B3B4(p->slots[i]);
    }
}
