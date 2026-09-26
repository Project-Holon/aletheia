/*
 * function: func_021B6CCC
 * address:  0x021B6CCC
 * packet:   pkt_021B6CCC
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 */

extern void func_02045808(int v);
extern void ENV_SetResourceSet(void *p);

void func_021B6CCC(int *p)
{
    func_02045808(p[0]);
    ENV_SetResourceSet(p);
}
