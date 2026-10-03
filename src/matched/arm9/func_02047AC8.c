/*
 * function: func_02047AC8
 * address:  0x02047AC8
 * packet:   pkt_020479D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A5C      0x02146A5C  data
 *   g_02148B4C      0x02148B4C  data
 *   g_02148C08      0x02148C08  data
 *   func_02047788   0x02047788  arm
 *   func_0204755C   0x0204755C  arm
 *   func_02047B4C   0x02047B4C  arm
 *   func_02047C8C   0x02047C8C  arm
 *   func_0206A9DC   0x0206A9DC  arm
 *   func_0206AA0C   0x0206AA0C  arm
 *   MI_Copy36B      0x02082B60  arm
 *
 * The sibling of func_02047A60 with a result: the same bring-up (the two
 * sub-objects of the argument at +0xC and +0x18, the `bic 0xa4` on word 63
 * of 0x02148B4C, the context's +0x88 callback) and then func_02047B4C,
 * whose value is returned and whose `== 1` gates the func_02047C8C release.
 *
 * NOTE ON func_02047B4C's ARITY.  src/matched/func_02047B4C.c declares it
 * `int func_02047B4C(void)` and is EXACT that way; here it must be declared
 * as taking one pointer, because the original saves this function's own
 * first argument in r5 across the whole body purely to set r0 before the
 * call (+0x0008 `mov r5, r0`, +0x0054 `mov r0, r5`).  A `void` declaration
 * drops those two instructions and the function comes out eight bytes
 * short.  The callee ignoring r0 is consistent with both files being exact:
 * the argument is passed and unused.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct { u32 x, y, z; } VecFx32;
typedef struct { u32 m[9]; } MtxFx33;

struct Arg {
    u8      pad_00[0x0C];
    VecFx32 v0c;
    MtxFx33 m18;
};

struct Ctx { u8 pad_00[0x88]; void (*f88)(void); };

extern struct Ctx *g_02146A5C;
extern u32 g_02148B4C[];
extern u32 g_02148C08[];

extern void *func_02047788(void *p);
extern void *func_0204755C(void *p);
extern int   func_02047B4C(void *p);
struct P02047C8C;
extern void func_02047C8C(struct P02047C8C *p);
extern void  func_0206A9DC(void *p);
extern void  func_0206AA0C(VecFx32 *p);
extern void  MI_Copy36B(const void *src, void *dst);

int func_02047AC8(void *a0, struct Arg *a1)
{
    void *r;
    int   s;

    r = func_0204755C(func_02047788(a0));
    func_0206A9DC(a1);
    MI_Copy36B(&a1->m18, g_02148C08);
    g_02148B4C[63] = g_02148B4C[63] & ~0xa4u;
    func_0206AA0C(&a1->v0c);
    g_02146A5C->f88();
    s = func_02047B4C(a0);
    if (s == 1)
        func_02047C8C(r);
    return s;
}
