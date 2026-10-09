/*
 * file:     mb_comm_sys_p09.c
 * unit:     yes
 * function: func_021F0DB4, func_021F0DDC, func_021F0DE8, func_021F0E40, func_021F0E6C, func_021F0EFC, func_021F0FE8, func_021F1008, func_021F1010, func_021F1018, func_021F1028, func_021F1040, func_021F1050, func_021F1060, func_021F1064, func_021F10D4, func_021F10DC, func_021F10E4, func_021F10EC, func_021F10F4, func_021F10FC, func_021F1104, func_021F110C, func_021F1110, func_021F1118, func_021F1120, func_021F1134, func_021F1148, func_021F115C, func_021F1164, func_021F116C, func_021F1174, func_021F1184, func_021F11BC, func_021F11C4, func_021F11CC, func_021F11E0, func_021F11F0
 * address:  0x021F0DB4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F6EAC 0x021F6EAC data a4
 *   func_020307B0 0x020307B0 arm
 *   func_0203D7FC 0x0203D7FC arm
 *   func_02030734 0x02030734 arm
 *   func_020173E8 0x020173E8 thumb
 *   d_021F6E28 0x021F6E28 data a4
 *   func_0203E6C0 0x0203E6C0 arm
 *   func_02039ACC 0x02039ACC arm
 *   func_020399A8 0x020399A8 arm
 *   func_020399B8 0x020399B8 arm
 *   func_0203D394 0x0203D394 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   request_021F6C94 0x021F6C94 data a4
 *   func_0203CBAC 0x0203CBAC arm
 *   func_0203E5F8 0x0203E5F8 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0203D01C 0x0203D01C arm
 *   func_0203E758 0x0203E758 arm
 *   func_02017550  0x02017550  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_0203996C  0x0203996C  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */
#include "../../matched/include/G_Masks.h"
#include "../../matched/include/Obj10259.h"
#include "../../matched/include/Obj22294.h"
#include "../../matched/include/Obj22296.h"
#include "../../matched/include/Obj22298.h"
#include "../../matched/include/Obj22299.h"

struct Link;
struct Req;
struct Entry;
struct Sav;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32_021F0DB4;

typedef struct {u16 f00,pad02;u32 f04,f08,f0C;void *f10;u32 f14;u16 pad18:11;u16 f18:1;u16 pad19:4;u8 pad1A[14];} Object;

typedef struct {u8 pad[24];unsigned short low:11,flag:1,rest:4;} State_021F0DB4;

typedef struct {u32 f00,f04,f08,f0C;} State_021F0E6C;

typedef struct {
    u32 f00,f04; u8 pad08[0x40]; u32 f48; u8 pad4c[8];
    u16 f54,f56,f58,f5a,f5c,f5e;
    u8 pad60,f61,pad62[3],f65,pad66,f67,pad68[8];
} Request;

typedef struct {
    u16 b00:1,b01:1,b02:1,b03:1,b04:1,b05:1,b06:1,b07:1;
    u16 b08:1,b09:1,b10:1,b11:1,b12:1,b13:1,b14:1,b15:1;
} Flags;

typedef struct {
    u16 heap; u8 pad02[22]; Flags f18,f1a;
    u8 f1c,pad1d; u16 f1e; u8 f20,pad21[3]; u32 f24;
} State_021F0EFC;

typedef struct {u32 a; u32 f4; u8 pad[16];unsigned short low:11,flag:1,rest:4;} State_021F0FE8;

typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags;

