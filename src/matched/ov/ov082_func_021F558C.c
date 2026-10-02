/*
 * function: func_021F558C
 * address: 0x021F558C
 * packet: pkt_ov082_021F558C
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02189A60 0x02189A60 thumb ov021
 */
typedef unsigned char u8;
extern u8 **func_02189A60(u8 *p);
void func_021F558C(u8 *p) { u8 *w = *func_02189A60(p); *(int *)(w+0x1c)=0; *(int *)(w+0x74)=1; }
