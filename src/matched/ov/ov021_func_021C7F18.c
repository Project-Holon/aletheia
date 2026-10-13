/*
 * function: FIELD_FLASH_CmdExpand
 * address:  0x021C7F18
 * packet:   pkt_ov021_021C7F18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_020307B0  0x020307B0  arm
 *   FIELD_FLASH_StartTween  0x021C7E70  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern int FIELD_FLASH_StartTween(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
void FIELD_FLASH_CmdExpand(M *m)
{
    m->f1C = 2;
    FIELD_FLASH_StartTween((u32)m->sub, 0x3000, 0xaa00, 0x1f, 0x1f, 0xf);
    GFL_USE_PlaySeDefaultVolume(0x767);
}
