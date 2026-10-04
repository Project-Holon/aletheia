/*
 * function: func_021BADF0
 * address:  0x021BADF0
 * packet:   pkt_ov070_021BADF0
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_0201CE5C  0x0201CE5C  thumb
 */

typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Rec;
struct Rec3;
extern u32 func_0201CE30(void *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020061E4(u32 a);
extern void func_0201CE38(void *p);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern void func_0201CE5C(struct Rec *p, s32 v);

int func_021BADF0(int p)
{
    int r;

    if (*(int *)(p + 0x510) != 0) {
        r = func_0201CE30((void *)(*(int *)(p + 0x510)));
        func_020286C4((struct Ctx *)(*(int *)(p + 0x518)), (void *)(*(int *)(p + 0x510)), (void *)(*(int *)(p + 0x4FC)));
        switch (r) {
        case 2:
            func_0201CE48((struct Rec3 *)(*(int *)(p + 0x510)));
            *(int *)(p + 0x510) = 0;
            *(int *)(p + 0x514) = 0;
            break;
        case 1:
            if (*(int *)(p + 0x514) == 0) {
                if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
                    func_020061E4(0x547);
                    func_0201CE38((void *)(*(int *)(p + 0x510)));
                    *(int *)(p + 0x514) = 1;
                }
            }
            break;
        case 0:
            if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
                func_0201CE5C((struct Rec *)(*(int *)(p + 0x510)), 0);
            }
            *(int *)(p + 0x514) = 0;
            break;
        }
        return 0;
    }
    return 1;
}
