/*
 * function: func_021DA318
 * address: 0x021DA318
 * packet: pkt_ov119_021DA318
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: keep=1 precedes choice=keep-2; a literal -1 initialized before
 * keep gave 14 entry-initialization bytes wrong with all later bytes equal.
 * initialization: 02035D20 writes both coordinates before return 1;
 * 021D9EBC's successful hit writes slot/column through 021E51A4.
 * return evidence: 02035C38/60 leave 020357A0/C0's u32 result in r0,
 * consumed here despite the legacy void forwarder declarations.
 * symbols:
 *   func_02027A20 0x02027A20 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020355D8 0x020355D8 arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_020355C4 0x020355C4 arm
 *   func_02027A08 0x02027A08 thumb
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_02035D20 0x02035D20 arm
 *   func_021D9EBC 0x021D9EBC thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021E2484 0x021E2484 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA158 0x021DA158 thumb ov119
 *   func_021D8C0C 0x021D8C0C thumb ov119
 *   func_02035C38 0x02035C38 arm
 *   func_021D8B54 0x021D8B54 thumb ov119
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_021DBD70 0x021DBD70 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D9548 0x021D9548 thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_021DA0CC 0x021DA0CC thumb ov119
 *   func_021DD0CC 0x021DD0CC thumb ov119
 *   func_021DA110 0x021DA110 thumb ov119
 *   func_021D9E54 0x021D9E54 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021DD2A8 0x021DD2A8 thumb ov119
 *   func_021DA27C 0x021DA27C thumb ov119
 *   func_021DA1DC 0x021DA1DC thumb ov119
 *   func_021DA2F4 0x021DA2F4 thumb ov119
 *   func_021DBB6C 0x021DBB6C thumb ov119
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021E5EF8 0x021E5EF8 thumb ov119
 *   func_021E4174 0x021E4174 thumb ov119
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj04475.h"
typedef unsigned int u32;
typedef unsigned char u8;
struct TaskMenu;
struct S;
struct Obj;
extern unsigned func_02027A20(char *p);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8),func_021D8C84(void *),func_021B63D0(struct S *);
extern int func_021B6470(u8 *),func_021B6448(u8 *);
extern u32 func_02027A08(struct TaskMenu *,u32),func_02035D20(u32 *,u32 *),func_020279E8(struct TaskMenu *);
extern u8 func_02027A04(const u8 *);
extern int func_021D9EBC(char *,int *,int *,int *,int *);
extern void func_020061E4(u32),func_021E2484(char *,int),func_021D8E84(void *,int),func_021D8C0C(void *),func_021D8B54(void *);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern int func_021DBD70(char *,int,int);
extern int func_021D8AA8(void *);
extern int func_021D9548(char *,int,int);
extern int func_021DD0CC(char *,int);
extern int func_021DD2A8(char *);
extern void func_021DF7AC(void *,int);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021DBB6C(char *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_021E5EF8(void *);
extern void func_021E4174(char *p);
extern void func_021E12F8(char *p);
extern void func_02041B6C(u32);
extern void func_021DA158(char *p);
extern void func_021DA0CC(char *p);
extern void func_021DA110(char *p);
extern void func_021D9E54(char *p);
extern void func_021DA27C(char *p);
extern void func_021DA1DC(char *p);
extern void func_021DA2F4(void *);
#define I(o) (*(int *)(p+(o)))
#define P(o) (*(void **)(p+(o)))
void func_021DA318(char *p)
{
    u32 x,y;
    int slot,column;
    int changed=0;
    int keep=1;
    int choice=keep-2;
    int active=0;
    int n;
    if(!func_02027A20(P(0x64c))) {
        n=func_02035C60();
        if(n) func_020355D8(keep);
        if(n) func_021D8C84(p);
        func_021B63D0(P(0x9c0));
        if(func_021B6470(P(0x9c0))==9 && func_020355C4()) func_02027A08(P(0x64c),0);
        if(func_021B6448(P(0x9c0))==9) {
            changed=1;
            ((struct Obj04475 *)p)->f10A0=1U-((struct Obj04475 *)p)->f10A0;
        }
        if(func_02035D20(&x,&y)==1) {
            func_020355D8(1);
            func_02027A08(P(0x64c),0);
            if(func_021D9EBC(p,(int *)(p+0xf98),(int *)(p+0xf94),&slot,&column)) {
                I(0xf78)=column;
                I(0xf74)=slot;
                ((struct Obj04475 *)p)->fF54=x;
                ((struct Obj04475 *)p)->fF58=y;
                func_020061E4(0x548);
                changed=1;
            } else if(y>=16 && y<144) active=1;
        }
        if(changed) {
            func_021E2484(p,1);
            func_021D8E84(p,(int)func_021DA158);
            return;
        }
        func_021D8C0C(p);
        if(!active && !func_02035C38() && I(0xf34)) {
            if(I(0xf60) && I(0xf5c)) {
                func_020061E4(0x72a);
                choice=0;
                active=1;
            } else func_021D8C84(p);
        }
        func_021D8B54(p);
        func_021D8C0C(p);
    }
    if(func_020279E8(P(0x64c))) {
        choice=func_02027A04(P(0x64c));
        active=1;
    }
    if(active) {
        if(choice==0) {
            n=(int)func_021D8DD0((void *)I(0x828),I(0xf98),I(0xf94),p);
            if(func_021DBD70(p,I(0xf98),I(0xf94)) && func_021D8AA8(p)) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021DA1DC);
            } else if(func_021D9548(p,I(0xf98),I(0xf94))) {
                func_021DF7AC(p,1);
                func_021D8E84(p,(int)func_021DA0CC);
            } else if(func_021DD0CC(p,n)) {
                func_021D8E84(p,(int)func_021DA110);
                func_021DF7AC(p,1);
            } else if(!func_021D8AA8(p)) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021D9E54);
                func_021B6558((unsigned char *)I(0x9c0),7,0);
                func_021B6558((unsigned char *)I(0x9c0),8,0);
                func_021B6558((unsigned char *)I(0x9c0),9,0);
                keep=0;
            } else if(func_021DD2A8(p) && !func_020355C4()) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021DA27C);
                func_021B6558((unsigned char *)I(0x9c0),7,0);
                func_021B6558((unsigned char *)I(0x9c0),8,0);
                func_021B6558((unsigned char *)I(0x9c0),9,0);
                keep=0;
            } else {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021DA1DC);
            }
        } else {
            func_021DF7AC(p,1);
            func_021D8E84(p,(int)func_021DA2F4);
        }
        I(0xf98)=-1;
        I(0xf94)=-1;
        if(keep) {
            func_021DBB6C(p);
            func_0204B3DC(P(0xf04),1);
        }
        func_021E5EF8(p+0x950);
        func_021E5EF8(p+0x964);
        func_021E5EF8(p+0x978);
        func_021E2484(p,1);
        func_02041B6C(6);
        func_021E4174(p);
        func_021E12F8(p);
        P(0x64c)=0;
    }
    I(0xf34)=func_02035C38();
}
