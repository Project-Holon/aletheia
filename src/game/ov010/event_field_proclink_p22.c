/*
 * file:     event_field_proclink_p22.c
 * unit:     yes
 * function: func_02161308, func_02161350
 * address:  0x02161308
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 *   func_021616A4   0x021616A4  thumb  ov010
 *   func_02188C54   0x02188C54  thumb
 *   func_02012374   0x02012374  thumb
 */
#include "../../matched/include/Obj12327.h"
#include "../../matched/include/Obj09158.h"
#include "../../matched/include/Obj09159.h"

struct Big;
struct Ctx;
struct Sub02008700Obj;
struct Evt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_021616A4(void *p, int a1, int a2, int a3, int a4);
extern void *func_02188C54(void *);
extern void func_02012374(struct Evt *evt, struct Evt **out);
u32 *func_02161308(char *c);
int func_02161340(int a0, int *a1);
void func_02161350(void *a0);
extern const char d_02172978[];


/*
 * Allocate an 8-byte record and store the save handle at +4. The extent
 * also holds the unlabelled leaf at 0x02161340 (nonzero test of *r1).
 */
u32 *func_02161308(char *c)
{
    u32 *r;

    func_0200873C(func_02012EBC(func_020120F4(**(void ** *)&((struct Obj12327 *)c)->f18)));
    r = func_02030734(4, 8, 1, d_02172978, 0x705);
    r[1] = **(u32 * *)&((struct Obj12327 *)c)->f18;
    return r;
}


int func_02161340(int a0, int *a1)
{
    if (*a1 != 0)
        return 1;
    return 0;
}


/*
 * Five arguments to the overlay builder: the two words of the descriptor,
 * the object's halfword, the descriptor's classification and a pointer to
 * the object's tail; the result goes to the arm9 call with the
 * object's word at +0x14.
 */
void func_02161350(void *a0)
{
    char *r4 = *(char * *)&((struct Obj09158 *)a0)->f18;
    void *t = func_02188C54(((struct Obj09159 *)r4)->f4);

    func_02012374(((struct Obj09158 *)a0)->f14,
                  func_021616A4(((struct Obj09159 *)r4)->f0, (int)(((struct Obj09159 *)r4)->f4),
                                ((struct Obj09158 *)a0)->f0, (int)t, (int)((char *)a0 + 0x10)));
}
