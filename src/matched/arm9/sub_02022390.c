/*
 * function: func_02022390
 * address:  0x02022390
 * packet:   pkt_02022390
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020223AC  0x020223AC  thumb
 */

typedef unsigned int u32;

extern u32 func_020223AC(void *p);

void func_02022390(u32 *obj, void *arg)
{
    if (*obj != 0) {
        if (func_020223AC(arg) == 1) {
            *obj = 0;
        }
    }
}
