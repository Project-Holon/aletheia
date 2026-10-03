/*
 * unit: yes
 * function: func_021B97C4, func_021B98FC
 * address: 0x021B97C4
 * packet: pkt_ov221_021B97C4
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021B9B64 0x021B9B64 thumb ov221
 *   func_021B9DAC 0x021B9DAC thumb ov221
 *   func_021B9B18 0x021B9B18 thumb ov221
 *   func_021B9D38 0x021B9D38 thumb ov221
 *   func_021B9F7C 0x021B9F7C thumb ov221
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 */
typedef unsigned int u32;
extern int func_021B9B64(unsigned char*);
extern int func_021B9DAC(unsigned char*);
extern void func_021B9B18(unsigned char*);
extern void func_021B9D38(unsigned char*);
extern void func_021B9F7C(void*);
extern int func_02005E50(void);
extern void func_02005DE4(void*);
extern void func_02005E64(void);
extern void func_02005D90(u32,unsigned short);
extern int func_02005F38(void);
extern void func_02005E9C(void);
extern void func_02005DF8(u32);
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern u32 func_020362DC(void);
extern void func_020355D8(unsigned char);
extern u32 func_02035D20(u32*,u32*);
extern u32 func_0201C4E4(void*);
int func_021B97C4(int unused, int *state, int unused2, unsigned char *p)
{
 int ready;
 u32 x,y;
 switch(*state) {
 case 0:
  ready=1;
  if(func_021B9B64(p)==0) ready=0;
  if(ready && *(int*)(*(char**)(p+4)+4)==0) {
   if(func_02005E50()) ready=0;
   else {func_02005DE4((void*)1);func_02005E64();func_02005D90(0x524,0xffff);}
  }
  if(ready) {func_0204E720(3,16,0,0);*state=1;}
  break;
 case 1:
  if(!func_0204E804()) {if(*(int*)(*(char**)(p+4)+4)!=0) *state=4;else *state=2;}
  break;
 case 2: if(func_021B9DAC(p)) *state=3; break;
 case 3:
  if(!func_02005F38()) {func_02005E9C();func_02005DE4(0);func_02005DF8(6);*state=4;}
  break;
 case 4:
  ready=0;
  if(func_020362DC()&3) {func_020355D8(0);ready=1;}
  else if(func_02035D20(&x,&y)) {func_020355D8(1);ready=1;}
  if(ready) {*state=5;func_0204E720(3,0,16,0);}
  break;
 case 5: if(!func_0204E804()) *state=6; break;
 case 6: return 1;
 }
 func_0201C4E4(*(void**)(p+16));
 func_021B9B18(p);
 if(*state>=1 && *state<=5) func_021B9D38(p);
 func_021B9F7C(*(void**)(p+8));
 return 0;
}
void func_021B98FC(void) {}
