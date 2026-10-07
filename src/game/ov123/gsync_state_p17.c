/*
 * file:     gsync_state_p17.c
 * unit:     yes
 * function: func_021D7F5C, func_021D7F9C, func_021D80B8, func_021D8130, func_021D8154, func_021D81B4, func_021D81E4, func_021D8210, func_021D8244, func_021D8270, func_021D8304, func_021D834C, func_021D83A4, func_021D83C8, func_021D840C, func_021D8448, func_021D8490, func_021D8520, func_021D8590, func_021D85C4, func_021D85F0, func_021D8624, func_021D8650, func_021D8790, func_021D87F8, func_021D885C, func_021D88A0, func_021D88C0, func_021D8958, func_021D8A38, func_021D8A7C
 * address:  0x021D7F5C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D6E70 0x021D6E70 thumb ov123
 *   func_021D6EBC 0x021D6EBC thumb ov123
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_021D7E58 0x021D7E58 thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D59E4 0x021D59E4 thumb ov123
 *   func_021D5A60 0x021D5A60 thumb ov123
 *   func_021D6EA4 0x021D6EA4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D746C 0x021D746C thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   d_021DAB78 0x021DAB78 data ov123 a1
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D57B8 0x021D57B8 thumb ov123
 *   func_021D5A7C 0x021D5A7C thumb ov123
 *   func_021D62E0 0x021D62E0 thumb ov123
 *   func_021D65F4 0x021D65F4 thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D706C 0x021D706C thumb ov123
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D5890 0x021D5890 thumb ov123
 *   func_020092E0 0x020092E0 thumb
 *   func_021D5960 0x021D5960 thumb ov123
 *   func_021D5AB0 0x021D5AB0 thumb ov123
 *   func_021D56FC 0x021D56FC thumb ov123
 *   func_0203CD98 0x0203CD98 arm
 *   func_020071D8 0x020071D8 thumb
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_021D6F04 0x021D6F04 thumb ov123
 *   func_020093C8 0x020093C8 thumb
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_0203F540 0x0203F540 arm
 */
#include "../../matched/include/Obj13991.h"
#include "../../matched/include/Obj00063.h"
#include "../../matched/include/Obj05368.h"
#include "../../matched/include/Obj22964.h"
#include "../../matched/include/Obj03795.h"
#include "../../matched/include/Obj22965.h"
#include "../../matched/include/Obj13992.h"
#include "../../matched/include/Obj22966.h"
#include "../../matched/include/Obj13993.h"
#include "../../matched/include/Obj03796.h"
#include "../../matched/include/Obj06466.h"
#include "../../matched/include/Obj03797.h"
#include "../../matched/include/Obj22967.h"
#include "../../matched/include/Obj10447.h"
#include "../../matched/include/Obj13994.h"
#include "../../matched/include/Obj06467.h"
#include "../../matched/include/Obj22968.h"
#include "../../matched/include/Obj10448.h"
#include "../../matched/include/Obj22969.h"
#include "../../matched/include/Obj13995.h"
#include "../../matched/include/Obj22970.h"
#include "../../matched/include/Obj13996.h"
#include "../../matched/include/Obj22971.h"
#include "../../matched/include/Obj22972.h"
#include "../../matched/include/Obj22973.h"
#include "../../matched/include/Obj22974.h"
#include "../../matched/include/Obj22975.h"
#include "../../matched/include/Obj08113.h"
#include "../../matched/include/Obj10450.h"
#include "../../matched/include/Obj22976.h"
#include "../../matched/include/Obj22977.h"
#include "../../matched/include/Obj22978.h"
#include "../../matched/include/Obj22979.h"
#include "../../matched/include/Obj22980.h"
#include "../../matched/include/Obj06468.h"
#include "../../matched/include/Obj13997.h"
#include "../../matched/include/Obj22981.h"

struct Sub02009448Obj;
struct TaskMenu;
struct Sub02009210Obj;
struct Sub0200852CObj;
struct Ctrl020071D8;
struct Sub02008AECSession;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

