/*
 * function: func_021D9038
 * address: 0x021D9038
 * packet: pkt_ov119_021D9038
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKETRADE_NEGO_StoreRemoteOffer 0x021DD380 thumb ov119
 *   POKETRADE_2D_CreateOfferIconActor 0x021E6334 thumb ov119
 *   POKETRADE_NEGO_ShowOfferSlotMon 0x021DF918 thumb ov119
 */
typedef unsigned char u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern unsigned int POKE_TOOL_GetPartyValue(void *,unsigned int,unsigned int);
extern void POKETRADE_NEGO_StoreRemoteOffer(char *p, int i, void *src);
extern void POKETRADE_2D_CreateOfferIconActor(char *p, int i, int j, void *mon, int selected, u32 visible);
extern void POKETRADE_NEGO_ShowOfferSlotMon(void *,int,void *);
void func_021D9038(int a,int b,int c,u8 *p,int e,int f) { int z;if(e==(int)GFL_NET_HANDLE_GetCurrentHandle()) { if(a!=GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {z=0;if(POKE_TOOL_GetPartyValue((void *)*(int *)(p+0x1064+a*4),169,0)) {POKETRADE_NEGO_StoreRemoteOffer((char *)p,f,(void *)(*(int *)(p+0x1064+a*4)));POKETRADE_2D_CreateOfferIconActor((char *)p,1,f,(void *)(*(int *)(p+0x1064+a*4)),1,z);POKETRADE_NEGO_ShowOfferSlotMon(p,1,*(void **)(p+0x1064+a*4));}p[0x11fb]=(p[0x11fb]&~240)|16;} } }
