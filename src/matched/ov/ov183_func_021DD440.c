/*
 * function: func_021DD440
 * address: 0x021DD440
 * packet: pkt_ov183_021DD440
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021DD5C6..021DD5C8 is two zero alignment bytes.
 * symbols:
 *   func_021DDCCC 0x021DDCCC thumb ov183
 *   func_021DDFA0 0x021DDFA0 thumb ov183
 *   func_021DDDE8 0x021DDDE8 thumb ov183
 *   func_021DD684 0x021DD684 thumb ov183
 *   func_021DD858 0x021DD858 thumb ov183
 *   func_021DDA2C 0x021DDA2C thumb ov183
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 */
typedef unsigned int u32;
struct Pair { int x,y; };
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *),func_02035D20(int *,int *);
extern int func_021DDFA0(char *,int,int),func_021FB4B4(int,int,int);
extern void func_021FD860(int,int,struct Pair *);
extern void func_021DDCCC(char *,char *);
extern void func_021DDDE8(char *,char *),func_021DD684(char *,char *),func_021DD858(char *,char *),func_021DDA2C(char *,char *);
extern void func_021F9BA0(void *),func_021FC830(void *),func_021FD854(void *),func_021FD1BC(void *),func_0201C4E4(void *);
int func_021DD440(void *unused,u32 *state,char *q,char *p)
{
 int x,y,i;
 struct Pair pair;
 switch(*state){
 case 0:func_021FE784(*(int *)q,2,3,0);*state=1;break;
 case 1:if(func_021FE7B0(*(int **)q)) *state=2;break;
 case 2:
  if(func_02035D20(&x,&y)){
   *(int *)(p+0x78)=func_021DDFA0(p,x,y);
   if(*(int *)(p+0x78)) *state=3;
   if(func_021FB4B4(*(int *)(p+0x20),x,y)){
    pair.x=x;pair.y=y;
    func_021FD860(*(int *)(p+0x74),1,&pair);
    *state=7;
   }
  }break;
 case 3:func_021FE784(*(int *)q,2,1,1);++*state;break;
 case 4:if(func_021FE7B0(*(int **)q)) ++*state;break;
 case 5:
  func_021DDDE8(p,q);
  switch(*(u32 *)(p+0x78)){
  case 1:func_021DD684(p,q);break;
  case 2:func_021DD858(p,q);break;
  case 3:func_021DDA2C(p,q);break;
  case 4:func_021DDCCC(p,q);break;
  }
  func_021FE784(*(int *)q,2,1,0);++*state;break;
 case 6:if(func_021FE7B0(*(int **)q)) *state=2;break;
 case 7:func_021FE784(*(int *)q,2,3,1);*state=8;break;
 case 8:if(func_021FE7B0(*(int **)q)) *state=9;break;
 case 9:func_021F9BA0(*(void **)(q+0xc));return 1;
 }
 for(i=0;i<4;i++) if(*(void **)(p+i*4+0x24)) func_021FC830(*(void **)(p+i*4+0x24));
 for(i=0;i<16;i++) if(*(void **)(p+i*4+0x34)) func_021FC830(*(void **)(p+i*4+0x34));
 func_0201C4E4(*(void **)(p+4));
 if(*(void **)(p+0x1c))func_021FD1BC(*(void **)(p+0x1c));
 func_021FD854(*(void **)(p+0x74));
 return 0;
}
