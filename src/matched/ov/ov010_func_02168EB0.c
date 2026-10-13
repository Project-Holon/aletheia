/*
 * function: func_02168EB0
 * address: 0x02168EB0
 * packet: pkt_ov010_02168EB0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * former blocker: pooled ov220_id is passed to func_02012444 r1, missing from
 * OVERLAY_ID_CONSUMERS. Its matched body stores a1 to payload[0]; matched
 * GAME_EVENT_CallProcSeq forwards item[0] as GAMESYSTEM_CallProc r1 (known consumer).
 * The ov220 table hint is supported by that load chain; matcher refuses
 * it as contested until the ID site resolves. No code leaf blocks this.
 * symbols:
 *   func_020124E8 0x020124E8 thumb
 *   func_02012444 0x02012444 thumb
 *   d_021BA39C 0x021BA39C data ov220 a4
 *   ov220_id 0x000000DC data
 
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern const unsigned int d_021BA39C[];
extern unsigned char ov220_id[];
int func_02168EB0(void *a, int *state)
{
    u8 *p;
    p = func_020124E8(a);
    switch (*state) {
    case 0:
        func_02012444(a, (unsigned int)ov220_id, (unsigned int)d_021BA39C, (unsigned int)(p + 8));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
