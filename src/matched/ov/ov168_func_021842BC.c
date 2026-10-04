/*
 * function: func_021842BC
 * address: 0x021842BC
 * packet: pkt_ov168_021842BC
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_02045180 0x02045180 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02184888 0x02184888 data a1
 *   d_02184868 0x02184868 data a2
 */
#include "../include/Obj03845.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void *func_02045B38(int,int,int,u16);
extern void *func_02045180(int,int,int,int,u8,u8,int);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned);
extern const u8 d_02184888[];
extern u16 d_02184868[];
void func_021842BC(void **p, int heap)
{
    int i;
    const u8 *row;
    void *a;
    void *b;
    void *s;
    p[3] = func_02045B38(0,2,65,heap);
    for (i=0;i<3;i++) {
        row = d_02184888+i*12;
        p[i] = func_02045180(row[0],row[1],row[2],row[3],row[4],row[5],((struct Obj03845 *)row)->f6);
        a = func_02045770(p[i]);
        func_02043B5C(a,0);
        func_020456F8(p[i]);
        b = func_02045EC0(p[3],i);
        func_0201C7D0(a,row[8],0,b,p[4],d_02184868[i]);
        func_02045808(b);
        s = p[i];
        func_02045334(s);
        func_02045374(s);
        func_020409B4(func_02045730(s));
    }
}
