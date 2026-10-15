/*
 * function: func_021BDDF8
 * address:  0x021BDDF8
 * packet:   pkt_021BDDF8
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(u8 *, u32, u32);

void func_021BDDF8(u8 *p)
{
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p, 0, 4);
}

