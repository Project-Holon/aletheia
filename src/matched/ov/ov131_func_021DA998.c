/*
 * function: func_021DA998
 * address: 0x021DA998
 * packet: pkt_ov131_021DA998
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
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
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021DB468 0x021DB468 thumb ov131
 *   func_021D9EE8 0x021D9EE8 thumb ov131
 *   func_021D9E30 0x021D9E30 thumb ov131
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_021DBA54 0x021DBA54 thumb ov131
 *   func_021DB508 0x021DB508 thumb ov131
 *   func_021DB3F0 0x021DB3F0 thumb ov131
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B9A0 0x0204B9A0 arm
 */
#include "../include/Obj00026.h"
#include "../include/Obj00132.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
struct Actor;
struct Vec2 { s16 x,y; };
extern u32 func_020362DC(void);
extern void func_021D5A9C(char *,int);
extern void func_021DB468(u8 *,u8 *,u8,int);
extern void func_021D9EE8(u8 *,u8 *);
extern void func_021D9E30(void *a, int b);
extern void func_021DBA78(u8 *,int);
extern void func_021DBA54(unsigned char *p, unsigned short *o);
extern void func_021DB508(u8 *,u8 *,u32,u32);
extern void func_021DB3F0(u8 *,u8 *);
extern void func_020061E4(u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B9A0(struct Actor *);
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
