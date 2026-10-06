/*
 * function: func_021D9740
 * address: 0x021D9740
 * packet: pkt_ov131_021D9740
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * proof: all scaled indices are ldrb or byte loop counters, hence
 * *24 <=6120 and *4 <=1020. p[40]+1 <=256 before the byte store;
 * signed %8 uses the reloaded byte 0..255, with no overflow or division
 * failure. No smaller range or successful callee result is assumed.
 * symbols:
 *   func_021DA958 0x021DA958 thumb ov131
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021D9E44 0x021D9E44 thumb ov131
 *   func_021D9EF0 0x021D9EF0 thumb ov131
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_021DB468 0x021DB468 thumb ov131
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DB7D0 0x021DB7D0 thumb ov131
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj00136.h"
#include "../include/Obj00502.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DA958(u8 *,u8 *);
struct Cfg;
struct Descriptor;
struct Obj;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_021D9E44(u8 *,u8 *);
extern void func_021D9EF0(u8 *,u8 *);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021DBA78(u8 *,int);
extern void func_021DB468(u8 *,u8 *,u8,int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021DB7D0(void *a0, void *a1, void *a2);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021D9740(u8 *a,u8 *p)
{
    u8 i;
    int ready;
    void *cell;
    if(((struct Obj00502 *)p)->f4==0 && ((struct Obj00502 *)p)->f8==0 && ((struct Obj00502 *)p)->f10==0 && ((struct Obj00502 *)p)->f20==0) func_021DA958(a,p);
    if(((struct Obj00502 *)p)->f4==1) {
        ready=1;
        for(i=0;i<=7;i++) {
            if(func_0201C6C4(((struct Obj00136 *)a)->f84,func_02045770(*(void **)((p+i*4)+0x5c)))==1) {
                ready=0;
                break;
            }
        }
        if(ready==1) {
            for(i=0;i<=7;i++) {
                cell=*(void **)((p+i*4)+0x5c);
                func_02045334(cell);
                func_02045374(cell);
                func_02041B6C(func_02045730(cell));
            }
            func_021D9E44(a,p);
            ((struct Obj00502 *)p)->f4=0;
        }
    }
    if(((struct Obj00502 *)p)->f8==1) {
        ready=1;
        for(i=8;i<=11;i++) {
            if(func_0201C6C4(((struct Obj00136 *)a)->f84,func_02045770(*(void **)((p+i*4)+0x5c)))==1) {
                ready=0;
                break;
            }
        }
        if(ready==1) {
            for(i=8;i<=11;i++) {
                cell=*(void **)((p+i*4)+0x5c);
                func_02045334(cell);
                func_02045374(cell);
                func_02041B6C(func_02045730(cell));
            }
            func_021D9EF0(a,p);
            ((struct Obj00502 *)p)->f8=0;
        }
    }
    if(((struct Obj00502 *)p)->fC==1) {
        if(func_0201C6C4(((struct Obj00136 *)a)->f84,func_02045770(((struct Obj00502 *)p)->f8C))==0) {
            cell=((struct Obj00502 *)p)->f8C;
            func_02045334(cell);
            func_02045374(cell);
            func_02041B6C(func_02045730(cell));
            ((struct Obj00502 *)p)->fC=0;
        }
    }
    if(((struct Obj00502 *)p)->f10==1 && func_0201C6B4(((struct Obj00136 *)a)->f84)==1) {
        ((struct Obj00502 *)p)->f14=0;
        func_021DBA78((p+0xb0)+p[0x2a]*24,0);
        p[0x2a]=5;
        func_021DB468(a,p,p[0x29],0);
        func_0204B3DC(((struct Obj00502 *)p)->f9C,0);
        ((struct Obj00502 *)p)->f10=0;
    }
    for(i=0;i<5;i++) func_021DB7D0(a,p,(p+0xb0)+i*24);
    if(((struct Obj00502 *)p)->f20==1) {
        p[40]++;
        if((int)p[40]%8<4) {
            if(((struct Obj00502 *)p)->f24==1) func_0204B878(*(void **)((p+p[41]*24)+0xb8),15);
            else func_021DBA78((p+0xb0)+p[41]*24,0);
        } else {
            if(((struct Obj00502 *)p)->f24==1) func_0204B878(*(void **)((p+p[41]*24)+0xb8),16);
            else func_021DBA78((p+0xb0)+p[41]*24,1);
        }
        if(p[40]>16) ((struct Obj00136 *)a)->f50=2;
    }
}
