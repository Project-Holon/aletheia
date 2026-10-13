/*
 * function: func_021DAEC8
 * address: 0x021DAEC8
 * packet: pkt_ov119_021DAEC8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAE2C 0x021DAE2C thumb ov119
 */
extern int func_021E12AC(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
extern void func_021D8E84(void *,int);
extern void func_021DAE2C(char *p);
void func_021DAEC8(void *p) {
 if(func_021E12AC(p)) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8);
  func_021D8E84(p,(int)func_021DAE2C);
 }
}
