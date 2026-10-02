/*
 * function: func_0216D7A8
 * address: 0x0216D7A8
 * packet: pkt_ov010_0216D7A8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */

typedef int (*Callback)(void *, unsigned int);
int func_0216D7A8(void *p, unsigned int v)
{
    Callback f;
    f = *(Callback *)((char *)*(void **)((char *)p + 0x90) + 0x14);
    if (f != 0)
        return f(p, v);
    return 0;
}
