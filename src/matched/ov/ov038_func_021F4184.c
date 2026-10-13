/*
 * function: GIMMICK38_StartSwitchEvent
 * address: 0x021F4184
 * packet: pkt_ov038_021F4184
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
 *   GIMMICK38_EventPressSwitch 0x021F4200 thumb ov038
 */
typedef unsigned int u32;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int *FIELDMAP_GetCommonWork(char *, int);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int GIMMICK38_EventPressSwitch(int, int *);
void *GIMMICK38_StartSwitchEvent(void *p, int v)
{
    unsigned char *s = (unsigned char *)FIELDMAP_GetCommonWork((char *)GAMESYSTEM_GetFieldMap(p), 1);
    if (v >= 8) return 0;
    s[0] = v;
    return func_020122C0(p, 0, GIMMICK38_EventPressSwitch, 0);
}
