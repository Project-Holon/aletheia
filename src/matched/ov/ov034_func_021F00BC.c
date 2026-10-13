/*
 * function: REPORT_StartSaveAnim
 * address:  0x021F00BC
 * packet:   pkt_ov034_021F00BC
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REPORT_StartSaveAnim 0x021F00BC thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */

typedef unsigned char  u8;
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void REPORT_StartSaveAnim(int *p)
{
    int h = p[0x11];
    unsigned int i;

    BMP_WIN_ClearScreen((struct Descriptor *)h);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    for (i = 6; i <= 15; i++)
        CLACT_SetActorDrawEnable((struct Obj *)p[0x15 + i], 1);
    p[0x44] = 1;
}
