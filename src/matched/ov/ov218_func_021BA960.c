/*
 * function: UN_SELECT_GRAPHIC_GetActor
 * address: 0x021BA960
 * packet: pkt_ov218_021BA960
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UN_SELECT_GRAPHIC_GetValue 0x021BAA90 thumb ov218
 */
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
extern u32 UN_SELECT_GRAPHIC_GetValue(u32 *);
u32 UN_SELECT_GRAPHIC_GetActor(char *p){return UN_SELECT_GRAPHIC_GetValue((u32 *)(p+4));}
