/*
 * unit: no
 * function: func_021BAD08
 * address: 0x021BAD08
 * packet: pkt_ov214_021BAD08
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
void func_021BAD08(void *a0, char *a1){BG_SYS_ClearLayerEx(2,0);}
