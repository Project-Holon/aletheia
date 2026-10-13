/*
 * function: func_021DAA7C
 * address: 0x021DAA7C
 * packet: pkt_ov119_021DAA7C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E31FC 0x021E31FC thumb ov119
 *   func_021DAA4C 0x021DAA4C thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int),func_021E31FC(void *),func_021DAA4C(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
void func_021DAA7C(char *p) {
 if(func_021D8A24(p)) {
  if(GFL_NET_SendData((unsigned)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0e,0x2d6,(u32)(p+16),0,0,1)) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,8);func_021D8E84(p,(int)func_021DAA4C);
  }
 } else {func_021E31FC(p);func_021D8E84(p,(int)func_021DAA4C);}
}
