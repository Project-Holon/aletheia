/*
 * unit:     yes
 * function: C_GEAR_ClearTabTimerCount, C_GEAR_GetTabTimerCount, C_GEAR_SetTabTimerRunning
 * address:  0x021F0D00
 * packet:   pkt_021F0D00
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void C_GEAR_ClearTabTimerCount(unsigned short *p, int i)
{
    p[i] = 0;
}

unsigned short C_GEAR_GetTabTimerCount(unsigned short *p, int i)
{
    return p[i];
}

void C_GEAR_SetTabTimerRunning(char *p, char v)
{
    p[9] = v;
}
