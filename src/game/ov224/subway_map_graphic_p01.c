/*
 * file:     subway_map_graphic_p01.c
 * unit:     yes
 * function: func_021B9788, func_021B9824
 * address:  0x021B9788
 * region:   ov224
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E804 0x0204E804 arm
 *   func_0204E720 0x0204E720 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021B9A44 0x021B9A44 thumb ov224
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj14799.h"

struct PrintSys;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned short u16;

extern int func_0204E804(void);
extern u32 func_020362DC(void);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_020355D8(u8 v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021B9A44(void *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_020409B4(u32);
int func_021B9788(void *a,unsigned *state,int b,char *p);
void func_021B9820(void);
void func_021B9824(u16 *work);

int func_021B9788(void *a,unsigned *state,int b,char *p)
{
    int x,y,flag;
    switch(*state) {
    case 0: *state=1; break;
    case 1: if(!func_0204E804()) *state=2; break;
    case 2:
        flag=0;
        if(func_020362DC()&3) { func_020355D8(0); flag=1; }
        else if(func_02035D20((u32 *)(&x),(u32 *)(&y))) { func_020355D8(1); flag=1; }
        if(flag) { *state=3; func_0204E720(3,0,16,0); }
        break;
    case 3: if(!func_0204E804()) *state=4; break;
    case 4: return 1;
    }
    func_0201C4E4(((struct Obj14799 *)p)->f10); func_021B9A44(((struct Obj14799 *)p)->f8);
    return 0;
}

void func_021B9820(void) {}

void func_021B9824(u16 *work)
{
    void *narc = func_020490F4(0xce, *work);
    func_02049B68(narc, 0, 0, 0, 0, *work);
    func_02049658(narc, 1, 1, 0, 0, 0, *work);
    func_020498F4(narc, 2, 1, 0, 0, 0, *work);
    func_020498F4(narc, 3, 2, 0, 0, 0, *work);
    func_02049238(narc);
    func_020409B4(1);
    func_020409B4(2);
}
