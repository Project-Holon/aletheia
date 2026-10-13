/*
 * function: SCRIPT_WORK_SetTargetObj
 * address: 0x02158F94
 * packet: pkt_ov010_02158F94
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_GetLocalWork 0x02158FD0 thumb ov010
 *   FLDMMDL_GetObjId 0x0216D588 thumb ov010
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern int SCRIPT_WORK_GetLocalWork(int a0, u32 a1, int a2);
extern u16 FLDMMDL_GetObjId(void *);
void SCRIPT_WORK_SetTargetObj(void *p, void *q, int a2)
{
    *(void **)((char *)p + 8) = q;
    if (q != 0) {
        u16 *r = (u16 *)SCRIPT_WORK_GetLocalWork((int)p, 0x8011, a2);
        *r = FLDMMDL_GetObjId(q);
    }
}
