/*
 * function: func_021EB874
 * address:  0x021EB874
 * packet:   pkt_ov170_021EB874
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_020078C4 0x020078C4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_020257D0 0x020257D0 thumb
 */
#include "../include/Obj23975.h"
#include "../include/Obj23977.h"
#include "../include/Obj23978.h"
#include "../include/Obj23979.h"
#include "../include/Obj23980.h"
#include "../include/Obj23981.h"
#include "../include/Obj23982.h"
#include "../include/Obj23983.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct Obj;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_020078C4(void *save, u32 box);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(void *x, short y, short z, void *s, void *w, unsigned short v);
extern void func_02045808(struct U16Vec *vec);
extern void func_020257D0(struct Obj *o);

void func_021EB874(char **p, unsigned a, int i)
{
    void *s = func_02045EC0(((struct Obj23975 *)(p[11]))->f80, 0x1E);
    unsigned n = func_020078C4((void *)(((unsigned *)p[0])[1]), a);
    func_0201EFA4(((struct Obj23977 *)(p[11]))->f84, 0, n, 2, 0, 1);
    func_0201F250(((struct Obj23978 *)(p[11]))->f84, ((struct Obj23979 *)(p[11]))->f88, s);
    func_02043B5C(*(void **)(p[11] + i * 8 + 8), 0);
    if (n == 0x1E)
        func_0201C7D0(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23980 *)(p[11]))->f88, ((struct Obj23981 *)(p[11]))->f7C, 0x1480);
    else
        func_0201C7D0(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23982 *)(p[11]))->f88, ((struct Obj23983 *)(p[11]))->f7C, 0x440);
    func_02045808(s);
    func_020257D0(*(void **)(p[11] + i * 8 + 4));
}
