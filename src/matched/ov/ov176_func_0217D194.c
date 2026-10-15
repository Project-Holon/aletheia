/*
 * function: DIGITALCARDCHECK_IsWorkDone
 * address: 0x0217D194
 * packet: pkt_ov176_0217D194
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: 12-byte tail stub before labelled 0217D1A0.
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_StepMainWindowIdle 0x021E65FC thumb ov177
 */
typedef struct Work Work;
extern int WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(Work *);
int DIGITALCARDCHECK_IsWorkDone(int *p)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle((Work *)p[4]);
}
