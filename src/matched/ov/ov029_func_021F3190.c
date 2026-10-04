/*
 * function: func_021F3190
 * address:  0x021F3190
 * packet:   pkt_021F3190
 * region:   ov029
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020091FC  0x020091FC  thumb
 *   func_0204932C  0x0204932C  arm
 */

int func_020091FC(int a0);
typedef unsigned int   u32;
struct ArcFile;
void func_0204932C(struct ArcFile *arc, u32 member, void *dst);

void func_021F3190(int a0, int a1, int a2)
{
    int x = func_020091FC(a0);

    func_0204932C((struct ArcFile *)a1, a2 + 0x19, (void *)x);
}
