/*
 * file:     wf2dmap_map_p04.c
 * unit:     yes
 * function: func_021C4B7C, func_021C4B90, func_021C4BA4, func_021C4C88
 * address:  0x021C4B7C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C4AD0 0x021C4AD0 thumb ov127
 *   func_021C4A54 0x021C4A54 thumb ov127
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C4914 0x021C4914 thumb ov127
 *   func_021C499C 0x021C499C thumb ov127
 *   d_021C601C 0x021C601C data a4
 */
#include "../../matched/include/Obj00535.h"
#include "../../matched/include/Obj23041.h"
#include "../../matched/include/Obj23042.h"

typedef unsigned short u16;

struct pair_021C4B7C {
    u16 a;
    u16 b;
};

struct pair_021C4B90 {
    u16 a;
    u16 b;
};

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { short a, b; } Pos;

struct pair_021C4C88 {u16 a,b;};

extern Pos func_021C4AC4(void *);
extern Pos func_021C4AD0(void *);
extern Pos func_021C4A54(Pos, int);
extern int func_021C49A4(u8 *, u32);
extern u32 func_021C4914(u8 *p);
extern u8 *func_021C499C(void *, u16);
void func_021C4B7C(char *p, struct pair_021C4B7C v);
void func_021C4B90(char *p, struct pair_021C4B90 v);
u8 *func_021C4BA4(u8 *p, void *list, int n);
void func_021C4C88(char *p,char *q);


/*
 * Addresses are Black-image addresses.
 */
void func_021C4B7C(char *p, struct pair_021C4B7C v)
{
    ((struct Obj00535 *)p)->f4 = v.a;
    ((struct Obj00535 *)p)->f6 = v.b;
}


void func_021C4B90(char *p, struct pair_021C4B90 v)
{
    ((struct Obj00535 *)p)->f8 = v.a;
    ((struct Obj00535 *)p)->fA = v.b;
}

/*
 * extent: two zero alignment bytes at 0x021C4C86 follow the function.
 * lever: Pos declaration order src,a,dst,b fixes stack slots; named qid fixes cmp order.
 */
u8 *func_021C4BA4(u8 *p, void *list, int n)
{
    Pos src, a, dst, b;
    u32 count;
    int id;
    u32 i;
    u8 *q;
    int qid;
    src = func_021C4AC4(p);
    dst = func_021C4A54(src, n);
    id = func_021C49A4(p, 4);
    count = func_021C4914(list);
    for (i = 0; i < count; i++) {
        q = func_021C499C(list, i);
        if (q != 0) {
            qid = func_021C49A4(q, 4);
            if (qid == id) continue;
            a = func_021C4AC4(q);
            if (a.a == dst.a && a.b == dst.b) return q;
            b = func_021C4AD0(q);
            if (b.a == dst.a && b.b == dst.b) return q;
        }
    }
    return 0;
}

extern void (*d_021C601C)(char *,struct pair_021C4C88,unsigned);

void func_021C4C88(char *p,char *q)
{
 (*(void (**)(char *,struct pair_021C4C88,unsigned))((unsigned)&d_021C601C+*(u16 *)(q+4)*4))(p,*(struct pair_021C4C88 *)q,((struct Obj23042 *)q)->f6);
 ((struct Obj23041 *)p)->f16=0;
}
