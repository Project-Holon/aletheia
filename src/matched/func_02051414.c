/*
 * function: func_02051414
 * address:  0x02051414
 * packet:   pkt_02051414
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A159C      0x020A159C  data
 *   g_02148B4C      0x02148B4C  data
 *   g_02148B98      0x02148B98  data
 *   g_02148C08      0x02148C08  data
 *   func_020467EC   0x020467EC  arm
 *   func_02046858   0x02046858  arm
 *   func_02046AFC   0x02046AFC  arm
 *   func_02046B40   0x02046B40  arm
 *   func_020479D8   0x020479D8  arm
 *   func_02048AD0   0x02048AD0  arm
 *   func_020526A8   0x020526A8  arm
 *   func_0206A9DC   0x0206A9DC  arm
 *   func_0206AA0C   0x0206AA0C  arm
 *   func_0206DB80   0x0206DB80  arm
 *   MI_Copy36B      0x02082B60  arm
 *   MTX_Identity33_ 0x0207ADC4  arm
 *
 * particle.c, the 3D setup half of a two-phase emitter pass (wave 13).  When
 * the private block at +0x20 exists: bring up the two frame objects (0x20 and
 * 0x24 bytes), copy the model vector 0x020A159C into a local, build an
 * identity 3x3, zero a vector for func_0206A9DC, copy the 3x3 to the
 * 0x02148C08 scratch, clear bits 0xa4 of word 63 of 0x02148B4C and hand the
 * model vector to func_0206AA0C; then the shared call func_020526A8 and, when
 * the block is still there, the teardown.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02051414.c.txt had it at 152 bytes out,
 * 220 against 224): the three setup-only locals are declared in a NESTED
 * BLOCK with INITIALISERS -- `VecFx32 v = g_020A159C; MtxFx33 m;
 * VecFx32 z = {0, 0, 0};`.  The aggregate initialiser `{0, 0, 0}` is what
 * keeps &z in a callee-saved register (r6) and stores the zero through it,
 * which costs the image's extra r7 (&v) and the push of r3/r7.  Assigning the
 * three fields, a pointer local, an inline VEC_Set, a compound literal and
 * the same locals in the if-block without initialisers all stay at 152 out.
 *
 * g_020A159C resolves through sole-ref/self (its only pool word is inside
 * this function; the ROM word equals the relocation), func_020526A8 through
 * sole-ref/code.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 x, y, z;
} VecFx32;

typedef struct {
    u32 m[9];
} MtxFx33;

typedef struct {
    u32 w[8];
} Blk32;

typedef struct {
    u32 w[9];
} Blk36;

extern VecFx32  g_020A159C;
extern u32      g_02148B4C[];
extern u32      g_02148B98[];
extern u32      g_02148C08[];

extern void func_020467EC(Blk32 *p);
extern void func_02046858(Blk32 *p);
extern void func_02046AFC(Blk36 *p);
extern void func_02046B40(Blk36 *p);
extern void func_020479D8(void);
extern void func_02048AD0(u32 a);
extern void func_020526A8(u32 a, void *b);
extern void func_0206A9DC(void *p);
extern void func_0206AA0C(VecFx32 *p);
extern void func_0206DB80(void);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_Identity33_(MtxFx33 *p);

void func_02051414(u8 *a0)
{
    Blk32    b;
    Blk36    g;

    if (*(u32 *)(a0 + 0x20) != 0) {
        func_020467EC(&b);
        func_02046AFC(&g);
        {
            VecFx32  v = g_020A159C;
            MtxFx33  m;
            VecFx32  z = {0, 0, 0};
            MTX_Identity33_(&m);
            func_0206A9DC(&z);
            MI_Copy36B(&m, g_02148C08);
            g_02148B4C[63] = g_02148B4C[63] & ~0xa4u;
            func_0206AA0C(&v);
        }
        func_02048AD0(*(u32 *)(a0 + 0x20));
        func_020479D8();
        func_0206DB80();
    }
    func_020526A8(*(u32 *)a0, g_02148B98);
    if (*(u32 *)(a0 + 0x20) == 0)
        return;
    func_02046858(&b);
    func_02046B40(&g);
    func_020479D8();
    func_0206DB80();
}
