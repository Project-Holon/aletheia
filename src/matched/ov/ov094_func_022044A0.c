/*
 * function: func_022044A0
 * address:  0x022044A0
 * packet:   pkt_ov094_022044A0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_IsDeletePending  0x02030EE8  arm  arm9
 */
typedef struct Bits { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits;
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

void func_022044A0(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((Bits *)(p + 0x68))->n--;
}
