/*
 * unit:     no
 * function: func_02029F14
 * address:  0x02029F14
 * packet:   pkt_02029DD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02029F6C has no witness outside this range
 */

extern void *func_02030734(void *a, int size, int b, void *name, int line);
extern void func_02029F6C(void);
extern void *g_02146944;
void *func_02029F14(void *a, int v)
{
    char *p = (char *)func_02030734(a, 0xc, 1, (void *)0x020A76BC, 0x72);
    *(unsigned short *)(p + 4) = 0;
    *(int *)(p + 8) = v;
    g_02146944 = p;
    func_02029F6C();
    return p;
}
