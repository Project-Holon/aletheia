/*
 * function: func_021EB190
 * address: 0x021EB190
 * packet: pkt_ov170_021EB190
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021EAC28 0x021EAC28 thumb ov170
 *   func_021EABD0 0x021EABD0 thumb ov170
 *   func_021EABA0 0x021EABA0 thumb ov170
 *   func_0201EF40 0x0201EF40 thumb
 */
#include "../include/Obj00414.h"
#include "../include/Obj06549.h"
typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021EAC28(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABD0(unsigned char *w, int i, void *bank, unsigned idx, int x, int y, unsigned font, unsigned short color);
extern void func_021EABA0(void **);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
void func_021EB190(char *p, unsigned char *e, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (((struct Obj06549 *)e)->f6 != 0) {
        func_0201EF40(((struct Obj00414 *)p)->f84, 0, ((struct Obj06549 *)e)->f6);
        func_021EAC28(p, i, ((struct Obj00414 *)p)->f80, 99, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    } else {
        func_021EABD0((unsigned char *)p, i, ((struct Obj00414 *)p)->f80, 105, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}
