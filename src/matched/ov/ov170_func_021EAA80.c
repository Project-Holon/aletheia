/*
 * function: BOX2_SEQ_InitBmpWins
 * address: 0x021EAA80
 * packet: pkt_ov170_021EAA80
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_021EFC20 0x021EFC20 data a1
 */
#define WORK(p) (*(char **)((p)+0x2C))
typedef unsigned short u16;
extern void BMP_WIN_Init(u16 heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern const unsigned char d_021EFC20[];
void BOX2_SEQ_InitBmpWins(unsigned char *p) {
 const unsigned char *x; unsigned i;
 BMP_WIN_Init(0x4C);
 x=d_021EFC20;
 for(i=0;i<28;i++,x+=6)
  *(void **)(WORK(p)+0x94+i*8)=(void *)BMP_WIN_Create(x[0],x[1],x[2],x[3],x[4],x[5],1);
}
