/*
 * file:     wifibattlematch_view_p15.c
 * unit:     yes
 * function: func_021E7454, func_021E7464
 * address:  0x021E7454
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
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_021E7CF0 0x021E7CF0 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_021E5978 0x021E5978 thumb ov177
 *   func_0204B294 0x0204B294 arm
 *   d_021E8CBE 0x021E8CBE data a1
 */
#include "../../matched/include/Obj24448.h"
#include "../../matched/include/Obj10710.h"

struct Obj;
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;

typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned int   u32;

extern void func_0204B3B4(struct Obj *p);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_0204B294(unsigned, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
extern int func_021E5978(int *p, int i);
extern unsigned func_021E7CF0(void *, unsigned short, unsigned short);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204ADA4(unsigned);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_021E7454(int *p);
void func_021E7464(char *p, char *desc, unsigned owner, void *table, unsigned heap);
extern const unsigned char d_021E8CBE[];


void func_021E7454(int *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj24448 *)p)->f18C));
}

void func_021E7464(char *p, char *desc, unsigned owner, void *table, unsigned heap)
{
    unsigned n, i, a, b, c;
    Request req;
    n = func_021E7CF0(((struct Obj10710 *)desc)->fC, ((struct Obj10710 *)desc)->f10, ((struct Obj10710 *)desc)->f12);
    func_02082BCC(&req, 0, 8);
    req.x = 0x100;
    req.y = 0x10;
    for (i = 0; i < n; i++) {
        req.x += 0x10;
        req.id = i + 2;
        a = func_021E5978(table, 3);
        b = func_021E5978(table, 1);
        c = func_021E5978(table, 5);
        *(void **)(p + i * 4 + 0x190) = func_0204B294(owner, a, b, c, &req, 1, heap);
    }
}
