/*
 * file:     sta_act_light_p07.c
 * unit:     yes
 * function: func_021F7ECC, func_021F7FA8, func_021F7FAC
 * address:  0x021F7ECC
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4EC4 0x021F4EC4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_020061F8 0x020061F8 thumb
 *   table 0x020A1B38 data a2
 */
#include "../../matched/include/Obj04463.h"
#include "../../matched/include/Obj22565.h"
#include "../../matched/include/Obj10324.h"
#include "../../matched/include/Obj22566.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int x,y,z; } Vec;

typedef struct { u16 count,pad; int index,a,b; } Tail_021F7ECC;

typedef struct { short y,x; } Scale;

typedef signed short   s16_021F7ECC;

typedef unsigned int   u32;

typedef short s16_021F7FAC;

typedef struct { u16 count, pad; int index; } Tail_021F7FAC;

extern void func_021F4EA4(unsigned int unused, unsigned int p, unsigned int q);
extern void func_021F4E8C(int,int,Vec *);
extern void func_021F4EC4(u32 unused, u32 p, s16_021F7ECC *a, s16_021F7ECC *b);
extern void func_021F4EB4(u32 unused, u32 p, s16_021F7ECC a, s16_021F7ECC b);
extern void func_021F4E6C(u8 *p, u8 *e, u32 value);
extern void func_020061F8(int);
void func_021F7ECC(char *p,char *q);
void func_021F7FA8(char *a0, char *a1);
void func_021F7FAC(char *p, char *q);
extern s16_021F7FAC table[];

/*
 * extent: 220-byte lead, 7FA8 two-byte return stub; 7FAA zero alignment padding.
 * function_starts: 0x021F7FA8
 */
void func_021F7ECC(char *p,char *q)
{
    Tail_021F7ECC *t=(Tail_021F7ECC *)(q+0xf0);
    Vec v;
    Scale s;
    func_021F4EA4(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),(unsigned int)(&v));
    t->b+=164;
    v.x-=2867;
    v.y+=t->b;
    v.z=0xc8000;
    func_021F4E8C(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),&v);
    func_021F4EC4(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),&s.x,&s.y);
    s.x+=12;
    s.y+=12;
    func_021F4EB4(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),s.x,s.y);
    t->count++;
    if(t->count>=180) {
        func_021F4E6C((u8 *)(((struct Obj04463 *)p)->f10),(u8 *)(*(int *)(q+0x84+t->index*4)),0);
        ((struct Obj22565 *)q)->f104=0;
        ((struct Obj04463 *)p)->f43C-=1;
        if(((struct Obj04463 *)p)->f43C==0) func_020061F8(2);
    }
}

void func_021F7FA8(char *a0, char *a1)
{
}

void func_021F7FAC(char *p, char *q) {
    Tail_021F7FAC *t = (Tail_021F7FAC *)(q + 0xf0);
    u16 angle = ((int)t->count << 11) % 65536;
    t->count++;
    if (t->count >= 0xb4) {
        ((struct Obj22566 *)q)->f104 = 0;
        ((struct Obj10324 *)p)->f43C -= 1;
        if (((struct Obj10324 *)p)->f43C == 0) func_020061F8(2);
        return;
    }
    func_021F4EB4(((struct Obj10324 *)p)->f10, *(int *)(q + 0x84 + t->index * 4),
                  table[(angle >> 4) * 2] / 8 + 1024,
                  table[(angle >> 4) * 2 + 1] / 8 + 1024);
}
