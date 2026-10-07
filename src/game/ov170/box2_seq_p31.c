/*
 * file:     box2_seq_p31.c
 * unit:     yes
 * function: func_021EA878, func_021EA8CC, func_021EA908
 * address:  0x021EA878
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202614C 0x0202614C thumb
 *   func_02026124 0x02026124 thumb
 *   func_021EB988 0x021EB988 thumb
 *   d_021EF8FC 0x021EF8FC data a1
 *   d_021EF8F4 0x021EF8F4 data a1
 *   func_021DD694  0x021DD694  thumb  ov170
 *   func_021DF110  0x021DF110  thumb  ov170
 */
#include "../../matched/include/Obj12168.h"
#include "../../matched/include/Obj00000.h"

#define OBJ(p) (*(void **)((p)->work + 0x70))
struct Sound;
typedef struct {
    unsigned char pad0[0x16];
    unsigned char b16;
    unsigned char pad17[0x2C - 0x17];
    char *work;
} Obj;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_0202614C(struct Sound *obj, u32 idx);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_021EB988(Obj *p, const void *e, unsigned n);
extern int func_021DD694(void ***p, unsigned skip);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_0202136C(u16 v);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_021DF110(char *p, int b);
void func_021EA878(Obj *p, int v);
int func_021EA8CC(unsigned char *p);
void func_021EA908(int p, int bit);
extern const unsigned char d_021EF8FC[];
extern const unsigned char d_021EF8F4[];


void func_021EA878(Obj *p, int v)
{
    if (v != 0) {
        if (p->b16 < 0x1E)
            func_0202614C(OBJ(p), 0x24);
        else
            func_0202614C(OBJ(p), 9);
        func_021EB988(p, d_021EF8FC, 3);
    } else {
        if (p->b16 < 0x1E)
            func_02026124(OBJ(p), 0x24);
        else
            func_02026124(OBJ(p), 9);
        func_021EB988(p, d_021EF8F4, 2);
    }
}

/*
 * Busy 1 for the 0x16 field below 0x1e, else run the panel query and
 *   answer 2 for a hit, 0 otherwise.  `p` must be unsigned char *
 *   (ldrb, not ldrsb) and the result must be the CONSTANTS 1/2/0 with
 *   an early return -- an `int r = 0; ... return r;` keeps r live from
 *   the top, which pushes i from r4 to r6 and widens the push set.
 */
int func_021EA8CC(unsigned char *p)
{
    int i = p[0x16] - 0x1e;
    if (func_021DD694((void ***)p, i) == 0)
        return 1;
    if (func_0202136C((unsigned short)func_02017E1C(
            func_0201AB28(*(void **)(((struct Obj12168 *)p)->f0 + 8), i), 6, 0)) == 1)
        return 2;
    return 0;
}

/*
 * candidate func_021EA908: xor bit
 */
void func_021EA908(int p, int bit)
{
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA174) ^= 1 << bit;
    func_021DF110((char *)p, *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA174));
}
