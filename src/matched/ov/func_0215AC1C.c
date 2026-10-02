/*
 * function: func_0215AC1C
 * address:  0x0215AC1C
 * packet:   pkt_0215AC1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The arm9 chain result is biased by the record's own 0x20 before the
 * halfword store.
 *
 * symbols:
 *   func_02159AE8   0x02159AE8  thumb  ov010
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_020127A4   0x020127A4  thumb
 *   func_02008550   0x02008550  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern int func_020127A4(void *);
extern int func_02008550(int);

int func_0215AC1C(void *a0, void *a1)
{
    u16 *p = func_02159AE8(a0, a1);

    *p = (u16)func_02008550(func_020127A4(func_0215A5E4(a1)) + 0x20);

    return 0;
}

