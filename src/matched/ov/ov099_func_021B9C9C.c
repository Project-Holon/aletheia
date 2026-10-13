/*
 * function: WIFICLUBACTOR_UpdateActors
 * address: 0x021B9C9C
 * packet: pkt_ov099_021B9C9C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFICLUBACTOR_FreeActor 0x021B9A34 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIFICLUBACTOR_FreeActor(void *);
void WIFICLUBACTOR_UpdateActors(u8 *p) { int i; int offset; u8 *base; i=0; base=p+48; for(;i<48;i++) { offset=i*28; if (*(u32 *)(p+offset+48)) { if ((*(int (**)(void *,void *))(p+offset+64))(p,base+offset)==1) WIFICLUBACTOR_FreeActor(base+offset); } } }
