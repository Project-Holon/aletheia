/*
 * function: func_0200846C
 * address:  0x0200846C
 * packet:   pkt_0200846C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_020A70AC      0x020A70AC  data
 *   g_020A70C4      0x020A70C4  data
 *   g_0209DDB4      0x0209DDB4  data
 *   g_020A716C      0x020A716C  data
 */

extern char g_020A70AC[];
extern void *func_02030734(int a, int b, int c, void *d, int e);
extern void func_020084A0(void *p);
void *func_0200846C(int a0)
{
    void *p = func_02030734((unsigned short)a0, 0x20, 0, g_020A70AC, 0x34);
    func_020084A0(p);
    return p;
}
