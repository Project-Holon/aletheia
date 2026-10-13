/*
 * function: func_022102BC
 * address:  0x022102BC
 * packet:   pkt_022102BC
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   func_02211984  0x02211984  thumb  ov198
 */

typedef unsigned int u32;

struct S {
    unsigned char pad[0x1eb0];
    int f1eb0;
    int f1eb4;
};

typedef signed int     s32;
typedef unsigned char  u8;
struct Rec;
struct Rec3;
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern void func_02211984(u8 **p, u32 b);

int func_022102BC(struct S *a)
{
    switch (func_0201CE30((void *)a->f1eb0)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (func_0203630C() & 3) != 0)
            func_0201CE5C((struct Rec *)a->f1eb0, 0);
        a->f1eb4 = 0;
        break;
    case 1:
        if (a->f1eb4 != 0)
            break;
        if (TOUCHPANEL_GetTrg() == 1 || (func_020362DC() & 3) != 0) {
            func_02211984((u8 **)a, 0x547);
            func_0201CE38((void *)a->f1eb0);
            a->f1eb4 = 1;
        }
        break;
    case 2:
        func_0201CE48((struct Rec3 *)a->f1eb0);
        a->f1eb0 = 0;
        a->f1eb4 = 0;
        return 0x18;
    }
    return 0x17;
}