struct RtcDate { int year; u32 month; int day, week; };

extern struct Sub02009448Obj *func_02009448(void *sys);
extern int func_021D6E70(u8 *p);
extern int func_021D6EBC(u8 *p);
extern void func_021D66D0(u8 *,int);
extern int func_021D6E08(char *,int);
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern char *func_021B97F4(void *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082D44(const void *,void *,u32);
extern void func_021D7E58(u8 *p, void *h, u8 *q, int *r);
extern int func_021D5950(u8 *,int);
extern void func_021D59E4(char *);
extern void func_021D5A60(char *);
extern int func_021D6EA4(char *);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D746C(int a);
extern void func_021D6FF0(char *);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B9748(u8 *p);
extern int func_021D580C(char *);
extern void func_021D57B8(char *, int);
extern void func_021D5A7C(char *);
extern void func_021D62E0(u8 *, int);
extern void func_021D65F4(u8 *p);
extern void func_021D6650(u8 *p, int flag);
extern void func_021D62BC(u8 *, int, unsigned int);
extern void func_021D62B4(u8 *p, unsigned int i);
extern void func_020061E4(u32 a);
extern void func_021D706C(char *);
extern unsigned int func_020362DC(void);
extern int func_02035C60(void);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern void func_021D584C(char *);
extern void func_02027858(struct TaskMenu *m);
extern int func_021D5890(char *p, int mode);
extern u32 func_02009370(const struct Sub02009210Obj *obj);
extern void func_020092E0(struct Sub02009210Obj *obj, u8 value);
extern void func_021D5960(char *, int, int);
extern u8 *func_02012944(void *p);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern void func_021D5AB0(u8 *, int);
extern void func_021D56FC(char *, int);
extern int func_0203CD98(void);
extern int func_021B973C(char *p);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern void *func_020071D8(struct Ctrl020071D8 *ctrl, int *out);
extern void func_021D6F04(char *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern int func_02008BD0(const struct Sub02008AECSession *s);
extern u32 func_020093C8(const struct Sub02009210Obj *obj);
extern void func_0203F4E4(struct RtcDate *);
extern int func_0203F540(struct RtcDate *);
int func_021D7F5C(char *p);
void func_021D7F9C(char *p);
void func_021D80B8(char *p);
void func_021D8130(char *p);
void func_021D8154(char *p);
void func_021D81B4(char *p);
void func_021D81E4(char *p);
void func_021D8210(char *p);
void func_021D8244(char *p);
void func_021D8270(char *p);
void func_021D8304(char *p);
void func_021D834C(char *p);
void func_021D83A4(char *p);
void func_021D83C8(char *p);
void func_021D840C(char *p);
void func_021D8448(char *p);
void func_021D8490(char *p);
void func_021D8520(char *p);
void func_021D8590(char *p);
void func_021D85C4(char *p);
void func_021D85F0(char *p);
void func_021D8624(char *p);
void func_021D8650(char *p,int x,int *q);
void func_021D8790(char *p);
void func_021D87F8(char *p);
void func_021D885C(char *p);
void func_021D88A0(char *p);
void func_021D88C0(char *p);
void func_021D8958(char *p);
void func_021D8A38(char *p);
void func_021D8A7C(char *p);
extern const char d_021DAB78[];

int func_021D7F5C(char *p)
{
    int i, j;
    char *q;
    func_02009448(((struct Obj13991 *)p)->f28);
    q = *(char * *)&((struct Obj13991 *)p)->f20 + 0xc;
    for (i = 0; i < 20; i++) {
        for (j = i + 1; j < 20; j++) {
            if (*(u16 *)(q + i * 2 + 8) != 0 &&
                *(u16 *)(q + j * 2 + 8) == *(u16 *)(q + i * 2 + 8))
                return 0;
        }
    }
    return 1;
}

void func_021D7F9C(char *p)
{
    char *q, *data;
    void *v, *allocated;
    if (func_021D6E70((u8 *)p) && !func_021D6EBC((u8 *)p)) {
        if (((struct Obj00063 *)p)->f70<30) ++((struct Obj00063 *)p)->f70;
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=func_021B97F4(((struct Obj00063 *)p)->f10);
        v=func_02009448(((struct Obj00063 *)p)->f28);
        data=q+0x80;
        allocated=func_02030734(((struct Obj00063 *)p)->f0,0x11c,1,d_021DAB78,0x573);
        ((struct Obj00063 *)p)->f38=allocated;
        func_02082D44(data,allocated,0x11c);
        func_021D7E58((u8 *)p,v,(u8 *)data,(int *)q);
        return;
    } else {
        ++((struct Obj00063 *)p)->f74;
        if (((struct Obj00063 *)p)->f70<30) ++((struct Obj00063 *)p)->f70;
        if (((struct Obj00063 *)p)->f74==360) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,43);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==720) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,44);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==1080) {
            if (func_021D6EA4(p)) func_021D5A60(*(char * *)&((struct Obj00063 *)p)->f18);
            if (func_021D7F5C(p)) {
                func_021D6EE0((u8 *)p,(int)func_021D746C,0x58c);
            } else {
                ((struct Obj00063 *)p)->f80=9;
                func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x591);
            }
        }
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
    }
}

