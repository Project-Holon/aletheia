/*
 * function: func_021E73E4
 * address: 0x021E73E4
 * packet: pkt_ov177_021E73E4
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021E5978 0x021E5978 thumb ov177
 *   func_0204B294 0x0204B294 arm
 *   d_021E8CBE 0x021E8CBE data a1
 */
#include "../include/Obj10709.h"
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;
typedef unsigned short u16;

extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_0204B294(unsigned, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
extern int func_021E5978(int *p, int i);
extern unsigned func_021E7CF0(void *, unsigned short, unsigned short);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204ADA4(unsigned);
extern void *func_020490F4(unsigned int id, u16 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern const unsigned char d_021E8CBE[];
void func_021E73E4(char *p, unsigned owner, void *table, unsigned heap)
{
    Request req;
    unsigned v, a, b, c;
    func_02082BCC(&req, 0, 8);
    req.x = 0x118;
    req.y = 0x98;
    req.id = 7;
    req.flag = 1;
    v = ((struct Obj10709 *)p)->f234;
    a = func_021E5978(table, v + 2);
    b = func_021E5978(table, ((struct Obj10709 *)p)->f234);
    c = func_021E5978(table, v + 4);
    ((struct Obj10709 *)p)->f18C = func_0204B294(owner, a, b, c, &req, v, heap);
}
