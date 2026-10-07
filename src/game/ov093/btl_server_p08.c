/*
 * file:     btl_server_p08.c
 * unit:     yes
 * function: func_021B9F84, func_021B9FAC, func_021B9FBC, func_021BA004
 * address:  0x021B9F84
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
 *   func_021B9F70 0x021B9F70 thumb ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 */
#include "../../matched/include/Obj13281.h"

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

extern int func_021B9F70(u8 *p, int i);
void *func_021B86B8(void ***p);
int func_021BA1A8(char **p, int m);
u32 func_021B8588(void **p);
u16 func_021B9F84(char *p,int i,unsigned int j);
u32 func_021B9FAC(u8 *p, int i, u32 *out);
int func_021B9FBC(char *p, int i);
u16 func_021BA004(char *p, int i);

u16 func_021B9F84(char *p,int i,unsigned int j) {
    char *q;
    if(func_021B9F70((u8 *)p,i)) {
        q=(char *)((u32)p+32+(u32)i*40);
        if(j<4) return *(u16 *)((u32)q+16+j*2);
    }
    return 0;
}

u32 func_021B9FAC(u8 *p, int i, u32 *out) {
    u32 q = (u32)p + (u32)i * 40;
    *out = ((struct Obj13281 *)q)->f28;
    return ((struct Obj13281 *)q)->f24;
}


int func_021B9FBC(char *p, int i)
{
    if (func_021B86B8((void ***)p) == 0) {
        i = 8;
        if (func_021BA1A8((char **)p, i)) {
            return i << 8;
        }
        if (func_021B8588((void **)p) == 1) {
            return 0x80;
        }
    } else {
        if (func_021B9F70((u8 *)p, i)) {
            return *(int *)(p + i * 0x28 + 0x2c);
        }
    }
    return 0;
}

u16 func_021BA004(char *p, int i)
{
    if (func_021B9F70((u8 *)p, i)) return *(u16 *)((u32)p + (u32)i * 0x28 + 0x2a);
    return 0;
}
