/*
 * function: func_0215AABC
 * address:  0x0215AABC
 * packet:   pkt_0215AABC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Same slot overwrite, keyed off the second index helper and the
 * caller's second argument.
 *
 * symbols:
 *   func_02159AE8   0x02159AE8  thumb  ov010
 *   func_02159B10   0x02159B10  thumb  ov010
 *   func_020056EC   0x020056EC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u32 func_020056EC(u32 range);

int func_0215AABC(void *a0, void *a1)
{
    u16 *p = func_02159AE8(a0, a1);

    *p = (u16)func_020056EC(func_02159B10(a0, a1));

    return 0;
}

