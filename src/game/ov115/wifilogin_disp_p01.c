/*
 * file:     wifilogin_disp_p01.c
 * unit:     yes
 * function: func_021D42A8, func_021D42B8, func_021D42C8, func_021D42E0, func_021D4310
 * address:  0x021D42A8
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 *   func_020099C8 0x020099C8 thumb
 *   func_02009C24 0x02009C24 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D4240 0x021D4240 thumb ov115
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_021D4644 0x021D4644 thumb ov115
 *   func_021D4BB4 0x021D4BB4 thumb ov115
 */
#include "../../matched/include/Obj22582.h"
#include "../../matched/include/Obj22583.h"
#include "../../matched/include/Obj22584.h"
#include "../../matched/include/Obj22585.h"
#include "../../matched/include/Obj08038.h"
#include "../../matched/include/Obj22586.h"
#include "../../matched/include/Obj22587.h"

struct BigObj;
struct Sub020097BCObj;
struct Sub020097BCFriend;
typedef unsigned char u8;

typedef unsigned int u32;

extern u32 func_0201283C(const struct BigObj *p);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
extern void func_02009C24(struct Sub020097BCObj *obj, int src, int dest);
extern u32 func_020221A4(void);
extern int func_021D5C70(int);
extern void func_021D426C(u8 *,u32);
extern void *func_021D5D5C(u8 *,int,int,int);
extern int func_021D4240(u8 *);
extern void func_021D4AB0(u8 *);
extern void func_021D5F7C(u8 *p);
extern void func_021D5CCC(u8 *p, u32 n);
extern int func_021D4644(u8 *);
extern void func_021D4BB4(u8 *p);
void func_021D42A8(u8 *p);
void func_021D42B8(u8 *p);
void func_021D42C8(int a,int b,u8 *p);
void func_021D42E0(u8 *p);
void func_021D4310(u8 *p);

void func_021D42A8(u8 *p) { func_02009860((struct Sub020097BCObj *)func_0201283C(((struct Obj22582 *)p)->f44)); }

void func_021D42B8(u8 *p) { func_020099C8((void *)func_0201283C(((struct Obj22583 *)p)->f44),0); }

/*
 * extent: Two zero bytes of alignment padding follow the return.
 */
void func_021D42C8(int a,int b,u8 *p) { func_02009C24((void *)func_0201283C(((struct Obj22584 *)p)->f44),a,b); }

void func_021D42E0(u8 *p) { if(func_020221A4() && func_021D5C70(((struct Obj22585 *)p)->f38) && func_021D4240(p)) func_021D426C(p,(u32)func_021D4AB0); }

void func_021D4310(u8 *p)
{
    if (func_021D4240(p)) {
        func_021D5F7C((u8 *)(((struct Obj08038 *)p)->f38));
        if (((struct Obj22586 *)(*(u8 * *)&((struct Obj08038 *)p)->f40))->f4 == 0)
            func_021D5CCC((u8 *)(((struct Obj08038 *)p)->f38), 0x23);
        if (((struct Obj22587 *)(*(u8 * *)&((struct Obj08038 *)p)->f40))->f10 != 0)
            func_021D426C(p, (u32)func_021D4BB4);
        else
            func_021D426C(p, (u32)func_021D4AB0);
    } else {
        func_021D4644(p);
    }
}
