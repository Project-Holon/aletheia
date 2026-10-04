/*
 * function: func_021B96C0
 * address: 0x021B96C0
 * packet: pkt_ov213_021B96C0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BA514 0x021BA514 thumb ov213
 *   func_021B613C 0x021B613C thumb ov067
 *   func_02045C04 0x02045C04 arm
 *   sub_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021BA710 0x021BA710 thumb ov213
 *   func_021BA7B8 0x021BA7B8 thumb ov213
 *   func_021BAC0C 0x021BAC0C thumb ov213
 *   sub_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   sub_02034A5C 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 */
#include "../../matched/include/Obj06704.h"
typedef unsigned short u16;typedef unsigned int u32;
struct Rec;struct PrintSys;struct S020315D4;
extern void func_02041EE4(u32,u32,u32);extern void func_021BA514(char *);
extern void func_021B613C(void *);extern void func_02045C04(struct Rec *);
extern void sub_0201C4C0(struct PrintSys *);extern void func_0201D83C(void *);
extern void func_021BA710(char *),func_021BA7B8(char *),func_021BAC0C(unsigned char *);
extern void sub_020315D4(struct S020315D4 *);extern void func_020306F0(u32);extern void sub_02034A5C(int);
extern char overlay_id[];
int func_021B96C0(struct S020315D4 *owner,int unused,const void *cfg,char *p) {
u16 heap;
func_02041EE4(3,0,0);
if(*(int *)((unsigned)cfg+0x44)==2 || *(int *)((unsigned)cfg+0x44)==4)func_021BA514(p);
func_021B613C(((struct Obj06704 *)p)->f49C4);
func_02045C04(*(void **)((unsigned)p+0x49c0));
sub_0201C4C0(((struct Obj06704 *)p)->f49BC);
func_0201D83C(*(void **)((unsigned)p+0x49b8));
func_021BA710(p+0xc);func_021BA7B8(p+0x24);
func_021BAC0C(((struct Obj06704 *)p)->f49B4);
heap=*(u16 *)p;sub_020315D4(owner);func_020306F0(heap);sub_02034A5C((int)overlay_id);return 1;
}
