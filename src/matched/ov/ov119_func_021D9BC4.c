/*
 * function: func_021D9BC4
 * address: 0x021D9BC4
 * packet: pkt_ov119_021D9BC4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9B84 0x021D9B84 thumb ov119
 */
extern int func_021E12AC(char *p);
extern int func_021D8A24(void *);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern void func_021D8E84(void *,int);
extern void func_021D9B84(void *);
void func_021D9BC4(char *p) {
 if(func_021E12AC(p) && *(int *)(p+0xF2C)>30) {
  if(func_021D8A24(p)) func_02039C68((struct Link *)func_020399A8(),20,8);
  func_021D8E84(p,(int)func_021D9B84);
 }
}
