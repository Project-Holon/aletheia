/*
 * file:     mb_comm_sys_p08.c
 * unit:     yes
 * function: func_021EFE40, func_021EFFB0, func_021F05DC, func_021F0608, func_021F0694
 * address:  0x021EFE40
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
 *   func_021F1B08 0x021F1B08 thumb ov107
 *   func_021F1B14 0x021F1B14 thumb ov107
 *   func_021F10D4 0x021F10D4 thumb ov107
 *   func_021F10DC 0x021F10DC thumb ov107
 *   func_021F10E4 0x021F10E4 thumb ov107
 *   func_021F10EC 0x021F10EC thumb ov107
 *   func_021F10F4 0x021F10F4 thumb ov107
 *   func_021F10FC 0x021F10FC thumb ov107
 *   func_021F1104 0x021F1104 thumb ov107
 *   func_021F110C 0x021F110C thumb ov107
 *   func_021F11F0 0x021F11F0 thumb ov107
 *   func_020056EC 0x020056EC thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021F1060  0x021F1060  thumb  ov107
 *   func_02012FFC  0x02012FFC  thumb
 *   func_021F1704  0x021F1704  thumb  ov107
 *   func_021F1B24  0x021F1B24  thumb  ov107
 *   func_021F1028  0x021F1028  thumb  ov107
 *   func_021F1110  0x021F1110  thumb  ov107
 *   func_021F1118  0x021F1118  thumb  ov107
 *   func_021F1120  0x021F1120  thumb  ov107
 *   func_021F1134  0x021F1134  thumb  ov107
 *   func_021F1148  0x021F1148  thumb  ov107
 *   func_021F115C  0x021F115C  thumb  ov107
 *   func_021F1164  0x021F1164  thumb  ov107
 *   func_021F116C  0x021F116C  thumb  ov107
 *   func_021F11BC  0x021F11BC  thumb  ov107
 *   func_021F1898  0x021F1898  thumb  ov107
 *   func_021F1628  0x021F1628  thumb  ov107
 *   func_021F18D8  0x021F18D8  thumb  ov107
 *   func_021F1900  0x021F1900  thumb  ov107
 *   func_021F18EC  0x021F18EC  thumb  ov107
 *   func_021F19E4  0x021F19E4  thumb  ov107
 *   func_021F1A2C  0x021F1A2C  thumb  ov107
 *   func_0201293C  0x0201293C  thumb
 *   func_02007774  0x02007774  thumb
 *   func_021F1A24  0x021F1A24  thumb  ov107
 *   func_021F17E0  0x021F17E0  thumb  ov107
 *   func_021F1B38  0x021F1B38  thumb  ov107
 *   func_021EFD98  0x021EFD98  thumb  ov107
 *   func_021F1184  0x021F1184  thumb  ov107
 *   func_0201292C  0x0201292C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0216BF9C  0x0216BF9C  thumb  ov010
 *   func_0216BF74  0x0216BF74  thumb  ov010
 *   func_02007E50  0x02007E50  thumb
 *   d_021F6EA0 0x021F6EA0 data a4
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_02040588 0x02040588 arm
 *   func_0203CDBC 0x0203CDBC arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   func_0203630C 0x0203630C arm
 *   func_020124F4 0x020124F4 thumb
 *   func_021EE740 0x021EE740 thumb ov107
 *   d_021F6E0C 0x021F6E0C data a4
 *   func_021EE824 0x021EE824 thumb ov107
 *   func_02012704 0x02012704 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F7B8 0x0200F7B8 thumb
 *   func_0200F83C 0x0200F83C thumb
 *   func_02035544 0x02035544 arm
 */
#include "../../matched/include/Obj01529.h"
#include "../../matched/include/G_Counter.h"

#define OBJ (*(void **)(p+0xc))
#define MSG (*(void **)(p+0x68))
#define TARGET (*(u8 **)(*(u8 **)(p+8)+4))
struct BigObj;
struct Obj0203159C;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    int f00;
    void *f04;
} Ov107Save;

typedef struct {
    unsigned short f00;
    unsigned char pad02[6];
    Ov107Save *f08;
    void *f0C;
    unsigned char pad10[0x10];
    int f20;
    unsigned char pad24;
    unsigned char state;
    unsigned char pad26[0xE];
    int f34;
    unsigned char pad38[8];
    int f40;
    int f44;
    int f48;
    unsigned char pad4C[0x1C];
    void *f68;
} Ov107Main;

typedef unsigned short u16;

typedef struct {u8 f00;u8 pad[3];void *f04;} Save;

