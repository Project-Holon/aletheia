/*
 * function: sub_02010E14
 * address:  0x02010E14
 * packet:   pkt_02010DB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocking: unresolved: 0202141C (data, from header) has no witness outside 02010E14..02010E; unresolved: 020214E8 (data, from header) has no witness outside 02010E14..02010E; unresolved: 0202142A (data, from header) has no witness outside 02010E14..02010E; unresolved: 02021428 (data, from header) has no witness outside 02010E14..02010E
 *
 * symbols:
 *   sub_02010F50   0x02010F50  thumb
 *   g0202141C      0x0202141C  data
 *   g02021428      0x02021428  data
 *   g0202142A      0x0202142A  data
 *   g020214E8      0x020214E8  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void sub_02010F50(int a);
extern u8   g0202141C[];
extern u8   g02021428[];
extern u8   g0202142A[];
extern u8   g020214E8[];

void sub_02010E14(int a0, u8 *a1, int a2)
{
    int k;

    if (a0 >= 0x30) {
        return;
    }
    a1 = a1 + a0 * 0xc;
    k = a1[0xa];
    g0202141C[k] = (u8)a0;
    *(u32 *)(g020214E8 + k * 4) = (u32)(a1[0xb] * 0xe10);
    *(u16 *)(g0202142A + k * 2) = *(u16 *)(a1 + 8);
    if (g02021428[0x1c] == k) {
        g02021428[0x1c] = 0xd;
    }
    if (a2 == 1) {
        g02021428[0x1c] = (u8)k;
    }
    switch (k) {
    case 0:
        sub_02010F50(1);
        break;
    case 1:
        sub_02010F50(0);
        break;
    case 7:
        sub_02010F50(8);
        break;
    case 8:
        sub_02010F50(7);
        break;
    }
}
