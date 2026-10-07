/*
 * file:     zukan_detail_graphic_p33.c
 * unit:     yes
 * function: func_021C2560, func_021C2644, func_021C270C
 * address:  0x021C2560
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC32C  0x021BC32C  thumb  ov208
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BC3A8  0x021BC3A8  thumb  ov208
 *   func_021BC3AC  0x021BC3AC  thumb  ov208
 *   func_021BC3B0  0x021BC3B0  thumb  ov208
 *   ov208_func_021BCF4C  0x021BCF4C  thumb  ov208
 *   func_021C2BE0  0x021C2BE0  thumb
 *   func_021C2BA8  0x021C2BA8  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_021BC448  0x021BC448  thumb  ov208
 *   func_021BC518  0x021BC518  thumb  ov208
 *   func_021BC508  0x021BC508  thumb  ov208
 *   func_021BC610  0x021BC610  thumb  ov208
 *   func_02006650  0x02006650  thumb
 *   func_020065D8  0x020065D8  thumb
 *   func_021C3638  0x021C3638  thumb  ov208
 *   func_021BC97C  0x021BC97C  thumb  ov208
 *   func_021BCA54  0x021BCA54  thumb  ov208
 *   func_021C2FEC  0x021C2FEC  thumb
 *   func_021C32FC  0x021C32FC  thumb  ov208
 *   func_021C3268  0x021C3268  thumb  ov208
 *   func_021C337C  0x021C337C  thumb  ov208
 *   func_021C3374  0x021C3374  thumb  ov208
 *   func_021C2D88  0x021C2D88  thumb  ov208
 *   func_021BC61C  0x021BC61C  thumb  ov208
 *   func_021BC464  0x021BC464  thumb  ov208
 *   func_021C2BF4  0x021C2BF4  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_021BC34C  0x021BC34C  thumb  ov208
 *   func_021BC3B4 0x021BC3B4 thumb ov208
 *   func_021BC3B8 0x021BC3B8 thumb ov208
 *   func_021BC3BC 0x021BC3BC thumb ov208
 *   func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_021C2C44 0x021C2C44 thumb ov208
 *   func_021C2E6C 0x021C2E6C thumb ov208
 *   func_021C3218 0x021C3218 thumb ov208
 *   func_021C3280 0x021C3280 thumb ov208
 *   func_021C3354 0x021C3354 thumb ov208
 *   func_021C3378 0x021C3378 thumb ov208
 *   func_021BC9BC 0x021BC9BC thumb ov208
 *   func_021BC844 0x021BC844 thumb ov208
 *   func_021C2DE0 0x021C2DE0 thumb ov208
 *   func_021C35DC 0x021C35DC thumb ov208
 *   func_021BC758 0x021BC758 thumb ov208
 *   func_021BC718 0x021BC718 thumb ov208
 *   func_021BC4F4 0x021BC4F4 thumb ov208
 *   func_021C3AA8 0x021C3AA8 thumb ov208
 *   func_021BC6D8 0x021BC6D8 thumb ov208
 *   func_021BDAD0 0x021BDAD0 thumb ov208
 *   func_021BDAAC 0x021BDAAC thumb ov208
 *   func_021BDAD4 0x021BDAD4 thumb ov208
 *   func_021BDBB8 0x021BDBB8 thumb ov208
 *   func_021BDC48 0x021BDC48 thumb ov208
 *   func_021BDC14 0x021BDC14 thumb ov208
 *   func_021BE840 0x021BE840 thumb ov208
 *   func_021BE82C 0x021BE82C thumb ov208
 *   func_021BE844 0x021BE844 thumb ov208
 *   func_021BC6C8 0x021BC6C8 thumb ov208
 *   func_021BDBA0 0x021BDBA0 thumb ov208
 *   func_021BC6F8 0x021BC6F8 thumb ov208
 *   func_021BE854 0x021BE854 thumb ov208
 *   func_021BDAE8 0x021BDAE8 thumb ov208
 *   func_021C3514 0x021C3514 thumb ov208
 *   func_021C3B14 0x021C3B14 thumb ov208
 *   func_021C3380 0x021C3380 thumb ov208
 *   func_021C3650 0x021C3650 thumb ov208
 *   func_021C301C 0x021C301C thumb ov208
 *   func_021C3318 0x021C3318 thumb ov208
 *   func_021BC99C 0x021BC99C thumb ov208
 *   func_021BC46C 0x021BC46C thumb ov208
 *   func_021BC678 0x021BC678 thumb ov208
 *   func_021C2C1C 0x021C2C1C thumb ov208
 *   func_02040618 0x02040618 arm
 *   func_020414AC 0x020414AC arm
 *   func_0204047C 0x0204047C arm
 *   func_0204B688 0x0204B688 arm
 *   func_02012BF8 0x02012BF8 thumb
 */
