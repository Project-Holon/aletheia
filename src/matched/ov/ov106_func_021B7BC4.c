/*
 * function: func_021B7BC4
 * address: 0x021B7BC4
 * packet: pkt_ov106_021B7BC4
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: The signed-halfword result of 021B913C is already sign-extended by its body. ROUND follows the runtime-confirmed add/subtract mapping.
 * symbols:
 *   func_021B84D0 0x021B84D0 thumb ov106
 *   func_021B84C4 0x021B84C4 thumb ov106
 *   func_021B8518 0x021B8518 thumb ov106
 *   func_021B900C 0x021B900C thumb ov106
 *   func_021B9134 0x021B9134 thumb ov106
 *   func_021B78D0 0x021B78D0 thumb ov106
 *   func_021B7984 0x021B7984 thumb ov106
 *   func_021B9198 0x021B9198 thumb ov106
 *   func_021B913C 0x021B913C thumb ov106
 *   func_021B8408 0x021B8408 thumb ov106
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B7948 0x021B7948 thumb ov106
 *   func_021B838C 0x021B838C thumb ov106
 *   func_021B8FD0 0x021B8FD0 thumb ov106
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_0207C768 0x0207C768 arm
 */
#include "../include/Obj10253.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021B84D0(u8 *);
extern s16 func_021B84C4(u8 *),func_021B8518(u8 *);
extern void func_021B900C(u8 *,int,int),func_021B9134(u8 *),func_021B78D0(u8 *,u32);
extern void func_021B7984(u8 *,u32,u8 *);
extern void func_021B7948(u8 *a, int *s);
extern int func_021B9198(int *p);
extern int func_021B7250(int *);
extern s16 func_021B913C(u8 *);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_021B8408(u8 *,s16);
extern void func_021B838C(u8 *);
extern void func_021B8FD0(u8 *);
extern void func_021B71E4(int a);
#define ROUND(a) ((int)((a)>0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))
void func_021B7BC4(u8 *a,u32 unused,u8 *p) {
    int target,current,last;
    target=(s16)(func_021B84D0(p+0x38)-192);
    if(target<0) target=0;
    current=func_021B84C4(p+0x38);
    last=func_021B8518(p+0x38);
    if((s16)target>current && current!=last) {
        int n=++((struct Obj10253 *)p)->f640;
        if(ROUND(n)>81920)
            func_021B900C(p+0x600,(int)(((long long)(int)func_0207C768((int)(ROUND(n)-81920),(int)163840)*245760+2048)>>12),12);
        else func_021B900C(p+0x600,8192,12);
    } else {
        func_021B9134(p+0x600);
        func_021B78D0(p+0x28,(u32)func_021B7984);
    }
    if(func_021B9198((int *)(p+0x600))) func_021B8408(p+0x38,func_021B913C(p+0x600));
    if(func_021B7250(*(int * *)&((struct Obj10253 *)p)->f614)==1)func_021B78D0(a,(u32)func_021B7948);
    func_021B838C(p+0x38);
    func_021B8FD0(p+0x600);
    func_021B71E4((u32)(*(u32 *)&((struct Obj10253 *)p)->f614));
}
