/*
 * function: func_021BA760, func_021BA894
 * unit: yes
 * extent: lead 308 bytes; empty callback at 021BA894 and two zero alignment bytes.
 * arity: 02028178 retains original r1 payload despite unused input in its body.
 * address: 0x021BA760
 * packet: pkt_ov225_021BA760
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021BAA50 0x021BAA50 thumb ov225
 *   func_02028178 0x02028178 thumb
 *   func_021BAE2C 0x021BAE2C thumb ov225
 *   func_021B9FBC 0x021B9FBC thumb ov225
 *   func_021BA158 0x021BA158 thumb ov225
 *   func_021BA154 0x021BA154 thumb ov225
 *   func_021BAABC 0x021BAABC thumb ov225
 *   func_021BB034 0x021BB034 thumb ov225
 *   func_02028230 0x02028230 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_021BAA50(char *);
extern void func_02028178(u8 *,void *);
extern int func_021BAE2C(char *);
extern void func_021B9FBC(char *);
extern unsigned func_021BA158(char *);
extern unsigned func_021BA154(char *);
extern int func_021BAABC(char *);
extern u16 func_021BB034(u16 **);
extern u32 func_02028230(u8 *);
int func_021BA760(char *p)
{
 u8 i;
 int result=0;
 unsigned selected;
 if(!func_0201C6B4(*(const struct PrintSys **)(*(char **)(p+4)+0x14))) return 0;
 if(*(signed char *)(p+0x90)==0) result=1;
 else if(*(signed char *)(p+0x90)>0) {
  if(*(signed char *)(p+0x90)==1) func_021BAA50(p);
  (*(signed char *)(p+0x90))--;
 }
 if(*(u32 *)(p+0x84)!=1) {
  for(i=0;i<8;i++) {
   if(*(u8 **)(p+i*4+0xc) && *(void **)(p+i*4+0x2c))
    func_02028178(*(u8 **)(p+i*4+0xc),*(void **)(p+i*4+0x2c));
  }
 }
 if(*(u32 *)(p+0x84)==0 || *(u32 *)(p+0x84)==2) {
  if(func_021BAE2C(p)) *(u32 *)(p+0x84)=2;
  else *(u32 *)(p+0x84)=0;
 }
 if(*(u32 *)(p+0x84)==0 || *(u32 *)(p+0x84)==3) {
  func_021B9FBC(*(char **)(*(char **)(p+4)+0x34));
  if(*(u32 *)(p+0x84)==0) {
   if(func_021BA158(*(char **)(*(char **)(p+4)+0x34))!=(unsigned)-1) *(u32 *)(p+0x84)=3;
  } else {
   selected=func_021BA154(*(char **)(*(char **)(p+4)+0x34));
   if(selected!=(unsigned)-1) {
    if(selected==1) *(u32 *)(*(char **)p+0x10)=0;
    *(u32 *)(p+0x84)=1;
    *(signed char *)(p+0x90)=1;
   }
  }
 }
 if(*(u32 *)(p+0x84)==0 || *(u32 *)(p+0x84)==4) {
  if(*(u32 *)(p+0x84)==0) {
   if(func_021BAABC(p)) *(u32 *)(p+0x84)=4;
  } else {
   if(func_02028230(*(u8 **)(p+func_021BB034((u16 **)p)*4+0xc))) {
    *(u32 *)(*(char **)p+0x10)=1;
    *(u32 *)(p+0x84)=1;
    *(signed char *)(p+0x90)=1;
   }
  }
 }
 return result;
}

void func_021BA894(void) {}
