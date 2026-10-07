/*
 * file:     sta_act_light_p06.c
 * unit:     yes
 * function: func_021F77EC, func_021F79A8, func_021F7A98
 * address:  0x021F77EC
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
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021F514C 0x021F514C thumb ov112
 *   func_0200616C 0x0200616C thumb
 *   func_021F7AEC 0x021F7AEC thumb ov112
 *   func_021F7C90 0x021F7C90 thumb ov112
 *   func_021F7E2C 0x021F7E2C thumb ov112
 *   func_021F7FA8 0x021F7FA8 thumb ov112
 *   func_021F7BA8 0x021F7BA8 thumb ov112
 *   func_021F7D30 0x021F7D30 thumb ov112
 *   func_021F7ECC 0x021F7ECC thumb ov112
 *   func_021F7FAC 0x021F7FAC thumb ov112
 *   d_021F832C 0x021F832C data a4
 */
#include "../../matched/include/Obj02169.h"
#include "../../matched/include/Obj03248.h"
#include "../../matched/include/Obj13841.h"
#include "../../matched/include/Obj22558.h"
#include "../../matched/include/Obj13842.h"
#include "../../matched/include/Obj22559.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16;

typedef struct { u16 count, pad; int index; } Tail;

extern u32 func_021F4F10(u8 *);
extern unsigned char func_021F514C(void *p, int i);
extern void func_0200616C(void *,int);
extern void func_021F7AEC(char *,char *);
extern void func_021F7C90(char *,char *);
extern void func_021F7E2C(char *,char *);
extern void func_021F7FA8(char *,char *);
extern void func_021F7BA8(u8 *,u8 *);
extern void func_021F7D30(u8 *p, u8 *q);
extern void func_021F7ECC(char *,char *);
extern void func_021F7FAC(char *,char *);
extern void func_020061F8(int);
void func_021F77EC(u32 unused, u8 *p, u32 v);
void func_021F79A8(char *p,char *q,int index);
int func_021F7A80(char *p,char *q);
void func_021F7A94(char *p,char *q);
void func_021F7A98(char *p, char *q);
extern void *d_021F832C[];


/*
 * Addresses are Black-image addresses.
 */
void func_021F77EC(u32 unused, u8 *p, u32 v)
{
    if (v == 0xe8) { ((struct Obj02169 *)p)->f24 = 0xfb3; return; }
    if (v == 0x184 || v == 0x1fc) { ((struct Obj02169 *)p)->f24 = 0xfc0; return; }
    if (v == 0x4b || v == 0xcd || v == 0xf5) { ((struct Obj02169 *)p)->f24 = 0xfcc; return; }
    if (v == 0x2d || v == 0x142) { ((struct Obj02169 *)p)->f24 = 0x1040; return; }

    if (v == 9 || v == 0x21 || v == 0x3d || v == 0x41 || v == 0x4c ||
        v == 0x7a || v == 0x7b || v == 0x8d || v == 0xd6 || v == 0xeb ||
        v == 0xfd || v == 0x100 || v == 0x108 || v == 0x115 || v == 0x11e ||
        v == 0x13b || v == 0x15b || v == 0x1b2 || v == 0x1bc || v == 0x276) {
        ((struct Obj02169 *)p)->f28 = 0xfcc;
        return;
    }
    if (v == 0x25 || v == 0xd7 || v == 0xdb || v == 0x16a || v == 0x250 ||
        v == 0x264) {
        ((struct Obj02169 *)p)->f28 = 0xfd9;
        return;
    }
    if (v == 0x12 || v == 0x35 || v == 0x7e || v == 0x80 || v == 0x9c ||
        v == 0x9d || v == 0xb5 || v == 0xd0 || v == 0xf6 || v == 0xf8 ||
        v == 0x134 || v == 0x162 || v == 0x17a || v == 0x189 || v == 0x18e ||
        v == 0x1a3 || v == 0x1cc || v == 0x222 || v == 0x231 || v == 0x26f ||
        v == 0x283) {
        ((struct Obj02169 *)p)->f28 = 0xfe6;
        return;
    }
    if (v == 0x26 || v == 0x120) { ((struct Obj02169 *)p)->f28 = 0xff3; return; }

    if (v == 0x1c1) {
        ((struct Obj02169 *)p)->f24 = 0x1040;
        ((struct Obj02169 *)p)->f28 = 0xfcc;
        return;
    }
    if (v == 0x26e) {
        ((struct Obj02169 *)p)->f24 = 0xfc0;
        ((struct Obj02169 *)p)->f28 = 0xfcc;
        return;
    }
}

/*
 * extent: Thumb followers7A80 (18 code+2 zero padding7A92) and7A94 (BX LR+2 zero padding7A96), parent-cleared.
 * ABI: 514C retains caller's explicitly loaded r1 halfword although its own legacy body ignores that input.
 */
void func_021F79A8(char *p,char *q,int index)
{
    u32 v;
    if(*(int *)(q+132+index*4)==0 || *(int *)&((struct Obj03248 *)q)->f104!=0) return;
    v=func_021F514C((void *)func_021F4F10((u8 *)((struct Obj13841 *)p)->f10),**(u16 **)(q+168+index*4));
    ((struct Obj03248 *)q)->fF0=0;
    ((struct Obj03248 *)q)->fF4=index;
    ((struct Obj03248 *)q)->fF8=0;
    func_0200616C(d_021F832C[v],2);
    ((struct Obj13841 *)p)->f43C+=1;
    switch(v) {
    case 0: func_021F7A94(p,q); *(void (**)(char *,char *))(q+260)=func_021F7A98; break;
    case 1: func_021F7AEC(p,q); *(void (**)(u8 *,u8 *))(q+260)=func_021F7BA8; break;
    case 2: func_021F7C90(p,q); *(void (**)(char *,char *))(q+260)=(void (*)(char *, char *))func_021F7D30; break;
    case 3: func_021F7E2C(p,q); *(void (**)(char *,char *))(q+260)=func_021F7ECC; break;
    case 4: func_021F7FA8(p,q); *(void (**)(char *,char *))(q+260)=func_021F7FAC; break;
    }
}

int func_021F7A80(char *p,char *q)
{
    if(((struct Obj22558 *)q)->f104!=0) return 1;
    return 0;
}

void func_021F7A94(char *p,char *q)
{
}

void func_021F7A98(char *p, char *q) {
    Tail *tail = (Tail *)(q + 0xf0);
    s16 *v = *(s16 **)(q + 0xa8 + tail->index * 4);
    v[1] += 0x1000;
    tail->count += 1;
    if (tail->count >= 0xc0) {
        ((struct Obj22559 *)q)->f104 = 0;
        ((struct Obj13842 *)p)->f43C -= 1;
        if (((struct Obj13842 *)p)->f43C == 0) func_020061F8(2);
    }
}
