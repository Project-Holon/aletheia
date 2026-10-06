/*
 * function: func_021DB030
 * address: 0x021DB030
 * packet: pkt_ov119_021DB030
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, s16 derives -1 from zero.
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAFB8 0x021DAFB8 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
typedef short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern void func_021E4E64(int a, char *p, int b);
extern void func_021E6700(void *);
extern void func_021D8E84(void *,int);
extern void func_021DAFB8(char *p);
extern void func_021DBE70(char *p);
void func_021DB030(char *p) {
 int v;
 if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
  v=func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));func_021E12F8(p);*(int *)&((struct Obj00001 *)p)->f64C=0;
  switch(v) {
  case 0:func_021D8E84(p,(int)func_021DAFB8);return;
  case 1:func_021E1098(p);func_021D8E84(p,(int)func_021DBE70);
   ((struct Obj00001 *)p)->f1080=-1;func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828,p,0);func_021E6700(p);return;
  }
 }
}
