/*
 * file:     p_sta_oam_p29.c
 * unit:     yes
 * function: func_021DABCC, func_021DAEE4
 * address:  0x021DABCC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_021D9E30 0x021D9E30 thumb ov131
 *   func_021DBA14 0x021DBA14 thumb ov131
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021DBA54 0x021DBA54 thumb ov131
 *   func_021DB468 0x021DB468 thumb ov131
 *   func_021DB508 0x021DB508 thumb ov131
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_02035C08 0x02035C08 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_02017E88 0x02017E88 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_020362DC 0x020362DC arm
 *   func_021DB614 0x021DB614 thumb ov131
 *   func_0202F72C 0x0202F72C thumb
 *   func_021DB688 0x021DB688 thumb ov131
 *   func_021DB3F0 0x021DB3F0 thumb ov131
 */
#include "../../matched/include/Obj00026.h"
#include "../../matched/include/Obj00132.h"
#include "../../matched/include/Obj23165.h"
#include "../../matched/include/Obj23166.h"

struct Obj;
struct Actor;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

struct Vec2 { s16 x,y; };

struct Point { s16 x,y; };

extern void func_021D5A9C(char *,int);
extern void func_021DBA78(u8 *,int);
extern void func_021D9E30(void *a, int b);
extern void func_021DBA14(u8 *,u8 *);
extern void *func_021D6064(u8 *);
extern void func_021DBA54(unsigned char *p, unsigned short *o);
extern void func_021DB468(u8 *,u8 *,u8,int);
extern void func_021DB508(u8 *,u8 *,u32,u32);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern int func_02035C08(const void *p);
extern int func_02035BA4(const void *p);
extern u32 func_02017E88(void *,u32,u32);
extern void func_020061E4(u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B9A0(struct Actor *);
extern u32 func_020362DC(void);
extern void func_021DB614(void *a, u8 *b, int c);
extern u32 func_0202F72C(void *,u16,u16);
extern void func_021DB688(u8 *,u8 *,int);
extern void func_021DB3F0(u8 *,u8 *);
void func_021DABCC(u8 *a,u8 *b);
int func_021DAEE4(u8 *a,u8 *p);

/*
 * lever: initialized bounded descriptor list and explicit controller arms;
 *   unsigned distance wrap preserves the original signed tests at INT_MIN.
 * output: BA14 writes all four bytes for each index0..4; terminal record
 *   first byte255 stops ADC before any remaining terminal bytes are read.
 *   Both C08->BBC and BA4->B58 return -1 or0..4 for this list; predicates
 *   do not write it. BA54 writes both halfwords before their consumers.
 * arithmetic: admitted index0..4 after -1 rejection keeps index+54 and
 *   index*24 representable; byte record selectors retain0..255, *24<=6120.
 *   Full word distance uses u32 subtraction/negation modulo2^32, with
 *   original signed tests; INT_MIN retains its wrapped negative result.
 * interfaces: observed C38/C60 scalar returns retained despite legacy
 *   own void wrappers; every original call argument and independent poll
 *   remains. No owner C, defaults, extra bound, volatile or signed overflow.
 */
void func_021DABCC(u8 *a,u8 *b)
{
    u8 i;
    int index;
    u32 distance;
    u8 touch[6][4];
    struct Vec2 point2;
    struct Vec2 point1;
    if (((struct Obj00132 *)a)->f24==7 && ((struct Obj00132 *)a)->f44==0) {
        func_021D5A9C((char *)a,1);
        func_0204B878(*(struct Obj * *)&((struct Obj00132 *)a)->f194,9);
        func_021DBA78(b+176+b[41]*24,0);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f98,0);
        func_021D9E30(a,(int)b);
        if (((struct Obj00026 *)b)->f14==1) {
            func_021DBA78(b+176+b[42]*24,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
            ((struct Obj00026 *)b)->f14=0;
            b[42]=5;
        }
        a[28]=1;
        func_020061E4(1361);
        return;
    }
    for (i=0;i<5;i++) func_021DBA14(b+176+i*24,touch[i]);
    touch[5][0]=255;
    if (func_02035C60()==1) {
        index=func_02035C08(touch[0]);
        if (index==-1) goto out;
        if (func_02017E88(func_021D6064(a),index+54,0)==0) goto out;
        if (((struct Obj00132 *)a)->f44==1) func_021D5A9C((char *)a,0);
        if ((*(u8 **)(a+8))[13]!=6) {
            ((struct Obj00026 *)b)->f1C=1;
            if (((struct Obj00026 *)b)->f14!=1) {
                b[42]=index;
                func_021DBA54(b+176+index*24,(short unsigned int *)((u8 *)&point1));
                func_0204B404(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,&point1,0);
                func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,1);
                if (index==0) func_0204B878(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,3);
                else if (index==3) func_0204B878(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,4);
                else func_0204B878(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,2);
            }
            ((struct Obj00026 *)b)->f2C=((struct Obj00132 *)a)->f28;
            ((struct Obj00026 *)b)->f30=((struct Obj00132 *)a)->f2C;
            func_021DBA54(b+176+index*24,(short unsigned int *)((u8 *)&point2));
            func_0204B404(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,&point2,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,1);
            func_0204B9A0(*(struct Actor * *)&((struct Obj00026 *)b)->f9C);
        }
        a[28]=1;
        func_021DB468(a,b,index,1);
        func_020061E4(1356);
        return;
    }
    if (func_02035C38()==1) {
        if (((struct Obj00026 *)b)->f1C!=1) goto out;
        index=func_02035BA4(touch[0]);
        if (((struct Obj00026 *)b)->f14==0) {
            if (index==-1) {
                ((struct Obj00026 *)b)->f1C=0;
                func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,0);
                func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
            } else {
                distance=((struct Obj00026 *)b)->f30-((struct Obj00132 *)a)->f2C;
                if ((int)distance<0) distance=0U-distance;
                if ((int)distance>8) {
                    func_021DBA78(b+176+b[42]*24,2);
                    ((struct Obj00026 *)b)->f14=1;
                    func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,0);
                }
            }
        }
        if (((struct Obj00026 *)b)->f14==1) {
            if (index!=-1) {
                if (func_02017E88(func_021D6064(a),index+54,0)==0) goto out;
                func_021DB468(a,b,index,0);
                return;
            }
            func_021DBA78(b+176+b[42]*24,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
            ((struct Obj00026 *)b)->f14=0;
            ((struct Obj00026 *)b)->f1C=0;
            func_021DB468(a,b,b[41],0);
            b[42]=5;
            return;
        }
    } else {
        if (((struct Obj00026 *)b)->f1C==1) {
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
            if (((struct Obj00026 *)b)->f14==1) {
                if (b[42]!=b[41]) {
                    func_021DB508(a,b,b[42],b[41]);
                    func_020061E4(1357);
                    return;
                }
                ((struct Obj00026 *)b)->f14=0;
                func_021DB468(a,b,b[41],0);
            }
        }
    }
