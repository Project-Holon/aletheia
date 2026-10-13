/*
 * unit:     yes
 * function: FIELD_FLASH_CmdShowExpanded, FIELD_FLASH_CmdHide
 * address:  0x021C7F44
 * packet:   pkt_ov021_021C7F44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   FIELD_FLASH_SetTweenSize  0x021C7EF0  thumb  ov021
 *   FIELD_FLASH_SetTweenAlpha  0x021C7EF8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern void FIELD_FLASH_SetTweenSize(u8 *p, u32 v);
extern u8 *FIELD_FLASH_SetTweenAlpha(u8 *p, u8 v);
void FIELD_FLASH_CmdHide(M *m);
void FIELD_FLASH_CmdShowExpanded(M *m)
{
    m->f1C = 3;
    FIELD_FLASH_SetTweenSize(m->sub, 0xaa00);
    FIELD_FLASH_SetTweenAlpha(m->sub, 0x1f);
}

void FIELD_FLASH_CmdHide(M *m)
{
    m->f1C = 0;
    FIELD_FLASH_SetTweenSize(m->sub, 0);
}
