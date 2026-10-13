/*
 * function: STARTMENU_CaptureRunTasks
 * address:  0x021B99E0
 * packet:   pkt_021B99E0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_Main  0x020310C4  arm
 */

struct Tcbl;
void TCBL_Main(struct Tcbl *p);

void STARTMENU_CaptureRunTasks(int *p)
{
    TCBL_Main((struct Tcbl *)p[0]);
}
