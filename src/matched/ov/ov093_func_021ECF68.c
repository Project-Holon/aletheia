/*
 * function: func_021ECF68
 * address:  0x021ECF68
 * packet:   pkt_ov093_021ECF68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case 2 writes the next state in if/else arms (the ternary loses the 0x144 base kept in r5),
 * case 4 decrements with `--` (reload of the halfword), and case 5 restarts the counter from
 * h14a without a decrement.
 *
 * symbols:
 *   func_021ED7C8  0x021ED7C8  thumb  ov093
 *   func_021ED814  0x021ED814  thumb  ov093
 *   func_021B86C0  0x021B86C0  thumb  ov093
 *   PRINTSYS_PrintStreamRun  0x0201CE20  thumb  arm9
 *   PRINTSYS_PrintStreamIsOverrideSpeed  0x0201CED4  thumb  arm9
 *   func_0201CE8C  0x0201CE8C  thumb  arm9
 *   func_02013080  0x02013080  thumb  arm9
 *   func_0201CEB8  0x0201CEB8  thumb  arm9
 *   func_0201CE30  0x0201CE30  thumb  arm9
 *   func_0203630C  0x0203630C  arm  arm9
 *   func_02035C38  0x02035C38  arm  arm9
 *   func_020362DC  0x020362DC  arm  arm9
 *   func_02035C60  0x02035C60  arm  arm9
 *   func_0201DD68  0x0201DD68  thumb  arm9
 *   func_0201CE48  0x0201CE48  thumb  arm9
 *   func_0201CE38  0x0201CE38  thumb  arm9
 *   GFL_USE_IsSeqPlaying  0x02006254  thumb  arm9
 *   func_020061E4  0x020061E4  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S;
struct T {
    u8 pad0[0x30];
    void *h30;
    u8 pad34[0x100];
    u8 **owner;
    u8 pad138[6];
    u8 b13e;
    u8 b13f;
    u8 pad140;
    u8 b141;
    u8 pad142[2];
    int i144;
    u16 h148;
    u16 h14a;
    u16 h14c;
    u8 pad14e[6];
    u8 s154[1];
};
extern void func_021ED7C8(struct S *, int);
extern int func_021ED814(struct S *);
extern u8 func_021B86C0(u8 **);
extern void PRINTSYS_PrintStreamRun(void *);
typedef signed int     s32;
struct Rec;
struct Rec3;
extern u32 PRINTSYS_PrintStreamIsOverrideSpeed(struct Rec *p);
extern void func_0201CE8C(struct Rec *p, s32 v);
extern signed char func_02013080(u32 idx);
extern void func_0201CEB8(struct Rec *p);
extern u32 func_0201CE30(void *p);
extern u32 func_0203630C(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201DD68(void);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *);
extern int GFL_USE_IsSeqPlaying(u32 a);
extern void func_020061E4(u32 a);
int func_021ECF68(struct T *p)
{
    switch (p->b13f) {
    case 0:
        func_021ED7C8((struct S *)p->s154, p->b13e);
        p->b13f = p->b13f + 1;
    case 1:
        if (func_021ED814((struct S *)p->s154) == 0)
            break;
        if (p->b13e != 0) {
            p->b13f = 6;
            break;
        }
        if (p->h30 != 0)
            PRINTSYS_PrintStreamRun(p->h30);
        p->b13f = p->b13f + 1;
    case 2:
        if (p->h30 != 0) {
            if (func_021B86C0(p->owner) == 0) {
                if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
                    if (PRINTSYS_PrintStreamIsOverrideSpeed(p->h30) == 0)
                        func_0201CE8C(p->h30, func_02013080(2));
                } else {
                    if (PRINTSYS_PrintStreamIsOverrideSpeed(p->h30) != 0)
                        func_0201CEB8(p->h30);
                }
            }
            p->i144 = func_0201CE30(p->h30);
            if (p->i144 != 0) {
                if (func_021B86C0(p->owner) == 0)
                    p->b13f = 3;
                else
                    p->b13f = 4;
                if (p->i144 == 2) {
                    p->h148 = p->h14c;
                    p->b141 = 1;
                }
            }
        } else {
            p->b13f = 6;
        }
        break;
    case 3:
        if ((func_020362DC() & 3) != 0 || func_02035C60() != 0)
            p->h148 = 0;
        if (p->h148 != 0) {
            p->h148 = p->h148 - 1;
            break;
        }
        p->b13f = 5;
        break;
    case 4:
        if (p->h148 != 0) {
            p->h148--;
            break;
        }
        p->b13f = 5;
        break;
    case 5:
        if (p->i144 == 2) {
            func_0201DD68();
            func_0201CE48(p->h30);
            p->h30 = 0;
            p->b13f = 6;
            break;
        }
        func_0201CE38(p->h30);
        func_020061E4(0x547);
        p->b13f = 2;
        p->h148 = p->h14a;
        break;
    case 6:
        if (GFL_USE_IsSeqPlaying(0x547) == 0) {
            p->b13f = 7;
            return 1;
        }
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}
