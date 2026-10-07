/*
 * file:     pdw_postman_p12.c
 * unit:     yes
 * function: func_021B830C, func_021B8314
 * address:  0x021B830C
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
 *   func_021B91C8  0x021B91C8  thumb
 *   func_021B91F8  0x021B91F8  thumb ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    void *x14;
} Obj;

extern void func_021B91C8();
extern void func_021B91F8(Obj *, void *);
void func_021B830C(void);
void func_021B8314(Obj *o, void *x);


/*
 * Tail-call thunk: forwards to func_021B91C8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021B830C(void)
{
    func_021B91C8();
}


void func_021B8314(Obj *o, void *x)
{
    void *save = o->x14;

    o->x14 = 0;
    func_021B91F8(o, x);
    o->x14 = save;
}