typedef struct {u16 f00,pad02;u32 f04;Save *f08;u32 f0C,f10,f14,f18;u8 pad1C[160];} Ctx_021F0608;

typedef struct {u16 f00,pad02;u32 f04;Save *f08;u32 f0C,f10,f14,f18;} Ctx_021F0694;

extern int func_021F1B08(void *),func_021F1B14(void *);
extern int func_021F10D4(void *),func_021F10DC(void *),func_021F10E4(void *),func_021F10EC(void *);
extern int func_021F10F4(void *),func_021F10FC(void *),func_021F1104(void *),func_021F110C(void *);
extern int func_021F11F0(void *,u8,u32);
extern u32 func_020056EC(u32);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
int func_021F1060(void *);
signed char func_02012FFC(void);
void func_021F1704(void *, int, int);
void func_021F1B24(void *, int);
void func_021F1028(int *p);
int func_021F1110(void *);
int func_021F1118(void *);
int func_021F1120(void *);
int func_021F1134(void *);
int func_021F1148(void *);
int func_021F115C(void *);
int func_021F1164(void *);
int func_021F116C(void *);
int func_021F11BC(void *);
void func_021F1898(void *);
void func_021F1628(void *, int);
void func_021F18D8(void *);
void func_021F1900(void *, int, int, int);
void func_021F18EC(void *);
void func_021F19E4(void *, int);
int func_021F1A2C(void *);
u32 func_0201293C(const struct BigObj *p);
int func_02007774(void *);
void func_021F1A24(u8 *p);
void func_021F17E0(void *, int);
void func_021F1B38(u8 *p, u32 v);
void func_021EFD98(Ov107Main *);
void func_021F1184(void *);
void *func_0201292C(const struct BigObj *p);
u8 *func_02012944(void *p);
void *func_02012F08(int *p);
int func_0216BF9C(void *, int, void *);
void func_0216BF74(void *, int, void *);
u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern void func_02043534(int),func_020435F4(int),func_02040588(u32,u32);
extern int func_0203CDBC(void);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern unsigned int func_0203630C(void);
extern void *func_020124F4(u16);
extern void func_021EE740(u8 *p);
extern void func_021EE824(u8 *p);
extern void func_02012704(unsigned char *);
extern void func_020307B0(void *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
extern u32 func_0200FB24(void);
extern int func_0200FBB0(void);
extern void func_0200F7B8(int);
extern void func_0200F83C(void);
extern void func_02035544(int);
void func_021EFE40(u8 *p);
void func_021EFFB0(Ov107Main *p);
int func_021F05DC(void);
int func_021F0608(void *task,void *arg,Save *save);
int func_021F0694(void *task,int unused,int keep,Ctx_021F0694 *p);
extern struct Counter d_021F6EA0;
extern const char d_021F6E0C[];

/*
 * evidence: caller-only TU/split was MATCH with nine overlay-only leaves;
 * parent-cleared 60-byte getter unit10D4 and standalone1B08 each verified
 * before unchanged caller re-run EXACT. Case18 is empty; case19 stores22.
 * prototype: own legacy02012DAC has three unused trailing parameters;
 * original supplies only r0; full body forwards only r0 to02012CE0 and
 * no inputs to0201042C, then replaces r0/r1 before remaining calls.
 */
void func_021EFE40(u8 *p)
{
    switch(p[0x24]) {
    case 9:
        if(func_021F1B08(MSG)==1 && func_021F1B14(MSG)==1 && func_021F10D4(OBJ)==1) {
            if(func_021F11F0(OBJ,1,func_020056EC(20)+10)==1) p[0x24]=10;
        }
        break;
    case 10: if(func_021F10F4(OBJ)==1) p[0x24]=11; break;
    case 11: func_02012DAC((int)TARGET); p[0x24]=12; break;
    case 12: if(func_02012DD0(TARGET)==1) p[0x24]=13; break;
    case 13:
        if(func_021F10DC(OBJ)==1 && func_021F11F0(OBJ,2,func_020056EC(20)+10)==1) {
            p[0x24]=14; p[0x27]=0;
        }
        break;
    case 14:
        if(func_021F10FC(OBJ)==1) {
            p[0x27]++;
            if(p[0x27]>(u32)func_021F110C(OBJ)) p[0x24]=15;
        }
        break;
    case 15: if(func_02012DD0(TARGET)==2) p[0x24]=16; break;
    case 16:
        if(func_021F10E4(OBJ)==1 && func_021F11F0(OBJ,3,0)==1) {
            p[0x24]=17; p[0x27]=0;
        }
        break;
    case 17:
        if(func_021F10EC(OBJ)==1 && func_021F11F0(OBJ,4,0)==1) p[0x24]=19;
        break;
    case 18: break;
    case 19: if(func_021F1104(OBJ)==1) ((struct Obj01529 *)p)->f20=22; break;
    }
}


void func_021EFFB0(Ov107Main *p)
{
    int a;
    int b;
    void *c;
    void *d;
    void *e;

    switch (p->state) {
    case 0:
        if (func_021F1060(p->f0C) == 10 || func_021F1060(p->f0C) == 12) {
            func_021F1704(p->f68, 0x29, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F1028(p->f0C);
            p->f20 = 0x1B;
        }
        if (func_021F1060(p->f0C) == 11) {
            func_021F1704(p->f68, 0x2C, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F1028(p->f0C);
            p->f20 = 0x1B;
        }
        if (func_021F1110(p->f0C) == 1) {
            a = func_021F1118(p->f0C);
            b = func_021F1120(p->f0C);
            if (a != 0) {
                func_021F1898(p->f68);
                func_021F1628(p->f68, 5);
                func_021F18D8(p->f68);
                func_021F1900(p->f68, 0, a + b, 3);
                func_021F1704(p->f68, 0x16, func_02012FFC());
                func_021F1B24(p->f68, 1);
                func_021F18EC(p->f68);
                p->state = 1;
            } else {
                p->state = 0x13;
            }
        }
        break;
    case 1:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 2;
        }
        break;
    case 2:
        p->f34 = func_021F1A2C(p->f68);
        if (p->f34 == 1) {
            b = func_021F1118(p->f0C);
            a = (unsigned short)func_02007774((void *)func_0201293C(p->f08->f04));
            func_021F1A24(p->f68);
            if ((unsigned int)a < (unsigned int)b) {
                p->f40 = 1;
                p->state = 0xD;
            } else {
                p->f40 = 0;
                p->state = 3;
            }
        } else if (p->f34 == 2) {
            p->state = 0xD;
        }
        break;
    case 3:
        if (func_021F1120(p->f0C) != 0) {
            a = func_021F1118(p->f0C);
            func_021F1898(p->f68);
            func_021F1628(p->f68, 1);
            func_021F18D8(p->f68);
            func_021F1900(p->f68, 0, a, 3);
            func_021F1704(p->f68, 0x24, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F18EC(p->f68);
            p->state = 4;
        } else {
            p->state = 5;
        }
        break;
    case 4:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 5;
        }
        break;
    case 5:
        if (func_021F1134(p->f0C) == 1) {
            func_021F1898(p->f68);
            func_021F1628(p->f68, 5);
            func_021F1704(p->f68, 0x1A, func_02012FFC());
            p->state = 6;
        } else {
            p->state = 0xD;
        }
        break;
    case 6:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 7;
        }
        break;
    case 7:
        a = func_021F1A2C(p->f68);
        if (a == 1) {
            if (func_021F1148(p->f0C) == 1) {
                func_021F1704(p->f68, 0x1B, func_02012FFC());
                p->state = 8;
            } else {
                p->state = 0xD;
            }
        } else if (a == 2) {
            p->state = 0xA;
        }
        break;
    case 8:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 9;
        }
        break;
    case 9:
        a = func_021F1A2C(p->f68);
        if (a == 1) {
            p->state = 0xD;
        } else if (a == 2) {
            p->state = 0xA;
        }
        break;
    case 10:
        func_021F1704(p->f68, 0x1C, func_02012FFC());
        p->state = 0xB;
        break;
    case 11:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 0xC;
        }
        break;
    case 12:
        a = func_021F1A2C(p->f68);
        if (a == 1) {
            p->f34 = 2;
            p->state = 0xD;
        } else if (a == 2) {
            p->state = 5;
        }
        break;
    case 13:
        if (p->f34 == 1) {
            if (p->f40 == 1) {
                a = 2;
            } else {
                a = 0;
            }
        } else {
            a = 1;
        }
        if (func_021F11F0(p->f0C, 0xF, a) == 1) {
            if (a == 0) {
                p->state = 0xE;
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F17E0(p->f68, 0x19);
                func_021F1B38(p->f68, 1);
            } else if (a == 2) {
                p->state = 0x11;
            } else {
                p->state = 0x13;
            }
        }
        break;
    case 14:
        if (func_021F11BC(p->f0C) == 1) {
            func_021EFD98(p);
            p->state = 0xF;
        }
        if (func_021F115C(p->f0C) == 1) {
            a = func_021F1118(p->f0C);
            func_021F1898(p->f68);
            func_021F1628(p->f68, 1);
            func_021F18D8(p->f68);
            func_021F1900(p->f68, 0, a, 3);
            func_021F1704(p->f68, 0x1E, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F18EC(p->f68);
            p->state = 0x10;
            p->f44 = 1;
        }
        break;
    case 15:
        if (func_021F11F0(p->f0C, 0, 0) == 1) {
            func_021F1184(p->f0C);
            p->state = 0xE;
        }
        break;
    case 16:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x13;
        }
        break;
    case 17:
        func_021F1898(p->f68);
        func_021F1628(p->f68, 5);
        func_021F1704(p->f68, 0x18, func_02012FFC());
        p->state = 0x12;
        break;
    case 18:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x13;
        }
        break;
    case 19:
        if (func_021F1164(p->f0C) == 1) {
            if (func_021F116C(p->f0C) == 1) {
                func_021F1898(p->f68);
                func_021F1628(p->f68, 5);
                func_021F1704(p->f68, 0x1F, func_02012FFC());
                p->state = 0x14;
            } else {
                p->state = 0x19;
            }
        }
        break;
    case 20:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x15;
            func_021F19E4(p->f68, 1);
        }
        break;
    case 21:
        a = func_021F1A2C(p->f68);
        if (a == 1 || a == 2) {
            c = func_0201292C(p->f08->f04);
            d = func_02012944(p->f08->f04);
            e = func_02012F08(p->f08->f04);
            if (a == 1 && func_0216BF9C(e, 0, d) == 1) {
                p->f34 = 2;
                p->state = 0x16;
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F1704(p->f68, 0x25, func_02012FFC());
                func_021F1B24(p->f68, 1);
            } else {
                p->f34 = a;
                p->state = 0x17;
            }
        }
        break;
    case 22:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x17;
        }
        break;
    case 23:
        a = 1;
        if (p->f34 != 1) {
            a = 0;
        }
        if (func_021F11F0(p->f0C, 0x10, a) == 1) {
            if (a == 1) {
                c = func_0201292C(p->f08->f04);
                d = func_02012944(p->f08->f04);
                e = func_02012F08(p->f08->f04);
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F1704(p->f68, 0x21, func_02012FFC());
                func_021F1B24(p->f68, 1);
                func_0216BF74(e, 0, d);
                func_02007E50(c, 0x215, 1, p->f00);
                p->f48 = 1;
                p->state = 0x18;
            } else {
                p->state = 0x19;
            }
        }
        break;
    case 24:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x19;
        }
        break;
    case 25:
        if (p->f44 == 1 || p->f48 == 1) {
            if (func_021F11F0(p->f0C, 0x11, 0) == 1) {
                p->f20 = 0x13;
            }
        } else {
            if (func_021F1118(p->f0C) == 0 && func_021F116C(p->f0C) == 0) {
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F1704(p->f68, 0x28, func_02012FFC());
                func_021F1B24(p->f68, 1);
            }
            p->f20 = 0x1B;
        }
        break;
    }
}

