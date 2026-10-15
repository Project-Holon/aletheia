/*
 * function: EL_SCOREBOARD_TeardownStandaloneDisplay
 * address:  0x0218793C
 * packet:   pkt_ov020_0218793C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *\n * symbols:\n *   func_020403F4  0x020403F4  arm\n *   BG_SYS_Delete  0x0203F9B4  arm\n */
extern void func_020403F4(unsigned int i);
extern void BG_SYS_Delete(void);

void EL_SCOREBOARD_TeardownStandaloneDisplay(char *p)
{
    func_020403F4(3);
    BG_SYS_Delete();
}
