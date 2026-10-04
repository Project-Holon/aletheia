/*
 * function: func_0202E474
 * address:  0x0202E474
 * packet:   pkt_0202E474
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_020A77C4  0x020A77C4  data
 *
 * Allocates and fills one record of a per-something description list,
 * followed by eight "read the sub-object" calls.  The fifth argument to
 * func_02030734 is the pool-relative caller tag (0x37 here, the same 0x3c/
 * 0x3d/0x83/0x84 tags in the neighbours are the same convention).
 *
 * Argument order of func_02082D44 is (src, dst, n): the original loads r1
 * with `p + 0x14` *before* r0 with a1, so r1 - the second slot - is the
 * destination.  Writing the copy as `func_02082D44(dst, src, n)` reverses the
 * two registers and costs seven bytes.
 *
 * The pool word 0x020A77C4 is a `string` site: it is the `__FILE__`-style
 * name run whose start is pinned by the terminator of the string before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E474.c \
 *       --func func_0202E474 --addr 0x0202E474 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
struct Big;
struct BigObj;
struct SaveBlock;
struct Sub02008700Obj;
extern void *func_02012EBC(struct Big *p);
extern void *func_02030734(unsigned int a0, unsigned int a1, int a2, const char *a3, unsigned short a4);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u8 *func_02012944(void *p);
extern int   func_02012924(int a0);
extern void *func_0201292C(const struct BigObj *p);
extern void  func_02082D44(void *src, void *dst, int n);
extern void *func_020127A4(struct SaveBlock *p);
typedef unsigned int   u32;
struct Rec44;
extern u32 func_02012B28(const struct Rec44 *p);

extern char data_020A77C4[];

void *func_0202E474(int a0, int a1, int a2, int a3)
{
    int   v = (int)func_02012EBC((struct Big *)a0);
    char *p = func_02030734(a3, 0x3c, 1, data_020A77C4, 0x37);

    *(int *)p = a0;
    *(int *)(p + 4) = (int)func_0200873C((void *)v);
    *(int *)(p + 8) = (int)func_02012944((void *)a0);
    *(int *)(p + 0xc) = func_02012924(a0);
    *(void **)(p + 0x10) = func_0201292C((const struct BigObj *)a0);
    if (a1 != 0) {
        func_02082D44((void *)a1, p + 0x14, 0x18);
    }
    *(int *)(p + 0x2c) = a2;
    *(int *)(p + 0x30) = func_02012B28(func_020127A4((struct SaveBlock *)a0)) == 1;
    return p;
}
