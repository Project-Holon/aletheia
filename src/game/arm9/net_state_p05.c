/*
 * file:     net_state_p05.c
 * unit:     yes
 * function: func_0203B5D4, func_0203B688, func_0203B6B4
 * address:  0x0203B5D4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_020393A8  0x020393A8  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203B2A8  0x0203B2A8  arm
 *   func_0203D700  0x0203D700  arm
 *   func_0203AD80  0x0203AD80  arm
 *   g_021469DC     0x021469DC  data
 *   func_0203B52C  0x0203B52C  arm
 *   str_0203B48C   0x0203B48C  data
 *   func_0203B344  0x0203B344  arm
 */
struct NetState;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char s8;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct NetState {
    u32  f00;
    u32  f04;
    void (*f08)(struct NetState *s);
    MATHRandContext64 rng;
    u32  f24;
    void (*f28)(void);
    void (*f2C)(u32 a);
    u32  err[4];
    u8   mac[6];
    u16  f46;
    s8   flag;
    u8   pad49;
    u8   f4A;
    u8   f4B;
    u8   f4C;
    u8   f4D;
    u8   pad4E;
    u8   f4F;
    u8   f50;
    u8   f51;
    u8   pad52;
    u8   f53;
    u8   pad54[2];
    u8   f56;
    u8   addr[6];
    u8   pad5D[7];
};

struct Vt {
    u8  pad_00[0x38];
    u32 (*f38)(u32 a);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt *f340;
};

extern void func_0203B52C(struct NetState *p);
extern void *func_0203D788(void);
extern int func_020393A8(void);
extern u8   *func_0203D798(void);
extern void func_0203B2A8(int a0);
extern void  func_0203D700(void);
extern void func_0203AD80(struct NetState *s, void *p, u32 v, int line);
extern u32 func_0203B344(struct NetState *p);
void func_0203B5D4(struct NetState *p);
void func_0203B688(struct NetState *a0);
int func_0203B6B4(void);
extern struct NetState *g_021469DC;
extern char str_0203B48C[];


void func_0203B5D4(struct NetState *p)
{
    struct Obj *q = (struct Obj *)func_0203D788();

    if (func_020393A8() != 0) {
        func_0203B2A8(*(u16 *)(func_0203D798() + 0x56));
        func_0203D700();
        func_0203AD80(g_021469DC, (void *)func_0203B52C, 0, 0x2c1);
        return;
    }
    if (p->f56 == 1)
        return;
    if (q->f340->f38(0) == 0)
        return;
    if (p->f46 != 0) {
        p->f46--;
        return;
    }
    func_0203AD80(g_021469DC, str_0203B48C, 0, 0x2d3);
}


void func_0203B688(struct NetState *a0)
{
    func_0203AD80(g_021469DC, (void *)func_0203B5D4, func_0203B344(a0), 0x2e0);
}


int func_0203B6B4(void)
{
    func_0203AD80(g_021469DC, (void *)func_0203B5D4, func_0203B344(g_021469DC), 0x2E6);
    return 1;
}
