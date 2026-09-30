/*
 * function: func_021B8B38
 * address: 0x021B8B38
 * packet: pkt_ov103_021B8B38
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B64B8 0x021B64B8 thumb ov101
 */
typedef unsigned char u8;
typedef struct {int words[54];} Block;
extern int func_020399A8(void);
extern int func_0203D1A4(int);
extern int func_021B64B8(int,int,int,void *,u8,int,int,int);
int func_021B8B38(u8 *p,const Block *q) {
 switch(*(int *)(p+4)) {
 case 0: *(Block *)(p+0x1b8)=*q;*(int *)(p+4)=1;break;
 case 1:
  if(func_021B64B8(*(int *)p,0xe00,0xd8,p+0x1b8,(u8)(func_0203D1A4(func_020399A8())==0),0,0,1))*(int *)(p+4)=2;
  break;
 case 2:
  if(*(int *)(p+0x290)) {*(int *)(p+0x290)=0;*(int *)(p+4)=0;return 1;}
  break;
 }
 return 0;
}
