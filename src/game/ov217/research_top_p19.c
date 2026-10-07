/*
 * file:     research_top_p19.c
 * unit:     yes
 * function: func_021BE4E0, func_021BE4E8
 * address:  0x021BE4E0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BE9B8 0x021BE9B8 thumb ov217
 *   func_021BE91C 0x021BE91C thumb ov217
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021BE934 0x021BE934 thumb ov217
 *   func_021BF3D8 0x021BF3D8 thumb ov217
 *   func_021BF4AC 0x021BF4AC thumb ov217
 *   func_021BF594 0x021BF594 thumb ov217
 *   func_021BEBA4 0x021BEBA4 thumb ov217
 *   func_021BEFF8 0x021BEFF8 thumb ov217
 */
#include "../../matched/include/Obj00021.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_021BE9B8(u8 *);
extern void func_021BE91C(char *,int);
extern u32 func_021BF810(void *p);
extern int func_021BE934(char *);
extern void func_021BF3D8(char *p);
extern void func_021BF4AC(char *p);
extern void func_021BF594(char *p, int i);
extern u32 func_021BEBA4(u32);
extern void func_020061E4(u32 a);
extern void func_021BEFF8(u8 *p);
void func_021BE4E0(void *p);
void func_021BE4E8(u8 *p);


/*
 * Increment the u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE4E0(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x24);
    *c += 1;
}

void func_021BE4E8(u8 *p)
{
    int repeat=1;
    func_021BE9B8(p);
    func_021BE91C((char *)p,-1);
    do {
        u32 index=((struct Obj00021 *)p)->f34;
        if (index-1<=1) {
            if (((struct Obj00021 *)p)->f3C8==0 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,-1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct Obj00021 *)p)->f3C8==1 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,-1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    func_021BE934((char *)p);
    func_021BF3D8((char *)p);
    func_021BF4AC((char *)p);
    func_021BF594((char *)p,1);
    if (((struct Obj00021 *)p)->f34==4) func_021BEBA4((u32)p);
    func_020061E4(1352);
    func_021BEFF8(p);
}
