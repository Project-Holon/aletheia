/*
 * function: func_021E11A8
 * address: 0x021E11A8
 * packet: pkt_ov119_021E11A8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200566C 0x0200566C thumb
 *   func_02028604 0x02028604 thumb
 *   func_021E106C 0x021E106C thumb ov119
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02031140 0x02031140 arm
 */
#include "../include/Obj00001.h"
extern void func_0200566C(void);
struct PrintSys;
struct Rec3;
extern int func_02028604(int a0);
typedef unsigned char  u8;
struct Descriptor;
struct Rec;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void func_021E106C(char *p);
extern void func_021E12F8(char *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02028148(u8 *p);
extern unsigned int func_02027FD8(struct TaskMenuState *s);
extern unsigned int func_020452E8(struct Descriptor *d);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02031140(struct S02031140 *p);
void func_021E11A8(char *p)
{
    int i;
    func_0200566C();
    if(*(int *)&((struct Obj00001 *)p)->f744) {
        func_02028604((int)(((struct Obj00001 *)p)->f74C));
        func_021E106C(p);
        func_021E12F8(p);
        if(((struct Obj00001 *)p)->f72C) {func_0201CE48((struct Rec3 *)(((struct Obj00001 *)p)->f72C));((struct Obj00001 *)p)->f72C=0;}
        if(((struct Obj00001 *)p)->f648) {func_02028148(((struct Obj00001 *)p)->f648);((struct Obj00001 *)p)->f648=0;}
        if(((struct Obj00001 *)p)->f6B0) {func_02027FD8(((struct Obj00001 *)p)->f6B0);((struct Obj00001 *)p)->f6B0=0;}
        if(((struct Obj00001 *)p)->f6B4) {func_020452E8(((struct Obj00001 *)p)->f6B4);((struct Obj00001 *)p)->f6B4=0;}
        for(i=0;i<2;i++) {if(*(void **)(p+i*4+0x5bc)) {func_020452E8(*(void **)(p+i*4+0x5bc));*(void **)(p+i*4+0x5bc)=0;}}
        func_0201ED04(((struct Obj00001 *)p)->f724);
        func_02045C04(((struct Obj00001 *)p)->f720);
        func_0201D83C(((struct Obj00001 *)p)->f728);
        func_02045808(((struct Obj00001 *)p)->f730);
        func_02045808(((struct Obj00001 *)p)->f734);
        func_02045808(((struct Obj00001 *)p)->f738);
        func_02045808(((struct Obj00001 *)p)->f73C);
        func_0201C6EC((struct PrintSys *)(*(unsigned *)&((struct Obj00001 *)p)->f740));
        func_0201C4C0((struct PrintSys *)(*(unsigned *)&((struct Obj00001 *)p)->f740));
        func_02031140(((struct Obj00001 *)p)->f744);
        *(int *)&((struct Obj00001 *)p)->f744=0;
    }
}
