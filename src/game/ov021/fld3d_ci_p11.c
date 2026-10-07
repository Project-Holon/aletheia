/*
 * file:     fld3d_ci_p11.c
 * unit:     yes
 * function: func_021C3250, func_021C3270, func_021C32BC
 * address:  0x021C3250
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
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_0200BCD8  0x0200BCD8  thumb
 *   func_021C3530  0x021C3530  thumb  ov021
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BC88  0x0200BC88  thumb
 *   func_021C36B0  0x021C36B0  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 */
struct Obj;
struct Party;
struct PartyMon;
struct Blk37;
struct Ctx;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned short u16;

extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_02017988(void *p, u32 a);
extern int func_0200BCA8(u32, u32);
extern u32 func_0200BC2C(u32, u32);
extern u32 func_0200BCD8(struct Obj *p, u32 i);
extern void func_021C3530(void *mon, u32 b);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_0200BC88(struct Obj *p, s32 i);
extern void func_021C36B0(void *e);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void func_0200CDE0(struct Blk37 *p, void *m);
void func_021C3250(void *mon);
void func_021C3270(u32 *p, u32 b, u32 c);
void func_021C32BC(void **p, void *mon);


void func_021C3250(void *mon)
{
    if (func_02017E1C(mon, 5, 0) == 0x1EC)
        func_02017988(mon, 0);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C3270(u32 *p, u32 b, u32 c)
{
    u32 m;

    if (func_0200BCA8(p[2], b) == 1) {
        m = func_0200BC2C(p[2], b);
        func_021C3530((void *)m, func_0200BCD8((struct Obj *)p[2], b));
        func_021C32BC((void **)p, (void *)m);
        func_0201A98C((void *)c, (void *)m);
        func_0200BC88((struct Obj *)p[2], b);
        func_021C36B0((void *)p[2]);
    }
}


/*
 * Returns the Pokemon's held item to the bag when it fits.
 */
void func_021C32BC(void **p, void *mon)
{
    void *bag = func_0200CA1C(func_020120F4(func_02188C80(p[1])));

    if (func_0200CED4(bag, func_02017E1C(mon, 5, 0)) == 0)
        func_0200CDE0(bag, mon);
}
