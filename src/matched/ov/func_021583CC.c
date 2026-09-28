/*
 * function: func_021583CC
 * address:  0x021583CC
 * packet:   pkt_021583CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dispatch on the record's key: an equal key goes to the
 * single-argument arm9 read, anything else to the pair form.
 *
 * symbols:
 *   func_02012B58   0x02012B58  thumb
 *   func_020127B8   0x020127B8  thumb
 *   func_020127AC   0x020127AC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012B58(void *);
extern int func_020127B8(void *);
extern int func_020127AC(void *, int);

int func_021583CC(void *a0, int a1)
{
    if (func_02012B58(a0) == a1)
        return func_020127B8(a0);

    return func_020127AC(a0, a1);
}

