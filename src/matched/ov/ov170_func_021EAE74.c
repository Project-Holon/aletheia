/*
 * function: func_021EAE74
 * address: 0x021EAE74
 * packet: pkt_ov170_021EAE74
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
 *   func_021EAAE4 0x021EAAE4 thumb ov170
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 */
#include "../include/Obj00414.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct StrObj;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021EAC28(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABD0(unsigned char *w, int i, void *bank, unsigned idx, int x, int y, unsigned font, unsigned short color);
extern void func_021EABA0(void **);
extern void func_021EAAE4(unsigned char *p, unsigned i);
typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void func_021EAE74(char *p, Entry *e, unsigned i)
{
    unsigned n;
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag) {
        func_021EAC28(p, i, ((struct Obj00414 *)p)->f80, 107, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
        n = func_0201D304(((struct Obj00414 *)p)->f88, ((struct Obj00414 *)p)->f78, 0);
        func_0201EFA4(((struct Obj00414 *)p)->f84, 0, e->low, 3, 0, 1);
        func_021EAC28(p, i, ((struct Obj00414 *)p)->f80, 103, n, 0, ((struct Obj00414 *)p)->f78, 0x440);
    } else {
        func_021EAAE4((unsigned char *)p, i); return;
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}