#include "../../matched/include/Obj03934.h"

#define W(o) (*(u32 *)(p+(o)))
struct Ov208Buf;
struct S;
struct Node;
struct Actor;
struct Ov208Win;
struct Ov208PalFade;
struct Ov208Scene;
struct Ov208Fade;
struct Ov208Icon;
struct Ov208Blend;
struct Key;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

struct S {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 pad0c[0x10];
    u32 f1c;
    u8 pad20[0x34];
    u32 a54[2];
    u32 f5c;
    u8 pad60[8];
    u32 f68;
    u8 pad6c[8];
    u16 f74;
    u16 f76;
    u8 pad78[0x40];
    u32 fb8;
    u32 fbc;
    u32 fc0;
    u32 fc4;
    u32 fc8;
    u32 fcc;
    u32 fd0;
};

extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern void func_02082BCC(void *dst, int v, u32 n);
extern int func_021BC3A8(int *p);
extern int func_021BC3AC(int *p);
extern int func_021BC3B0(int *p);
extern u32 ov208_func_021BCF4C(int v);
extern void func_021C2BE0(void *unused, u8 *p, void *a2);
extern void func_021C2BA8(void *a0, u8 *st);
extern u32 func_020056A0(void (*cb)(void *, u8 *), void *arg, int pri);
extern void *func_021BC448(u32 heap);
extern void func_021BC518(int *p);
extern void func_021BC508(int flag, int *p);
extern void *func_021BC610(u32 heap);
extern int func_02006650(void);
extern void func_020065D8(void);
extern void func_021C3638(void *unused, char *p, void *a2);
extern void func_021BC97C(char *p);
extern void func_021BCA54(u32 a, u32 packed);
extern void func_021C2FEC(void *unused, struct S *p, u32 unused2, u32 i);
extern void func_021C32FC(u16 *heap, u8 *p, int key);
extern void func_021C3268(void *unused, char *p, void *a2);
extern void func_021C337C(void *a0, void *st, void *a2);
extern void func_021C3374(void *a0, void *st, void *a2);
extern void func_021C2D88(void *a0, u8 *st, void *a2);
extern void func_021BC61C(char *p);
extern void func_021BC464(void *a0);
extern void func_021C2BF4(void *unused, char *p, void *a2);
extern void func_02030EAC(struct Node *n);
extern void func_021BC34C(char *p);
extern int func_021BC3B4(int *p);
extern int func_021BC3B8(char *p);
extern u16 func_021BC3BC(char *);
extern int func_021BC3A4(int *p);
extern void func_02040618(u32,u32,u32);
extern void func_020414AC(u8);
extern void func_0204047C(int,u16);
extern void func_0204B688(struct Actor *,u32);
extern int func_02012BF8(int,int);
extern void func_021C2C44(u16 *heap, struct S *st, int a2);
extern void func_021C2E6C(u16 *,u8 *,int,u32);
extern void func_021C3218(u16 *,u8 *,int);
extern void func_021C3280(u16 *,u8 *,struct Key *);
extern void func_021C3354(unsigned short *p, void *a1, int a2);
extern void func_021C3378(void *a0, void *a1, int a2, int a3, int a4);
extern u32 func_021BC9BC(int,u16,u8,u8,u8,u8,u32,u32,u32,u32,u32);
extern struct Ov208Win *func_021BC844(u16,u32,u8,u8,u8);
extern void func_021C2DE0(void *,u8 *,void *,int,u16);
extern void func_021C35DC(u16 *,u8 *,int);
extern void func_021BC758(struct Ov208PalFade *);
extern void func_021BC718(char *p);
extern void func_021BC4F4(int flag, int *p);
extern void func_021C3AA8(void *,u8 *,int);
extern void func_021BC6D8(char *p);
extern int func_021BDAD0(struct Ov208Fade *);
extern void func_021BDAAC(struct Ov208Scene *,u32,u32,u32);
extern void func_021BDAD4(struct Ov208Fade *,int);
extern void func_021BDBB8(struct Ov208Scene *,u32);
extern void func_021BDC48(struct Ov208Scene *,u32);
extern void func_021BDC14(char *p, int b);
extern int func_021BE840(struct Ov208Icon *);
extern void func_021BE82C(struct Ov208Icon *,int);
extern void func_021BE844(struct Ov208Icon *);
extern int func_021BC6C8(char *p);
extern void func_021BDBA0(struct Ov208Scene *);
extern void func_021BC6F8(char *p);
extern void func_021BE854(struct Ov208Icon *);
extern void func_021BDAE8(char *p, int v);
extern void func_021C3514(u16 *,u8 *,int);
extern void func_021C3B14(void *,u8 *,int);
extern void func_021C3380(u16 *,u8 *,int);
extern void func_021C3650(u16 *,u8 *,int);
extern void func_021C301C(u16 *,u8 *,int);
extern void func_021C3318(u16 *,u8 *,int);
extern void func_021BC99C(char *p);
extern void func_021BC46C(struct Ov208Blend *,struct Ov208Blend *);
extern void func_021BC678(char *p);
extern void func_021C2C1C(int unused, char *p, int a2);
u32 func_021C2560(void *a0, u32 a1, u16 *desc, u32 a3, int *obj);
u32 func_021C2644(void *a0, u32 a1, void *a2, u8 *st, void *a4);
/* Explicit caller r2 loads preserve trailing arguments on setup/update helpers. */ int func_021C270C(void *unused,int *seq,u16 *heap,u8 *p,int key);


