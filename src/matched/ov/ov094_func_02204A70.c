/*
 * function: func_02204A70
 * address:  0x02204A70
 * packet:   pkt_ov094_02204A70
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef struct Bits { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits;
extern char **func_02030EE8(void *h);

void func_02204A70(void *h)
{
    char *p = *func_02030EE8(h);
    ((Bits *)(p + 0x68))->mode = 0;
}
