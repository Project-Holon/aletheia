/*
 * function: GIMMICK38_StartScriptedEvent
 * address: 0x021F41DC
 * packet: pkt_ov038_021F41DC
 * region: ov038
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   GIMMICK38_EventScripted 0x021F44C0 thumb ov038
 */
typedef unsigned int u32;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int *FIELDMAP_GetCommonWork(char *, int);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int GIMMICK38_EventScripted(void *, int *);
void *GIMMICK38_StartScriptedEvent(void *p, int v)
{
    unsigned char *s = (unsigned char *)FIELDMAP_GetCommonWork((char *)GAMESYSTEM_GetFieldMap(p), 1);
    s[2] = v;
    return func_020122C0(p, 0, GIMMICK38_EventScripted, 0);
}
