/*
 * function: func_02047A60
 * address:  0x02047A60
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
 *   func_02047C8C   0x02047C8C  arm
 *   func_0206A9DC   0x0206A9DC  arm
 *   func_0206AA0C   0x0206AA0C  arm
 *   MI_Copy36B      0x02082B60  arm
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
extern void  func_02047C8C(void *p);
extern void  func_0206A9DC(void *p);
extern void  func_0206AA0C(VecFx32 *p);
extern void  MI_Copy36B(const void *src, void *dst);

void func_02047A60(void *a0, struct Arg *a1)
{
    void *r;

    r = func_0204755C(func_02047788(a0));
    func_0206A9DC(a1);
    MI_Copy36B(&a1->m18, g_02148C08);
    g_02148B4C[63] = g_02148B4C[63] & ~0xa4u;
    func_0206AA0C(&a1->v0c);
    g_02146A5C->f88();
    func_02047C8C(r);
}
