/*
 * function: NHTTPi_idleCommThread
 * address:  0x021B9BF4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Queries one field of the resource `a` into a throwaway local.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02085E50(int, int *, int);

void NHTTPi_idleCommThread(int a)
{
    int tmp;

    func_02085E50(a, &tmp, 1);
}
