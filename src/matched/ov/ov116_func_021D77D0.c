/*
 * function: func_021D77D0
 * address: 0x021D77D0
 * packet: pkt_ov116_021D77D0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6998 0x021D6998 thumb ov116
 *   func_021D69A8 0x021D69A8 thumb ov116
 *   func_021D69C0 0x021D69C0 thumb ov116
 *   func_021D69EC 0x021D69EC thumb ov116
 *   func_021D6A10 0x021D6A10 thumb ov116
 *   func_021D6A40 0x021D6A40 thumb ov116
 *   func_021D6A44 0x021D6A44 thumb ov116
 *   func_021D6A48 0x021D6A48 thumb ov116
 *   func_021D6A4C 0x021D6A4C thumb ov116
 *   func_021D6A5C 0x021D6A5C thumb ov116
 *   func_021D6B30 0x021D6B30 thumb ov116
 *   func_021D7278 0x021D7278 thumb ov116
 *   func_021D72D0 0x021D72D0 thumb ov116
 *   func_021D730C 0x021D730C thumb ov116
 *   func_021D7324 0x021D7324 thumb ov116
 *   func_021D7B70 0x021D7B70 thumb ov116
 *   func_021D7C58 0x021D7C58 thumb ov116
 *   func_021D8010 0x021D8010 thumb ov116
 *   func_021D80CC 0x021D80CC thumb ov116
 *   func_021D8118 0x021D8118 thumb ov116
 *   func_021D8134 0x021D8134 thumb ov116
 *   func_021D8168 0x021D8168 thumb ov116
 *   func_021D8190 0x021D8190 thumb ov116
 *   func_021D81B4 0x021D81B4 thumb ov116
 *   func_021D81D0 0x021D81D0 thumb ov116
 *   func_021D81EC 0x021D81EC thumb ov116
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 */
#include "../include/Obj00470.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern void func_021D6998(void *a);
extern void func_021D69A8(u8 *,u8 *,u16);
extern void func_021D69EC(u8 *,u8 *,u16);
extern int func_021D69C0(u8 *,u8 *),func_021D6A10(u8 *,u8 *);
extern u16 func_021D6A40(u8 *),func_021D6A44(u8 *),func_021D6A48(u8 *);
extern int func_021D6A4C(unsigned char *p);
extern void func_021D6A5C(u8 *);
extern void func_021D6B30(u8 *,void *);
extern void func_021D7278(u8 *,int);
extern void func_021D72D0(u8 *p, u32 heap);
extern void func_021D730C(u8 *p);
extern u32 func_021D7324(u8 *);
extern void func_021D7B70(u8 *,u32),func_021D7C58(u8 *),func_021D8010(void *,u32);
extern int func_021D80CC(void *);
extern u32 func_021D8168(u8 *p);
extern int func_021D81EC(u8 *);
extern int FADE_IsActive(void);
extern void func_021D8118(u8 *p, u32 i, u32 a, u32 b);
extern void func_021D8134(u8 *p);
extern void func_021D8190(u8 *p);
extern void func_021D81B4(u8 *p);
extern void func_021D81D0(u8 *);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
int func_021D77D0(u8 *p,int heap)
{
    int v;
    u32 n;
    switch(((struct Obj00470 *)p)->fB6C) {
    case 0: func_021D81B4(p+4); func_021D8010(p+4,5); ++((struct Obj00470 *)p)->fB6C; break;
    case 1: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 2: FADE_Start(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 3: if(FADE_IsActive()==0) { func_021D7C58(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 4: func_021D72D0(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 5: ((struct Obj00470 *)p)->fB70=func_021D7324(p); func_021D730C(p); func_021D7B70(p+4,heap); FADE_Start(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 6:
        if(FADE_IsActive()==0) {
            n=((struct Obj00470 *)p)->fB70;
            if(n>=1 && n<=10) {
                func_021D69A8(p+0xb74,p+0x182c,n); func_021D8010(p+4,26); func_021D8190(p+4); ++((struct Obj00470 *)p)->fB6C;
            } else ((struct Obj00470 *)p)->fB6C=19;
        } break;
    case 7:
        if(func_021D69C0(p+0xb74,p+0x182c)!=0) {
            func_021D81B4(p+4); v=func_021D6A48(p+0xb74); func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74)); func_021D8010(p+4,6); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 8: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 9: FADE_Start(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 10: if(FADE_IsActive()==0) { func_021D7C58(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 11: func_021D7278(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 12: ((struct Obj00470 *)p)->fB70=func_021D7324(p); func_021D730C(p); func_021D7B70(p+4,heap); FADE_Start(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 13:
        if(FADE_IsActive()==0) {
            v=func_021D6A48(p+0xb74); n=((struct Obj00470 *)p)->fB70;
            if(n<1 || n>(u32)v) { ((struct Obj00470 *)p)->fB6C=19; break; }
            func_021D69EC(p+0xb74,p+0x182c,n);
            v=func_021D6A44(p+0xb74); func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74));
            func_021D8118(p+4,1,func_021D6A40(p+0xb74),(u32)((void *)2)); func_021D8010(p+4,1); func_021D8190(p+4); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 14: if(func_021D6A10(p+0xb74,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 15: func_021D6A5C(p+0xb74); func_021D6B30(p+0xb74,((struct Obj00470 *)p)->f1854); func_021D81D0(p); ++((struct Obj00470 *)p)->fB6C; break;
    case 16: if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,3); ++((struct Obj00470 *)p)->fB6C; } break;
    case 17: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 18: return 1;
    case 19: func_021D8010(p+4,9); ++((struct Obj00470 *)p)->fB6C; break;
    case 20: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 21: func_021D8134(p+4); ++((struct Obj00470 *)p)->fB6C; break;
    case 22: v=func_021D8168(p+4); if(v==0) return 2; if(v==-2) { func_021D6998(p+0xb74); ((struct Obj00470 *)p)->fB6C=0; } break;
    }
    return 0;
}
