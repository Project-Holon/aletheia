/*
 * function: func_021F47B4
 * address: 0x021F47B4
 * packet: pkt_ov194_021F47B4
 * region: ov194
 * status: EXACT
 * symbols:
 *   func_021F32D8 0x021F32D8 thumb ov194
 *   func_021F32FC 0x021F32FC thumb ov194
 *   func_021F4390 0x021F4390 thumb ov194
 *   func_021F3DE0 0x021F3DE0 thumb ov194
 *   func_021F3E18 0x021F3E18 thumb ov194
 *   func_021F3D70 0x021F3D70 thumb ov194
 *   func_021F2190 0x021F2190 thumb ov194
 *   func_021F21BC 0x021F21BC thumb ov194
 *   func_021F21FC 0x021F21FC thumb ov194
 *   func_021F22AC 0x021F22AC thumb ov194
 *   func_021F2150 0x021F2150 thumb ov194
 *   func_021F233C 0x021F233C thumb ov194
 *   func_021F235C 0x021F235C thumb ov194
 *   func_021F23F8 0x021F23F8 thumb ov194
 *   func_021F45A8 0x021F45A8 thumb ov194
 *   PROF_WORD_FindMatch 0x021F5370 thumb ov194
 *   PROF_WORD_CheckDigitCount 0x021F54CC thumb ov194
 *   func_021F4524 0x021F4524 thumb ov194
 *   func_021F3EF0 0x021F3EF0 thumb ov194
 *   func_021F462C 0x021F462C thumb ov194
 *   func_021F46F4 0x021F46F4 thumb ov194
 *   func_021F46B4 0x021F46B4 thumb ov194
 *   func_021F4480 0x021F4480 thumb ov194
 *   func_021F2394 0x021F2394 thumb ov194
 *   func_021F23B8 0x021F23B8 thumb ov194
 *   func_021F31F4 0x021F31F4 thumb ov194
 *   func_021F1FB4 0x021F1FB4 thumb ov194
 *   func_021F42E8 0x021F42E8 thumb ov194
 *   func_021F3E78 0x021F3E78 thumb ov194
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj01287.h"
#include "../include/Obj01577.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern int func_021F32D8(char *,u16 *);
extern unsigned func_021F4390(unsigned char *p);
extern u16 func_021F32FC(char *);
extern u32 KEY_GetTrg(void);
extern void func_021F3DE0(char *,int,u32,u32,u16);
extern void func_021F3E18(char *,int,void *),func_021F3D70(char *,int);
extern int func_021F2190(char *,u16);
extern int func_021F21BC(unsigned char *p, unsigned short a, unsigned short b);
extern int func_021F21FC(unsigned char *a, int b);
extern int func_021F22AC(char *);
extern int func_021F2150(unsigned char *p);
extern void func_021F233C(char *);
extern void func_021F235C(char *);
extern void func_021F2394(unsigned char *p);
extern void func_021F23B8(char *p, const u16 *q);
typedef unsigned char  u8;
struct U16Vec;
extern u32 func_021F23F8(const u8 *p);
extern int func_021F45A8(int);
extern int PROF_WORD_FindMatch(const u32 *cache, const void *input, u16 heap);
extern int PROF_WORD_CheckDigitCount(void *,int,int);
extern int func_021F4480(u8 *p, int a, int b);
extern void func_021F4524(char *),func_021F3EF0(char *,char *,int *,u32),func_021F462C(unsigned char *,u32);
extern void func_021F46F4(unsigned char *a, int *state, char *p);
extern void func_021F46B4(unsigned char *p, int *state);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void func_021F31F4(char *,char *);
extern int func_021F1FB4(u8 *p);
extern void func_021F42E8(char *);
extern int func_021F3E78(u8 *p);
static inline int invert(char *p,int v) { int r=1; if(func_021F21FC((unsigned char *)p,v)==0) r=0; return r; }
void func_021F47B4(unsigned char *owner,void *unused,char *p)
{
    u16 selected;
    u32 action=func_021F32D8(p+0xfc,&selected);
    u16 value=func_021F32FC(p+0xfc);
    if(((struct Obj01287 *)p)->f2C8==1) {
        if(action!=0 || func_021F4390((unsigned char *)(p+0x264))!=0 || (KEY_GetTrg()&~1u)!=0) {
            int *q=*(int * *)&((struct Obj01287 *)p)->f2C4;
            if(q[0]==1) {
                if(q[2]==0) func_021F3DE0(p+0x230,q[0],((struct Obj01577 *)q)->f4,((struct Obj01577 *)q)->f6,30);
                else func_021F3E18(p+0x230,q[0],(void *)q[2]);
            } else func_021F3D70(p+0x230,q[0]);
            ((struct Obj01287 *)p)->f2C8=0;
        }
    }
    switch(action) {
    case 1: if(func_021F2190(p+0x68,selected)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 2: if(func_021F21BC((unsigned char *)(p+0x68),selected,value)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 3: if(invert(p+0x68,0)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 4: if(invert(p+0x68,1)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 10: if(func_021F22AC(p+0x68)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 5: if(func_021F2150((unsigned char *)(p+0x68))) GFL_USE_PlaySeDefaultVolume(0x553); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 6: func_021F233C(p+0x68); break;
    case 11: func_021F235C(p+0x68); break;
    case 7: if(func_021F23F8((const u8 *)((int)(p+0x68)))==0) {
        if(func_021F45A8((int)p)==0) {GFL_USE_PlaySeDefaultVolume(0x557);func_021F3D70(p+0x230,8);((struct Obj01287 *)p)->f2C8=1;}
        else {
            if(PROF_WORD_FindMatch(*(u32 * *)&((struct Obj01287 *)p)->f2CC,p+0x68,30)) GFL_USE_PlaySeDefaultVolume(0x557);
            else if(PROF_WORD_CheckDigitCount(p+0x68,((struct Obj01287 *)p)->f86,30)) {GFL_USE_PlaySeDefaultVolume(0x557);func_021F3D70(p+0x230,9);((struct Obj01287 *)p)->f2C8=1;}
            else {
                int *q;
                GFL_USE_PlaySeDefaultVolume(0x54d);func_021F4524(p);q=*(int * *)&((struct Obj01287 *)p)->f2C4;
                if(q[0]==1 && q[3]!=0) {func_021F3EF0(p+0x254,p+0x230,q,30);func_021F462C(owner,(u32)func_021F46F4);}
                else func_021F462C(owner,(u32)func_021F46B4);
            }
        }
    } else {func_021F235C(p+0x68);GFL_USE_PlaySeDefaultVolume(0x54d);} break;
    case 0: if(func_021F4390((unsigned char *)(p+0x264))) {
        int text=func_021F4480((u8 *)p,**(int * *)&((struct Obj01287 *)p)->f2C4,30);
        func_021F2394((unsigned char *)(p+0x68));
        if(text) {func_021F23B8(p+0x68,STRBUF_GetChars((struct U16Vec *)text));STRBUF_Delete((struct U16Vec *)text);}
        GFL_USE_PlaySeDefaultVolume(0x54c);
    } break;
    case 9: func_021F235C(p+0x68);if(func_021F2190(p+0x68,selected)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557);break;
    default: break;
    }
    func_021F31F4(p+0xfc,p+0x68);
    func_021F1FB4((u8 *)(p+0x68));
    func_021F42E8(p+0x264);
    func_021F3E78((u8 *)(p+0x230));
}
