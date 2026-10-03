/*
 * unit:     no
 * function: func_02037A44
 * address:  0x02037A44
 * packet:   pkt_02037234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

extern void *func_0203D788(void);
void func_02037A44(int a)
{
    int *r = func_0203D788();
    int *t = *(int **)((char *)r + 0x340);
    if (t == 0)
        return;
    ((void (*)(int))t[0x30])(a);
}
