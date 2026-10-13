/*
 * function: INTRUDE_SUBDISP_GuideScriptEventMain
 * address: 0x0217CDD0
 * packet: pkt_ov018_0217CDD0
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_SYS_CallScriptEvent 0x02158780 thumb ov010
 */
typedef unsigned short u16;
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
int INTRUDE_SUBDISP_GuideScriptEventMain(void *p, int *state)
{
    switch (*state) {
    case 0:
        SCRIPT_SYS_CallScriptEvent(p, 0x279e, 0, 0, 0x15);
        ++*state;
        break;
    case 1:
        return 1;
    }
    return 0;
}
