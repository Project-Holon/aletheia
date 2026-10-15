/*
 * function: func_0215A4B4
 * address:  0x0215A4B4
 * packet:   pkt_0215A4B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);

int func_0215A4B4(int a0)
{
    int a1;

a1 = 2;
    a0 = TPOKE_DATA_GetRecordField((void *)a0, a1);
loc_0215A4BC:
    if (a0 != 1) goto loc_0215A4C4;
loc_0215A4C0:
a0 = 1;
    return a0;
loc_0215A4C4:
a0 = 0;
    return a0;}