void func_021D80B8(char *p)
{
    if (func_021D6E70((unsigned char *)p) && !func_021D6EBC((unsigned char *)p)) {
        if (func_021B95D4(2, ((struct Obj05368 *)p)->f10) && !func_021B9748(((struct Obj05368 *)p)->f10)) {
            func_021D6EE0((u8 *)p, (int)func_021D7F9C, 0x59d);
            return;
        }
    } else {
        if (func_021D6EA4(p)) {
            ((struct Obj05368 *)p)->f74 = 0;
            func_021D5950((u8 *)(*(char * *)&((struct Obj05368 *)p)->f18), 42);
            func_021D59E4(*(char * *)&((struct Obj05368 *)p)->f18);
        } else {
            ((struct Obj05368 *)p)->f74 = 0x42e;
        }
        func_021D6EE0((u8 *)p, (int)func_021D7F9C, 0x5aa);
    }
}

void func_021D8130(char *p) { if(func_021D580C(*(char * *)&((struct Obj22964 *)p)->f18)) func_021D6EE0((u8 *)p,(int)func_021D80B8,0x5b3); }

void func_021D8154(char *p)
{
    func_021D57B8(*(char * *)&((struct Obj03795 *)p)->f18, 11);
    func_021D5A7C(*(char * *)&((struct Obj03795 *)p)->f18);
    func_021D62E0(*(u8 * *)&((struct Obj03795 *)p)->f14, 8);
    func_021D65F4((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14));
    func_021D6650((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 1);
    func_021D62BC(*(u8 * *)&((struct Obj03795 *)p)->f14, 6, 5);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 0);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 12);
    func_020061E4(0x657);
    func_021D6EE0((u8 *)p, (int)func_021D8130, 0x5c3);
}

void func_021D81B4(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22965 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            func_021D6EE0((u8 *)p, (int)func_021D706C, 0x5d0);
        }
    }
}

void func_021D81E4(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13992 *)p)->f18)) {
        func_021D57B8(*(char * *)&((struct Obj13992 *)p)->f18, 16);
        func_021D6EE0((u8 *)p, (int)func_021D81B4, 0x5de);
    }
}

void func_021D8210(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22966 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            func_021D6EE0((u8 *)p, (int)func_021D706C, 0x5e9);
        }
    }
}

void func_021D8244(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13993 *)p)->f18)) {
        func_021D57B8(*(char * *)&((struct Obj13993 *)p)->f18, 49);
        func_021D6EE0((u8 *)p, (int)func_021D8210, 0x5f6);
    }
}

