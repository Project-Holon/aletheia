/*
 * function: INTRUDE_SUBDISP_CreateGuideScriptEvent
 * address: 0x0217CDBC
 * packet: pkt_ov018_0217CDBC
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   INTRUDE_SUBDISP_GuideScriptEventMain 0x0217CDD0 thumb ov018
 */
extern int INTRUDE_SUBDISP_GuideScriptEventMain(void *, int *);
typedef unsigned int   u32;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *INTRUDE_SUBDISP_CreateGuideScriptEvent(void *p)
{
    return func_020122C0(p, 0, INTRUDE_SUBDISP_GuideScriptEventMain, 0);
}
