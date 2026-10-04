/*
 * function: func_021C0F14
 * address: 0x021C0F14
 * packet: pkt_ov110_021C0F14
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Byte +99 is a one-bit field; selection bytes retain 255 and the signed touch result retains -1.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021C0C50 0x021C0C50 thumb ov110
 *   func_021C0D34 0x021C0D34 thumb ov110
 *   func_021C0EB0 0x021C0EB0 thumb ov110
 *   func_021C0DE4 0x021C0DE4 thumb ov110
 *   func_021C12F8 0x021C12F8 thumb ov110
 */
#include "../include/Obj00217.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 lo:1; u8 hi:7; } Flags;
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020061E4(u32);
extern void func_021C0C50(u8 *);
extern void func_021C0D34(char *,int);
extern int func_021C0EB0(char *);
extern int func_021C0DE4(char *);
extern int func_021C12F8(void);
int func_021C0F14(u8 *p)
{
    int result=0;
    int proceed=1;
    int active;
    int hit;
    if(!((Flags *)(p+0x99))->lo) {
        active=0;
        if(func_020362DC()&~2) active=1;
        if(active && p[0x95]==255) {
            if(p[0x94]==255) p[0x95]=p[0x96];
            else if(p[0x96]<=p[0x94] && p[0x94]<p[0x96]+3) p[0x95]=p[0x94];
            else p[0x95]=p[0x96];
            p[0x94]=255;
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
            func_020061E4(1352);
            func_021C0C50(p);
        }
    }
    if(proceed && p[0x95]!=255 && !((Flags *)(p+0x99))->lo) {
        if(func_020362DC()&1) {
            result=1;
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        } else if(func_0203633C()&64) {
            if(p[0x95]!=0) {
                p[0x94]=p[0x95];
                p[0x95]--;
                if(p[0x95]+1==p[0x96]) p[0x96]--;
                func_021C0D34((char *)p,0);
                func_021C0C50(p);
                func_020061E4(1352);
            }
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        } else if(func_0203633C()&128) {
            if(p[0x95]<p[0x98]-1) {
                p[0x94]=p[0x95];
                p[0x95]++;
                if(p[0x95]==p[0x96]+3) p[0x96]++;
                func_021C0D34((char *)p,0);
                func_021C0C50(p);
                func_020061E4(1352);
            }
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        }
    }
    if(proceed) {
        if(((Flags *)(p+0x99))->lo) {
            if(func_021C0EB0((char *)p)) {
                func_021C0C50(p);
                func_020061E4(1352);
            }
            ((struct Obj00217 *)p)->fA8=1;
        } else {
            hit=func_021C12F8();
            if(hit!=-1 && hit>p[0x98]-1) hit=-1;
            if(hit!=-1) {
                p[0x94]=p[0x95];
                p[0x95]=p[0x96]+hit;
                func_021C0C50(p);
                result=1;
                ((struct Obj00217 *)p)->fA8=1;
            } else {
                if(!((Flags *)(p+0x99))->lo) func_021C0DE4((char *)p);
                if(((Flags *)(p+0x99))->lo==1) {
                    if(func_021C0EB0((char *)p) || p[0x95]!=255) {
                        p[0x94]=p[0x95];
                        p[0x95]=255;
                        func_021C0C50(p);
                    }
                    func_020061E4(1352);
                    ((struct Obj00217 *)p)->fA8=1;
                }
            }
        }
    }
    return result;
}
