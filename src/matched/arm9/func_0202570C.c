/*
 * function: BMP_OAM_Delete
 * address:  0x0202570C
 * packet:   pkt_020255A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * bmp_oam.c.  Tears down the window grid: for every cell of the
 * rows x cols grid, releases the cell's two resources, then frees the
 * object itself.
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Grid {
    u32   pad_0;
    void *a[25];
    void *b[24];
    u8    pad_C8[2];
    u8    cols;
    u8    rows;
};

extern void CLACT_ReleaseCharacter(u32 i);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 func_020307B0(void *p);

void BMP_OAM_Delete(struct Grid *g)
{
    u8 i, j;

    for (i = 0; i < g->rows; i++) {
        for (j = 0; j < g->cols; j++) {
            CLACT_ReleaseCharacter((u32)g->b[j + i * g->cols]);
            CLACT_DeleteActor(g->a[j + i * g->cols]);
        }
    }
    func_020307B0(g);
}
