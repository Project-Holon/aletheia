/*
 * function: func_021DAE2C
 * address: 0x021DAE2C
 * packet: pkt_ov119_021DAE2C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_020173EC 0x020173EC thumb
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBA80 0x021DBA80 thumb ov119
 */
#include "../include/Obj10354.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned,unsigned);
typedef unsigned int   u32;
extern int func_021DD24C(char *p);
extern u32 func_020173EC(void);
extern void func_021DD294(char *p, int a, int b);
extern void func_021E1098(char *p);
extern void MI_CpuFill8(void *,int,int);
extern void func_021D8E84(void *,int);
extern void func_021DBA80(char *p);
void func_021DAE2C(char *p) {
 int i;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8)==0) {func_021DD24C(p);return;}
 func_021DD294(p,1,1);func_021E1098(p);
 p[0x11e0]=0;p[0x11e1]=0;p[0x11e8]=0;p[0x11e9]=0;
 for(i=0;i<6;i++) {
  char *q=p+(i/3)*12+(i%3)*4;
  ((struct Obj10354 *)q)->fFA4=-1;
  if(((struct Obj10354 *)q)->fFD8)MI_CpuFill8(((struct Obj10354 *)q)->fFD8,0,func_020173EC());
 }
 func_021D8E84(p,(int)func_021DBA80);
}
