/*
 * file:     fldeff_ripple_p10.c
 * unit:     yes
 * function: func_021C4788, func_021C47B4
 * address:  0x021C4788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F3758  0x021F3758  thumb  ov063
 *   ov063_id       0x0000003F  data
 *   func_021F376C  0x021F376C  thumb  ov063
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C90  0x02188C90  thumb  ov021
 *   func_021C47FC  0x021C47FC  thumb  ov021
 *   d_021DE468     0x021DE468  data  ov021
 */
struct Obj;
struct P;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct {
    void *owner;
    u32 obj;
    u32 f8;
} R;

typedef unsigned short u16;

void *func_020124E8(struct Obj *p);
extern void func_02034A5C(s32 handle);
extern int func_021F376C(int *p);
extern void func_021F3758(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C90(u8 *p);
extern void func_021C47FC(struct P *p);
int func_021C4788(void *t);
R *func_021C47B4(u8 *owner, u32 heap);
extern char ov063_id[];
extern char d_021DE468[];


/*
 * Task callback: when the ov063 effect reports done, frees it and unloads
 * ov063.
 * Callee witnesses filed in wave A1 (witness lane).
 */
int func_021C4788(void *t)
{
    void **w = func_020124E8(t);

    if (func_021F376C(*w) != 0) {
        func_021F3758(*w);
        func_02034A5C((u32)ov063_id);
        return 1;
    }
    return 0;
}


/*
 * Allocates the 0xC-byte field-object record and initialises it.
 */
R *func_021C47B4(u8 *owner, u32 heap)
{
    R *r = func_02030734(heap, 0xC, 1, d_021DE468, 0x56);

    r->owner = owner;
    r->obj = func_02188C90((u8 *)func_021ABE14(owner));
    func_021C47FC((struct P *)r);
    return r;
}
