/*
 * function: func_021ECF68
 * address:  0x021ECF68
 * packet:   pkt_ov093_021ECF68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 (wave B2 lane 06): the lane list says 30 bytes but the real extent is 432 bytes
 * (8-state switch over p->b13f, jump table at 021ECF82; cases 0..2 fall through).
 * Draft matches the dispatch and cases 3..6 (same instruction sequence, shifted by 8 bytes);
 * remaining diff is case 2: the original lays the `h30 == 0` else arm (strb 6 through a pool
 * 0x13f) after the main arm, keeps 0x144 in r5 (state stored via r5-5, owner via r5-0x10) and
 * re-materialises 0x144 in r1 for the i144 == 2 test; mine uses a pool 0x13f and r1 throughout.
 * Draft is 424 bytes vs 432.
 *
 * symbols:
 *   func_021ED7C8  0x021ED7C8  thumb  ov093
 *   func_021ED814  0x021ED814  thumb  ov093
 *   func_021B86C0  0x021B86C0  thumb  ov093
 *   func_0201CE20  0x0201CE20  thumb  arm9
 *   func_0201CED4  0x0201CED4  thumb  arm9
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
 *   func_02006254  0x02006254  thumb  arm9
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
extern void func_0201CE20(void *);
extern int func_0201CED4(void *);
extern void func_0201CE8C(void *, int);
extern int func_02013080(int);
extern void func_0201CEB8(void *);
extern int func_0201CE30(void *);
extern u32 func_0203630C(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201DD68(void);
extern void func_0201CE48(void *);
extern void func_0201CE38(void *);
extern int func_02006254(int);
extern void func_020061E4(int);
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
            func_0201CE20(p->h30);
        p->b13f = p->b13f + 1;
    case 2:
        if (p->h30 != 0) {
            if (func_021B86C0(p->owner) == 0) {
                if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
                    if (func_0201CED4(p->h30) == 0)
                        func_0201CE8C(p->h30, func_02013080(2));
                } else {
                    if (func_0201CED4(p->h30) != 0)
                        func_0201CEB8(p->h30);
                }
            }
            p->i144 = func_0201CE30(p->h30);
            if (p->i144 != 0) {
                p->b13f = func_021B86C0(p->owner) == 0 ? 3 : 4;
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
        if (p->h148 == 0) {
            p->b13f = 5;
            break;
        }
        p->h148 = p->h148 - 1;
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
        p->h148 = p->h14a - 1;
        break;
    case 6:
        if (func_02006254(0x547) == 0) {
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
