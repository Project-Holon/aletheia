/*
 * file:     bsubway_scr_p11.c
 * unit:     yes
 * function: func_021C8FE0, func_021C8FF0, func_021C9064
 * address:  0x021C8FE0
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
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0204784C  0x0204784C  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047828  0x02047828  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DABCC     0x021DABCC  data  a4
 *   d_021DABB8  0x021DABB8  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */
struct AnmCtl;
struct Arg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 x, y, z; } V;

typedef struct T_021C8FF0 { int w[15]; } T_021C8FF0;

typedef signed int     s32;

typedef struct { u32 a; V v; u32 c; } T_021C9064;

extern void func_021AC154(u32 a);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern int func_020478B8(void *a, int idx, int amount);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern void func_0207ADC4(int *m);
extern void func_021AC1B8(u32 a, T_021C8FF0 *t);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
void func_021C8FE0(u32 a, u32 *p);
void func_021C8FF0(u32 a, u32 *b);
void func_021C9064(u32 a, V *v, u32 c);
extern T_021C8FF0 d_021DABCC;
extern u8 d_021DABB8[];

void func_021C8FE0(u32 a, u32 *p)
{
    if (p[2] == 1)
        func_021AC154(a);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C8FF0(u32 a, u32 *b)
{
    T_021C8FF0 t;
    u32 h;

    if (b[2] == 0) {
        t = d_021DABCC;
        h = *(u32 *)(b[0] + 0x30);
        func_0204784C((struct AnmCtl *)h, 0, (s32 *)(b + 1));
        if (func_020478B8((void *)h, 0, 0x1000) == 0) {
            b[2] = 1;
        }
        if (func_02047828((struct AnmCtl *)h, 0, (s32 *)(b + 1)) == 0) {
            b[2] = 1;
        }
        func_0207ADC4(&t.w[6]);
        func_021AC1B8(a, &t);
        func_02047AC8((void *)h, (struct Arg *)(&t));
    }
}

void func_021C9064(u32 a, V *v, u32 c)
{
    T_021C9064 t;
    t.a = func_021ABEA0(a, 0xb);
    t.v = *v;
    t.c = c;
    func_021ABFA8(a, d_021DABB8, 0, 0, &t, 0);
}
