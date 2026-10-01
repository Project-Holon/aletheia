/*
 * function: func_02204AEC
 * address:  0x02204AEC
 * packet:   pkt_ov094_02204AEC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef struct Bits { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits;
extern char **func_02030EE8(void *h);

void func_02204AEC(void *h)
{
    char *p = *func_02030EE8(h);
    ((Bits *)(p + 0x68))->n--;
}
