/*
 * function: func_021DAC20
 * address: 0x021DAC20
 * packet: pkt_ov119_021DAC20
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021DABE8 0x021DABE8 thumb ov119
 *   func_021DAB34 0x021DAB34 thumb ov119
 */
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *, int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern void func_021DABE8(char *p);
extern void func_021DAB34(char *p);
void func_021DAC20(void *p) {
 if(WIPE_SYS_EndCheck()) {
  if(func_021D8A24(p)) {
   func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),22,8);
   func_021D8E84(p,(int)func_021DABE8);
  } else { func_021D8E84(p,(int)func_021DAB34); }
 }
}
