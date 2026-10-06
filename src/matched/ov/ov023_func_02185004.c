/*
 * function: func_02185004
 * address:  0x02185004
 * packet:   pkt_ov023_02185004
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203115C  0x0203115C  arm
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 */
#include "../include/Obj03624.h"

typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
struct S02031140;
struct Tcbl;
extern void func_0203115C(struct Tcbl *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);

void func_02185004(char *p)
{
    int i;

    func_0203115C((struct Tcbl *)(((struct Obj03624 *)p)->f170));
    func_02031140((struct S02031140 *)(((struct Obj03624 *)p)->f170));
    func_0201C6EC((struct PrintSys *)(((struct Obj03624 *)p)->f168));
    func_0201C4C0((struct PrintSys *)(((struct Obj03624 *)p)->f168));
    func_0201C6EC((struct PrintSys *)(((struct Obj03624 *)p)->f164));
    func_0201C4C0((struct PrintSys *)(((struct Obj03624 *)p)->f164));
    for (i = 0; i < 5; i++)
        func_020452E8((struct Descriptor *)(*(u32 *)(p + 0x104 + i * 4)));
    func_020452E8((struct Descriptor *)(((struct Obj03624 *)p)->f118));
    func_020452E8((struct Descriptor *)(((struct Obj03624 *)p)->f11C));
    func_020450C8();
}
