/*
 * function: PLIST_PLATE_CreateMonIcon
 * address:  0x021BAA50
 * packet:   pkt_ov091_021BAA50
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   POKE_TOOL_GetIconPalette  0x0201BBE8  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B92C  0x0204B92C  arm
 */
#include "../include/Obj05169.h"
#include "../include/Obj05170.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} R;

extern void *func_020490F4(u32 id, u32 heap);
extern void *func_0201AB28(void *p, u32 idx);
extern void *POKE_TOOL_GetBoxParam(void *p);
struct Obj;
extern u32 func_0201BA68(void *mon);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *a);
extern int POKE_TOOL_GetIconPalette(void *a0);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *a, u32 b, u32 c, u32 d, const void *r, u16 f, u16 g);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
struct Obj;
extern void func_0204B92C(struct Obj *a, u32 b);

void PLIST_PLATE_CreateMonIcon(u8 *a, u8 *s)
{
    void *h;
    int t;
    int r;
    R rc;

    h = func_020490F4(7, ((struct Obj05169 *)a)->f0);
    t = (int)POKE_TOOL_GetBoxParam(func_0201AB28(**(void ** *)&((struct Obj05169 *)a)->f280, s[4]));
    ((struct Obj05170 *)s)->f2C = CLACT_RegisterCharacter(h, func_0201BA68((void *)t), 0, 0, ((struct Obj05169 *)a)->f0);
    ARC_TOOL_DeleteHandle(h);
    r = POKE_TOOL_GetIconPalette((void *)t);
    rc.a = 0x18;
    rc.b = 0x10;
    rc.c = 1;
    rc.d = 0;
    rc.e = 2;
    {
        int x = (int)CLACT_CreateActor((void *)((struct Obj05170 *)s)->f28, ((struct Obj05170 *)s)->f2C, ((struct Obj05169 *)a)->f190,
                              ((struct Obj05169 *)a)->f1D0, &rc, 0, ((struct Obj05169 *)a)->f0);
        ((struct Obj05170 *)s)->f30 = x;
        func_0204B6F4((struct Obj *)x, r, 1);
    }
    func_0204B92C((struct Obj *)((struct Obj05170 *)s)->f30, 1);
}
