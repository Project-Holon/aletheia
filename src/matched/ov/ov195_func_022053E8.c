/*
 * function: func_022053E8
 * address:  0x022053E8
 * packet:   pkt_022053E8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_020355D8  0x020355D8  arm
 *
 * The `(x & 3) != 0 ? 0 : 1` call arguments must be written as an explicit
 * if/else. The ternary makes mwccarm pick the opposite branch polarity and
 * then colour the pointer r5/result r4 the other way; the if/else gives the
 * original pointer r4 / result r5 split and the shared return. See
 * docs/idioms/a-ternary-constant-call-argument-takes-the-opposite-branch-polarity.md.
 */

typedef unsigned int u32;

typedef signed int     s32;
struct Rec;
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
typedef unsigned char  u8;
extern void func_020061E4(u32 a);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern u32 func_02035C60(void);
extern void func_020355D8(u8 v);

int func_022053E8(char *a)
{
    int r = 0;

    switch (func_0201CE30((void *)(*(u32 *)(a + 0x64)))) {
    case 0:
        if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
            func_0201CE5C((struct Rec *)(*(u32 *)(a + 0x64)), 0);
            if ((func_0203630C() & 3) != 0)
                func_020355D8(0);
            else
                func_020355D8(1);
        }
        break;
    case 1:
        if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
            func_020061E4(0x547);
            func_0201CE38((void *)(*(u32 *)(a + 0x64)));
            if ((func_020362DC() & 3) != 0)
                func_020355D8(0);
            else
                func_020355D8(1);
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}
