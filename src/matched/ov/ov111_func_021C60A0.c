/*
 * function: VIEWER_TEXT_Exit
 * address:  0x021C60A0
 * packet:   pkt_ov111_021C60A0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[4];
    void *bg[8];
    u8 pad24[0x32CC - 0x24];
    void *f32CC;
} Work;

struct Descriptor;
struct PrintSys;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);

void VIEWER_TEXT_Exit(Work *p)
{
    u16 i;

    PRINTSYS_QUE_Delete(p->f32CC);
    for (i = 0; i < 8; i++) {
        BMP_WIN_Delete(p->bg[i]);
    }
    BMP_WIN_Exit();
}
