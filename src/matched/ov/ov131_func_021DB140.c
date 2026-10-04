/*
 * function: func_021DB140
 * address: 0x021DB140
 * packet: pkt_ov131_021DB140
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: callee func_0202F72C filed as arm9 witness (pkt_0202F72C).
 * interface: C08 returns -1 or 0..4 for this five-record list (full
 *   C08/BBC/ADC bodies and nonwriting A70/AA4 predicates, retained evidence).
 *   BA14 writes every four-byte record; the sixth first byte is the sentinel.
 *   BA54 stores both output halfwords before returning. Only sentinel byte
 *   touch[5][0] is read; no other bytes of its partial record are consumed.
 * arithmetic: loop i is initialized zero and guarded <5; selected index
 *   admitted after -1 rejection is 0..4, so index+54 and index*24 are safe.
 *   Secondary record selector is an ldrb, 0..255, product <=6120. No menu
 *   domain, default output value, volatile or narrowed full-word result.
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_021DB468 0x021DB468 thumb ov131
 *   func_021D9EE8 0x021D9EE8 thumb ov131
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DB614 0x021DB614 thumb ov131
 *   func_021DBA14 0x021DBA14 thumb ov131
 *   func_02035C08 0x02035C08 arm
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_0202F72C 0x0202F72C thumb
 *   func_021DBA54 0x021DBA54 thumb ov131
 *   func_0204B404 0x0204B404 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_021DB688 0x021DB688 thumb ov131
 */
#include "../include/Obj00026.h"
#include "../include/Obj00132.h"
#include "../include/Obj23167.h"
#include "../include/Obj23168.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32);
extern void func_021DBA78(u8 *,int);
extern void func_021DB468(u8 *,u8 *,u8,int);
extern void func_021D9EE8(u8 *,u8 *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021DB614(void *,u8 *,int);
extern void func_021DBA14(u8 *,u8 *);
extern int func_02035C08(u8 *);
extern void *func_021D6064(u8 *);
extern int func_02017E88(void *,int,int);
extern u32 func_0202F72C(void *a, u16 b, u16 c);
extern void func_021DBA54(u8 *,u8 *);
extern void func_0204B404(void *,u8 *,int);
extern void func_0204B9A0(struct Actor *);
extern void func_021DB688(u8 *,u8 *,int);

void func_021DB140(u8 *a,u8 *b)
{
    u8 i;
    int index,result;
    u16 point[2];
    u8 touch[6][4];
    if (((struct Obj00132 *)a)->f24==7) {
        if (((struct Obj00026 *)b)->f18==0) {
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[18]=1;
            ((struct Obj00132 *)a)->f50=2;
            func_0204B878(((struct Obj00132 *)a)->f194,9);
            ((struct Obj00132 *)a)->f1A0=((struct Obj00132 *)a)->f194;
            func_020061E4(1361);
            return;
        }
        a[28]=1;
        func_021DBA78(b+176+b[42]*24,0);
        func_021DB468(a,b,b[41],0);
        func_0204B3DC(((struct Obj00026 *)b)->f9C,0);
        b[42]=5;
        ((struct Obj00026 *)b)->f18=0;
        if (b[43]==5) {
            func_021DB468(a,b,4,0);
            func_021D9EE8(a,b);
        } else {
            b[41]=255;
            func_021DB468(a,b,255,0);
        }
        func_021DB614(a,b,0);
        func_020061E4(1361);
        return;
    }
    for (i=0;i<5;i++) func_021DBA14(b+176+i*24,touch[i]);
    touch[5][0]=255;
    index=func_02035C08(touch[0]);
    if (index==-1) return;
    if (((struct Obj00026 *)b)->f18==0) {
        if (index<4) {
            if (func_02017E88(func_021D6064(a),index+54,0)==0) return;
            result=func_0202F72C(((struct Obj23167 *)(*(u8 * *)&((struct Obj00132 *)a)->f8))->f8,func_02017E88(func_021D6064(a),index+54,0),((struct Obj00132 *)a)->f0);
            if (result==0 || ((struct Obj00132 *)a)->f14==1) {
                if (((struct Obj23168 *)(*(u8 * *)&((struct Obj00132 *)a)->f8))->f14==0) {
                    ((struct Obj00132 *)a)->f54=1;
                    (*(u8 **)(a+8))[18]=0;
                    (*(u8 **)(a+8))[17]=index;
                    ((struct Obj00026 *)b)->f20=1;
                    *(int *)&((struct Obj00132 *)a)->f1A0=0;
                    func_020061E4(1356);
                    func_021DB468(a,b,index,0);
                    func_021DBA78(b+176+index*24,2);
                    return;
                }
                a[28]=1;
                ((struct Obj00026 *)b)->f18=1;
                func_021DB468(a,b,index,0);
                b[42]=index;
                func_021DBA78(b+176+index*24,2);
                b[41]=4;
                func_021DB468(a,b,b[41],0);
                func_021DBA54(b+176+b[42]*24,(u8 *)point);
                func_0204B404(((struct Obj00026 *)b)->f9C,(u8 *)point,0);
                func_0204B3DC(((struct Obj00026 *)b)->f9C,1);
                func_0204B9A0(*(struct Actor * *)&((struct Obj00026 *)b)->f9C);
                func_021DB614(a,b,1);
                func_020061E4(1356);
                return;
            }
            func_021DB468(a,b,index,0);
            b[42]=index;
            func_021DBA78(b+176+index*24,2);
            func_021DB688(a,b,result);
            return;
        }
        func_021DB468(a,b,index,0);
        a[28]=1;
        ((struct Obj00132 *)a)->f54=1;
        (*(u8 **)(a+8))[18]=1;
        ((struct Obj00026 *)b)->f20=1;
        *(int *)&((struct Obj00132 *)a)->f1A0=0;
        func_020061E4(1356);
        return;
    }
    if (index==4) {
        a[28]=1;
        ((struct Obj00132 *)a)->f54=1;
        (*(u8 **)(a+8))[17]=b[42];
        (*(u8 **)(a+8))[18]=0;
        ((struct Obj00026 *)b)->f20=1;
        ((struct Obj00026 *)b)->f24=1;
        *(int *)&((struct Obj00132 *)a)->f1A0=0;
        func_020061E4(1356);
    }
}
