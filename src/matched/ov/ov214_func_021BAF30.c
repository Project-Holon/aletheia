/*
 * unit: no
 * function: func_021BAF30
 * address: 0x021BAF30
 * packet: pkt_ov214_021BAF30
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * evidence: caller explicitly loads r0 for 02021540 and 02030DA4; preserve these pointer arguments despite legacy void declarations. 02021540 forwards unchanged to 020307B0.
 * symbols:
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct PalAnmSlot;extern void func_020215A0(struct PalAnmSlot *,u32);extern void func_02021540(void *);extern void func_02030DA4(void *);extern void func_020307B0(void *);
void func_021BAF30(int unused,u8 *p){func_020215A0(*(struct PalAnmSlot **)(p+0x2e0),0);func_020215A0(*(struct PalAnmSlot **)(p+0x2e0),2);func_02021540(*(void **)(p+0x2e0));func_02030DA4(*(void **)(p+0x2d8));func_020307B0(*(void **)(p+0x2dc));}
