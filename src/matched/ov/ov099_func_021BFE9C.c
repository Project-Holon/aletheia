/*
 * function: func_021BFE9C
 * address: 0x021BFE9C
 * packet: pkt_ov099_021BFE9C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
extern int func_021BA928(void *);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
int func_021BFE9C(char *p,int ret) {
 if (!func_021BA928(p)) return ret;
 if (--*(int *)(p+0x1e0)<0) {
  func_02039C68((struct Link *)func_020399A8(),18,10);
  *(int *)(p+0x1cc)=147;
 }
 return ret;
}
