/*
 * file:     wifilogin_disp_p07.c
 * unit:     yes
 * function: func_021D497C, func_021D4A98, func_021D4AB0
 * address:  0x021D497C
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0202EB4C 0x0202EB4C thumb
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5ED8 0x021D5ED8 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5B50 0x021D5B50 thumb ov115
 *   func_02009860 0x02009860 thumb
 *   func_020597C8 0x020597C8 arm
 *   func_02059760 0x02059760 arm
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021D42E0 0x021D42E0 thumb ov115
 *   func_021D46CC 0x021D46CC thumb ov115
 *   func_021D45D0 0x021D45D0 thumb ov115
 *   func_021D493C 0x021D493C thumb ov115
 *   func_021D460C 0x021D460C thumb ov115
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D5F7C  0x021D5F7C  thumb  ov115
 *   func_021D5C94  0x021D5C94  thumb  ov115
 *   func_0203CD98  0x0203CD98  arm
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203C968  0x0203C968  arm
 *   func_021D4B3C  0x021D4B3C  thumb  ov115
 */
#include "../../matched/include/Obj13850.h"
#include "../../matched/include/Obj02825.h"

#define P(k) (*(u8 **)(p+(k)))
struct DWCstAccUserData;
struct Sub020097BCObj;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_0202EB44(u8 *);
extern u32 func_0202EB4C(void);
extern void func_021D5D3C(u8 *p);
extern void func_021D5ED8(u8 *,u32);
extern void func_021D426C(u8 *,u32);
extern void func_021D5B50(void *,int);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int func_020597C8(struct DWCstAccUserData *userdata);
extern int func_02059760(struct DWCstAccUserData *userdata);
extern u32 func_0202EB0C(void);
extern void func_021D42E0(u8 *),func_021D46CC(u8 *),func_021D45D0(u8 *);
extern void func_021D493C(u8 *),func_021D460C(u8 *);
extern u32 func_020221A4(void);
extern int func_021D5C70(int);
extern void *func_021D5D5C(u8 *,int,int,int);
extern void func_021D5F7C(unsigned char *p);
extern void func_021D5C94(unsigned char *p);
extern int func_0203CD98(void);
extern u32 func_0200FBB0(void);
extern void func_0203CA04(void);
extern void func_0200FBA0(void);
extern void func_0203C968(void);
extern void func_021D4B3C(u8 *p);
void func_021D497C(u8 *p);
void func_021D4A98(u8 *p);
void func_021D4AB0(unsigned char *a);

/*
 * evidence: 0202EB44 leaves r0 live for this caller; entry p is forwarded.
 * 02009860 is bx lr; its unchanged entry pointer feeds both SDK readers.
 * callbacks: both zero-status arms use 42E0; mode2 and final else use 46CC;
 * missing profile uses 45D0, missing console uses 493C, mode1 uses 460C.
 */
void func_021D497C(u8 *p)
{
    if(func_0202EB44(p)==0) {
        func_021D5D3C(P(0x38));
        func_021D5ED8(P(0x38),39);
        *(int *)(P(0x40)+0x1c)=1;
        func_021D426C(p,(u32)func_021D42E0);
        return;
    }
    if(func_0202EB4C()==0) {
        func_021D5D3C(P(0x38));
        func_021D5ED8(P(0x38),34);
        *(int *)(P(0x40)+0x1c)=1;
        func_021D426C(p,(u32)func_021D42E0);
        return;
    }
    if(*(int *)(P(0x40)+0x14)==2) {
        func_021D5B50(P(0x38),17);
        func_021D426C(p,(u32)func_021D46CC);
        return;
    }
    if(func_020597C8((struct DWCstAccUserData *)func_02009860((struct Sub020097BCObj *)P(0x3c)))==0) {
        ((struct Obj13850 *)p)->f20=1;
        func_021D5D3C(P(0x38));
        if(func_0202EB0C()==0) func_021D5ED8(P(0x38),18);
        else func_021D5ED8(P(0x38),43);
        func_021D426C(p,(u32)func_021D45D0);
        return;
    }
    if(func_02059760((struct DWCstAccUserData *)func_02009860((struct Sub020097BCObj *)P(0x3c)))==0) {
        ((struct Obj13850 *)p)->f20=1;
        func_021D5D3C(P(0x38));
        if(func_0202EB0C()==0) func_021D5ED8(P(0x38),20);
        else func_021D5ED8(P(0x38),45);
        func_021D426C(p,(u32)func_021D493C);
        return;
    }
    if(*(int *)(P(0x40)+0x14)==1) {
        func_021D5D3C(P(0x38));
        func_021D5ED8(P(0x38),37);
        func_021D426C(p,(u32)func_021D460C);
    } else {
        func_021D5B50(P(0x38),17);
        func_021D426C(p,(u32)func_021D46CC);
    }
}

void func_021D4A98(u8 *p) { if(func_020221A4()) func_021D426C(p,0); }


void func_021D4AB0(unsigned char *a)
{
    int r;

    if (*(int *)(((struct Obj02825 *)a)->f40 + 0x20) != 0 &&
        *(int *)(((struct Obj02825 *)a)->f40 + 0x1c) == 0) {
        r = ((int (*)(int, int)) * (int *)(*(int *)(a + 0x40) + 0x20))(
            ((struct Obj02825 *)a)->f38, *(int *)(((struct Obj02825 *)a)->f40 + 0x24));
        if (r == 2)
            return;
        switch (r) {
        case 0:
            *(int *)(((struct Obj02825 *)a)->f40 + 0x1c) = 0;
            func_021D426C(a, (int)func_021D4B3C);
            break;
        case 1:
            *(int *)(((struct Obj02825 *)a)->f40 + 0x1c) = 1;
            func_021D5F7C((unsigned char *)(((struct Obj02825 *)a)->f38));
            func_021D5D3C((unsigned char *)(((struct Obj02825 *)a)->f38));
            func_021D5C94((unsigned char *)(((struct Obj02825 *)a)->f38));
            if (func_0203CD98() != 0)
                func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            func_021D5ED8((unsigned char *)(((struct Obj02825 *)a)->f38), 0x25);
            func_021D426C(a, (int)func_021D460C);
            break;
        }
    } else {
        func_021D426C(a, (int)func_021D4B3C);
    }
}
