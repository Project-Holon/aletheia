/*
 * unit: no
 * function: func_0220BE04
 * address: 0x0220BE04
 * packet: pkt_ov198_0220BE04
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220BDD4 0x0220BDD4 thumb ov198
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_0220BD84 0x0220BD84 thumb ov198
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;extern void BMP_WIN_Delete(struct Descriptor *);extern void func_0220BDD4(char *);extern void func_0220BD84(u8 *);
void func_0220BE04(u8 *p){u32 i;func_0220BDD4((char *)p);for(i=0;i<2;i++)BMP_WIN_Delete(*(struct Descriptor **)(p+i*8+0x1f60));func_0220BD84(p);}
