/*
 * function: func_0220CFC4
 * address: 0x0220CFC4
 * packet: pkt_ov198_0220CFC4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj06650.h"
#include "../include/Obj25164.h"
#include "../include/Obj25165.h"
#include "../include/Obj25166.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct MsgBank;
struct Rec;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern void func_02045808(struct U16Vec *vec);
extern int func_022110D4(u8 *, int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
void func_0220CFC4(char *p, int index)
{
    char *elem;
    void *bank;
    void *t;
    void *f;
    elem = p + 4 + func_022110D4((u8 *)p, index) * 0x4C;
    bank = func_02045B38(0, 2, 0xB7, ((struct Obj25164 *)(*(char * *)&((struct Obj06650 *)p)->f0))->f10);
    t = func_02045EC0(bank, ((struct Obj25165 *)elem)->f18);
    f = ((struct Obj06650 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(((struct Obj06650 *)p)->f1F80), 0, 0, (u32)t, ((struct Obj25166 *)(*(char * *)&((struct Obj06650 *)p)->f0))->fC, 0x2120);
    ((struct Obj06650 *)p)->f1F84 = 1;
    func_02045808(t);
    func_02045C04(bank);
}
