/*
 * function: func_0216DBCC
 * address:  0x0216DBCC
 * packet:   pkt_0216DBCC
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

int func_0216DBCC(void *a0, u32 a1, int a2)
{
    if (a1 == 1)
        return func_0216D568(a0, 0x40000, a2);

    return func_0216D570(a0, 0x40000, a2);
}

