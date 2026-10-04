/*
 * function: func_021EDBE8
 * address:  0x021EDBE8
 * packet:   pkt_ov093_021EDBE8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020437AC  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

struct Obj020437AC;
extern void func_020437AC(struct Obj020437AC *p);
extern void func_020307B0(void *p);

void func_021EDBE8(char *s)
{
    u32 i;

    for (i = 0; i < 2; i++) {
        if (*(int *)(s + i * 0x24 + 0x94) != 0) {
            func_020437AC((struct Obj020437AC *)(*(int *)(s + i * 0x24 + 0x94)));
            *(int *)(s + i * 0x24 + 0x94) = 0;
        }
    }
    if (*(int *)(s + 0xd8) != 0) {
        func_020307B0((void *)(*(int *)(s + 0xd8)));
        *(int *)(s + 0xd8) = 0;
    }
}
