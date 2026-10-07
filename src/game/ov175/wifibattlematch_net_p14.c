/*
 * file:     wifibattlematch_net_p14.c
 * unit:     yes
 * function: func_021D9804, func_021D9854, func_021D9868, func_021D9874, func_021D98B8, func_021D98CC, func_021D98D8, func_021D98E4, func_021D99F4, func_021D9A08, func_021D9A1C, func_021D9A30
 * address:  0x021D9804
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E5548  0x021E5548  thumb  ov177
 *   func_0200B078  0x0200B078  thumb
 *   func_021E7520  0x021E7520  thumb  ov177
 *   func_021E7710   0x021E7710  thumb
 *   func_021E8AA0   0x021E8AA0  thumb
 *   func_021E8A80   0x021E8A80  thumb
 *   func_021E8A90   0x021E8A90  thumb
 *   func_021E64C8   0x021E64C8  thumb
 *   func_021E8AA8   0x021E8AA8  thumb
 *   func_021E777C  0x021E777C  thumb  ov177
 *   func_021E7E3C 0x021E7E3C thumb ov177
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_021E82BC  0x021E82BC  thumb  ov177
 *   func_021E8338 0x021E8338 thumb ov177
 *   func_021E8420 0x021E8420 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_021E888C 0x021E888C thumb ov177
 *   func_021E88B0 0x021E88B0 thumb ov177
 *   func_021E5D40   0x021E5D40  thumb
 *   func_021E89D0   0x021E89D0  thumb
 *   func_021E8A00   0x021E8A00  thumb
 *   func_021E5EF8   0x021E5EF8  thumb
 *   func_021E5F24   0x021E5F24  thumb
 */
#include "../../matched/include/Obj14329.h"
#include "../../matched/include/Obj24304.h"
#include "../../matched/include/Obj00013.h"
#include "../../matched/include/Obj24305.h"
#include "../../matched/include/Obj14330.h"
#include "../../matched/include/Obj24307.h"
#include "../../matched/include/Obj24308.h"
#include "../../matched/include/Obj24309.h"

struct Reg2;
struct Big;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32_021D9804;

typedef signed int     s32;

typedef unsigned long u32_021D9854;

typedef unsigned long u32_021D9868;

typedef unsigned long u32_021D98B8;

typedef struct Work Work;

typedef unsigned int u32_021D98E4;

typedef struct { u32_021D98E4 x0,x1,x2,x3,x4,x5,x6,x7; u16 a,b,c,d; int enabled; u16 kind,pad; } Desc;

typedef unsigned long u32_021D99F4;

typedef unsigned long u32_021D9A08;

typedef unsigned long u32_021D9A1C;

typedef unsigned long u32_021D9A30;

extern int func_021E5548(int *p);
extern s32 func_0200B078(struct Reg2 *p, u32_021D9804 id);
extern u32_021D9804 func_021E7520(u32_021D9804 a, u32_021D9804 b, u32_021D9804 c, u32_021D9804 d, u32_021D9804 e, u32_021D9804 f, u32_021D9804 g,
                         u32_021D9804 h, u32_021D9804 i, u32_021D9804 j, u32_021D9804 k);
