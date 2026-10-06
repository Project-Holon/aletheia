/*
 * function: func_021D6710
 * address: 0x021D6710
 * packet: pkt_ov116_021D6710
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D696C 0x021D696C thumb ov116
 *   func_021D7158 0x021D7158 thumb ov116
 *   func_021D737C 0x021D737C thumb ov116
 *   func_021D73D4 0x021D73D4 thumb ov116
 *   func_021D7B70 0x021D7B70 thumb ov116
 *   func_021D7A3C 0x021D7A3C thumb ov116
 *   func_021D8010 0x021D8010 thumb ov116
 *   func_021D8190 0x021D8190 thumb ov116
 *   func_021D7A94 0x021D7A94 thumb ov116
 *   func_021D80CC 0x021D80CC thumb ov116
 *   func_021D6B88 0x021D6B88 thumb ov116
 *   func_021D6C50 0x021D6C50 thumb ov116
 *   func_021D6CBC 0x021D6CBC thumb ov116
 *   func_021D6D18 0x021D6D18 thumb ov116
 *   func_021D7424 0x021D7424 thumb ov116
 *   func_021D7AA8 0x021D7AA8 thumb ov116
 *   func_021D7AC8 0x021D7AC8 thumb ov116
 *   func_021D7C58 0x021D7C58 thumb ov116
 *   func_021D73E0 0x021D73E0 thumb ov116
 *   func_021D7B00 0x021D7B00 thumb ov116
 *   func_021D7038 0x021D7038 thumb ov116
 *   func_021D7B64 0x021D7B64 thumb ov116
 *   func_021D7CF4 0x021D7CF4 thumb ov116
 *   func_021C8FA8 0x021C8FA8 arm ov114
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 */
#include "../include/Obj00671.h"
#include "../include/Obj22612.h"
#include "../include/Obj22613.h"
#include "../include/Obj22614.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern int func_021D696C(u8 *,int);
extern int func_021D7158(u8 *p);
extern u32 func_0200FB24(void);
extern int func_02005E50(void);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(int,int);
extern void func_02005DF8(unsigned);
extern void func_02005E30(u32 a);
extern void func_021D737C(u8 *);
extern void func_021D7B70(u8 *,u32);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_021D7A3C(u8 *);
extern int func_021D73D4(u8 *),func_0204E804(void),func_021D7A94(u8 *),func_021D80CC(void *);
extern void func_021D8010(void *,u32);
extern void func_021D8190(u8 *p);
extern void func_021D6B88(u8 *,void *,int);
extern int func_021D6C50(u8 *,unsigned),func_021D6D18(u8 *,u8 *),func_021D7424(u8 *,int),func_021D7AC8(u8 *);
extern void func_021D6CBC(u8 *,void *,u8 *),func_021D7AA8(u8 *),func_021D7C58(u8 *),func_021D73E0(u8 *);
extern int func_0200F7B8(int),func_021D7B00(u8 *),func_021D7B64(u8 *);
extern void func_021D7038(u8 *),func_021C8FA8(void),func_021D7CF4(u8 *);
int func_021D6710(void *a,int *state,int b,u8 *p)
{
    int v;
    if(func_021D696C(p,*state)!=0) {
        if(func_021D7158(p+0x182c)!=0 || func_0200FB24()!=0) *state=20;
    }
    switch(*state) {
    case 0: func_02005E30(6); ++*state; break;
    case 1: if(func_02005E50()==0) { func_02005DE4((void *)1); func_02005E64(); func_02005D90(1153,65535); func_02005DF8(6); ++*state; } break;
    case 2: func_021D737C(p); ++*state; break;
    case 3: if(func_021D73D4(p)==0) ++*state; else { ((struct Obj22612 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f8=2; *state=17; } break;
    case 4: func_021D7B70(p+4,125); func_0204E720(3,16,0,1); ++*state; break;
    case 5: if(func_0204E804()==0) ++*state; break;
    case 6: func_021D7A3C(p); func_021D8010(p+4,26); func_021D8190(p+4); ++*state; break;
    case 7: if(func_021D7A94(p)!=0) ++*state; break;
    case 8: if(func_021D80CC(p+4)!=0) ++*state; break;
    case 9: func_021D6B88(p+0x1610,((struct Obj00671 *)p)->f1844,125); ++*state; break;
    case 10: if(func_021D6C50(p+0x1610,125)!=0) ++*state; break;
    case 11: func_021D6CBC(p+0x1610,((struct Obj00671 *)p)->f1844,p+0x182c); ++*state; break;
    case 12: if(func_021D6D18(p+0x1610,p+0x182c)!=0) ++*state; break;
    case 13: v=func_021D7424(p,125); if(v==1) { ((struct Obj22613 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f8=0; ++*state; } else if(v==2) { ((struct Obj22614 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f8=2; ++*state; } break;
    case 14: func_021D7AA8(p); func_0204E720(3,0,16,1); ++*state; break;
    case 15: if(func_021D7AC8(p)!=0 && func_0204E804()==0) { func_021D7C58(p+4); ++*state; } break;
    case 16: if(func_0200F7B8(0)==0) func_021D73E0(p); ++*state; break;
    case 17: func_02005E30(6); ++*state; break;
    case 18: if(func_02005E50()==0) ++*state; break;
    case 19: return 1;
    case 20: if(func_021D7B00(p)!=0) *state=21; else *state=14; func_021D7038(p+0x1610); break;
    case 21: if(func_021D7B64(p)!=0) *state=14; break;
    }
    if(((struct Obj00671 *)p)->fB68!=0) func_021C8FA8();
    func_021D7CF4(p+4);
    return 0;
}
