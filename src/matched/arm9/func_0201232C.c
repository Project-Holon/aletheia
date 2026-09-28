/*
 * function: func_0201232C
 * address:  0x0201232C
 * packet:   pkt_0201232C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_020A727C      0x020A727C  data
 */

extern char g_020A727C[];
extern void func_020307B0(void *p);
extern void *func_02030734(int a, int b, int c, void *d, int e);
void func_0201232C(char *p, int a1, int a2)
{
    void *q;
    *(int *)(p + 8) = 0;
    q = *(void **)(p + 0xc);
    *(int *)(p + 4) = a1;
    if (q)
        func_020307B0(q);
    *(void **)(p + 0xc) = func_02030734(4, a2, 1, g_020A727C, 0x60);
}
