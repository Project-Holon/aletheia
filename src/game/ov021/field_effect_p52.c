/*
 * file:     field_effect_p52.c
 * unit:     yes
 * function: func_021ABFDC, func_021ABFEC, func_021ABFFC, func_021AC03C
 * address:  0x021ABFDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030D28  0x02030D28  arm
 *   func_021AC074  0x021AC074  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DE018     0x021DE018  data  ov021  a1
 *   func_021AC154  0x021AC154  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj07511.h"

struct Ctx;
struct Mgr;
typedef unsigned short u16;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T;

typedef unsigned int   u32;

typedef struct {
    int f0;
    char pad[0xd0];
} E;

typedef struct {
    u32 f0;
    int f4;
    E *f8;
} U;

extern void func_02030D28(struct Ctx *c);
extern void func_021AC074(struct Mgr *m);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021AC154(E *e);
extern u32 func_020307B0(void *p);
void func_021ABFDC(T *t);
void func_021ABFEC(T *t);
char *func_021ABFFC(u16 heap, int b, int cnt);
void func_021AC03C(U *u);
extern char d_021DE018[];


void func_021ABFDC(T *t)
{
    if (t->f1c != 0) {
        func_02030D28((struct Ctx *)t->f1c);
    }
}


void func_021ABFEC(T *t)
{
    if (t->f20 != 0) {
        func_021AC074((struct Mgr *)t->f20);
    }
}


char *func_021ABFFC(u16 heap, int b, int cnt)
{
    char *p;

    p = (char *)func_02030734(heap, 0x10, 1, d_021DE018, 0x23a);
    ((struct Obj07511 *)p)->f0 = cnt;
    ((struct Obj07511 *)p)->f4 = heap;
    ((struct Obj07511 *)p)->f8 = func_02030734(heap, cnt * 0xd4, 1, d_021DE018, 0x23e);
    ((struct Obj07511 *)p)->fC = b;
    return p;
}


void func_021AC03C(U *u)
{
    u32 i;
    for (i = 0; i < u->f0; i++) {
        if (u->f8[i].f0 != 0) {
            func_021AC154(&u->f8[i]);
        }
    }
    func_020307B0(u->f8);
    func_020307B0(u);
}
