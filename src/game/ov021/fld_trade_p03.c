/*
 * file:     fld_trade_p03.c
 * unit:     yes
 * function: func_021CC5D8, func_021CC614, func_021CC6A8, func_021CC6FC, func_021CC720, func_021CC7B4
 * address:  0x021CC5D8
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
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C1A4  0x0200C1A4  thumb
 *   func_0200C184  0x0200C184  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0216530C  0x0216530C  thumb  ov010
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021653C4  0x021653C4  thumb  ov010
 *   func_021656A0  0x021656A0  thumb  ov010
 *   func_021656D0  0x021656D0  thumb  ov010
 *   func_0216573C  0x0216573C  thumb  ov010
 *   func_02165604  0x02165604  thumb  ov010
 *   func_02165634  0x02165634  thumb  ov010
 *   func_0216566C  0x0216566C  thumb  ov010
 *   func_02010F18  0x02010F18  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02010F40  0x02010F40  thumb
 *   func_02010F8C  0x02010F8C  thumb
 *   func_021F5340  0x021F5340  thumb  ov083
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_021CCEB8  0x021CCEB8  thumb  ov021
 *   func_021CC8DC  0x021CC8DC  thumb  ov021
 *   func_021CCA00  0x021CCA00  thumb  ov021
 *   func_021CCC50  0x021CCC50  thumb  ov021
 *   func_021CCCE4  0x021CCCE4  thumb  ov021
 *   d_021DE5BC  0x021DE5BC  data  a1
 *   d_021DE5C0  0x021DE5C0  data  ov021
 *   func_021CC8B0  0x021CC8B0  thumb  ov021
 *   func_021CCDF8  0x021CCDF8  thumb  ov021
 *   func_021CCCC4  0x021CCCC4  thumb  ov021
 *   func_021CCB98  0x021CCB98  thumb  ov021
 *   func_021CC9A4  0x021CC9A4  thumb  ov021
 *   func_021CCEE4  0x021CCEE4  thumb  ov021
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020307B0  0x020307B0  arm
 */
struct Big;
struct Blk34;
struct Ctx;
struct Bank;
struct GfFont;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x14];
    u8 *pc;
} ScriptVM;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Obj_021CC720 {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u8 padE[2];
    u32 f10;
    u32 f14;
    u32 f18;
    u8 pad1C[0xb8 - 0x1c];
    u32 fB8;
    u8 padBC[0xc4 - 0xbc];
} Obj_021CC720;

