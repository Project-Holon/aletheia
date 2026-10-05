/*
 * function: func_0216DCE8
 * address:  0x0216DCE8
 * packet:   pkt_0216DCE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The first argument picks which of the pair of field setters
 * takes the shifted mask and the value.
 *
 * symbols:
 *   func_0216D568   0x0216D568  thumb  ov010
 *   func_0216D570   0x0216D570  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D568(void *, unsigned, int);
extern int func_0216D570(void *, unsigned, int);

int func_0216DCE8(void *a0, int a1, int a2)
{
    if (a1 == 1)
        return func_0216D568(a0, 0x200000, a2);

    return func_0216D570(a0, 0x200000, a2);
}