void func_021D8270(char *p)
{
    if (((struct Obj03796 *)p)->f64 % 110 == 0) func_020061E4(0x659);
    (((struct Obj03796 *)p)->f64)++;
    if (func_020279E8(((struct Obj03796 *)p)->f1C)) {
        if (func_02027A04(((struct Obj03796 *)p)->f1C) == 0) {
            if (func_020076D0(((struct Obj03796 *)p)->f24, (int *)(p + 0x48), (int *)(p + 0x4c)) == 0)
                func_021D6EE0((u8 *)p, (int)func_021D8244, 0x60f);
            else
                func_021D6EE0((u8 *)p, (int)func_021D8154, 0x612);
        } else {
            func_021D6EE0((u8 *)p, (int)func_021D706C, 0x616);
        }
        func_021D584C(*(char * *)&((struct Obj03796 *)p)->f18);
        func_02027858(((struct Obj03796 *)p)->f1C);
        *(unsigned short *)0x04001050 = 0;
        ((struct Obj03796 *)p)->f1C = 0;
    }
}

void func_021D8304(char *p)
{
    if (((struct Obj06466 *)p)->f64 % 110 == 0) func_020061E4(0x659);
    (((struct Obj06466 *)p)->f64)++;
    if (func_021D580C(*(char * *)&((struct Obj06466 *)p)->f18)) {
        ((struct Obj06466 *)p)->f1C = (void *)func_021D5890(*(char * *)&((struct Obj06466 *)p)->f18, 0);
        func_021D6EE0((u8 *)p, (int)func_021D8270, 0x632);
    }
}

void func_021D834C(char *p)
{
    func_021D584C(*(char * *)&((struct Obj03797 *)p)->f18);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 0);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 12);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 6);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 8);
    if (func_02009370((const struct Sub02009210Obj *)func_02009448(((struct Obj03797 *)p)->f28)))
        func_021D57B8(*(char * *)&((struct Obj03797 *)p)->f18, 21);
    else
        func_021D57B8(*(char * *)&((struct Obj03797 *)p)->f18, 10);
    func_021D6EE0((u8 *)p, (int)func_021D8304, 0x64c);
}

void func_021D83A4(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22967 *)p)->f18)) {
        func_021D6EE0((u8 *)p, (int)func_021D834C, 0x68d);
    }
}

void func_021D83C8(char *p)
{
    if (func_020362DC() != 0 || func_02035C60() != 0) {
        func_021D5A60(*(char * *)&((struct Obj10447 *)p)->f18);
        func_020092E0((struct Sub02009210Obj *)func_02009448(((struct Obj10447 *)p)->f28), 1);
        p[0xaf] = 1;
        func_021D6EE0((u8 *)p, (int)func_021D8958, 0x6a2);
    }
}

void func_021D840C(char *p)
{
    if (func_020362DC() || func_02035C60()) {
        func_021D5950((u8 *)(*(char * *)&((struct Obj13994 *)p)->f18), 48);
        func_021D5960(*(char * *)&((struct Obj13994 *)p)->f18, 7, 14);
        func_021D6EE0((u8 *)p, (int)func_021D83C8, 0x6ab);
    }
}

void func_021D8448(char *p)
{
    func_021D5AB0(*(u8 * *)&((struct Obj06467 *)p)->f18, func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj22968 *)(*(char * *)&((struct Obj06467 *)p)->f20))->f4)));
    func_021D56FC(*(char * *)&((struct Obj06467 *)p)->f18, 1);
    func_021D5950((u8 *)(*(char * *)&((struct Obj06467 *)p)->f18), 47);
    func_021D5960(*(char * *)&((struct Obj06467 *)p)->f18, 7, 14);
    func_021D6EE0((u8 *)p, (int)func_021D840C, 0x6b7);
}

