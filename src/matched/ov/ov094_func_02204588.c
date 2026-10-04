/*
 * function: func_02204588
 * address:  0x02204588
 * packet:   pkt_ov094_02204588
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef struct Bits { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits;
typedef unsigned int   u32;
struct S02030EE8;
extern u32 func_02030EE8(struct S02030EE8 *p);

void func_02204588(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    ((Bits *)(p + 0x68))->n--;
}
