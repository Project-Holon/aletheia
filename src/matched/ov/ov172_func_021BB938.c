/*
 * function: func_021BB938
 * address: 0x021BB938
 * packet: pkt_ov172_021BB938
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE034 0x021BE034 thumb ov172
 *   func_021BE03C 0x021BE03C thumb ov172
 *   func_021BE044 0x021BE044 thumb ov172
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 */
#include "../include/Obj02881.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021BE034(void *);
extern u32 func_021BE03C(void *);
extern u32 func_021BE044(void *);
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
struct Cfg;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(u32, u32, int, int, u32, u32, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
void func_021BB938(void *p, u8 *q, int id)
{
    u32 font = func_021BE034(p);
    u32 msgs = func_021BE03C(p);
    u32 sys = func_021BE044(p);
    u32 text;
    if (*(u32 *)&((struct Obj02881 *)q)->f50 != 0) func_020452E8(((struct Obj02881 *)q)->f50);
    *(u32 *)&((struct Obj02881 *)q)->f50 = func_020450F0(0, 1, q[4] == 0 ? 4 : 1, 30, 4, 10, 1);
    func_0201C6EC((struct PrintSys *)sys);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj02881 *)q)->f50)), 15);
    text = (u32)func_02045EC0((struct MsgBank *)msgs, id);
    func_0201C724(sys, (u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj02881 *)q)->f50), 0, 0, text, font, 1088);
    func_02045808((struct U16Vec *)text);
    func_02045334((struct Descriptor *)*(u32 *)&((struct Obj02881 *)q)->f50);
    func_02045374((struct Cfg *)(*(u32 *)&((struct Obj02881 *)q)->f50));
    func_0201F73C((void *)(*(u32 *)&((struct Obj02881 *)q)->f50), 1, 512, 9);
    ((struct Obj02881 *)q)->f44 = 1;
}
