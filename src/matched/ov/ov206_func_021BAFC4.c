/*
 * function: func_021BAFC4
 * address:  0x021BAFC4
 * packet:   pkt_ov206_021BAFC4
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The shared zero is an enum-typed local initialised at declaration (not folded to
 * a literal), which yields the `adds r3, r4, #0` copy for the fourth argument of
 * the fifth BMP_Blit call.
 *
 * symbols:
 *   BMP_Delete  0x020437AC  arm
 *   BMP_CreateFromArchive  0x0204384C  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *
 * Addresses are Black-image addresses.
 */

typedef enum { ZERO } Zero;

typedef struct {
    unsigned short f0;
    char pad2[0x4d - 2];
    unsigned char f4d;
    char pad4e[0x8c - 0x4e];
    int f8c;
    int f90;
} Ent;

typedef unsigned int   u32;
struct Bmp;
struct Obj020437AC;
extern struct Bmp *BMP_CreateFromArchive(u32 arc, u32 member, u32 heap2, u32 heap);
extern int BMP_WIN_Create(int, int, int, int, int, int, int);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void BMP_Delete(struct Obj020437AC *p);

void func_021BAFC4(Ent *e)
{
    Zero z = ZERO;
    int s = (int)BMP_CreateFromArchive(0x9f, 0x19, z, e->f0);
    int q;

    e->f8c = BMP_WIN_Create(e->f4d, 0xc, 4, 4, 3, z, z);
    q = (int)func_02045770((struct Descriptor *)e->f8c);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 8, 0, z, z, 0x20, 0x18, z);

    e->f90 = BMP_WIN_Create(e->f4d, 0xc, 4, 4, 3, z, z);
    q = (int)func_02045770((struct Descriptor *)e->f90);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0xa8, 8, z, z, 0x20, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0xf8, 8, z, 8, 8, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0x28, 0x10, 8, 8, 0x18, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0x80, z, 0, 0x10, 8, 8, 0);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0x58, 0x10, 8, 0x10, 0x18, 8, z);

    BMP_Delete((struct Obj020437AC *)s);
}
