/*
 * file:     mb_comm_sys_p13.c
 * unit:     yes
 * function: func_021F0E6C, func_021F0EFC, func_021F0FE8, func_021F1008, func_021F1010, func_021F1018, func_021F1028, func_021F1040, func_021F1050, func_021F1060
 * address:  0x021F0E6C
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
 *   func_02039ACC 0x02039ACC arm
 *   func_020399A8 0x020399A8 arm
 *   func_020399B8 0x020399B8 arm
 *   func_0203D394 0x0203D394 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021F11F0 0x021F11F0 thumb ov107
 *   request_021F6C94 0x021F6C94 data a4
 *   func_0203CBAC 0x0203CBAC arm
 *   func_0203E5F8 0x0203E5F8 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203E6C0 0x0203E6C0 arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0203D01C 0x0203D01C arm
 */
#include "../../matched/include/Obj22294.h"

struct Link;
struct Req;
struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

typedef short s16;

typedef signed char s8;

typedef int s32;

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
} Ov107Ctx;

extern int func_02039ACC(void);
extern void *func_020399A8(void);
extern int func_020399B8(void *);
extern int func_0203D394(void *);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void func_0203D7BC(int);
extern int func_021F11F0(void *,u8,u32);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_0203E5F8(int,int);
extern int func_0203CEAC(int);
extern void func_0203E6C0(void);
extern int func_0203CD98(void);
extern int func_0203CDBC(void);
extern void func_0203D01C(void);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
void func_021F0E6C(State_021F0E6C *p);
void func_021F0EFC(State_021F0EFC *p);
void func_021F0FE8(State_021F0FE8 *p);
int func_021F1008(void *p);
int func_021F1010(void *p);
void func_021F1018(u8 *p);
void func_021F1028(int *p);
int func_021F1040(int *p);
int func_021F1050(int *p);
void *func_021F1060(Ov107Ctx *p);
extern const Request request_021F6C94;

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


void *func_021F1060(Ov107Ctx *p)
{
    return p->f0C;
}
