/*
 * function: func_021BAD68
 * address: 0x021BAD68
 * packet: pkt_ov110_021BAD68
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3744 0x021C3744 data ov110 a4
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj07999.h"
#include "../include/Obj13777.h"
#include "../include/Obj22347.h"
#include "../include/Obj22348.h"
#include "../include/Obj22349.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 values[6]; } Table;
extern const Table d_021C3744;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
struct MsgBank;
struct Rec;
struct U16Vec;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *,void *,u32,u32,void *,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *rec);
void func_021BAD68(u8 *p,int index) {
    Table table;
    void *bank,*str;
    u8 *q;
    table=d_021C3744;
    func_02043B5C(func_02045770((struct Descriptor *)((struct Obj22347 *)(*(u8 * *)&((struct Obj07999 *)p)->f0))->f6C),7);
    bank=func_02045B38(0,2,146,42);
    str=func_02045EC0(bank,table.values[index]);
    q=*(u8 * *)&((struct Obj07999 *)p)->f0;
    func_0201C724(((struct Obj22348 *)(*(u8 * *)&((struct Obj07999 *)p)->f0))->f7C,func_02045770((struct Descriptor *)((struct Obj13777 *)q)->f6C),2,4,str,((struct Obj13777 *)q)->f80,0x39e7);
    ((struct Obj22349 *)(*(u8 * *)&((struct Obj07999 *)p)->f0))->f70=1;
    func_02045808(str);
    func_02045C04(bank);
}