int func_021F05DC(void) { func_02043534(0);func_020435F4(0);func_02040588(*(int *)(((u8 *)&d_021F6EA0)+4)==1?4:2,1);return 1; }

int func_021F0608(void *task,void *arg,Save *save){Ctx_021F0608 *p;
if(!func_0203CDBC())return 0;
func_0203064C(1,93,0x130000);p=func_0203159C(task,188,93);
if(!save){save=func_02030734(93,8,0,d_021F6E0C,2788);if(func_0203630C()&256)save->f00=1;else{save->f00=0;save->f04=func_020124F4(93);}}
if(save->f00==1)save->f04=func_020124F4(93);
p->f00=93;p->f08=save;p->f10=0;p->f14=0;p->f18=0;func_021EE740((u8 *)p);return 1;}

/*
 * extent: two zero padding bytes follow the epilogue.
 */
int func_021F0694(void *task,int unused,int keep,Ctx_021F0694 *p){int mode;u32 a,b,c;
a=p->f10;mode=0;c=p->f18;b=p->f14;if(p->f08->f00==1)mode=1;func_021EE824((u8 *)p);
if(!keep){func_02012704(p->f08->f04);func_020307B0(p->f08);}else if(p->f08->f00==1){func_02012704(p->f08->f04);func_020307B0(p->f08);}
func_020315D4(task);func_020306F0(93);
if(a==1){if(mode){if(c==1||func_0200FB24()==1){func_0200FBB0();func_0200F7B8(1);}else func_0200F7B8(0);}else if(c==1){func_0200FBB0();func_0200F7B8(1);}}
if(b==1)func_0200F83C();if(mode==1)func_02035544(0);return 1;}
