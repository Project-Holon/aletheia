/*
 * function: SCRCMD_PROC_FLD_AddUniqueU16
 * address:  0x021B5190
 * packet:   pkt_ov021_021B5190
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:

 */

typedef unsigned short u16;

u16 SCRCMD_PROC_FLD_AddUniqueU16(u16 *arr, u16 n, u16 v)
{
    int i;

    for (i = 0; i < n; i++) {
        if (v == arr[i]) {
            return n;
        }
    }
    arr[n] = v;
    return n + 1;
}
