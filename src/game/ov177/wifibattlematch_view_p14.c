/*
 * file:     wifibattlematch_view_p14.c
 * unit:     yes
 * function: func_021E72FC, func_021E73B8, func_021E73E4
 * address:  0x021E72FC
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   d_021E8CBE 0x021E8CBE data a1
 *   func_021E5978 0x021E5978 thumb ov177
 */
#include "../../matched/include/Obj02224.h"
#include "../../matched/include/Obj00133.h"
#include "../../matched/include/Obj10709.h"

struct Obj;
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_0204B294(unsigned, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
extern int func_021E5978(int *p, int i);
extern unsigned func_021E7CF0(void *, unsigned short, unsigned short);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204ADA4(unsigned);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned func_0204AC18(void *, unsigned, unsigned, unsigned short, unsigned, unsigned, unsigned);
extern unsigned func_0204A6C8(void *, unsigned, unsigned, unsigned, unsigned);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_021E72FC(unsigned char *p, unsigned idx, unsigned owner, unsigned heap);
void func_021E73B8(char *p);
void func_021E73E4(char *p, unsigned owner, void *table, unsigned heap);
extern const unsigned char d_021E8CBE[];

/*
 * lever: full flag byte times 32 narrowed by fourth callee parameter; no three-bit mask.
 */
void func_021E72FC(unsigned char *p, unsigned idx, unsigned owner, unsigned heap)
{
    void *handle;
    Request req;
    handle = func_020490F4(0x20, heap);
    ((struct Obj02224 *)p)->f1E8 = func_0204AC18(handle, 0, ((struct Obj02224 *)p)->f234, p[0x233] * 32, d_021E8CBE[idx], 1, heap);
    ((struct Obj02224 *)p)->f1EC = func_0204A6C8(handle, idx + 0x31, 0, ((struct Obj02224 *)p)->f234, heap);
    ((struct Obj02224 *)p)->f1F0 = func_0204AF28(handle, 0x41, 0x42, heap);
    func_02049238(handle);
    func_02082BCC(&req, 0, 8);
    req.y = 0;
    req.x = 0;
    req.flag = 1;
    ((struct Obj02224 *)p)->f188 = func_0204B294(owner, ((struct Obj02224 *)p)->f1EC, ((struct Obj02224 *)p)->f1E8, ((struct Obj02224 *)p)->f1F0, &req, ((struct Obj02224 *)p)->f234, heap);
    func_0204B6F4(((struct Obj02224 *)p)->f188, 0, 1);
}

void func_021E73B8(char *p)
{
    func_0204B3B4(((struct Obj00133 *)p)->f188);
    func_0204A8D4((u32)(((struct Obj00133 *)p)->f1EC));
    func_0204AFD8((u32)(((struct Obj00133 *)p)->f1F0));
    func_0204ADA4((u32)(((struct Obj00133 *)p)->f1E8));
}

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
