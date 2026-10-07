/*
 * file:     psel_p03.c
 * unit:     yes
 * function: func_021B9A6C, func_021B9A8C, func_021B9AE4
 * address:  0x021B9A6C
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020480E4 0x020480E4 arm
 *   func_021B9600 0x021B9600 thumb ov223
 *   func_02011558 0x02011558 thumb
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_02047910 0x02047910 arm
 *   func_02011590 0x02011590 thumb
 *   func_021BC52C 0x021BC52C thumb ov223
 *   func_02011B8C 0x02011B8C thumb
 *   table 0x021BC78C data a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021B95A0 0x021B95A0 thumb ov223
 */
#include "../../matched/include/Obj05571.h"
#include "../../matched/include/Obj00738.h"
#include "../../matched/include/Obj05572.h"

struct Ctx;
struct IcaAnime;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern void func_020480E4(struct Ctx *,u32);
extern void func_021B9600(void *);
extern void func_02011558(struct IcaAnime *);
extern u32 func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *);
extern int func_02047910(void *,int,int);
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern unsigned func_021BC52C(unsigned char *p);
extern void func_02011B8C(void *,void *);
extern int func_021B95A0(int,int);
void func_021B9A6C(char *p);
void func_021B9A8C(char *p);
void func_021B9AE4(char *p,int type,int flag);
extern u16 table[][5];

void func_021B9A6C(char *p) {func_020480E4(*(struct Ctx * *)&((struct Obj05571 *)p)->f28,((struct Obj05571 *)p)->f2E);func_021B9600(((struct Obj05571 *)p)->f3C);((struct Obj05571 *)p)->f3A=0;func_02011558(*(struct IcaAnime * *)&((struct Obj05571 *)p)->f40);}

void func_021B9A8C(char *p)
{
    int *obj;
    u32 n;
    u16 j;
    obj=(int *)func_02048A18(*(unsigned char * *)&((struct Obj00738 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj00738 *)p)->f3C+((struct Obj00738 *)p)->f32*68));
    n=func_0204779C(obj);
    for(j=0;j<n;j++) func_02047910(obj,j,2048);
    func_02011590(((struct Obj00738 *)p)->f40,2048);
    func_02011B8C((void *)func_021BC52C(((struct Obj00738 *)p)->f14),((struct Obj00738 *)p)->f40);
    (((struct Obj00738 *)p)->f50)++;
}

void func_021B9AE4(char *p,int type,int flag)
{
    u16 v;
    float f;
    v=table[type][flag?1:0];
    if(v!=0) f=0.5f+(float)(v<<12);
    else f=(float)(v<<12)-0.5f;
    func_021B95A0(*(int *)&((struct Obj05572 *)p)->f40,(int)f);
    func_02011B8C((void *)func_021BC52C(((struct Obj05572 *)p)->f14),((struct Obj05572 *)p)->f40);
    ((struct Obj05572 *)p)->f44=type;
    ((struct Obj05572 *)p)->f48=flag;
    ((struct Obj05572 *)p)->f4C=v;
}
