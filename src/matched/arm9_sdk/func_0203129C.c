/*
 * function: func_0203129C
 * address:  0x0203129C
 * packet:   pkt_0203129C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02031354 0x02031354 arm
 *   g_02146990 0x02146990 data
 */

extern void *func_02031354(int a0);
#define g_02146990 (*(void **)0x02146990)

void func_0203129C(int a0)
{
    g_02146990 = func_02031354(a0);
}
