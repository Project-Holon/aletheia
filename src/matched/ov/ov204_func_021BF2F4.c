/*
 * function: func_021BF2F4
 * address:  0x021BF2F4
 * packet:   pkt_021BF2F4
 * region:   ov204
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
 */

typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Rec;
struct Rec3;
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern void func_020061E4(u32 a);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern u32 func_02035C60(void);

int func_021BF2F4(char *a)
{
    if (*(int *)(a + 0x14) != 0) {
        func_020286C4((struct Ctx *)(*(int *)(a + 0x20)), (void *)(*(int *)(a + 0x14)),
                      (void *)(*(int *)(a + 0x1c)));

        switch (func_0201CE30((void *)(*(int *)(a + 0x14)))) {
        case 2:
            func_0201CE48((struct Rec3 *)(*(int *)(a + 0x14)));
            *(int *)(a + 0x14) = 0;
            return 1;
        case 1:
            if (func_020362DC() == 1 || func_020362DC() == 2
                || func_02035C60() != 0) {
                func_0201CE38((void *)(*(int *)(a + 0x14)));
                func_020061E4(0x547);
            }
            break;
        case 0:
            if ((func_0203630C() & 3) != 0 || func_02035C38() != 0)
                func_0201CE5C((struct Rec *)(*(int *)(a + 0x14)), 0);
            break;
        }
        return 0;
    }
    return 0;
}
