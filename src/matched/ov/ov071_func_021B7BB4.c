/*
 * function: MONOLITH_TOOL_SLOT_SELECT_UpdateButtons
 * address: 0x021B7BB4
 * packet: pkt_ov071_021B7BB4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MONOLITH_TOOL_UpdateHighlight 0x021B6C7C thumb ov071
 *   MONOLITH_TOOL_IsButtonUploaded 0x021B6B70 thumb ov071
 */

typedef unsigned char  u8;
extern void MONOLITH_TOOL_UpdateHighlight(int *p, int idx);
extern int MONOLITH_TOOL_IsButtonUploaded(void **p, u8 *q);
void MONOLITH_TOOL_SLOT_SELECT_UpdateButtons(int *a,char *p) { int i; MONOLITH_TOOL_UpdateHighlight(a,3); p+=0x2c; for(i=0;i<2;i++) MONOLITH_TOOL_IsButtonUploaded((void **)a[1],(u8 *)(p+i*16)); }
