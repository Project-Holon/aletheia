/*
 * function: PROCSYS_CreateGlobal
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
 *   PROCSYS_CreateInternal 0x02031354 arm
 *   g_02146990 0x02146990 data
 */

extern void *PROCSYS_CreateInternal(int a0);
#define g_02146990 (*(void **)0x02146990)

void PROCSYS_CreateGlobal(int a0)
{
    g_02146990 = PROCSYS_CreateInternal(a0);
}
