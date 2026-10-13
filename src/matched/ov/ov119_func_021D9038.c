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
 *   func_021DD380 0x021DD380 thumb ov119
 *   func_021E6334 0x021E6334 thumb ov119
 *   func_021DF918 0x021DF918 thumb ov119
 */
typedef unsigned char u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern unsigned int POKE_TOOL_GetPartyValue(void *,unsigned int,unsigned int);
extern void func_021DD380(char *p, int i, void *src);
extern void func_021E6334(char *p, int i, int j, void *mon, int selected, u32 visible);
extern void func_021DF918(void *,int,void *);
void func_021D9038(int a,int b,int c,u8 *p,int e,int f) { int z;if(e==(int)GFL_NET_HANDLE_GetCurrentHandle()) { if(a!=GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {z=0;if(POKE_TOOL_GetPartyValue((void *)*(int *)(p+0x1064+a*4),169,0)) {func_021DD380((char *)p,f,(void *)(*(int *)(p+0x1064+a*4)));func_021E6334((char *)p,1,f,(void *)(*(int *)(p+0x1064+a*4)),1,z);func_021DF918(p,1,*(void **)(p+0x1064+a*4));}p[0x11fb]=(p[0x11fb]&~240)|16;} } }
