/*
 * file:     eventdata_system_p01.c
 * unit:     yes
 * function: func_02161E60, func_02161E78, func_02161E84, func_02161ECC, func_02161EEC, func_02161F00
 * address:  0x02161E60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021620B0  0x021620B0  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_02045A98  0x02045A98  arm
 */
#include "../../matched/include/Obj17710.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
    u8 b1;
    u8 b2;
    u8 pad;
    u16 ids[8];
} T;

extern int func_021620B0();
extern void func_02082BCC(void *, unsigned, unsigned);
extern u16 func_02045A98(void);
int func_02161E60(int a0, int a1);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Tail call through a pool word and `bx r3`: a two-instruction * thunk into func_02082BCC, the shape of the arm9 copy. * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02161E78.c \ * --func func_02161E78 --addr 0x02161E78 --region ov010 --cc dsi/1.1p1 --thumb */ void func_02161E78(void *a0);
int func_02161E84(T *p);
int func_02161ECC(T *p);
/* * Fills ten halfwords with 0xFFFF. A leaf with no lr-saving prologue, * called only from arm9 (func_0200A848), so the listing emits it as data. */ void func_02161EEC(u16 *buf);
void func_02161F00(void *p);





int func_02161E60(int a0, int a1)
{

    if (a1 != 0) goto loc_02161E6E;
loc_02161E66:
a0 = a0 + 8;
    a0 = func_021620B0(a0);
loc_02161E6C:
    return a0;
loc_02161E6E:
a0 = a0 + 0xf8;
    a0 = func_021620B0(a0);
loc_02161E74:
    return a0;}





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_02082BCC, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02161E78.c \
 *       --func func_02161E78 --addr 0x02161E78 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02161E78(void *a0)
{

    func_02082BCC(a0, 0, 24);
}




int func_02161E84(T *p)
{
    int id = func_02045A98();
    int i;
    int found;
    if (p->b1 >= 30) return 0;
    if (p->b2 > 100) return 0;
    if (p->hi != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (id == p->ids[i]) found = 1;
        }
        if (found == 0) return 0;
    }
    return 1;
}



int func_02161ECC(T *p)
{
    if (p->lo == 0) return 0;
    if (func_02161E84(p) != 0) return 1;
    return 0;
}




/*
 * Fills ten halfwords with 0xFFFF.  A leaf with no lr-saving prologue,
 * called only from arm9 (func_0200A848), so the listing emits it as data.
 */
void func_02161EEC(u16 *buf)
{
    int i;
    for (i = 0; i < 10; i++)
        buf[i] = 0xffff;
}


void func_02161F00(void *p)
{
    func_02082BCC(p, 0, 4);
    ((struct Obj17710 *)p)->f2 = 10;
}