typedef struct Obj_021CC7B4 {
    u8 pad0[0x18];
    u32 f18;
    u8 pad1C[0xb8 - 0x1c];
    u32 fB8;
    u8 padBC[0xc1 - 0xbc];
    u8 fC1;
} Obj_021CC7B4;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *ctx);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *p);
extern u8 func_0200C1A4(struct Blk34 *p);
extern u32 func_0200C184(struct Blk34 *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0215A5F4(void *p);
extern void func_0216530C(void *a0);
extern void func_02165534(void *a0);
extern void func_021653C4(void);
extern void func_021656A0(void);
extern void func_021656D0(u8 a);
extern void func_0216573C(void);
extern void func_02165604(void);
extern void func_02165634(void *a0);
extern void func_0216566C(void);
extern u8 func_02010F18(void);
extern void *func_02010F7C(u32 heap);
extern void func_02010F40(u16 v, void *p);
extern void func_02010F8C(void *p);
extern void func_0215897C(void *vm, void *task);
extern void *func_021F5340(void *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_021CCEB8(Obj_021CC720 *p);
extern void func_021CC8DC(Obj_021CC720 *p);
extern void func_021CCA00(Obj_021CC720 *p);
extern void func_021CCC50(u8 *p);
extern void func_021CCCE4(Obj_021CC720 *p);
extern u32 func_021CC8B0(Obj_021CC7B4 *p, u32 *out);
extern void func_021CCDF8(u8 *p);
extern int func_021CCCC4(u32 a);
extern void func_021CCB98(u8 *p);
extern void func_021CC9A4(u8 *p);
extern int func_021CCEE4(u32 a);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);
int func_021CC5D8(ScriptVM *vm, void *ctx);
int func_021CC614(u32 a, u32 b);
int func_021CC6A8(void *vm, void *ctx);
int func_021CC6FC(u32 a, u32 b, u32 c, u32 d);
Obj_021CC720 *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
u32 func_021CC7B4(Obj_021CC7B4 *p, u32 *out);
extern const char d_021DE5BC[];
extern const char d_021DE5C0[];


/*
 * Script command: reads a mode byte and a result variable, then stores one of two values from the save-data block selected by the mode.
 *
 * Addresses are Black-image addresses.
 */
int func_021CC5D8(ScriptVM *vm, void *ctx)
{
    u8 mode;
    u16 *dst;
    void *p;

    mode = *vm->pc;
    vm->pc++;
    dst = func_02159AE8(vm, ctx);
    p = func_0200C0F0(func_02012EBC(func_0215A5E4(ctx)));

    switch (mode) {
    case 0:
        *dst = func_0200C1A4(p);
        break;
    case 1:
        *dst = func_0200C184(p);
        break;
    }
    return 0;
}


/*
 * func_020120F4 takes the func_0215A5DC result as its argument (r0 still
 * holds it at the bl), as it does at every other caller; declaring it
 * void(void) was what shuffled the whole register assignment.
 */
int func_021CC614(u32 a, u32 b)
{
    u32 sel;
    u32 v;
    void *t;

    sel = func_02159B10((void *)a, (void *)b);
    v = func_02159B10((void *)a, (void *)b);
    t = func_0215A5DC((void *)b);
    func_020120F4(t);
    func_0201210C((void *)t);
    func_0215A5F4((void *)b);
    switch (sel) {
    case 0:
        func_0216530C((void *)v);
        break;
    case 1:
        func_02165534((void *)v);
        break;
    case 2:
        func_021653C4();
        break;
    case 3:
        func_021656A0();
        break;
    case 4:
        func_021656D0(v);
        break;
    case 5:
        func_0216573C();
        break;
    case 6:
        func_02165604();
        break;
    case 7:
        func_02165634((void *)v);
        break;
    case 8:
        func_0216566C();
        break;
    }
    return 0;
}


/*
 * Script command: stores the current value of func_02010F18 in one variable and whether it changes away from 0x30 after a func_02010F40 round trip in another.
 *
 * Addresses are Black-image addresses.
 */
int func_021CC6A8(void *vm, void *ctx)
{
    u16 *a = func_02159AE8(vm, ctx);
    u16 *b = func_02159AE8(vm, ctx);
    void *p;

    *a = func_02010F18();
    if (*a != 0x30) {
        p = func_02010F7C(0x8015);
        func_02010F40(*a, p);
        func_02010F8C(p);
        *b = (func_02010F18() != 0x30) ? 1 : 0;
    } else {
        *b = 0;
    }
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CC6FC(u32 a, u32 b, u32 c, u32 d)
{
func_0215897C(func_0215A5F4((void *)b), func_021F5340(func_0215A5DC((void *)b)));
return 1;
}


Obj_021CC720 *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap)
{
    Obj_021CC720 *p;

    if (b == 0 || c == 0)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    p = func_02030734(heap, 0xc4, 1, d_021DE5C0, 0xd3);
    p->f0 = a;
    p->f4 = b;
    p->f8 = c;
    p->fC = heap;
    p->f10 = d;
    p->f14 = e;
    p->f18 = (u32)func_0204B100(0x20, 0xa, p->fC);
    p->fB8 = (u32)func_0201D7EC(0x17, 3, 0, 0, p->fC);
    func_021CCEB8(p);
    func_021CC8DC(p);
    func_021CCA00(p);
    func_021CCC50((u8 *)p);
    func_021CCCE4(p);
    return p;
}


u32 func_021CC7B4(Obj_021CC7B4 *p, u32 *out)
{
    u32 r;

    r = func_021CC8B0(p, out);
    if (p->fC1 != 1)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    func_021CCDF8((u8 *)p);
    func_021CCCC4((u32)p);
    func_021CCB98((u8 *)p);
    func_021CC9A4((u8 *)p);
    func_021CCEE4((u32)p);
    func_0201D83C((void *)p->fB8);
    func_0204B1CC((struct Bank *)p->f18);
    func_020307B0(p);
    return r;
}
