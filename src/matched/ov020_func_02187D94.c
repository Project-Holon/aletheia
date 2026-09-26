/*
 * function: func_02187D94
 * address:  0x02187D94
 * packet:   pkt_02187D94
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    unsigned char _pad[0x20];
    void (*fn)(int);
    int arg;
} T_02187D94;

void func_02187D94(T_02187D94 *p)
{
    if (p->fn)
        p->fn(p->arg);
}
