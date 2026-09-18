/*
 * unit:     no
 * function: func_0209D820
 * address:  0x0209D820
 * packet:   pkt_0209D784
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * symbols:
 *   g_handlerTable  0x020A64F8  data
 */

typedef void (*Handler)(void);

void func_0209D820(void)
{
    Handler *p = (Handler *)0x020A64F8;
    while (p != 0 && *p != 0)
    {
        (*p)();
        p++;
    }
}