/*
 * file:     worldtrade_enter_p02.c
 * unit:     yes
 * function: func_021F8A44, func_021F8A74, func_021F8A80, func_021F8AB0, func_021F8AF4
 * address:  0x021F8A44
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02005D90  0x02005D90  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 *   func_02168064  0x02168064  arm
 *   func_02168124 0x02168124 arm ov009
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_0205994C 0x0205994C arm
 *   func_021C7BA0 0x021C7BA0 arm ov114
 */
#include "../../matched/include/Obj23396.h"
#include "../../matched/include/Obj23397.h"
#include "../../matched/include/Obj23398.h"
#include "../../matched/include/Obj23399.h"
#include "../../matched/include/Obj18565.h"

struct Sub020097BCObj;
struct DWCstAccUserData;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x28];
    u32 x28;
    u16 x2C;
    u16 x2E;
    u16 x30;
    u8 pad32[0xEB2 - 0x32];
    u16 xEB2;
} Work;

typedef signed char s8;

typedef signed short s16;

typedef unsigned long long u64;

typedef signed int s32;

extern void func_02005D90(u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_02168064(void);
extern int func_02168124(void);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int func_02009CC0(void *a0);
extern void func_02008540(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned long long func_0205994C(struct DWCstAccUserData *userdata);
extern void func_021C7BA0(u32 a, u32 b, u32 c, int d);
extern void func_021C8DA0(u8 *p);
int func_021F8A44(Work *p);
int func_021F8A74(void *a0);
int func_021F8A80(u8 *a0);
int func_021F8AB0(u8 **p);
int func_021F8AF4(u8 *p);


int func_021F8A44(Work *p)
{
    func_02005D90(0x486, 0xFFFF);
    p->x28 = 1;
    p->xEB2 = 1;
    p->x30 = 0;
    func_021F4EC0((u8 *)p, 1, 0);
    return 2;
}


/*
 * Call func_02168064 and report success.
 */
int func_021F8A74(void *a0)
{
    func_02168064();
    return 1;
}

/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int func_021F8A80(u8 *a0) { switch(func_02168124()) {case 3:return 1;case 0:case 4:case 5:return 2;default:return 0;} }

/*
 * extent: 0x021F8AF2..0x021F8AF4 is two zero alignment bytes.
 */
int func_021F8AB0(u8 **p)
{
    void *handle;
    u32 id;
    u64 key;
    handle = func_02009860(((struct Obj23396 *)(*p))->f14);
    func_02008540(((struct Obj23397 *)(*p))->f1C, func_02009CC0(((struct Obj23398 *)(*p))->f14));
    id = func_0200853C(((struct Obj23399 *)(*p))->f1C);
    key = func_0205994C(handle);
    func_021C7BA0(id, (u32)key, (u32)(key >> 32), 0);
    return 1;
}


/*
 * Hand the object over, clear the +0xf8c slot and latch 1.
 */
int func_021F8AF4(u8 *p)
{
    func_021C8DA0(p);
    ((struct Obj18565 *)p)->fF8C = 0;
    return 1;
}
