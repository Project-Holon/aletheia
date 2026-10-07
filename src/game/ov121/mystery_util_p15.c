/*
 * file:     mystery_util_p15.c
 * unit:     yes
 * function: func_021DBF10, func_021DBF40, func_021DBF70, func_021DBF9C, func_021DBFE4, func_021DC004, func_021DC024, func_021DC02C
 * address:  0x021DBF10
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_02020E60 0x02020E60 thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 */
#include "../../matched/include/Obj08097.h"
#include "../../matched/include/Obj06452.h"
#include "../../matched/include/Obj22905.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_020490F4(u32,u16);
extern int func_0201BC3C(void);
extern u32 func_02020E60(u16,u32);
extern u32 func_0201BB5C(u32,u32,u32,u32);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
void *func_021DBF10(void *p,u16 heap);
u32 func_021DBF40(void *p);
u32 func_021DBF70(void *p);
int func_021DBF9C(void *p);
int func_021DBFE4(void *p);
int func_021DC004(void *p);
int func_021DC024(void *p);
char *func_021DC02C(void *p);

void *func_021DBF10(void *p,u16 heap) { switch(func_021DC024(p)) { case 1:return func_020490F4(7,heap); case 2:return func_020490F4(25,heap); default:return func_020490F4(34,heap); } }

/*
 * prototype: func_02020E60 item is u16 here, matching caller truncation before the call.
 */
u32 func_021DBF40(void *p) { switch(func_021DC024(p)) { case 1:return func_0201BC3C(); case 2:return func_02020E60(*(u32 *)func_021DC02C(p),2); default:return 3; } }

u32 func_021DBF70(void *p) { char *q; if (func_021DC024(p)==1) { q=func_021DC02C(p); return func_0201BB5C(((struct Obj08097 *)q)->f1A,((struct Obj08097 *)q)->f1C,((struct Obj08097 *)q)->f35,((struct Obj08097 *)q)->f5C); } return 0; }

int func_021DBF9C(void *p)
{
    char *q;
    switch(func_021DC024(p)) {
    case 1:
        q=func_021DC02C(p);
        return func_0201BABC(((struct Obj06452 *)q)->f1A,((struct Obj06452 *)q)->f1C,((struct Obj06452 *)q)->f35,((struct Obj06452 *)q)->f5C);
    case 2:
        q=func_021DC02C(p);
        return func_02020E60((u16)((struct Obj06452 *)q)->f0,1);
    default: return 12;
    }
}

int func_021DBFE4(void *p) { switch(func_021DC024(p)) { case 1: return func_0201BC40(); case 2: return 1; default:return 33; } }

int func_021DC004(void *p) { switch(func_021DC024(p)) { case 1: return func_0201BCB4(); case 2: return 0; default:return 36; } }

int func_021DC024(void *p) { return ((struct Obj22905 *)p)->fB7; }

char *func_021DC02C(void *p) { return (char *)p+4; }
