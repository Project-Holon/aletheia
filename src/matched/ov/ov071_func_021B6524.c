/*
 * unit:     yes
 * function: MONOLITH_TOOL_DeleteBg, MONOLITH_TOOL_InitBmpWin, MONOLITH_TOOL_ExitBmpWin
 * address:  0x021B6524
 * packet:   pkt_ov071_021B6524
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three ARM9 thunks that share a literal-pool tail-call shape.
 *
 * symbols:
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 */

void MONOLITH_TOOL_DeleteBg(void)
{
    void BG_SYS_Delete(void);
    BG_SYS_Delete();
}

typedef unsigned short u16;
void MONOLITH_TOOL_InitBmpWin(void)
{
    void BMP_WIN_Init(u16 heapId);
    BMP_WIN_Init(0x61);
}

void MONOLITH_TOOL_ExitBmpWin(void)
{
    void BMP_WIN_Exit(void);
    BMP_WIN_Exit();
}
