/*
 * file:     btl_server_p34.c
 * unit:     yes
 * function: func_021BEC08, func_021BEC2C
 * address:  0x021BEC08
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
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 */
#include "../../matched/include/Obj09965.h"

typedef unsigned char u8;

typedef unsigned int u32;

extern u8 func_021D5440(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern u8 func_021B8FF4(u8 *);
extern void func_021BA1B4(char **p, int i);
int func_021BEC08(u8 *p,u8 *a);
void func_021BEC2C(u8 *p,u8 *a,int c);

int func_021BEC08(u8 *p,u8 *a)
{
    int n;
    n=func_021B8DDC(func_021D5440(a));
    if(n==func_021B8FF4(*(u8 * *)&((struct Obj09965 *)p)->f4)) return 1;
    return 0;
}

void func_021BEC2C(u8 *p,u8 *a,int c)
{
    if(func_021BEC08(p,a)) {
        if(c==150) func_021BA1B4((char **)(*(u8 * *)&((struct Obj09965 *)p)->f4),73);
        else if(c==165) func_021BA1B4((char **)(*(u8 * *)&((struct Obj09965 *)p)->f4),74);
    }
}
