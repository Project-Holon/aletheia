/*
 * function: func_021DA76C
 * address: 0x021DA76C
 * packet: pkt_ov119_021DA76C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA700 0x021DA700 thumb ov119
 */
extern int func_021D8A24(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern void func_021D8E84(void *,int);
extern void func_021DA700(char *p);
void func_021DA76C(void *p) {
 if(!func_021D8A24(p) || func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),13,8)) func_021D8E84(p,(int)func_021DA700);
}
