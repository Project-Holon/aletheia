/*
 * function: func_021D8F20
 * address: 0x021D8F20
 * packet: pkt_ov119_021D8F20
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 */
extern int func_021D8A24(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
int func_021D8F20(void *p,int idx) {
 unsigned v=func_021D8A24(p);
 if(v==0) return *(int *)((char *)p+idx*4+0x5e4);
 if(GFL_NET_GetHandleNetID((struct Link *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()))==0) return *(int *)((char *)p+idx*4+0x5e4);
 return *(int *)((char *)p+(1-idx)*4+0x5e4);
}
