/*
 * function: GF_FONT_Delete
 * address:  0x0201D83C
 * packet:   pkt_0201D83C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GF_FONT_ExitFormat  0x0201DADC  thumb
 *   GF_FONT_FreeBuffers  0x0201D9C8  thumb
 *   func_020307B0  0x020307B0  arm
 */

struct Font;
extern void GF_FONT_ExitFormat(struct Font *f);
extern void GF_FONT_FreeBuffers(struct Font *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

u32 GF_FONT_Delete(void *ptr)
{
    GF_FONT_ExitFormat(ptr);
    GF_FONT_FreeBuffers(ptr);
    return func_020307B0(ptr);
}
