/*
 * function: func_02159398
 * address:  0x02159398
 * packet:   pkt_02159398
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Halfword out of the record the overlay looks up, classified through an
 * arm9 call, and the class byte stored back on the object.
 *
 * symbols:
 *   func_02159AE8   0x02159AE8  thumb  ov010
 *   func_0215932C   0x0215932C  thumb  ov010
 *   func_02011330   0x02011330  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02011330(void *);
extern u8 func_0215932C(u16, void *);

int func_02159398(void *a0, void *a1)
{
    u16 v = *func_02159AE8(a0, a1);

    *(u8 *)((char *)a0 + 0xE) = func_0215932C(v, func_02011330(a0));

    return 0;
}

