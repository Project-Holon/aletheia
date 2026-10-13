/*
 * function: EVENTDATA_SYSTEM_GetHiddenItemTable
 * address:  0x0216476C
 * packet:   pkt_ov010_0216476C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HiddenItemTable 0x02171534 data ov010 a4
 */

extern char HiddenItemTable[];

char *EVENTDATA_SYSTEM_GetHiddenItemTable(unsigned short *n)
{
    *n = 0xB1;
    return HiddenItemTable;
}
