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
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 */
typedef unsigned char  u8;
struct Descriptor;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p); extern unsigned char BMP_WIN_GetWidth(void *); extern unsigned char BMP_WIN_GetHeight(void *); extern void BGWINFRM_AddFrame(void *,unsigned,unsigned,unsigned,unsigned); extern void BGWINFRM_PutBmpWin(void *,unsigned,void *);
void func_021EB708(void *m,unsigned i,void *d){unsigned bg=BMP_WIN_GetBgLayer(d);unsigned w=BMP_WIN_GetWidth(d);unsigned h=BMP_WIN_GetHeight(d);BGWINFRM_AddFrame(m,i,bg,w,h);BGWINFRM_PutBmpWin(m,i,d);}
