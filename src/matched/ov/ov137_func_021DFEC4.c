/*
 * function: func_021DFEC4
 * address: 0x021DFEC4
 * packet: pkt_ov137_021DFEC4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 */
typedef unsigned int u32;struct PalAnmSlot;
extern void *func_02021518(u32);extern void func_02021EE4(struct PalAnmSlot *,int);extern void func_0202155C(struct PalAnmSlot *,u32,u32,u32);
void func_021DFEC4(char *p){*(struct PalAnmSlot **)(p+0xd78)=func_02021518(114);func_02021EE4(*(struct PalAnmSlot **)(p+0xd78),1);func_0202155C(*(struct PalAnmSlot **)(p+0xd78),0,512,114);func_0202155C(*(struct PalAnmSlot **)(p+0xd78),1,512,114);}
