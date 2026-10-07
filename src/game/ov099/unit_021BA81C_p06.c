/*
 * file:     unit_021BA81C_p06.c
 * unit:     yes
 * function: func_021BB0B4, func_021BB1A8, func_021BB224, func_021BB2B0
 * address:  0x021BB0B4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201FEF4 0x0201FEF4 thumb
 *   sub_020457B0  0x020457B0  arm
 *   unit_0201C440  0x0201C440  thumb
 *   sub_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_021BB4D0  0x021BB4D0  thumb  ov099
 *   func_021BB42C  0x021BB42C  thumb  ov099
 *   func_02028604  0x02028604  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02009864  0x02009864  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021BB528  0x021BB528  thumb  ov099
 *   func_02043598  0x02043598  arm
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj03526.h"
#include "../../matched/include/Obj01706.h"
#include "../../matched/include/Obj06353.h"

struct Descriptor;
struct Obj;
struct Tcbl;
struct U16Vec;
struct PrintSys;
struct Rec3;
struct S02031140;
struct CharBuf;
struct Sub020097BCObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021BB0B4;

typedef unsigned long  u32_021BB1A8;

typedef int BOOL;

typedef struct {
    char pad[0xF0];
    void *f0F0;
    void *f0F4;
    void *f0F8;
    void *f0FC;
    char pad2[0xB4];
    void *f1B4;
    void *f1B8;
    void *f1BC;
    void *f1C0;
} S;

typedef unsigned int   u32_021BB2B0;

extern void func_021BA8EC(char *p);
extern int func_021BA8BC(void *);
extern u32_021BB0B4 func_020452E8(struct Descriptor *d);
extern void func_0202020C(struct Obj *, u16 *, u16 *);
extern u32_021BB0B4 func_0201F868(void *p);
extern void func_020456F8(struct Descriptor *);
extern void func_02041B6C(u32_021BB0B4);
extern void func_0201FEF4(u8 *);
extern struct U16Vec *sub_020457B0(u32_021BB1A8 capacity, u32_021BB1A8 heapId);
extern void *unit_0201C440(int tag);
extern struct Tcbl *sub_0203101C(u16 heap, u16 tag, u32_021BB1A8 count, u32_021BB1A8 workSize);
extern void *func_02028590(int a, int b, int c, int d);
extern void func_021BB4D0(char *p);
extern void func_021BB42C(void *p);
extern int func_02028604(int a0);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32_021BB2B0 func_02009864(const struct Sub020097BCObj *obj, u32_021BB2B0 i, u32_021BB2B0 field);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021BB528(char *p, int v);
extern void func_02043598(u32_021BB2B0 mask, u32_021BB2B0 enable);
void func_021BB0B4(char *p);
void func_021BB1A8(char *s);
void func_021BB224(char *p);
void func_021BB2B0(char *p, int v);

void func_021BB0B4(char *p)
{
    func_021BA8EC(p);
    if (((struct Obj00008 *)p)->f1A4) {
        func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f1A4);
        func_0202020C(*(struct Obj * *)&((struct Obj00008 *)p)->fBC, 0, 0);
        func_0201F868(((struct Obj00008 *)p)->fB8);
        ((struct Obj00008 *)p)->fB8 = 0;
    }
    if (((struct Obj00008 *)p)->f198) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f198); ((struct Obj00008 *)p)->f198 = 0; }
    if (((struct Obj00008 *)p)->f190) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f190); ((struct Obj00008 *)p)->f190 = 0; }
    if (((struct Obj00008 *)p)->f1A8) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f1A8); ((struct Obj00008 *)p)->f1A8 = 0; }
    if (((struct Obj00008 *)p)->f194) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f194); ((struct Obj00008 *)p)->f194 = 0; }
    if (((struct Obj00008 *)p)->f1A0) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f1A0); ((struct Obj00008 *)p)->f1A0 = 0; }
    if (((struct Obj00008 *)p)->f19C) {
        func_020456F8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f19C);
        func_02041B6C(2);
        func_021BA8BC(((struct Obj00008 *)p)->f19C);
        ((struct Obj00008 *)p)->f19C = 0;
    }
    if (((struct Obj00008 *)p)->fB4) { func_0202020C(*(struct Obj * *)&((struct Obj00008 *)p)->fB4, 0, 0); ((struct Obj00008 *)p)->fB4 = 0; }
    if (((struct Obj00008 *)p)->fB0) { func_0201F868(((struct Obj00008 *)p)->fB0); ((struct Obj00008 *)p)->fB0 = 0; }
    if (((struct Obj00008 *)p)->f108) { func_0201FEF4(*(u8 * *)&((struct Obj00008 *)p)->f108); ((struct Obj00008 *)p)->f108 = 0; }
}


/*
 * Allocates eight objects and homes them in the block: four buffers of 0x17C,
 * 0x17C, 0x17C and 0xB4 bytes at +0xF4, +0xFC, +0xF0, +0xF8, two objects from
 * one factory at +0x1B8 and +0x1B4, one four-argument object at +0x1C0 and one
 * at +0x9B0.  The offsets are spelled per access, which is why the listing
 * re-materialises 0x17C as `movs #0x5f; lsls #2` and adds small deltas to it.
 */
void func_021BB1A8(char *s)
{
    ((struct Obj03526 *)s)->fF4 = sub_020457B0(0x17C, 0x21);
    ((struct Obj03526 *)s)->fFC = sub_020457B0(0x17C, 0x21);
    ((struct Obj03526 *)s)->fF0 = sub_020457B0(0x17C, 0x21);
    ((struct Obj03526 *)s)->fF8 = sub_020457B0(0xB4, 0x21);
    ((struct Obj03526 *)s)->f1B8 = unit_0201C440(0x21);
    ((struct Obj03526 *)s)->f1B4 = unit_0201C440(0x21);
    ((struct Obj03526 *)s)->f1C0 = sub_0203101C(0x21, 0x21, 2, 0);
    ((struct Obj03526 *)s)->f9B0 = func_02028590(0xF, 1, 0, 0x21);
}


void func_021BB224(char *p)
{
    func_021BB4D0(p);
    func_021BB42C(p);
    func_02028604((int)(((struct Obj01706 *)p)->f9B0));
    func_02045808(((struct Obj01706 *)p)->fF8);
    func_02045808(((struct Obj01706 *)p)->fF4);
    func_02045808(((struct Obj01706 *)p)->fFC);
    if (((struct Obj01706 *)p)->f1BC != 0) {
        func_0201CE48(((struct Obj01706 *)p)->f1BC);
        ((struct Obj01706 *)p)->f1BC = 0;
    }
    func_02045808(((struct Obj01706 *)p)->fF0);
    func_02031140(((struct Obj01706 *)p)->f1C0);
    func_0201C6EC(((struct Obj01706 *)p)->f1B8);
    func_0201C6EC(((struct Obj01706 *)p)->f1B4);
    func_0201C4C0(((struct Obj01706 *)p)->f1B8);
    func_0201C4C0(((struct Obj01706 *)p)->f1B4);
    ((struct Obj01706 *)p)->f1B8 = 0;
}


void func_021BB2B0(char *p, int v)
{
    func_02009864(((struct Obj06353 *)p)->f4, ((struct Obj06353 *)p)->f8ED - 1, 9);
    func_02043B5C(func_02045770(((struct Obj06353 *)p)->f958), 0);
    func_021BB528(p, v);
    func_02043598(2, 0);
    func_02043598(8, 1);
}
