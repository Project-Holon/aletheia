/*
 * function: func_021FA0FC
 * address: 0x021FA0FC
 * packet: pkt_ov186_021FA0FC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FACE0 0x021FACE0 thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB760 0x021FB760 thumb ov186
 *   func_021FB704 0x021FB704 thumb ov186
 *   func_021FB7D0 0x021FB7D0 thumb ov186
 *   func_021FAC20 0x021FAC20 thumb ov186
 *   func_021FAFA0 0x021FAFA0 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct Fields;
extern void func_021FACE0(void *);
extern int func_021FC214(char *);
extern u16 func_021FB760(void *,int);
extern void *func_021FB704(char *,int,u16);
extern void *func_021FB7D0(unsigned *const *,void *,int,u16);
extern void func_021FAC20(struct Fields *,unsigned,unsigned,unsigned,void *,const void *,unsigned,u16);
extern int func_021FAFA0(void *,int);
extern void func_021FB514(void *,short,short),func_02045808(void *);
void func_021FA0FC(u8 *p,int section,const int *pos)
{
 int i,bank;
 void *rec,*text;
 for(i=0;i<p[0x38];i++)func_021FACE0(*(u8 **)(p+0x40)+i*0x44);
 bank=func_021FC214(*(char **)(p+4));
 p[0x39]=func_021FB760(*(void **)(p+0x44),section);
 for(i=0;i<p[0x39];i++){
  rec=func_021FB704(*(char **)(p+0x44),section,i);
  text=func_021FB7D0(*(unsigned *const **)(p+0x44),rec,bank,(*(u16 *)p&0x7fff)|0x8000);
  func_021FAC20((struct Fields *)(*(u8 **)(p+0x40)+i*0x44),(u32)rec,*(u32 *)(p+8),*(u32 *)(p+0x48),*(void **)(p+4),text,*(u32 *)(p+0x10),*(u16 *)p);
  func_02045808(text);
  func_021FAFA0(*(u8 **)(p+0x40)+i*0x44,3);
  if(pos)func_021FB514(*(void **)(*(u8 **)(p+0x40)+i*0x44+8),pos[0],pos[1]);
 }
}
