/*
 * function: func_021BD11C
 * address:  0x021BD11C
 * packet:   pkt_021BD11C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_Exit  0x02046788  arm  arm9
 *   G3D_CAMERA_Delete  0x02048AC4  arm  arm9
 *   (none)
 *
 * Loads the word at [p], then calls the ARM9 functions at 0x02048AC4 and 0x02046788.
 */

typedef unsigned int   u32;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);

void func_021BD11C(int *p)
{
    G3D_CAMERA_Delete((void *)(*p));
    G3D_SYSTEM_Exit();
}
