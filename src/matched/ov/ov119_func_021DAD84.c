/*
 * function: func_021DAD84
 * address: 0x021DAD84
 * packet: pkt_ov119_021DAD84
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA798 0x021DA798 thumb ov119
 */
extern int func_021E12AC(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern void func_021D8E84(void *,int);
extern void func_021DA798(char *p);
void func_021DAD84(void *p) {
 if(func_021E12AC(p)) {
  func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),27,8);
  func_021D8E84(p,(int)func_021DA798);
 }
}
