/*
 * function: func_021BAC80
 * address: 0x021BAC80
 * packet: pkt_ov100_021BAC80
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 0x021799C0 is the ov015 Thumb callback setter, while ov009
 *   holds unrelated interior ARM instructions at the overlapping address.
 * symbols:
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_0203CD98 0x0203CD98 arm
 *   func_021799C0 0x021799C0 thumb ov015
 *   func_021BAAEC 0x021BAAEC thumb ov100
 *   func_0203D060 0x0203D060 arm
 *   func_021B9FBC 0x021B9FBC thumb ov100
 *   func_021B9FF4 0x021B9FF4 thumb ov100
 *   func_021B9848 0x021B9848 thumb ov100
 *   func_021BB270 0x021BB270 thumb ov100
 */
extern int func_0203CD98(void);
extern void func_021799C0(void (*)(void));
extern void func_021BAAEC(void);
extern void func_0203D060(void (*)(void),void (*)(void),void (*)(void));
extern void func_021B9FBC(void),func_021B9FF4(void),func_021B9848(void),func_021BB270(void);
extern void func_021B95B8(int,void (*)(void));
void func_021BAC80(int a) {
 if(func_0203CD98()==1) {
  switch(*(int *)(a+0x24c)) { case 9: case 10: func_021799C0(func_021BAAEC); break; }
  func_0203D060(func_021B9FBC,func_021B9FF4,func_021B9848);
  func_021B95B8(a,func_021BB270);
 }
}
