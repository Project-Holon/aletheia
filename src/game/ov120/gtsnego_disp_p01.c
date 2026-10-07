/*
 * file:     gtsnego_disp_p01.c
 * unit:     yes
 * function: func_021D4240, func_021D4244, func_021D424C, func_021D4278, func_021D42A8, func_021D42D8, func_021D435C, func_021D437C, func_021D439C
 * address:  0x021D4240
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02008468 0x02008468 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D593C 0x021D593C thumb ov120
 *   func_021D5980 0x021D5980 thumb ov120
 */
#include "../../matched/include/Obj22820.h"
#include "../../matched/include/Obj22821.h"
#include "../../matched/include/Obj22822.h"
#include "../../matched/include/Obj02830.h"
#include "../../matched/include/Obj06431.h"
#include "../../matched/include/Obj06432.h"
#include "../../matched/include/Obj01150.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *);
extern void func_02082D44(const void *,void *,u32);
extern int func_02008468(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 a);
extern void func_021D69F4(u8 *, void *, u32);
extern int func_021D593C(u8 *, int);
extern void func_021D5980(u8 *);
void func_021D4240(int *p,int v);
void func_021D4244(int *p, int v, int a2);
void func_021D424C(u32 id,int b,const void *src,u8 *p,struct Entry *entry);
void func_021D4278(u32 id,int b,const void *src,u8 *p,struct Entry *entry);
void func_021D42A8(u32 id,int b,const void *src,u8 *p,struct Entry *entry);
int func_021D42D8(int n, u8 *p);
void func_021D435C(int n, char *p);
void func_021D437C(int n, char *p);
void func_021D439C(int n, char *p);

void func_021D4240(int *p,int v) { *p=v; }

void func_021D4244(int *p, int v, int a2) {func_021D4240(p,v);}

void func_021D424C(u32 id,int b,const void *src,u8 *p,struct Entry *entry) { u8 *q; q=*(u8 * *)&((struct Obj22820 *)p)->f48; if(entry==func_020399A8() && id!=func_0203D1A4((struct Link *)func_020399A8())) func_02082D44(src,q+12,8); }

void func_021D4278(u32 id,int b,const void *src,u8 *p,struct Entry *entry) { u8 *q; q=*(u8 * *)&((struct Obj22821 *)p)->f48; if(entry==func_020399A8() && id!=func_0203D1A4((struct Link *)func_020399A8())) func_02082D44(src,((struct Obj22822 *)q)->f18,func_02008468()); }

void func_021D42A8(u32 id,int b,const void *src,u8 *p,struct Entry *entry) { if(entry==func_020399A8() && id!=func_0203D1A4((struct Link *)func_020399A8())) func_02082D44(src,p+0x174,12); }

/*
 * extent: existing matched followers 021D435C, 021D437C, 021D439C remain separate.
 */
int func_021D42D8(int n, u8 *p)
{
    ((struct Obj02830 *)p)->f138 = n;
    func_020355D8(1);
    if (((struct Obj02830 *)p)->f184 == 1) {
        func_020061E4(0x551);
        return 1;
    }
    if (n == 0) {
        ((struct Obj02830 *)p)->f15C = 0;
        func_021D69F4(*(u8 * *)&((struct Obj02830 *)p)->f3C, ((struct Obj02830 *)p)->f34, 0);
        func_021D593C(p, ((struct Obj02830 *)p)->f15C);
        func_021D4244((int *)p, (int)func_021D5980, 0x177);
    } else {
        ((struct Obj02830 *)p)->f15C = 1;
        func_021D69F4(*(u8 * *)&((struct Obj02830 *)p)->f3C, ((struct Obj02830 *)p)->f34, 1);
        func_021D593C(p, ((struct Obj02830 *)p)->f15C);
        func_021D4244((int *)p, (int)func_021D5980, 0x17e);
    }
    return 1;
}

/*
 * follower: separately filed 021D437C.
 */
void func_021D435C(int n, char *p) {
    ((struct Obj06431 *)p)->f13C+=n;
    if(((struct Obj06431 *)p)->f13C>=5) ((struct Obj06431 *)p)->f13C=0;
    else if(((struct Obj06431 *)p)->f13C<0) ((struct Obj06431 *)p)->f13C=4;
}

/*
 * follower: separately filed 021D439C.
 */
void func_021D437C(int n, char *p) {
    ((struct Obj06432 *)p)->f140+=n;
    if(((struct Obj06432 *)p)->f140>=5) ((struct Obj06432 *)p)->f140=0;
    else if(((struct Obj06432 *)p)->f140<0) ((struct Obj06432 *)p)->f140=4;
}

void func_021D439C(int n, char *p) {
    ((struct Obj01150 *)p)->f144+=n;
    if(((struct Obj01150 *)p)->f144>=4) ((struct Obj01150 *)p)->f144=0;
    else if(((struct Obj01150 *)p)->f144<0) ((struct Obj01150 *)p)->f144=3;
}
