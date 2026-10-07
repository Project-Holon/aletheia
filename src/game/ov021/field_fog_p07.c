/*
 * file:     field_fog_p07.c
 * unit:     yes
 * function: func_0219FFD4, func_021A000C, func_021A006C, func_021A0084
 * address:  0x0219FFD4
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D538  0x0216D538  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0219D738  0x0219D738  thumb  ov021
 *   func_021642D4  0x021642D4  thumb  ov010
 *   func_020507A0  0x020507A0  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_02197C9C  0x02197C9C  thumb  ov021
 *   func_0219C648  0x0219C648  thumb  ov021
 *   func_0216D6D8  0x0216D6D8  thumb  ov010
 *   func_0219D634  0x0219D634  thumb  ov021
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219D49C  0x0219D49C  thumb  ov021
 *   func_021C6664  0x021C6664  thumb  ov021
 *   func_021C6678  0x021C6678  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void *func_0216D67C(void *a0);
extern u32 func_0216D538(u8 *p);
extern u16 func_0216D5F8(void *p);
extern int func_0216D55C(int a0, int a1);
extern u32 func_0219D738(u32 a, int b);
extern u8 func_021642D4(int i, int v);
extern int func_0219C648(u32 a);
extern int func_02197C9C(u32 a);
extern int func_0216DAB4(void *a0);
extern void func_020507F0(void *p, int idx, u32 v);
extern int func_020507A0(void *p, int idx, u32 x);
extern void *func_0216D6D8(int a0, int a1);
extern u32 func_0219D634(u32 a);
extern void *func_0216D6F0(void *p);
extern u32 func_0219D49C(u32);
extern void func_02197CCC(u8 *p, s32 *out);
extern void func_021C6664(u32, u32, u32 *);
extern void func_021C6678(u32, u32, u32);
extern int func_021C66EC(u32 *a, int idx, int v);
void func_0219FFD4(u32 a);
void func_021A000C(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021A006C(u32 a);
void func_021A0084(u32 a);


void func_0219FFD4(u32 a)
{
    u32 x = func_0216D538(func_0216D67C((void *)a));
    u32 y = func_0216D5F8((void *)a);
    if (func_0216D55C(a, 0x2000))
        func_0219D738(a, x);
    else
        func_021642D4(y, x);
}


/*
 * Blocked at MATCH: func_020507F0 (0x020507F0) is an unlabelled arm9 leaf
 * (Ilias's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   void func_020507F0(u8 *p, int i, u32 v) { *(u32 *)(*(u8 **)(p + 0x18) + i * 40 + 0x18) = v; }  (EXACT, verified)
 *
 * Addresses are Black-image addresses.
 */
void func_021A000C(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 f;
    u32 k;

    f = 1;
    k = func_0219C648(a);
    if (d == 0) {
        if (e == 1) {
            if (k == 1 && func_0216D55C(a, 0x10) != 0) f = 0;
        } else {
            if (k == 1 && func_02197C9C(a) == 1) f = 0;
        }
    }
    func_020507F0((void *)b, c, f);
    f = 1;
    if (func_0216DAB4((void *)a) == 1) f = 0;
    func_020507A0((void *)b, c, f);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A006C(u32 a)
{
    u16 *q = (u16 *)func_0216D6D8(a, 2);
    *q = func_0219D634(a);
}


void func_021A0084(u32 a)
{
    u32 f;
    u32 q;
    u32 buf[3];
    u16 *p;

    p = func_0216D6F0((void *)a);
    q = func_0219D49C(a);
    func_02197CCC((u8 *)a, (s32 *)buf);
    func_021C6664(q, *p, buf);
    f = 0;
    if (func_0216DAB4((void *)a) == 1) f = 1;
    func_021C6678(q, *p, f);
    if (func_02197C9C(a) == 0) {
        func_021C66EC((u32 *)q, *p, 0x1000);
    }
}
