/*
 * file:     btlv_effvm_p44.c
 * unit:     yes
 * function: func_021FBF48, func_021FBFA0
 * address:  0x021FBF48
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
 *   func_0201134C  0x0201134C  thumb
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021FFFD8  0x021FFFD8  thumb  ov094
 *   func_02200140 0x02200140 thumb ov094
 */
#include "../../matched/include/Obj09236.h"

struct Cursor;
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

typedef unsigned int   u32;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021F8694(void);
extern int func_021FCA04(State *s, int i, int *out);
extern void func_021FFFD8(char *w, int key, int flag, int clear);
extern void func_02200140(int a, int b, int c);
int func_021FBF48(struct Cursor *a, State *s);
int func_021FBFA0(int a, char *b);


int func_021FBF48(struct Cursor *a, State *s)
{
    int buf[8];
    int x = func_0201134C(a);
    int n = func_021FCA04(s, func_0201134C(a), buf);
    int y = func_0201134C(a);
    int i;

    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFFD8((char *)func_021F8694(), buf[i], x, y);
    }
    return s->f23c;
}


/*
 * lane O10 candidate
 */
int func_021FBFA0(int a, char *b)
{
    func_02200140(func_021F8694(), ((struct Obj09236 *)b)->fE0, ((struct Obj09236 *)b)->fDC);
    return ((struct Obj09236 *)b)->f23C;
}
