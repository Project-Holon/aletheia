/*
 * function: func_02204678
 * address:  0x02204678
 * packet:   pkt_ov094_02204678
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef struct Bits { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits;
extern char **func_02030EE8(void *h);

void func_02204678(void *h)
{
    char *p = *func_02030EE8(h);
    ((Bits *)(p + 0x68))->n--;
}