void func_021D8490(char *p)
{
    char *q;
    if (func_0203CD98()) {
        if (func_021D6E08(p, func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q = func_021B97F4(((struct Obj00063 *)p)->f10);
        if (((struct Obj10448 *)q)->f0 == 2) {
            func_021D6EE0((u8 *)p, (int)func_021D8958, 0x6d4);
            return;
        }
        if (((struct Obj10448 *)q)->f0 == 0) {
            func_021D584C(*(char * *)&((struct Obj00063 *)p)->f18);
            func_021D6EE0((u8 *)p, (int)func_021D8448, 0x6d8);
            return;
        }
        ((struct Obj00063 *)p)->f80 = ((struct Obj10448 *)q)->f0;
        func_021D6EE0((u8 *)p, (int)func_021D6FF0, 0x6dc);
        return;
    } else {
        func_021D6EE0((u8 *)p, (int)func_021D8958, 0x6e2);
    }
}

void func_021D8520(char *p)
{
    int x;
    unsigned int v;
    if (func_0203CD98()) {
        if (func_021B95D4(9,*(void **)(p+0x10))) {
            v=(unsigned int)func_020071D8(*(void **)(p+0x28),&x);
            func_021BE79C((void *)func_021B973C(*(void **)(p+0x10)),(void *)v,0x80000);
            if (!func_021B9748(*(void **)(p+0x10)))
                func_021D6EE0((u8 *)p,(int)func_021D8490,0x6fa);
        }
    } else {
        if (func_020362DC() || func_02035C60())
            func_021D6EE0((u8 *)p,(int)func_021D8490,0x700);
    }
}

void func_021D8590(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22969 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            func_021D6EE0((u8 *)p, (int)func_021D83A4, 0x727);
        }
    }
}

void func_021D85C4(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13995 *)p)->f18)) {
        func_021D57B8(*(char * *)&((struct Obj13995 *)p)->f18, 17);
        func_021D6EE0((u8 *)p, (int)func_021D8590, 0x739);
    }
}

void func_021D85F0(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22970 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            func_021D6EE0((u8 *)p, (int)func_021D706C, 0x746);
        }
    }
}

void func_021D8624(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13996 *)p)->f18)) {
        func_021D57B8(*(char * *)&((struct Obj13996 *)p)->f18, 20);
        func_021D6EE0((u8 *)p, (int)func_021D85F0, 0x758);
    }
}

