/*
 * function: func_021B8F68
 * address: 0x021B8F68
 * packet: pkt_ov070_021B8F68
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent follower 021B8F90 is already filed separately; no unit here.
 * symbols:
 *   func_02012B70 0x02012B70 thumb
 */
extern int func_02012B70(int object);
int func_021B8F68(char *p, int value)
{
    if (*(int *)(p + 0x10) == 3 || *(int *)(p + 0x10) == 1)
        return 0;
    if (func_02012B70(*(int *)p) == 1 && value == 4)
        return 0;
    return 1;
}
