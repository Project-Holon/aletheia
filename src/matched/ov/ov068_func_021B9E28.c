/*
 * function: func_021B9E28
 * address:  0x021B9E28
 * packet:   pkt_ov068_021B9E28
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The `movs r7, #0` at entry that feeds the second memset's value comes
 * from naming CLACT_SetUnitDefaultRenderer's argument (the bank func_0204B100 returned);
 * with that call left argument-free the zero folds to `movs r1, #0`.
 * Table rows are indexed `i - 2` over a loop from 2 to 12.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D34C  0x0203D34C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_021BB704     0x021BB704  data  ov068  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Ent;

extern char d_020A1448[];
extern Ent d_021BB704[];

extern void func_02082BCC(void *p, int c, u32 n);
struct Bank;
struct Cfg;
struct Obj;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_020434DC(u32 a, u32 b);
typedef signed int     s32;
extern void func_02043598(u32 mask, u32 enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204ABF0(void *, int, int, int, int);
extern int func_0204A6C8(void *, int, int, int, int);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern int func_0204B294(int, int, int, int, Local *, int, int);
struct Obj;
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_0203CD98(void);
extern void func_0203D34C(u32 a, u32 b);

void func_021B9E28(int *p, void *res, u32 heap)
{
    Local s;
    void *h;
    int i;

    func_02082BCC(p, 0, 0x54);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)res, heap);
    p[0] = (int)func_0204B100(0x80, 0, heap);
    CLACT_SetUnitDefaultRenderer((struct Bank *)p[0]);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    h = func_020490F4(0x1b, heap);
    p[1] = func_0204ABF0(h, 6, 0, 0, heap);
    p[2] = func_0204A6C8(h, 5, 0, 0, heap);
    p[3] = func_0204AF28(h, 4, 3, heap);
    p[4] = func_0204A6C8(h, 0xc, 0, 0, heap);
    p[5] = func_0204AF28(h, 0xb, 0xa, heap);
    func_02049238(h);
    func_02082BCC(&s, 0, 8);
    s.e = 2;
    s.d = 2;
    for (i = 2; i < 13; i++) {
        s.a = d_021BB704[i - 2].f8;
        s.b = d_021BB704[i - 2].fC;
        p[6 + i] = func_0204B294(p[0], p[2], p[1], p[3], &s, 0, heap);
        func_0204B92C((struct Obj *)p[6 + i], 0);
    }
    func_02082BCC(&s, 0, 8);
    s.a = 0x80;
    s.b = 0x60;
    s.e = 2;
    s.d = 1;
    p[7] = func_0204B294(p[0], p[4], p[1], p[5], &s, 0, heap);
    func_0204B6F4((struct Obj *)p[7], 6, 1);
    if (func_0203CD98())
        func_0203D34C(1, heap);
}
