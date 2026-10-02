/*
 * function: func_021693A0
 * address:  0x021693A0
 * packet:   pkt_021693A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02049238(void *arc);

void func_021693A0(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x10);
    if (a0 == 0) goto loc_021693B2;
loc_021693AA:
    func_02049238((void *)a0);
loc_021693AE:
a0 = 0;
*(int *)((char *)t4 + 0x10) = a0;
loc_021693B2:
    return;}
