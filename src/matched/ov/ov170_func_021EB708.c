/*
 * function: func_021EB708
 * address: 0x021EB708
 * packet: pkt_ov170_021EB708
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045730 0x02045730 arm
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 */
typedef unsigned char  u8;
struct Descriptor;
extern u8 func_02045730(struct Descriptor *p); extern unsigned char func_02045738(void *); extern unsigned char func_02045740(void *); extern void BGWINFRM_AddFrame(void *,unsigned,unsigned,unsigned,unsigned); extern void BGWINFRM_PutBmpWin(void *,unsigned,void *);
void func_021EB708(void *m,unsigned i,void *d){unsigned bg=func_02045730(d);unsigned w=func_02045738(d);unsigned h=func_02045740(d);BGWINFRM_AddFrame(m,i,bg,w,h);BGWINFRM_PutBmpWin(m,i,d);}
