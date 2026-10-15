/*
 * function: FIELD_MSGBG_DeleteWindow
 * address:  0x02193130
 * packet:   pkt_02193130
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

int FIELD_MSGBG_DeleteWindow(struct Descriptor *a)
{
BMP_MENUWORK_DrawWindowBorder((void *)a, 0);
return BMP_WIN_Delete(a);
}

