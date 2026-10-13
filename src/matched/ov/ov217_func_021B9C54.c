/*
 * function: func_021B9C54
 * address: 0x021B9C54
 * packet: pkt_ov217_021B9C54
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 02035C08 result is compared in the original; matched 02025EA4/02027E3C callers also declare its int return despite the forwarding body's void spelling.
 * Original passes p to 020362DC although the own matched body ignores entry r0.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_021C09B8 0x021C09B8 thumb ov217
 *   func_021BA4D4 0x021BA4D4 thumb ov217
 *   func_021BA1C0 0x021BA1C0 thumb ov217
 *   func_021BA1CC 0x021BA1CC thumb ov217
 *   func_021BA31C 0x021BA31C thumb ov217
 *   func_020061E4 0x020061E4 thumb
 *   func_021BA380 0x021BA380 thumb ov217
 *   func_021BA150 0x021BA150 thumb ov217
 *   func_021BA144 0x021BA144 thumb ov217
 *   func_021BA284 0x021BA284 thumb ov217
 *   func_021BA3E8 0x021BA3E8 thumb ov217
 *   func_021BA3B4 0x021BA3B4 thumb ov217
 *   func_021BA254 0x021BA254 thumb ov217
 *   func_021BA40C 0x021BA40C thumb ov217
 *   func_021BA1F8 0x021BA1F8 thumb ov217
 *   func_021BA228 0x021BA228 thumb ov217
 */
#include "../include/Obj00511.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern void * func_021C09B8(void *);
extern u32 func_021BA4D4(void *);
extern void func_021BA1C0(u8 *,u32);
extern void func_021BA1CC(void *,u32);
extern void func_021BA31C(u8 *);
extern void func_020061E4(u32);
extern void func_021BA380(void *,u32);
extern void func_021BA150(void *);
extern void func_021BA144(u8 *,u32);
extern void func_021BA284(int);
extern void func_021BA3E8(char *,int);
extern u32 func_021BA3B4(u32,u32);
extern u32 func_021BA254(u32,u32);
extern void func_021BA40C(u8 *,u32);
extern u32 func_021BA1F8(u32);
extern u32 func_021BA228(u32);
void func_021B9C54(char *p)
{
    u32 keys=func_020362DC();
    int choice=TOUCHPANEL_HitTrg(p+44);
    int other=TOUCHPANEL_HitTrg(func_021C09B8(((struct Obj00511 *)p)->f0));
    if(func_021BA4D4(p)!=0 || other==0) {
        func_021BA1C0((u8 *)p,1);func_021BA1CC(p,2);func_021BA31C((u8 *)p);func_020061E4(1361);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);return;
    }
    if(keys&2) {
        func_021BA1C0((u8 *)p,0);func_021BA1CC(p,2);func_021BA31C((u8 *)p);func_020061E4(1361);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);return;
    }
    if((keys&64)||(keys&128)||(keys&32)||(keys&16)||(keys&1)) {
        func_021BA284(*(int *)&((struct Obj00511 *)p)->f28);func_021BA3E8(p,0);func_021BA150(p);func_021BA144((u8 *)p,2);return;
    }
    if(choice==0) {
        if(func_021BA3B4((u32)p,0)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA1CC(p,0);func_021BA254((u32)p,0);func_021BA284(*(int *)&((struct Obj00511 *)p)->f28);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);func_020061E4(1356);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else func_020061E4(1367);
    } else if(choice==1) {
        if(func_021BA3B4((u32)p,1)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA1CC(p,1);func_021BA254((u32)p,1);func_021BA284(*(int *)&((struct Obj00511 *)p)->f28);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);func_020061E4(1356);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else func_020061E4(1367);
    }
}
