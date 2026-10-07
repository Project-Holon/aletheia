/*
 * file:     field_msgbg_p04.c
 * unit:     yes
 * function: func_0218AD28, func_0218AD80
 * address:  0x0218AD28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A3038  0x021A3038  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021C8A74  0x021C8A74  thumb
 *   func_021C8A30  0x021C8A30  thumb
 *   func_021C8CF0  0x021C8CF0  thumb
 *   func_021C8C88  0x021C8C88  thumb
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626A8  0x021626A8  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02185410  0x02185410  thumb  ov020
 *   func_02185360  0x02185360  thumb  ov020
 */
#include "../../matched/include/Obj00705.h"

struct VecFx32;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021C8A74(u32 a);
extern void *func_021C8A30(u32 prio, void *sys, struct Obj00020 *owner);
extern int func_021C8CF0(u32 a);
extern void *func_021C8C88(u32 prio, void *sys, struct Obj00020 *owner);
extern void *func_021625CC(char *p, unsigned i);
extern u16 func_021626A8(void *b, void *pos);
extern u8 func_021626E8(u8 *p);
extern void *func_02185410(void *p, int u, int a, int b);
extern void *func_02185360(void *p, int u, int a, int b);
void *func_0218AD28(struct FieldCtx *p, struct Obj00020 *pos);
void func_0218AD80(u8 *p, void *a, int id, void *arg);


/*
 * Looks up the tile attribute under the position and starts the matching tile
 * task (func_021C8A30 or func_021C8C88); returns the task or 0.
 *
 * Addresses are Black-image addresses.
 */
void *func_0218AD28(struct FieldCtx *p, struct Obj00020 *pos)
{
    int buf[3];
    u16 attr;

    func_021A3038(p->f18, (struct VecFx32 *)buf);
    attr = func_021AB0F0(func_021AB0D4((void *)func_02188C98((u8 *)pos), buf));
    if (func_021C8A74(attr))
        return func_021C8A30(0, p->f4, pos);
    if (func_021C8CF0(attr))
        return func_021C8C88(0, p->f4, pos);
    return 0;
}


/*
 * Looks up entry id through func_021625CC, optionally resolves its argument,
 * then dispatches to ov020 func_02185410 for kind 6 or func_02185360
 * otherwise.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * Addresses are Black-image addresses.
 */
void func_0218AD80(u8 *p, void *a, int id, void *arg)
{
    void *obj = func_021625CC(((struct Obj00705 *)p)->fC, (u16)id);
    void *d;

    if (arg != 0)
        d = (void *)func_021626A8(obj, arg);
    else
        d = 0;
    if (func_021626E8(obj) == 6)
        func_02185410(((struct Obj00705 *)p)->f4, (int)a, (int)obj, (int)d);
    else
        func_02185360(((struct Obj00705 *)p)->f4, (int)a, (int)obj, (int)d);
}
