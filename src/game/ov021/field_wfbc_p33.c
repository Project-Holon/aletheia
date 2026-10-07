/*
 * file:     field_wfbc_p33.c
 * unit:     yes
 * function: func_02196B24, func_02196B28
 * address:  0x02196B24
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
 *   func_02196ACC  0x02196ACC  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02196034  0x02196034  thumb  ov021
 */
struct Actor;
struct Cmd;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Obj { u32 x0; u32 x4; u32 x8; u8 pad[0x288]; void *objs[27]; u32 mode; } Obj;

typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;

extern void func_02196ACC(u8 *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern void func_02196034(Obj *, void (*)(), u32);
void func_02196B24(void);
void func_02196B28(Obj *a);


/*
 * Untraced blob: empty body (bx lr only).
 *
 * Addresses are Black-image addresses.
 */
void func_02196B24(void)
{
}


/*
 * Addresses are Black-image addresses.
 */
void func_02196B28(Obj *a)
{
    Req r;
    int i;

    i = 0;
    if (a->x8 == 5) {
        i = 1;
    }
    r.x0 = 0;
    r.a = a;
    r.cb = func_02196ACC;
    func_0204B92C(a->objs[i], 1);
    func_0204BA00(a->objs[i], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[i]);
    func_02196034(a, func_02196B24, 0x471);
}
