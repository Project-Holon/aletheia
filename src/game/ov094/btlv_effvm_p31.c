/*
 * file:     btlv_effvm_p31.c
 * unit:     yes
 * function: func_021F9824, func_021F9844
 * address:  0x021F9824
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02011324 0x02011324 thumb
 */
#include "../../matched/include/Obj21656.h"

struct ScriptVm;
typedef struct {
    unsigned lo : 6;
    unsigned b6 : 1;
} Flags;

typedef struct {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned int  w1;
    unsigned int  w2;
    unsigned short h1;
} S9844;

extern void *func_02011324(struct ScriptVm *vm);
int func_021F9824(void *a);
void func_021F9844(S9844 *p);


/*
 * Returns flag bit 6 of the owner's work when the handle at 0x1e8 is set, else -1.
 */
int func_021F9824(void *a)
{
    Flags *s = func_02011324(a);
    int r = -1;

    if (((struct Obj21656 *)s)->f1E8 != 0)
        r = s->b6;
    return r;
}


/*
 * lane O10 candidate
 */
void func_021F9844(S9844 *p)
{
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 0;
    p->b3 = 0;
    p->w1 = 0;
    p->w2 = 0;
    p->h1 = 0;
}
