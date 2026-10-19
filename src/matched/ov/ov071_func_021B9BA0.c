/*
 * unit:     yes
 * function: MONOLITH_TOOL_LIST_FreeBackButton, MONOLITH_TOOL_LIST_UpdateBackButton
 * address:  0x021B9BA0
 * packet:   pkt_ov071_021B9BA0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two thunks advancing a pointer by 8.
 *
 * symbols:
 *   MONOLITH_TOOL_FreeButton  0x021B6B38  thumb  ov071
 *   MONOLITH_TOOL_IsButtonUploaded  0x021B6B70  thumb  ov071
 */

void MONOLITH_TOOL_LIST_FreeBackButton(void *p)
{
    void MONOLITH_TOOL_FreeButton(void **p);
    MONOLITH_TOOL_FreeButton((void **)((char *)p + 8));
}

typedef unsigned char  u8;
void MONOLITH_TOOL_LIST_UpdateBackButton(void *p, int a)
{
    int MONOLITH_TOOL_IsButtonUploaded(void **p, u8 *q);
    MONOLITH_TOOL_IsButtonUploaded(p, (u8 *)(a + 8));
}
