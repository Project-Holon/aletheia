/*
 * function: func_021DA8F8
 * address: 0x021DA8F8
 * packet: pkt_ov119_021DA8F8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DD1B8 0x021DD1B8 thumb ov119
 *   func_021DF904 0x021DF904 thumb ov119
 *   func_0215642C 0x0215642C thumb ov009
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021DD528 0x021DD528 thumb ov119
 *   func_021DD68C 0x021DD68C thumb ov119
 *   func_021DF78C 0x021DF78C thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_02027858 0x02027858 thumb
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021DBB6C 0x021DBB6C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA898 0x021DA898 thumb ov119
 *   func_021DB7AC 0x021DB7AC thumb ov119
 */
typedef unsigned char u8;
extern int func_021D8A24(void *),func_020399A8(void),func_02039CB4(int,int,int),func_021D8AA8(void *);
extern void func_021E1098(char *),func_021DD1B8(char *),func_021DF904(void *),func_0215642C(int),func_02045CAC(int,int,int),func_021E1024(void *);
extern void func_021DD528(char *,int),func_021DD68C(void *),func_021DF78C(void *),func_021DF7AC(void *,int),func_02082BCC(void *,int,int),func_021D8C84(void *),func_02027858(int),func_021E4420(void *),func_021E6700(void *),func_021DBB6C(char *),func_021D8E84(void *,int),func_021DA898(char *),func_021DB7AC(char *,int,int);
void func_021DA8F8(char *p)
{
 if(func_021D8A24(p) && !func_02039CB4(func_020399A8(),18,8)) return;
 func_021E1098(p);
 if(func_021D8AA8(p)) {
  func_021DD1B8(p);func_021DF904(p);
  if(*(int *)(p+0x118c)==2) func_0215642C(0);
  func_02045CAC(*(int *)(p+0x720),134,*(int *)(p+0x738));func_021E1024(p);
  func_021DD528(p,0);func_021DD68C(p);
  *(u8 *)(p+0x11e8)=0;*(u8 *)(p+0x11e9)=0;
  func_021DF78C(p);func_021DF7AC(p,1);
  func_02082BCC(p+0xca0,0,0x78);func_02082BCC(p+0xd18,0,0x3c);func_02082BCC(p+0xd54,0,0x3c);
  func_021D8C84(p);
  if(*(int *)(p+0x64c)) {func_02027858(*(int *)(p+0x64c));*(int *)(p+0x64c)=0;}
  func_021E4420(p);func_021E6700(p);func_021DBB6C(p);
 }
 func_021D8E84(p,(int)func_021DA898);func_021DB7AC(p,0,1);
}
