/*
 * function: func_021D5DC4
 * address: 0x021D5DC4
 * packet: pkt_ov131_021D5DC4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: byte hardware writes 0400004C at 021D5DE6/021D5E1C
 *   and 0400104C at 021D5DF2/021D5E28; no ordinary object is volatile.
 * arithmetic: byte inc/dec is modulo 256; reloaded byte <=255 shifted
 *   by five fits int. Signed selector <3 admits negatives: address uses
 *   unsigned full-word multiply/add, preserving original wrap.
 * output: matched unit_02006CAC unconditionally stores the one-word out;
 *   the pointer payload passed as the eighth 02006984 argument is u32.
 * interfaces: callee own matched files; 7EAC keeps second caller payload
 *   visibly set at 021D5E9C despite its own body's unused parameter.
 * symbols:
 *   func_021D6D04 0x021D6D04 thumb ov131
 *   func_021D6A38 0x021D6A38 thumb ov131
 *   func_021D7EAC 0x021D7EAC thumb ov131
 *   func_021D9D94 0x021D9D94 thumb ov131
 *   func_021D90C0 0x021D90C0 thumb ov131
 *   func_021DA8BC 0x021DA8BC thumb ov131
 *   func_021D7CAC 0x021D7CAC thumb ov131
 *   func_021D9CD0 0x021D9CD0 thumb ov131
 *   func_021D8FAC 0x021D8FAC thumb ov131
 *   func_021DA7A4 0x021DA7A4 thumb ov131
 *   func_021D5BAC 0x021D5BAC thumb ov131
 *   func_021D62E4 0x021D62E4 thumb ov131
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_02006BB4 0x02006BB4 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02006CAC 0x02006CAC thumb
 *   func_02006984 0x02006984 thumb
 */
#include "../include/Obj00035.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021D6D04(void *,u8 *);
extern void func_021D6A38(u8 *p, u8 *q);
extern void func_021D7EAC(u8 *,void *);
extern void func_021D9D94(u8 *,u8 *);
extern void func_021D90C0(u8 *,u8 *);
extern void func_021DA8BC(u8 *,u8 *);
extern void func_021D7CAC(u8 *,u8 *);
extern void func_021D9CD0(u8 *,u8 *);
extern void func_021D8FAC(u8 *,u8 *);
extern void func_021DA7A4(u8 *,u8 *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021D5BAC(u8 *,int,u16 *);
extern int func_021D62E4(char *);
extern void func_02006BB4(u32);
extern int func_021D60A4(char *p);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02006CAC(void **);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
void func_021D5DC4(u8 *p)
{
    void *q;
    u32 a,b;
    void *out;
    if (((struct Obj00035 *)p)->f25C==1) {
        ++p[0x260];
        *(volatile u8 *)0x0400004c=p[0x260] | (p[0x260]<<5);
        *(volatile u8 *)0x0400104c=p[0x260] | (p[0x260]<<5);
        if (p[0x260]>=3) ((struct Obj00035 *)p)->f25C=2;
    }
    if (((struct Obj00035 *)p)->f25C==3) {
        --p[0x260];
        *(volatile u8 *)0x0400004c=p[0x260] | (p[0x260]<<5);
        *(volatile u8 *)0x0400104c=p[0x260] | (p[0x260]<<5);
        if (p[0x260]==0) {
            *(u32 *)&((struct Obj00035 *)p)->fC=0;
            ((struct Obj00035 *)p)->f25C=0;
            return;
        }
    }
    if (func_0201C6B4(((struct Obj00035 *)p)->f84)==1 &&
        (((struct Obj00035 *)p)->f25C==2 || ((struct Obj00035 *)p)->f25C==0)) {
        if (p[0x1a]!=((struct Obj00035 *)p)->f18) {
            if (p[0x1a]!=255) func_021D6D04(p,*(u8 * *)&((struct Obj00035 *)p)->f88);
            func_021D6A38(p,((struct Obj00035 *)p)->f88);
            p[0x1a]=((struct Obj00035 *)p)->f18;
        }
        switch (((struct Obj00035 *)p)->f5C) {
        case 0: func_021D7EAC(p,((struct Obj00035 *)p)->f8C); break;
        case 1: func_021D9D94(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        case 2: func_021D90C0(p,*(u8 * *)&((struct Obj00035 *)p)->f94); break;
        case 3: func_021DA8BC(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        }
        switch (((struct Obj00035 *)p)->f58) {
        case 0: func_021D7CAC(p,*(u8 * *)&((struct Obj00035 *)p)->f8C); break;
        case 1: func_021D9CD0(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        case 2: func_021D8FAC(p,*(u8 * *)&((struct Obj00035 *)p)->f94); break;
        case 3: func_021DA7A4(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        }
        if (((struct Obj00035 *)p)->f38==0 && (*(u8 **)(p+8))[13]!=2) {
            func_0204B3DC(((struct Obj00035 *)p)->f17C,1);
            if (((struct Obj00035 *)p)->f40==0) func_0204B3DC(((struct Obj00035 *)p)->f180,0);
            else func_0204B3DC(((struct Obj00035 *)p)->f180,1);
        } else {
            func_0204B3DC(((struct Obj00035 *)p)->f17C,0);
            func_0204B3DC(((struct Obj00035 *)p)->f180,0);
        }
        if (*(u32 *)&((struct Obj00035 *)p)->f48==0) {
            if (func_021D5BAC(p,0,0)==1) func_0204B878(((struct Obj00035 *)p)->f188,3);
            else func_0204B878(((struct Obj00035 *)p)->f188,17);
        }
        if (*(u32 *)&((struct Obj00035 *)p)->f4C==0) {
            if (func_021D5BAC(p,1,0)==1) func_0204B878(((struct Obj00035 *)p)->f18C,2);
            else func_0204B878(((struct Obj00035 *)p)->f18C,16);
        }
        if (*(int *)&((struct Obj00035 *)p)->f58<3 && func_021D62E4((char *)p)==1) {
            if (*(u32 *)((u32)p + (u32)*(int *)&((struct Obj00035 *)p)->f58*4 + 0x60)==1)
                func_0204B878(((struct Obj00035 *)p)->f184,7);
            else func_0204B878(((struct Obj00035 *)p)->f184,6);
        }
        if (((struct Obj00035 *)p)->f10==1) {
            ((struct Obj00035 *)p)->f10=0;
            func_02006BB4(0);
            if (((struct Obj00035 *)p)->f38==0) {
                q=(void *)func_021D60A4((char *)p);
                a=func_02017E1C(q,5,0);
                b=func_02017E1C(q,111,0);
                func_02006CAC(&out);
                func_02006984(a,b,64,0,0,0,0,(u32)&out);
            }
        }
        if (((struct Obj00035 *)p)->f25C==2) {
            ((struct Obj00035 *)p)->f25C=3;
            ((struct Obj00035 *)p)->f5C=((struct Obj00035 *)p)->f58;
            return;
        }
        *(u32 *)&((struct Obj00035 *)p)->fC=0;
        ((struct Obj00035 *)p)->f5C=((struct Obj00035 *)p)->f58;
    }
}