out:
    return;
}

int func_021DAEE4(u8 *a,u8 *p)
{
    struct Point pt;
    u32 r;
    u8 t;
    if(a[0x1c]==1 && func_020362DC()!=0) {
        a[0x1c]=0;
        if(((struct Obj00026 *)p)->f18==0) {
            p[0x2a]=5;
            func_021DB468(a,p,p[0x29],0);
        }
    }
    if(func_020362DC()==2) {
        if(((struct Obj00026 *)p)->f18==0) {
            a[0x1c]=0;
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[0x12]=1;
            ((struct Obj00132 *)a)->f50=2;
            func_0204B878(((struct Obj00132 *)a)->f194,9);
            ((struct Obj00132 *)a)->f1A0=((struct Obj00132 *)a)->f194;
            func_020061E4(0x551);
            return 1;
        } else {
            a[0x1c]=0;
            func_021DBA78(p+0xb0+p[0x2a]*0x18,0);
            func_021DB468(a,p,p[0x29],0);
            func_0204B3DC(((struct Obj00026 *)p)->f9C,0);
            p[0x29]=p[0x2a];
            p[0x2a]=5;
            ((struct Obj00026 *)p)->f18=0;
            func_021DB468(a,p,p[0x29],0);
            func_0204B878(((struct Obj00132 *)a)->f194,9);
            func_021DB614(a,p,0);
            func_020061E4(0x551);
        }
    } else if(((struct Obj00026 *)p)->f18!=0) {
        if(func_020362DC()==1) {
            a[0x1c]=0;
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[0x11]=p[0x2a];
            (*(u8 **)(a+8))[0x12]=0;
            ((struct Obj00026 *)p)->f20=1;
            ((struct Obj00026 *)p)->f24=1;
            *(int *)&((struct Obj00132 *)a)->f1A0=0;
            func_020061E4(0x54c);
        }
    } else if(func_020362DC()==1) {
        a[0x1c]=0;
        if(p[0x29]<4) {
            r=func_0202F72C(((struct Obj23165 *)((*(u8 * *)&((struct Obj00132 *)a)->f8)))->f8,func_02017E88(func_021D6064(a),*(volatile u8 *)&((struct Obj00026 *)p)->f29+0x36,0),((struct Obj00132 *)a)->f0);
            if(r==0 || ((struct Obj00132 *)a)->f14==1) {
                if(((struct Obj23166 *)((*(u8 * *)&((struct Obj00132 *)a)->f8)))->f14==0) {
                    ((struct Obj00132 *)a)->f54=1;
                    (*(u8 **)(a+8))[0x12]=0;
                    (*(u8 **)(a+8))[0x11]=p[0x29];
                    ((struct Obj00026 *)p)->f20=1;
                    *(int *)&((struct Obj00132 *)a)->f1A0=0;
                } else {
                    ((struct Obj00026 *)p)->f18=1;
                    t=p[0x29];
                    p[0x2a]=t;
                    func_021DBA78(p+0xb0+t*0x18,2);
                    p[0x29]=4;
                    func_021DB468(a,p,p[0x29],0);
                    func_021DBA54(p+0xb0+p[0x2a]*0x18,(short unsigned int *)(&pt));
                    func_0204B404(((struct Obj00026 *)p)->f9C,(const struct Vec2 *)(&pt),0);
                    func_0204B3DC(((struct Obj00026 *)p)->f9C,1);
                    func_0204B9A0(((struct Obj00026 *)p)->f9C);
                    func_021DB614(a,p,1);
                }
            } else {
                func_021DB688(a,p,r);
                goto done;
            }
        } else {
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[0x12]=1;
            ((struct Obj00026 *)p)->f20=1;
            *(int *)&((struct Obj00132 *)a)->f1A0=0;
        }
        func_020061E4(0x54c);
done:
        return 1;
    } else {
        if(func_020362DC()==0x40 || func_020362DC()==0x80) {
            func_021DB3F0(a,p);
            return 1;
        }
    }
    return 0;
}
