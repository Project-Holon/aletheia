/*
 * function: func_021B50D0
 * address:  0x021B50D0
 * packet:   pkt_ov021_021B50D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: func_0216EFCC is an unlabelled ov010 leaf (ldr r1,=0x021725B8;
 * ldrb r0,[r1,r0]; 0xFF maps to 1) with no witness outside this range; every
 * byte is right. Filing that ov010 leaf (outside this lane) would close it.
 *
 * symbols:
 *   func_02012A44  0x02012A44  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0216EFCC  0x0216EFCC  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5E4(u32);
extern u32 func_02012A44(u32);
extern u16 *func_02159AE8(u32, u32);
extern u16 func_0216EFCC(u32);

int func_021B50D0(u32 a, u32 b)
{
    u32 x = func_02012A44(func_0215A5E4(b));
    u16 *o = func_02159AE8(a, b);

    *o = func_0216EFCC(x);
    return 0;
}