u32 func_021C2560(void *a0, u32 a1, u16 *desc, u32 a3, int *obj)
{
    struct S *st;
    u8 i;

    st = func_021BC32C(a0, 0xd4, *desc);
    func_02082BCC(st, 0, 0xd4);
    i = 0;
    st->f0 = ov208_func_021BCF4C(func_021BC3A8(obj));
    st->f4 = func_021BC3AC(obj);
    st->f8 = func_021BC3B0(obj);
    st->f1c = 0;
    st->f68 = 0;
    st->f74 = 0;
    st->f76 = 1;
    st->fb8 = 0;
    func_021C2BE0(desc, (u8 *)st, obj);
    st->fbc = func_020056A0(func_021C2BA8, st, 1);
    st->fc0 = (u32)func_021BC448(*desc);
    st->fc4 = (u32)func_021BC448(*desc);
    func_021BC518((int *)st->fc0);
    func_021BC518((int *)st->fc4);
    func_021BC508(0, (int *)st->fc0);
    func_021BC508(1, (int *)st->fc4);
    st->fc8 = (u32)func_021BC610(*desc);
    st->fcc = 0;
    st->fd0 = 1;
    for (i = 0; i < 2; i++) {
        st->a54[i] = 0;
    }
    st->f5c = 0;
    return 1;
}


u32 func_021C2644(void *a0, u32 a1, void *a2, u8 *st, void *a4)
{
    u8 i;

    if (func_02006650() != 0) {
        func_020065D8();
    }
    func_021C3638(a2, (char *)st, a4);
    func_021BC97C(*(char * *)&((struct Obj03934 *)st)->f80);
    func_021BC97C(*(char * *)&((struct Obj03934 *)st)->f7C);
    func_021BCA54(2, ((struct Obj03934 *)st)->f78);
    for (i = 0; i < 2; i++) {
        func_021C2FEC(a2, (struct S *)st, (u32)a4, i);
    }
    func_021C32FC(a2, st, (int)a4);
    func_021C3268(a2, (char *)st, a4);
    func_021C337C(a2, st, a4);
    func_021C3374(a2, st, a4);
    func_021C2D88(a2, st, a4);
    func_021BC61C(*(char * *)&((struct Obj03934 *)st)->fC8);
    func_021BC464(*(char * *)&((struct Obj03934 *)st)->fC4);
    func_021BC464(*(char * *)&((struct Obj03934 *)st)->fC0);
    if (((struct Obj03934 *)st)->fB8 != 3) {
        func_021C2BF4(a2, (char *)st, a4);
    }
    func_02030EAC(((struct Obj03934 *)st)->fBC);
    func_021BC34C((char *)a0);
    return 1;
}

