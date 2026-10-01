/*
 * function: func_02204940
 * address:  0x02204940
 * packet:   pkt_ov094_02204940
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef struct Bits { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits;
extern char **func_02030EE8(void *h);

void func_02204940(void *h)
{
    char *p = *func_02030EE8(h);
    ((Bits *)(p + 0x68))->n--;
}
