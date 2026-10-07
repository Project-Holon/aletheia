/*
 * file:     unit_021BF050_p07.c
 * unit:     yes
 * function: func_021C04A4, func_021C04D0, func_021C0528, func_021C0554
 * address:  0x021C04A4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9B64  0x021B9B64  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C23D8 0x021C23D8 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 */
#include "../../matched/include/Obj00008.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C04A4;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef unsigned int   u32_021C04D0;

typedef enum { K274=0x274 } Off;

typedef unsigned long  u32_021C0528;

typedef unsigned int   u32_021C0554;

extern void func_021B9B64(char *p);
extern int func_021BA928(void *p);
extern void func_021BA828(char *p);
extern u32_021C04D0 func_021BA858(char *p);
extern int func_021C23C8(void *a, void *b);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021C23D8(char *,int);
extern void func_021C2408(char *);
extern void func_021BA8EC(char *);
extern int func_021B97F4(char *);
extern void *func_021BE2A8(char *,int);
extern int func_021C27E0(void *);
extern void func_021BAAB8(char *,int,int);
extern void func_021B9AE0(void *w, u8 *s);
int func_021C04A4(char *p, int v);
int func_021C04D0(char *p,int ret);
int func_021C0528(char *p, int v);
int func_021C0554(char *p,int ret);


/*
 * The same re-arm and stamp as func_021C01A0 with selector 0xA1.
 */
int func_021C04A4(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        *(u32_021C04A4 *)&((struct Obj00008 *)p)->f1CC = 0xA1;
    }

    return v;
}

int func_021C04D0(char *p,int ret) {
    int r;
    Off o;
    r=func_021BA858(p);
    o=K274;
    func_021B9B64(p+o);
    if(r==-1)return ret;
    if(r==0){
        func_021C23C8(p,(void *)(-1));
        func_021C18C8(p,2,5);
        func_021C23D8(p,1);
        *(int *)(p+(o-0xa8))=158;
    } else {
        func_021C2408(p);
        func_021BA8EC(p);
        *(int *)(p+(o-0xa8))=11;
    }
    return ret;
}


/*
 * The same re-arm and stamp as func_021C01A0 with selector 0xA3.
 */
int func_021C0528(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        *(u32_021C0528 *)&((struct Obj00008 *)p)->f1CC = 0xA3;
    }

    return v;
}

/*
 * note (2026-10-05, wD9r lane82): the enum-typed offset local and the enum inline helper (stand-ins)
 *   are removed. The real form is a pointer local `st = p + 0x24c;` set as the first statement and
 *   passed to the first func_021C27E0; the other uses are plain p + 0x274, p + 0x1cc and p + 0x1f0.
 *   mwcc keeps 0x24C in r6 and derives the other offsets from it, as in the image. EXACT in c99 and c.
 */
int func_021C0554(char *p,int ret) {
    int i;
    int r;
    void *q;
    char *st;
    st=p+0x24c;
    i=func_021B97F4(p+0x274);
    r=func_021BA858(p);
    q=func_021BE2A8(p,i);
    func_021B9B64(p+0x274);
    if(r==-1)return ret;
    if(r==0){
        *(int *)&((struct Obj00008 *)p)->f135C=2;
        if(func_021C27E0(st)==func_021C27E0(((struct Obj00008 *)p)->f8)){
            *(int *)(p+0x1cc)=118;
        }else{
            if(func_021C27E0(((struct Obj00008 *)p)->f8))func_021BAAB8(p,73,0);
            else func_021BAAB8(p,72,0);
            ((struct Obj00008 *)p)->f1CC=55;
        }
    } else {
        func_021BA8EC(p);
        func_021C18C8(p,1,2);
        *(int *)(p+0x1f0)=-1;
        func_021C2408(p);
        *(int *)(p+0x1cc)=11;
        if(q)func_021B9AE0(p+0x274,q);
    }
    return ret;
}
