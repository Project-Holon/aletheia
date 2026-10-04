/*
 * function: func_021F2C10
 * address:  0x021F2C10
 * packet:   pkt_ov029_021F2C10
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B98C  0x0204B98C  arm
 */

struct Obj;
extern void func_0204B92C(struct Obj *a, unsigned int b);
typedef unsigned int   u32;
struct Actor;
extern void func_0204B954(struct Actor *a, u32 v);
extern u32 func_0204B98C(struct Actor *a);

int func_021F2C10(char *p)
{
    switch (*(unsigned char *)(p + 0x455)) {
    case 0:
        func_0204B92C((struct Obj *)*(int *)(p + *(unsigned char *)(p + 0x416) * 4 + 0x12c), 1);
        func_0204B954((struct Actor *)(*(int *)(p + *(unsigned char *)(p + 0x416) * 4 + 0x12c)), 1 << 13);
        *(unsigned char *)(p + 0x455) += 1;
        break;
    case 1:
        if (func_0204B98C((struct Actor *)(*(int *)(p + *(unsigned char *)(p + 0x416) * 4 + 0x12c))) == 0)
            return 1;
        break;
    }
    return 0;
}
