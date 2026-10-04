/*
 * function: func_02205340
 * address:  0x02205340
 * packet:   pkt_02205340
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 */

struct Ctx;
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);

void func_02205340(int a, char *b)
{
    func_020310C4((struct Tcbl *)(*(int *)(b + 0x68)));
    if (*(int *)(b + 0x64) != 0)
        func_020286C4((struct Ctx *)(*(int *)(b + 0x84)), (void *)(*(int *)(b + 0x64)), (void *)(*(int *)(b + 0x6c)));
}