void func_021D8650(char *p,int x,int *q)
{
    int state;
    switch (*q) {
    case 0:
        state=((struct Obj22971 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8;
        switch (state) {
        case 0:
            if (x==0) func_021D6EE0((u8 *)p,(int)func_021D83A4,0x774);
            else if (x==3) func_021D6EE0((u8 *)p,(int)func_021D83A4,0x777);
            else if (x==1) func_021D6EE0((u8 *)p,(int)func_021D85C4,0x77b);
            else if (x==2) func_021D6EE0((u8 *)p,(int)func_021D8624,0x77f);
            else if (x==4) func_021D6EE0((u8 *)p,(int)func_021D83A4,0x782);
            else func_021D6EE0((u8 *)p,(int)func_021D83A4,0x787);
            break;
        case 3:
            if (((struct Obj00063 *)p)->fAF==0) func_021D6EE0((u8 *)p,(int)func_021D8448,0x78c);
            else func_021D6EE0((u8 *)p,(int)func_021D8958,0x78f);
            break;
        }
        break;
    case 5:
        if (((struct Obj22972 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8==3)
            func_021D6EE0((u8 *)p,(int)func_021D8958,0x797);
        else {
            ((struct Obj00063 *)p)->f80=*q;
            func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x79b);
        }
        break;
    case 8:
        switch (((struct Obj22973 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8) {
        case 0: func_021D6EE0((u8 *)p,(int)func_021D83A4,0x7a2); break;
        case 3: func_021D6EE0((u8 *)p,(int)func_021D8520,0x7a6); break;
        }
        break;
    default:
        ((struct Obj00063 *)p)->f80=*q;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x7ac);
        break;
    }
}

void func_021D8790(char *p)
{
    char *q;
    if (func_0203CD98()) {
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=func_021B97F4(((struct Obj00063 *)p)->f10);
        func_02082D44(q+0x80,*(char * *)&((struct Obj00063 *)p)->f20+0xc,0x44);
        ((struct Obj22975 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f50=1;
        func_021D8650(p,((struct Obj22974 *)q)->f80,(int *)q);
    } else {
        func_021D6EE0((u8 *)p,(int)func_021D83A4,0x7d4);
    }
}

void func_021D87F8(char *p)
{
    func_021D57B8(*(char * *)&((struct Obj08113 *)p)->f18,13);
    func_021D5A7C(*(char * *)&((struct Obj08113 *)p)->f18);
    if (func_0203CD98()) {
        if (func_021B95D4(0,((struct Obj08113 *)p)->f10)) {
            if (!func_021B9748(((struct Obj08113 *)p)->f10))
                func_021D6EE0((unsigned char *)p,(int)func_021D8790,0x7ea);
        }
    } else {
        if (func_020362DC() || func_02035C60())
            func_021D6EE0((unsigned char *)p,(int)func_021D8790,0x7f1);
    }
}

void func_021D885C(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj10450 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            ((struct Obj22976 *)(*(char * *)&((struct Obj10450 *)p)->f20))->f1C8 = 1;
            func_021D584C(*(char * *)&((struct Obj10450 *)p)->f18);
            func_021D6EE0((u8 *)p, (int)func_021D6F04, 0x808);
        }
    }
}

void func_021D88A0(char *p)
{
    func_021D57B8(*(char * *)&((struct Obj22977 *)p)->f18, 19);
    func_021D6EE0((u8 *)p, (int)func_021D885C, 0x817);
}

void func_021D88C0(char *p)
{
    char *q;
    int state;
    if (func_0203CD98()) {
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=func_021B97F4(((struct Obj00063 *)p)->f10);
        state=((struct Obj22978 *)q)->f0;
        if (state==0 || state==8) {
            func_02082D44(q+0x80,*(char * *)&((struct Obj00063 *)p)->f20+0x1d8,0x80);
            ((struct Obj22979 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8=5;
            func_021D6EE0((u8 *)p,(int)func_021D6F04,0x837);
        } else {
            ((struct Obj00063 *)p)->f80=state;
            func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x842);
        }
    } else {
        ((struct Obj22980 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8=5;
        func_021D6EE0((u8 *)p,(int)func_021D6F04,0x849);
    }
}

void func_021D8958(char *p)
{
    struct RtcDate saved, current;
    u32 value;
    int day;
    if (func_02008BD0(func_02008B14(((struct Obj06468 *)p)->f28)) && ((struct Obj06468 *)p)->fAC) {
        func_021D6EE0((u8 *)p,(int)func_021D81E4,0x85c);
        return;
    }
    value=func_020093C8((const struct Sub02009210Obj *)func_02009448(((struct Obj06468 *)p)->f28));
    saved.year=(u8)(value>>24);
    saved.month=(u8)(value>>16);
    saved.day=(u8)(value>>8);
    saved.week=(u8)value;
    func_0203F4E4(&current);
    day=func_0203F540(&saved);
    if (day==func_0203F540(&current)) {
        func_021D6EE0((u8 *)p,(int)func_021D81E4,0x869);
        return;
    }
    if (func_0203CD98()) {
        if (func_021B95D4(1,((struct Obj06468 *)p)->f10) && !func_021B9748(((struct Obj06468 *)p)->f10))
            func_021D6EE0((u8 *)p,(int)func_021D88C0,0x871);
    } else {
        if (func_020362DC() || func_02035C60())
            func_021D6EE0((u8 *)p,(int)func_021D88C0,0x878);
    }
}

void func_021D8A38(char *p)
{
    if (((struct Obj13997 *)p)->f64 % 110 == 0) func_020061E4(0x659);
    ++((struct Obj13997 *)p)->f64;
    if (func_020362DC() || func_02035C60())
        func_021D6EE0((u8 *)p, (int)func_021D706C, 0x88e);
}

void func_021D8A7C(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22981 *)p)->f18)) {
        func_021D6EE0((u8 *)p, (int)func_021D8A38, 0x8a0);
    }
}
