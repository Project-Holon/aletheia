/*
 * function: func_021D9B84
 * address: 0x021D9B84
 * packet: pkt_ov119_021D9B84
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 */
extern int func_021D8A24(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void func_021E1098(char *p);
extern void func_021D8E84(void *,int);
extern void func_021D9434(void *);
void func_021D9B84(void *p) {
 if(func_021D8A24(p)) {
  if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),20,8)) {
   func_021E1098(p); func_021D8E84(p,(int)func_021D9434);
  }
 } else { func_021E1098(p); func_021D8E84(p,(int)func_021D9434); }
}
