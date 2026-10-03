/*
 * function: func_021DFEFC
 * address: 0x021DFEFC
 * packet: pkt_ov137_021DFEFC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 */
typedef unsigned int u32;struct PalAnmSlot;
extern void func_020215A0(struct PalAnmSlot *,u32);extern void func_02021540(struct PalAnmSlot *);
void func_021DFEFC(char *p){func_020215A0(*(struct PalAnmSlot **)(p+0xd78),0);func_020215A0(*(struct PalAnmSlot **)(p+0xd78),1);func_02021540(*(struct PalAnmSlot **)(p+0xd78));}
