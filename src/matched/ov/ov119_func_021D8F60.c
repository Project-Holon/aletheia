/*
 * function: POKETRADE_PROC_SetSideValue
 * address: 0x021D8F60
 * packet: pkt_ov119_021D8F60
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 */
extern int POKETRADE_PROC_IsNetSession(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
void POKETRADE_PROC_SetSideValue(void *p,int idx,int x) {
 unsigned v=POKETRADE_PROC_IsNetSession(p);
 if(v==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 if(GFL_NET_GetHandleNetID((struct Link *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()))==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 *(int *)((char *)p+(1-idx)*4+0x5e4)=x;
}
