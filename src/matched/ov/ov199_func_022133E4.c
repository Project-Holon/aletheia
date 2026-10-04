/*
 * function: func_022133E4
 * address: 0x022133E4
 * packet: pkt_ov199_022133E4
 * region: ov199
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0200853C 0x0200853C thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02167ED8 0x02167ED8 arm ov009
 *   func_02034714 0x02034714 arm
 *   func_022135CC 0x022135CC thumb ov199
 *   func_0200AE54 0x0200AE54 thumb
 *   d_02213D00 0x02213D00 data a1 ov199
 */
#include "../include/Obj06660.h"
#include "../include/Obj25296.h"
#include "../include/Obj25297.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct Flags { u32 year:7, month:4, day:5, hour:5, minute:6, rest:4, enabled:1; } Flags;
typedef struct Nibbles { u8 a:4,b:4; } Nibbles;
typedef struct Triple { int a,b,c; } Triple;
typedef struct Date { int a,b,c,weekday; } Date;
typedef struct Bytes { u8 a,b; } Bytes;
extern void func_02082BCC(void *,int,unsigned);
extern unsigned func_0200853C(const void *);
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *,unsigned);
extern unsigned func_02017E1C(void *,unsigned,unsigned);
struct Reg;
extern int func_02167ED8(void *date, void *time);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_022135CC(u8 *,u8 *,u8 *);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern const char d_02213D00[];
void func_022133E4(u8 *p,void *party1,void *party2,u8 *save,void *reg,int setting,u8 *record,void *other,int mode)
{
    int i;
    unsigned zero = 0;
    void *mon;
    Date date;
    Triple time;
    Bytes bytes;
    func_02082BCC(p,0,0x50);
    ((struct Obj06660 *)p)->f0=func_0200853C(save);
    ((struct Obj06660 *)p)->f4=((struct Obj25296 *)save)->f48;
    for(i=0;i<(int)func_0201AA18(party2);i++) {
        mon=func_0201AB28(party2,i);
        if(func_02017E1C(mon,0xa9,0)) {
            *(u16 *)((unsigned)p+i*2+8)=func_02017E1C(mon,5,0);
            *(u8 *)((unsigned)p+i+0x14)=func_02017E1C(mon,0x6f,0);
            *(u8 *)((unsigned)p+i+0x1a)=func_02017E1C(mon,0x9e,0);
            *(u8 *)((unsigned)p+i+0x20)=func_02017E1C(mon,0x6e,0);
        }
    }
    for(i=0;i<(int)func_0201AA18(party1);i++) {
        mon=func_0201AB28(party1,i);
        if(func_02017E1C(mon,0xa9,zero)) {
            *(u16 *)((unsigned)p+i*2+0x26)=func_02017E1C(mon,5,zero);
            *(u8 *)((unsigned)p+i+0x32)=func_02017E1C(mon,0x6f,zero);
            *(u8 *)((unsigned)p+i+0x38)=func_02017E1C(mon,0x9e,zero);
            *(u8 *)((unsigned)p+i+0x3e)=func_02017E1C(mon,0x6e,zero);
        }
    }
    if(func_02167ED8(&date,&time)==0) func_02034714(d_02213D00,0,d_02213D00);
    ((Flags *)(p + 0x44))->year=date.a;
    ((Flags *)(p + 0x44))->month=date.b;
    ((Flags *)(p + 0x44))->day=date.c;
    ((Flags *)(p + 0x44))->hour=time.a;
    ((Flags *)(p + 0x44))->minute=time.b;
    ((struct Obj06660 *)p)->f48=setting;
    p[0x4c]=((struct Obj25297 *)record)->f8C;
    func_022135CC(record,&bytes.a,&bytes.b);
    ((Nibbles *)(p + 0x4e))->a=bytes.a;
    ((Nibbles *)(p + 0x4e))->b=bytes.b;
    p[0x4d]=func_0200AE54(reg,0x15);
    ((Flags *)(p + 0x44))->enabled=func_0200AE54(reg,0xd);
}
