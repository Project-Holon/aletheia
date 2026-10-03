/*
 * function: func_021BE4C0
 * address: 0x021BE4C0
 * packet: pkt_ov110_021BE4C0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9C90 0x021B9C90 thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BEADC 0x021BEADC thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int (*Handler)(u8 *,void *);
extern int func_021B9C90(u8 *,int);
extern int func_021B9C74(u8 *);
extern void func_021B9BEC(u8 *,int);
extern void func_021BEADC(u8 *p, void *q);
extern void func_021BD7A0(u8 *,Handler);
extern int func_021BD894(u8 *,void *);
int func_021BE4C0(u8 *p,unsigned *q) {
 switch(*q) {
 case 0:
  if(func_021B9C90(*(u8 **)(p+0x14),18) && func_021B9C90(*(u8 **)(p+0x14),33) && func_021B9C90(*(u8 **)(p+0x14),32)) func_021BEADC(p,q);
  break;
 case 1:
  if(func_021B9C90(*(u8 **)(p+0x14),32)) {
   if(*(u16 *)(p+0x50)!=253) { *(u16 *)(p+0x4c)=*(u16 *)(p+0x50); func_021B9BEC(*(u8 **)(p+0x14),18); }
   *q=0;
  }
  break;
 case 2:
  if(func_021B9C74(*(u8 **)(p+0x14))) { if(*(Handler *)(p+0x28)==func_021BD894) func_021B9BEC(*(u8 **)(p+0x14),4); *q=3; }
  break;
 case 3:
  if(func_021B9C74(*(u8 **)(p+0x14))) func_021BD7A0(p,*(Handler *)(p+0x28));
  break;
 case 4:
  if(func_021B9C90(*(u8 **)(p+0x14),25)) *q=0;
  break;
 }
 return 0;
}
