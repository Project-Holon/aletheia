/*
 * file:     wifibattlematch_net_p11.c
 * unit:     yes
 * function: func_021D6A98, func_021D6B38, func_021D6BF4
 * address:  0x021D6A98
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021DD008 0x021DD008 thumb ov175
 *   func_021E7DF0 0x021E7DF0 thumb ov177
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_021E8628 0x021E8628 thumb ov177
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 *   func_021D98B8 0x021D98B8 thumb ov175
 *   func_021D9854 0x021D9854 thumb ov175
 *   func_021D97A4 0x021D97A4 thumb ov175
 *   func_021D99F4 0x021D99F4 thumb ov175
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021E5868 0x021E5868 thumb ov177
 *   func_021E54E0 0x021E54E0 thumb ov177
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data
 *   ov067_id 0x00000043 data
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   func_021D9ED0 0x021D9ED0 thumb ov175
 *   func_021E5534 0x021E5534 thumb ov177
 *   func_021E867C 0x021E867C thumb ov177
 *   func_021E7E08 0x021E7E08 thumb ov177
 *   func_021E5980 0x021E5980 thumb ov177
 *   func_021E64C0 0x021E64C0 thumb ov177
 *   func_021E7774 0x021E7774 thumb ov177
 *   func_021E84F8 0x021E84F8 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021D97D0 0x021D97D0 thumb ov175
 *   func_021D6C54 0x021D6C54 thumb ov175
 *   func_021D8904 0x021D8904 thumb ov175
 *   func_021D8BC4 0x021D8BC4 thumb ov175
 */
#include "../../matched/include/Obj01563.h"
#include "../../matched/include/Obj14328.h"

struct PrintSys;
struct Rec;
struct WordSet;
struct S020315D4;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef signed int     s32;

extern u32 func_020307B0(void *p);
extern void func_021DD008(char *,int);
extern void func_021E7DF0(int *p);
extern void func_021E8A78(void *p);
extern void func_021E8628(char *p);
extern void func_021D9EA0(u8 *p);
extern void func_021D98B8(char *);
extern void func_021D9854(char *);
extern void func_021D97A4(char *);
extern void func_021D99F4(char *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_021E5868(u32);
extern void func_021E54E0(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32);
extern void func_02034A5C(int);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021E8A80(unsigned);
extern int func_021E8A90(int **p);
extern void func_021D9ED0(int);
extern void func_021E5534(u8 *p);
extern void func_021E867C(char *p);
extern void func_021E7E08(int);
extern void func_021E5980(int);
extern int func_021E64C0(unsigned char *,void *);
extern int func_021E7774(void *p, void *mgr);
extern int func_021E84F8(char *p, void *q);
extern void func_021E8AA0(int *p, int v);
extern void func_021DA36C(u32);
extern void func_021D97D0(char *);
extern void func_021D6C54(u32 sys, int *state, u32 *p);
extern void func_021D8904(u32 sys, int *state, char *p);
extern void func_021D8BC4(int *a, int *state, char *ctx);
int func_021D6A98(u32 sys,u32 unused,u32 arg,char *p);
int func_021D6B38(unsigned sys,int *state,int unused,int *p);
void func_021D6BF4(u32 sys,void *unused,char *p);
extern const char ov114_id[],ov067_id[];

int func_021D6A98(u32 sys,u32 unused,u32 arg,char *p)
{
    func_020307B0(((struct Obj01563 *)p)->fFC);
    func_021DD008((char *)((u32 *)p)[13],0);
    func_021E7DF0((int *)(((u32 *)p)[10]));
    func_021E8A78((void *)(((u32 *)p)[15])); func_021E8A78((void *)(((u32 *)p)[14]));
    func_021E8628((char *)(((u32 *)p)[11]));
    if(((u32 *)p)[13]) func_021D9EA0((u8 *)(((u32 *)p)[13]));
    func_021D98B8(p); func_021D9854(p); func_021D97A4(p); func_021D99F4(p);
    func_0201ED04((struct WordSet *)(((u32 *)p)[6])); func_02045C04((struct Rec *)(((u32 *)p)[5]));
    func_0201C4C0((struct PrintSys *)(((u32 *)p)[4])); func_0201D83C((void *)(((u32 *)p)[3])); func_0201D83C((void *)(((u32 *)p)[2]));
    func_021E5868(((u32 *)p)[1]); func_021E54E0((char *)(((u32 *)p)[0]));
    func_020315D4((struct S020315D4 *)sys); func_020306F0(87);
    func_02034A5C((int)ov114_id); func_02034A5C((int)ov067_id);
    return 1;
}

int func_021D6B38(unsigned sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: func_0204E720(3,16,0,0); *state=1; break;
    case 1: if(func_0204E804()==0) *state=2; break;
    case 2: func_021E8A80(p[14]); if(func_021E8A90((int **)p[14])) *state=3; break;
    case 3: func_0204E720(3,0,16,0); *state=4; break;
    case 4: if(func_0204E804()==0) return 1; break;
    }
    func_021E5534((u8 *)p[0]); func_0201C4E4((struct PrintSys *)p[4]); func_021E867C((char *)p[11]);
    func_021E7E08(p[10]); func_021E5980(p[1]); func_021D9ED0(p[13]);
    if(p[7]) func_021E64C0((unsigned char *)p[7],(void *)p[4]);
    if(p[8]) func_021E7774((void *)p[8],(void *)p[4]);
    if(p[9]) func_021E84F8((char *)p[9],(void *)p[4]);
    return 0;
}

void func_021D6BF4(u32 sys,void *unused,char *p)
{
    switch (((u32 *)((struct Obj14328 *)p)->f104)[3]) {
    case 0: func_021E8AA0((int *)sys,(int)func_021D6C54); break;
    case 2:
        func_021DA36C(((struct Obj14328 *)p)->f34);
    case 1:
        func_021D97D0(p);
        func_021E8AA0((int *)sys,(int)func_021D8904);
        break;
    case 3: func_021D97D0(p); func_021E8AA0((int *)sys,(int)func_021D8BC4); break;
    }
}