extern void func_021E7710(u32_021D9854 p);
extern u32_021D9868 func_021E777C(u32_021D9868 p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern void *func_021E7E3C(void *, int, int, int, int, int, int);
extern void func_021E82BC(char *p);
extern int func_021E8338(Work *);
extern int func_021E8420(Work *);
extern void func_02082BCC(void *, int, u32_021D98E4);
extern u32_021D98E4 func_021E888C(Desc *, int);
extern u32_021D98E4 func_021E88B0(Desc *, int, unsigned char, int, int, int);
extern void func_021E89D0(u32_021D99F4 p);
extern int func_021E8A00(u32_021D9A08 p);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8A80(u32_021D9A30 h);
extern int func_021E8A90(int **p);
void func_021D9804(u32_021D9804 *obj, u32_021D9804 arg);
void func_021D9854(char *obj);
u32_021D9868 func_021D9868(char *obj);
void func_021D9874(char *ctx);
void func_021D98B8(char *obj);
int func_021D98CC(char *p);
int func_021D98D8(char *p);
void func_021D98E4(u32_021D98E4 *p, int mode);
void func_021D99F4(char *obj);
int func_021D9A08(char *obj);
void func_021D9A1C(char *obj, void *fn);
u32_021D9A30 func_021D9A30(char *obj);


/*
 * Lazy create: when the handle at +0x20 is empty, builds it through the eleven-argument ov177 constructor from the +0x0/+0x4/+0x8/+0x10/+0x14/+0x18 words and the heap id at +0x108.
 */
void func_021D9804(u32_021D9804 *obj, u32_021D9804 arg)
{
    if (obj[8] == 0) {
        u32_021D9804 base = func_021E5548((int *)obj[0]);
        obj[8] = func_021E7520(arg, base, obj[1], obj[2], obj[4], obj[5], obj[6], 0, 1,
                               func_0200B078((struct Reg2 *)obj[0x42], 0xb), 0x57);
    }
}


/*
 * Release path for the ov175 object's 0x20 pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
void func_021D9854(char *obj)
{
    u32_021D9854 p = ((struct Obj14329 *)obj)->f20;

    if (p != 0) {
        func_021E7710(p);
        ((struct Obj14329 *)obj)->f20 = 0;
    }
}


/*
 * Thunk: hands the +0x20 block to 0x021E777C (ov177) and returns its result.
 */
u32_021D9868 func_021D9868(char *obj)
{
    return func_021E777C(((struct Obj24304 *)obj)->f20);
}

/*
 * tail: 021D98B6..021D98B8 is two zero alignment bytes.
 */
void func_021D9874(char *ctx)
{
    int window;
    if (((struct Obj00013 *)ctx)->f24 == 0) {
        window = func_021E5548(*(int * *)&((struct Obj00013 *)ctx)->f0);
        ((struct Obj00013 *)ctx)->f24 = func_021E7E3C(func_0200BAC8(func_02012EBC(**(void ** *)&((struct Obj24305 *)(*(char * *)&((struct Obj00013 *)ctx)->f104))->f8)), window, *(int *)&((struct Obj00013 *)ctx)->f4, ((struct Obj00013 *)ctx)->fC, *(int *)&((struct Obj00013 *)ctx)->f10, *(int *)&((struct Obj00013 *)ctx)->f14, 87);
    }
}


/*
 * Free-and-null on the +0x24 block: hands it to 0x021E82BC (ov177) and
 *  *  clears the field, so a second call is harmless.
 */
void func_021D98B8(char *obj)
{
    u32_021D98B8 p = ((struct Obj14330 *)obj)->f24;
    if (p != 0) {
        func_021E82BC((char *)p);
        ((struct Obj14330 *)obj)->f24 = 0;
    }
}

int func_021D98CC(char *p)
{
    return func_021E8338(*(Work * *)&((struct Obj24307 *)p)->f24);
}

int func_021D98D8(char *p)
{
    return func_021E8420(*(Work * *)&((struct Obj24308 *)p)->f24);
}

void func_021D98E4(u32_021D98E4 *p, int mode) {
    Desc d;
    if (p[12] == 0) {
        func_02082BCC(&d, 0, 48);
        d.x0=p[5]; d.x1=p[2]; d.x2=p[4];
        d.a=0; d.b=15; d.c=13; d.d=1;
        switch (mode) {
        case 5: d.pad=1;
        case 0:
            d.x3=52; d.x4=53; d.x7=2; d.enabled=1; d.kind=1;
            p[12]=func_021E888C(&d,87); break;
        case 1:
            d.x3=47; d.x4=48; d.x5=49; d.x7=3; d.enabled=1; d.kind=2;
            p[12]=func_021E888C(&d,87); break;
        case 2:
            d.x3=66; d.x4=67; d.x7=2; d.enabled=1; d.kind=1;
            p[12]=func_021E888C(&d,87); break;
        case 3:
            d.x3=75; d.x4=76; d.x5=77; d.x7=3; d.enabled=1; d.kind=2;
            p[12]=func_021E88B0(&d,3,6,26,6,87); break;
        case 4:
            d.x3=93; d.x4=94; d.x5=95; d.x7=3; d.enabled=1; d.kind=2;
            p[12]=func_021E88B0(&d,3,6,26,6,87); break;
        }
    }
}


void func_021D99F4(char *obj)
{
    u32_021D99F4 p = ((struct Obj00013 *)obj)->f30;

    if (p != 0) {
        func_021E89D0(p);
        ((struct Obj00013 *)obj)->f30 = 0;
    }
}


/*
 * Field query: if the +0x30 pointer is live, hand it to the ov175-adjacent
 *     routine at 0x021E8A00 and return its result, else -1.  func_021D99F4 is
 *     the matching free path for the same field.
 */
int func_021D9A08(char *obj)
{
    u32_021D9A08 p = ((struct Obj24309 *)obj)->f30;

    if (p != 0)
        return func_021E8A00(p);
    return -1;
}


void func_021D9A1C(char *obj, void *fn)
{
    func_021E8AA0((int *)(((struct Obj00013 *)obj)->f3C), (int)fn);
    ((struct Obj00013 *)obj)->f40 = 0xFFFF;
}


/*
 * Reads back the +0x3c stream: 0x021E8A80 for pending data, 0x021E8A90
 *     for a byte read, returning the +0x40 word or the 0xFFFF sentinel.
 *     Mirrors func_021D679C.
 */
u32_021D9A30 func_021D9A30(char *obj)
{
    func_021E8A80(((struct Obj00013 *)obj)->f3C);
    if (func_021E8A90((int **)(((struct Obj00013 *)obj)->f3C)) != 0)
        return ((struct Obj00013 *)obj)->f40;
    return 0xFFFF;
}


/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x021E8A90
 * Identical blocker to func_021D679C: the call at +0x0C targets 0x021E8A90,
 * which is not a traced function label in any overlay listing.
 */
