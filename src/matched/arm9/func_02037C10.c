/*
 * function: func_02037C10
 * address:  0x02037C10
 * packet:   pkt_02037C10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The net tick dispatcher.  Two shapes are load-bearing: the f1EA/0x393D0
 * early exit is an out-of-line `goto bail` block placed AFTER the main body,
 * and the main path's `return 1` is reached by a `goto done` that lands on
 * the SAME `mov r0,#1; pop` the bail block falls into.  Writing either as a
 * plain `return 1` duplicates the epilogue and loses the `b #0x2037d6c`.
 *
 * symbols:
 *   lbl_021469D0   0x021469D0  data
 *   func_0203D788  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   func_020370F4  0x020370F4  arm
 *   func_020393D0  0x020393D0  arm
 *   func_02037F48  0x02037F48  arm
 *   func_0203802C  0x0203802C  arm
 *   func_02038298  0x02038298  arm
 *   func_02038340  0x02038340  arm
 *   func_02039050  0x02039050  arm
 *   func_02039338  0x02039338  arm
 *   func_02039160  0x02039160  arm
 *   func_020385C4  0x020385C4  arm
 *   func_020390BC  0x020390BC  arm
 *   func_0203ACAC  0x0203ACAC  arm
 *   func_02037BA4  0x02037BA4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8   pad00[0x340];
    u32 *f340;
};

struct Oth {
    u8 pad00[0x64];
    u8 f64;
    u8 f65;
};

struct Net {
    u8 pad00[0x1ea];
    u8 f1EA;
};

extern struct Net *lbl_021469D0;
extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern u32  func_020370F4(u32 a);
extern int  func_020393D0(void);
extern void func_02037F48(void);
extern void func_0203802C(void);
extern void func_02038298(void);
extern void func_02038340(void);
extern void func_02039050(void);
extern u16 func_02039338(void);
extern int  func_02039160(u32 a);
extern void func_020385C4(void);
extern void func_020390BC(void);
extern void func_0203ACAC(void);
extern void func_02037BA4(void);

int func_02037C10(void)
{
    struct Ctx *c = func_0203D788();
    struct Oth *o = func_0203D798();

    if (lbl_021469D0 == 0) {
        if (c != 0)
            ((void (*)(u32))c->f340[0xc / 4])(0);
        return 1;
    }

    {
        u32 (*h)(void) = (u32 (*)(void))c->f340[0x84 / 4];
        if (h != 0) {
            func_020370F4(h());
        }
    }

    if (lbl_021469D0->f1EA != 0)
        goto bail;
    if (func_020393D0() != 0)
        goto bail;

    if (o->f64 == 0 && (o->f65 == 0 || o->f65 == 5)) {
        func_02037F48();
    } else if ((u8)(o->f65 + 0xfd) <= 1) {
        func_0203802C();
    } else if ((u8)(o->f65 + 0xff) <= 1) {
        func_02038298();
    } else {
        func_02038340();
        func_02039050();
        if (func_02039338() == 0) {
            if (func_02039160(0) != 0 && o->f64 != 0)
                func_020385C4();
        }
        if (func_02039338() != 0)
            goto skip;
    }
    func_020390BC();
skip:
    if (o->f65 != 1 && o->f65 != 2) {
        ((void (*)(u16))c->f340[0xc / 4])(
            *(u16 *)((u8 *)lbl_021469D0 + 0x1e4));
    }
    func_0203ACAC();
    func_02037BA4();
    goto done;

bail:
    ((void (*)(u32))c->f340[0xc / 4])(0);
done:
    return 1;
}
