/*
 * file:     p_sta_oam_p28.c
 * unit:     yes
 * function: func_021DA7A4, func_021DA84C, func_021DA8BC, func_021DA958, func_021DA998
 * address:  0x021DA7A4
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
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021D9EF0 0x021D9EF0 thumb ov131
 *   func_021DB964 0x021DB964 thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021DB468 0x021DB468 thumb ov131
 *   func_020437AC 0x020437AC arm
 *   func_021DBC3C 0x021DBC3C thumb ov131
 *   func_021DB9E8 0x021DB9E8 thumb ov131
 *   func_020452E8 0x020452E8 arm
 *   func_021DB9FC 0x021DB9FC thumb ov131
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02041570 0x02041570 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DABCC 0x021DABCC thumb ov131
 *   func_021DAEE4 0x021DAEE4 thumb ov131
 *   func_021DB140 0x021DB140 thumb ov131
 *   func_02035C38 0x02035C38 arm
 *   func_020362DC 0x020362DC arm
 *   func_021D9EE8 0x021D9EE8 thumb ov131
 *   func_021D9E30 0x021D9E30 thumb ov131
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_021DBA54 0x021DBA54 thumb ov131
 *   func_021DB508 0x021DB508 thumb ov131
 *   func_021DB3F0 0x021DB3F0 thumb ov131
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0204B9A0 0x0204B9A0 arm
 */
#include "../../matched/include/Obj00136.h"
#include "../../matched/include/Obj00536.h"
#include "../../matched/include/Obj02190.h"
#include "../../matched/include/Obj10521.h"
#include "../../matched/include/Obj10522.h"
#include "../../matched/include/Obj00026.h"
#include "../../matched/include/Obj00132.h"

struct Obj;
struct Descriptor;
struct Obj020437AC;
struct Actor;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short s16;

struct Vec2 { s16 x,y; };

extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(unsigned);
extern void func_021D9EF0(u8 *,u8 *);
extern void func_021DB964(u8 *,void *,u8 *);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021D5A9C(char *p, int a);
extern void func_021DB468(u8 *,u8 *,u8,int);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_021DBC3C(u8 *p);
extern void func_021DB9E8(void *,void *,u8 *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021DB9FC(void *,void *,u8 *);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_020409B4(unsigned);
extern void func_02041570(int channel, u16 val);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021DABCC(u8 *,u8 *);
extern int func_021DAEE4(u8 *,u8 *);
extern void func_021DB140(u8 *,u8 *);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern void func_021D9EE8(u8 *,u8 *);
extern void func_021D9E30(void *a, int b);
extern void func_021DBA78(u8 *,int);
extern void func_021DBA54(unsigned char *p, unsigned short *o);
extern void func_021DB508(u8 *,u8 *,u32,u32);
extern void func_021DB3F0(u8 *,u8 *);
extern void func_020061E4(u32);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B9A0(struct Actor *);
void func_021DA7A4(u8 *a,u8 *b);
void func_021DA84C(u8 *a,u8 *b);
void func_021DA8BC(u8 *a,u8 *b);
void func_021DA958(u8 *a,u8 *b);
int func_021DA998(u8 *a,u8 *b);

/*
 * extent: two-byte zero alignment padding at 0x021DA84A.
 */
void func_021DA7A4(u8 *a,u8 *b) {
    u8 i;
    func_020410D0(2,0,0,32,24,(u32)(*(u8 * *)&((struct Obj00536 *)b)->f34+12),0,0,32,32);
    func_02041B6C(2);
    func_021D9EF0(a,b);
    for(i=0;i<b[43];i++) func_021DB964(a,b,b+176+i*24);
    func_0204B878(((struct Obj00136 *)a)->f17C,4);
    if(b[43]==5) b[41]=4;else b[41]=0;
    func_021D5A9C((char *)a,0);
    func_021DB468(a,b,b[41],0);
}

void func_021DA84C(u8 *a,u8 *b) {
    u8 i;
    if(b[43]==5) {
        func_020437AC(((struct Obj02190 *)b)->fA8);
        func_021DBC3C(((struct Obj02190 *)b)->fAC);
    }
    for(i=0;i<b[43];i++) func_021DB9E8(a,b,b+176+i*24);
    for(i=0;i<13;i++) func_020452E8(*(void **)(b+92+i*4));
    *(int *)&((struct Obj02190 *)b)->f0=0;
}

void func_021DA8BC(u8 *a,u8 *b) {
    u8 i;
    for(i=0;i<b[43];i++) func_021DB9FC(a,b,b+176+i*24);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    func_02041570(4,0);
    func_02041B6C(4);
    func_0204B3DC(((struct Obj10522 *)b)->f90,0);
    func_0204B3DC(((struct Obj10522 *)b)->f94,0);
    func_0204B3DC(((struct Obj10521 *)a)->f198,0);
    func_0204B3DC(((struct Obj10521 *)a)->f19C,0);
    func_0204B878(((struct Obj10521 *)a)->f17C,1);
}

void func_021DA958(u8 *a,u8 *b) {
    if ((*(u8 **)(a+8))[13] != 2) {
        if (func_021DA998(a,b)==0) func_021DABCC(a,b);
    } else {
        if (func_021DAEE4(a,b)==0) func_021DB140(a,b);
    }
    if (func_02035C38()==0) ((struct Obj00026 *)b)->f1C=0;
}

/*
 * lever: original shared return0 branch is goto out; selected byte local
 *   preserves the loaded value across its neighbouring selector store.
 * semantics: every key poll is independent; selector bytes retain their
 *   full0..255 domain, so promoted selector*24 is at most6120. No menu
 *   bound is assumed. BA54 unconditionally writes both point halfwords
 *   at BA5E/BA6A before4B404 reads them; no default or success assumption.
 * interfaces: own matched callees, else own-region matched callers.
 *   362DC own body returns a full-word pointer payload; this caller uses
 *   full r0 as a scalar comparison, retained as u32. No argument narrowed
 *   beyond original/callee width. All original call/store order retained.
 */
int func_021DA998(u8 *a,u8 *b)
{
    struct Vec2 point;
    if (((struct Obj00026 *)b)->f1C==1) return 0;
    if (((struct Obj00132 *)a)->f44==1) {
        if (func_020362DC()!=1) goto out;
            b[41]=0;
            a[28]=0;
            func_021D5A9C((char *)a,0);
            func_021DB468(a,b,b[41],0);
            func_021D9EE8(a,b);
            func_020061E4(1356);
            return 1;
    } else {
        if (func_020362DC()==2 && ((struct Obj00026 *)b)->f14==0) {
            func_021D5A9C((char *)a,1);
            func_0204B878(*(struct Obj * *)&((struct Obj00132 *)a)->f194,9);
            func_021DBA78(b+176+b[41]*24,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f98,0);
            func_021D9E30(a,(int)b);
            a[28]=0;
            func_020061E4(1361);
            return 1;
        }
        if (a[28]==1) {
            if (func_020362DC()==0) goto out;
                a[28]=0;
                b[42]=5;
                func_021DB468(a,b,b[41],0);
                func_020061E4(1352);
                return 1;
        } else {
            if (func_020362DC()==1) {
                if ((*(u8 **)(a+8))[13]==6) goto out;
                if (((struct Obj00026 *)b)->f14==0) {
                    u8 selected;
                    ((struct Obj00026 *)b)->f14=1;
                    selected=b[41];
                    b[42]=selected;
                    func_021DBA78(b+176+selected*24,2);
                    func_021DBA54(b+176+b[42]*24,(short unsigned int *)((u8 *)&point));
                    func_0204B404(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,&point,0);
                    func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,1);
                    func_0204B9A0(*(struct Actor * *)&((struct Obj00026 *)b)->f9C);
                    func_020061E4(1356);
                } else {
                    if (b[42]!=b[41]) {
                        func_021DB508(a,b,b[42],b[41]);
                        func_020061E4(1357);
                    } else {
                        ((struct Obj00026 *)b)->f14=0;
                        func_021DB468(a,b,b[41],0);
                        func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
                        func_020061E4(1356);
                    }
                }
                return 1;
            }
            if (func_020362DC()==2 && ((struct Obj00026 *)b)->f14==1) {
                func_021DBA78(b+176+b[42]*24,0);
                func_021DB468(a,b,b[41],0);
                func_0204B878(*(struct Obj * *)&((struct Obj00132 *)a)->f194,9);
                func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
                ((struct Obj00026 *)b)->f14=0;
                b[42]=5;
                func_020061E4(1361);
                return 1;
            }
            if (func_020362DC()==64 || func_020362DC()==128) {
                func_021DB3F0(a,b);
                return 1;
            }
        }
    }
out:
    return 0;
}
