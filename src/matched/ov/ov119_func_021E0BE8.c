/*
 * function: func_021E0BE8
 * address: 0x021E0BE8
 * packet: pkt_ov119_021E0BE8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021E049C 0x021E049C thumb ov119
 *   func_020108C4 0x020108C4 thumb
 *   func_021E0260 0x021E0260 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0C44 0x021E0C44 thumb ov119
 *   func_021E0C78 0x021E0C78 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
extern int func_021E12AC(char *);
extern int func_021D8A24(void *);
extern void func_021E049C(char *p);
typedef unsigned int   u32;
extern void *func_020108C4(u32 heap, u32 a1, u32 a2, u32 a3);
extern void func_021E0260(char *p);
extern void func_021D8E84(void *,int);
extern void func_021E0C44(char *p);
extern void func_021E0C78(char *);
void func_021E0BE8(char *p) {if(func_021E12AC(p)) {if(func_021D8A24(p)) {func_021E049C(p);((struct Obj00001 *)p)->fEF8=(int)func_020108C4(((struct Obj00001 *)p)->f5F4,*(int *)&((struct Obj00001 *)p)->f82C,(u32)func_021E0260,(u32)p);func_021D8E84(p,(int)func_021E0C44);return;}func_021D8E84(p,(int)func_021E0C78);}}
