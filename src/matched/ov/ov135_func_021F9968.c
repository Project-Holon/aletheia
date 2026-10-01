/*
 * function: func_021F9968
 * address: 0x021F9968
 * packet: pkt_ov135_021F9968
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021F99CE.
 */
typedef unsigned char u8;
typedef signed short s16;
void func_021F9968(u8 *p, int mode)
{
    *(s16 *)(p + 84) = mode;
    switch (mode) {
    case 0:
        p[122] = 0;
        *(int *)(p + 68) = 0;
        *(s16 *)(p + 56) = 0;
        *(s16 *)(p + 58) = 0;
        *(int *)(p + 72) = 6;
        return;
    case 3:
        p[122] = 0;
        *(int *)(p + 68) = 0;
        *(s16 *)(p + 56) = 0;
        *(s16 *)(p + 58) = 0;
        *(int *)(p + 72) = 18;
        return;
    case 1:
        p[122] = 0;
        *(int *)(p + 68) = 0;
        *(int *)(p + 72) = 30;
        return;
    case 2:
        p[122] = 0;
        *(int *)(p + 68) = 0;
        *(int *)(p + 72) = 33;
        break;
    }
}
