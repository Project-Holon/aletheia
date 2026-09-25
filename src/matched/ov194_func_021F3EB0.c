/*
 * function: func_021F3EB0
 * address:  0x021F3EB0
 * packet:   pkt_021F3EB0
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC arm
 *   func_0203101C  0x0203101C arm
 */

extern void MI_CpuFill8(void *, int, int);
extern void *func_0203101C(int, int, int, int);

void func_021F3EB0(char *p, int v)
{
    MI_CpuFill8(p, 0, 0x10);
    *(void **)(p + 4) = func_0203101C(v, v, 1, 0);
}