/* Explicit caller r2 loads preserve trailing arguments on setup/update helpers. */
int func_021C270C(void *unused,int *seq,u16 *heap,u8 *p,int key)
{
    void *scene;
    struct Ov208Icon *icon;
    u8 i;
    int ready;
    scene=(void *)func_021BC3B4((int *)key);
    icon=(struct Ov208Icon *)func_021BC3B8((char *)key);
    switch(*seq){
    case 0:
        *seq=1;
        for(i=0;i<=7;i++){
            if(i!=1 && i!=5){
                func_02040618(i,0,0);
                func_02040618(i,3,0);
                func_020414AC(i);
            }
        }
        func_0204047C(2,1);
        func_0204047C(3,2);
        func_0204047C(0,3);
        func_0204047C(6,1);
        func_0204047C(4,3);
        func_021C2C44(heap,(struct S *)p,key);
        func_021C2E6C(heap,p,key,W(0x5c));
        func_0204B688((struct Actor *)(*(u32 *)((p+W(0x5c)*4)+0x54)),1);
        func_021C3218(heap,p,key);
        func_021C3280(heap,p,(struct Key *)key);
        func_021C3354(heap,p,key);
        func_021C3378(heap,p,key,0,0);
        W(0x78)=func_021BC9BC(0,*heap,2,1,0,5,0x9f,1,0xb,0x2a,0);
        W(0x7c)=(u32)func_021BC844(*heap,2,0,2,3);
        W(0x80)=(u32)func_021BC844(*heap,2,4,1,2);
        func_021C2DE0(heap,p,(void *)key,0,0);
        func_021C35DC(heap,p,key);
        func_021BC758((struct Ov208PalFade *)W(0xc8));
        func_021BC718((char *)W(0xc8));
        break;
    case 1:
        *seq=2;
        func_021BC4F4(0,(int *)W(0xc0));
        func_021BC4F4(1,(int *)W(0xc4));
        func_021C3AA8(heap,p,key);
        break;
    case 2:
        *seq=3;
        func_021BC6D8((char *)W(0xc8));
        if(func_021BDAD0(scene)!=2){
            func_021BDAAC(scene,0,2,func_021BC3BC((char *)key)>1);
            func_021BDAD4(scene,0);
        }else func_021BDBB8(scene,2);
        func_021BDC48(scene,0);
        func_021BDC14(scene,func_02012BF8(func_021BC3A4((int *)key),0x13));
        if(func_021BE840(icon)!=2){
            func_021BE82C(icon,2);
            func_021BE844(icon);
        }
        break;
    case 3:
        if(func_021BC6C8((char *)W(0xc8))==0 && func_021BDAD0(scene)==2 && func_021BE840(icon)==2){
            func_021BDBA0(scene);
            func_021BDC48(scene,1);
            *seq=4;
        }
        break;
    case 4:
        if(W(0xcc)!=0){
            *seq=5;
            func_021BC6F8((char *)W(0xc8));
            func_021BE854(icon);
            if(W(0xcc)==2)func_021BDAE8(scene,0);
            func_021C2BF4(heap,(char *)p,(void *)key);
        }else func_021C3514(heap,p,key);
        break;
    case 5:
        ready=0;
        if(func_021BC6C8((char *)W(0xc8))==0 && func_021BE840(icon)==0){
            if(W(0xcc)==2){
                if(func_021BDAD0(scene)==0)ready=1;
            }else ready=1;
        }
        if(ready)*seq=6;
        break;
    case 6:
        *seq=7;
        func_021C3B14(heap,p,key);
        func_021BC508(0,(int *)W(0xc0));
        func_021BC508(1,(int *)W(0xc4));
        break;
    case 7:
        return 1;
    }
    if(*seq>=3){
        func_021C3380(heap,p,key);
        func_021C3650(heap,p,key);
        func_021C301C(heap,p,key);
    }
    if(*seq>=2){
        func_021C3318(heap,p,key);
        func_021BC99C((char *)W(0x7c));
        func_021BC99C((char *)W(0x80));
    }
    func_021BC46C((struct Ov208Blend *)W(0xc0),(struct Ov208Blend *)W(0xc4));
    func_021BC678((char *)W(0xc8));
    func_021C2C1C((int)heap,(char *)p,key);
    return 0;
}
