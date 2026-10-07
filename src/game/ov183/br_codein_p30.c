/*
 * file:     br_codein_p30.c
 * unit:     yes
 * function: func_021E24C4, func_021E24F8, func_021E2538
 * address:  0x021E24C4
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj24668.h"
#include "../../matched/include/Obj24669.h"
#include "../../matched/include/Obj24670.h"

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_021FC734(u8 *p);
extern void func_021FBDA4(int,unsigned);
extern void func_020409B4(u32 index);
extern void func_021FD860(int obj, int one, int *args);
extern void func_020061E4(u32 a);
void func_021E24C4(char *p,char *q);
int func_021E24F8(char *p, int a, int b);
int func_021E2538(char *p, int a, int b);

/*
 * extent: final two bytes are alignment padding.
 */
void func_021E24C4(char *p,char *q){int i;for(i=0;i<2;i++){if(*(void **)(p+i*4+12)){func_021FC734(*(void **)(p+i*4+12));*(void **)(p+i*4+12)=0;}}func_020409B4(4);func_021FBDA4(((struct Obj24668 *)q)->fC,30);}


int func_021E24F8(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(((struct Obj24669 *)p)->f18, 1, args);
        func_020061E4(0x703);
    }
    return ok;
}


int func_021E2538(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x90) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(((struct Obj24670 *)p)->f18, 1, args);
        func_020061E4(0x703);
    }
    return ok;
}