typedef struct {
    unsigned char pad00[0xC];
    void *f0C;
    unsigned char pad10[8];
    Ov107Flags f18;
    Ov107Flags f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx_021F0DB4;

typedef struct { u8 pad00[0x18]; Flags f18; u16 f1a; u8 f1c; } State_021F1064;

typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags_021F116C;

typedef struct {
    unsigned char pad00[0xC];
    void *f0C;
    unsigned char pad10[8];
    Ov107Flags_021F116C f18;
    Ov107Flags_021F116C f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx_021F116C;

typedef struct {
    unsigned char f00;
    unsigned char pad01;
    unsigned short f02;
} Ov107List;

typedef struct {
    unsigned short b0 : 1;
    unsigned short b1 : 1;
    unsigned short b2 : 1;
    unsigned short rest : 13;
} Ov107Flags_021F1184;

typedef struct {
    unsigned char pad00[0x10];
    Ov107List *f10;
    unsigned char pad14[4];
    Ov107Flags_021F1184 f18;
} Ov107Ctx_021F1184;

typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags_021F11BC;

typedef struct {
    unsigned char pad00[0xC];
    void *f0C;
    unsigned char pad10[8];
    Ov107Flags_021F11BC f18;
    Ov107Flags_021F11BC f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx_021F11BC;

typedef struct {
    unsigned char pad00[0x10];
    unsigned char *f10;
} Ov107Ctx_021F11CC;

struct Bits { unsigned char pad[24]; u16 unused:2; u16 flag:1; u16 rest:13; };

typedef struct {
    unsigned int f00;
    unsigned char f04;
} Ov107Msg;

typedef signed int     s32_021F11F0;

extern u32 func_020307B0(void *p);
extern void func_0203D7FC(void *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020173E8(void);
extern void func_0203E6C0(void);
extern int func_02039ACC(void);
extern void *func_020399A8(void);
extern int func_020399B8(void *);
extern int func_0203D394(void *);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void func_0203D7BC(int);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_0203E5F8(int,int);
extern int func_0203CEAC(int);
extern int func_0203CD98(void);
extern int func_0203CDBC(void);
extern void func_0203D01C(void);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern void func_0203E758(int,int,int,int);
void func_02017550(struct Sav *);
u32 func_0203D378(void);
struct Entry *func_0203996C(s32_021F11F0 idx);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_021F0DB4(void);
u32 func_021F0DDC(void);
Object *func_021F0DE8(u16 heap);
void func_021F0E40(State_021F0DB4 *p);
void func_021F0E6C(State_021F0E6C *p);
void func_021F0EFC(State_021F0EFC *p);
void func_021F0FE8(State_021F0FE8 *p);
int func_021F1008(void *p);
int func_021F1010(void *p);
void func_021F1018(u8 *p);
void func_021F1028(int *p);
int func_021F1040(int *p);
int func_021F1050(int *p);
void *func_021F1060(Ov107Ctx_021F0DB4 *p);
void func_021F1064(unsigned char *p);
int func_021F10D4(State_021F1064 *p);
int func_021F10DC(State_021F1064 *p);
int func_021F10E4(State_021F1064 *p);
int func_021F10EC(State_021F1064 *p);
int func_021F10F4(State_021F1064 *p);
int func_021F10FC(State_021F1064 *p);
int func_021F1104(State_021F1064 *p);
int func_021F110C(State_021F1064 *p);
int func_021F1110(Ov107Ctx_021F0DB4 *p);
unsigned short func_021F1118(Ov107Ctx_021F0DB4 *p);
unsigned short func_021F1120(Ov107Ctx_021F0DB4 *p);
int func_021F1134(Ov107Ctx_021F0DB4 *p);
int func_021F1148(Ov107Ctx_021F0DB4 *p);
int func_021F115C(Ov107Ctx_021F0DB4 *p);
int func_021F1164(Ov107Ctx_021F0DB4 *p);
int func_021F116C(Ov107Ctx_021F116C *p);
void func_021F1174(int a,int b,int c);
void func_021F1184(Ov107Ctx_021F1184 *p);
int func_021F11BC(Ov107Ctx_021F11BC *p);
u8 func_021F11C4(u8 *p);
void *func_021F11CC(Ov107Ctx_021F11CC *p, int i);
int func_021F11E0(unsigned char *a);
int func_021F11E8(struct Bits *a);
int func_021F11F0(void *p, unsigned char kind, unsigned int val);
extern void *d_021F6EAC[];
extern const char d_021F6E28[];
extern const Request request_021F6C94;






void func_021F0DB4(void) {if(d_021F6EAC[0]) {func_020307B0(d_021F6EAC[0]);d_021F6EAC[0]=0;}if(d_021F6EAC[1]) {func_0203D7FC(d_021F6EAC[1]);d_021F6EAC[1]=0;}}







u32 func_021F0DDC(void) { return *(u32 *)(((u8 *)&d_021F6EAC) + 0x18); }







Object *func_021F0DE8(u16 heap){Object *p;p=func_02030734(heap,40,1,d_021F6E28,159);p->f00=heap;p->f04=0;p->f14=0;p->f18=0;p->f0C=0;p->f08=0;p->f10=func_02030734(p->f00,6*func_020173E8()+4,1,d_021F6E28,169);return p;}







void func_021F0E40(State_021F0DB4 *p) { if(((struct Obj10259 *)p)->f14)func_020307B0(((struct Obj10259 *)p)->f14);if(p->flag==1)func_0203E6C0();func_020307B0(((struct Obj10259 *)p)->f10);func_020307B0(p); }






/*
 * extent: two zero padding bytes follow the epilogue.
 */
void func_021F0E6C(State_021F0E6C *p){switch(p->f04){case 0:break;case 1:if(func_02039ACC()==1)p->f04=2;break;case 2:if(func_020399B8(func_020399A8())==1)p->f04=3;break;case 3:if(func_0203D394(func_020399A8())==1){p->f04=6;func_0203D7BC(1);}break;case 4:if(func_02039CB4(func_020399A8(),64,4)==1){p->f04=5;func_0203D7BC(0);}break;case 5:case 6:default:break;}
if(p->f0C!=p->f08&&p->f08!=0){if(func_021F11F0(p,10,p->f08)==1)p->f0C=p->f08;}}






/*
 * evidence: 112-byte request copy, heap halfword at54, and own matched
 * 0203CBAC/0203E5F8 bodies establish all three/two arguments. The third
 * CBAC input carries the unchanged pointer word through its u32 parameter.
 * Halfword flag fields reproduce every original read/store without volatile.
 */
void func_021F0EFC(State_021F0EFC *p)
{
    Request q=request_021F6C94;
    q.f54=p->heap;
    func_0203CBAC((struct Req *)(&q),0,(u32)p);
    p->f24=0;
    p->f18.b00=0;
    p->f1e=0;
    p->f18.b03=0;
    p->f1c=0;
    p->f18.b04=0;
    p->f18.b05=0;
    p->f18.b06=0;
    p->f18.b07=0;
    p->f18.b08=0;
    p->f18.b09=0;
    p->f18.b10=0;
    p->f18.b11=1;
    p->f18.b14=0;
    p->f18.b13=0;
    p->f18.b15=0;
    p->f1a.b00=0;
    p->f1a.b01=0;
    p->f1a.b02=0;
    p->f1a.b03=0;
    p->f1a.b04=0;
    p->f1a.b05=0;
    p->f20=0;
    func_0203E5F8(p->heap,0);
}






void func_021F0FE8(State_021F0FE8 *p) { func_0203CEAC(0); func_0203E6C0(); p->flag=0; p->f4=0; }






int func_021F1008(void *p) { return func_0203CD98(); }






int func_021F1010(void *p) { return func_0203CDBC(); }






void func_021F1018(u8 *p) { func_0203D01C();((struct Obj22294 *)p)->f4=1; }







void func_021F1028(int *p)
{
    int r = (int)func_020399A8();
    func_02039C68((struct Link *)r, 0x40, 4);
    p[1] = 4;
}






int func_021F1040(int *p) { return p[1] == 5; }






int func_021F1050(int *p) { return p[1] >= 6; }







void *func_021F1060(Ov107Ctx_021F0DB4 *p)
{
    return p->f0C;
}





void func_021F1064(unsigned char *p)
{
    unsigned short *h = (unsigned short *)(p + 0x18);
    *h = *h & ~(unsigned short)2;
    *h = *h & ~(unsigned short)4;
    *h = *h & ~(unsigned short)8;
    *h = *h & ~(unsigned short)0x10;
    *h = *h & ~(unsigned short)0x20;
    *h = *h & ~(unsigned short)0x40;
    *h = *h & ~(unsigned short)0x80;
    *h = *h & ~0x100;
    *h = *h & ~0x200;
    *h = *h & ~0x400;
    *h = *h & ~0x1000;
    p[0x1C] = 0;
}





/*
 * leaf: parent cleared all eight original Thumb starts; 60 bytes stop
 * before existing 021F1110. Both 10DC and10E4 read bit4 in the ROM.
 */
int func_021F10D4(State_021F1064 *p) { return p->f18.b03; }





int func_021F10DC(State_021F1064 *p) { return p->f18.b04; }





int func_021F10E4(State_021F1064 *p) { return p->f18.b04; }





int func_021F10EC(State_021F1064 *p) { return p->f18.b06; }





int func_021F10F4(State_021F1064 *p) { return p->f18.b07; }





int func_021F10FC(State_021F1064 *p) { return p->f18.b08; }





int func_021F1104(State_021F1064 *p) { return p->f18.b10; }





int func_021F110C(State_021F1064 *p) { return p->f1c; }






int func_021F1110(Ov107Ctx_021F0DB4 *p)
{
    return p->f18.b14;
}






unsigned short func_021F1118(Ov107Ctx_021F0DB4 *p)
{
    return p->f24;
}






unsigned short func_021F1120(Ov107Ctx_021F0DB4 *p)
{
    return (p->f24 & 0x3FFF0000) >> 16;
}






int func_021F1134(Ov107Ctx_021F0DB4 *p)
{
    if (p->f24 & 0x40000000) {
        return 1;
    }
    return 0;
}






int func_021F1148(Ov107Ctx_021F0DB4 *p)
{
    if (p->f24 & 0x80000000) {
        return 1;
    }
    return 0;
}






int func_021F115C(Ov107Ctx_021F0DB4 *p)
{
    return p->f18.b15;
}






int func_021F1164(Ov107Ctx_021F0DB4 *p)
{
    return p->f1A.b00;
}





int func_021F116C(Ov107Ctx_021F116C *p)
{
    return p->f1A.b01;
}




void func_021F1174(int a,int b,int c) { func_0203E758(b,c,2,1); }





void func_021F1184(Ov107Ctx_021F1184 *p)
{
    Ov107List *list;
    unsigned char i;

    list = p->f10;
    list->f00 = 0;
    list->f02 = 0;
    for (i = 0; i < 6; i++) {
        func_02017550((struct Sav *)((unsigned char *)p->f10 + i * func_020173E8() + 4));
    }
    p->f18.b1 = 0;
    p->f18.b2 = 0;
}





int func_021F11BC(Ov107Ctx_021F11BC *p)
{
    return p->f18.b01;
}





u8 func_021F11C4(u8 *p) { return *(u8 *)(((struct Obj22296 *)p)->f10); }




void *func_021F11CC(Ov107Ctx_021F11CC *p, int i)
{
    return p->f10 + i * func_020173E8() + 4;
}



int func_021F11E0(unsigned char *a) { return ((struct Obj22299 *)(*(unsigned char * *)&((struct Obj22298 *)a)->f10))->f2; }



int func_021F11E8(struct Bits *a) { return a->flag; }


int func_021F11F0(void *p, unsigned char kind, unsigned int val)
{
    Ov107Msg msg;
    void *obj;

    if (func_0203D378() == 1) {
        obj = func_0203996C(0xFF);
    } else {
        obj = func_020399A8();
    }
    msg.f04 = kind;
    msg.f00 = val;
    return func_0203D3F8((u32)obj, 0xFF, 0x400, 8, (u32)(&msg), 1, 0, 0);
}
