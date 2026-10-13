/*
 * function: BTL_CLIENT_GetCursor
 * address:  0x021CDD94
 * packet:   pkt_021CDD94
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 12, compiled 10, trailing padding)
 */

typedef struct {
    int a;
    int b;
} S;

void BTL_CLIENT_GetCursor(char *p, int *o)
{
    *(S *)o = *(S *)(p + 0x2c);
}
