/*
 * function: func_02207288
 * address: 0x02207288
 * packet: pkt_ov094_02207288
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0220742E..02207430 is two zero alignment bytes.
 * lever: rows are an array member of the object; raw offset casts gave 416 bytes and the wrong field-base spills, while the member form gives exact 422 bytes.
 * symbols:
 *   MIi_CpuClear16 0x02082A48 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_GetExpForLevel 0x02018584 thumb
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   POKE_TOOL_GetStatusCondition 0x02017F90 thumb
 *   BTLV_GAUGE_SetStatusIcon 0x02208814 thumb ov094
 *   BTLV_GAUGE_PlaceSlot 0x022079C0 thumb ov094
 *   BTLV_GAUGE_SetSlotBarsVisible 0x02208D50 thumb ov094
 *   func_0220793C 0x0220793C thumb ov094
 *   func_0220785C 0x0220785C thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct O O;
typedef struct { char pad[0x40]; u32 mode, side, a, b, f90, f94, f98, f9c, fa0, fa4, fa8; u8 level, sex, fae, seen; u32 flags, fb4, fb8, fbc; } Row;
typedef struct W { char pad[0x40]; Row rows[8]; } W;
typedef struct S S;
typedef struct { short x, y; } Pt;
extern void MIi_CpuClear16(u32, void *, u32);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u32 POKE_TOOL_GetExpForLevel(u16, u16, u16);
struct Blk37;
extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id);
extern u8 POKE_TOOL_GetGender(void *);
extern u32 POKE_TOOL_GetStatusCondition(void *);
extern void BTLV_GAUGE_SetStatusIcon(struct O *obj, int k, int idx);
extern void BTLV_GAUGE_PlaceSlot(char *, int, Pt *);
extern void BTLV_GAUGE_SetSlotBarsVisible(W *, int, int);
extern void func_0220793C(char *p);
extern void func_0220785C(struct O *o, int unused, int idx, void *data);
void func_02207288(W *p, void *a, void *q, int mode, int i)
{
    u32 x, y, exp;
    u16 species;
    MIi_CpuClear16(0, &p->rows[i].mode, 0x40);
    p->rows[i].a = POKE_TOOL_GetPartyValue(q, 0xa0, 0);
    p->rows[i].b = POKE_TOOL_GetPartyValue(q, 0xa1, 0);
    p->rows[i].f90 = 0x80000000;
    p->rows[i].fa8 = 0;
    p->rows[i].level = POKE_TOOL_GetPartyValue(q, 0x9e, 0);
    p->rows[i].mode = mode;
    p->rows[i].side = i & 1;
    p->rows[i].flags |= 0x08000000;
    if (p->rows[i].level < 100) {
        x = POKE_TOOL_GetPartyValue(q, 5, 0);
        y = POKE_TOOL_GetPartyValue(q, 0x6f, 0);
        exp = POKE_TOOL_GetExpForLevel(x, y, p->rows[i].level);
        p->rows[i].f94 = POKE_TOOL_GetPartyValue(q, 8, 0) - exp;
        p->rows[i].f98 = POKE_TOOL_GetExpForLevel(x, y, p->rows[i].level + 1) - exp;
    } else {
        p->rows[i].f94 = 0;
        p->rows[i].f98 = 0;
    }
    p->rows[i].fa4 = 0x80000000;
    p->rows[i].fa0 = 0;
    p->rows[i].fae = 0;
    species = POKE_TOOL_GetPartyValue(q, 5, 0);
    p->rows[i].seen = ZUKAN_SAVE_IsCaught(a, species);
    if (species != 32 && species != 29)
        p->rows[i].sex = POKE_TOOL_GetGender(q);
    else
        p->rows[i].sex = 2;
    BTLV_GAUGE_SetStatusIcon((O *)p, POKE_TOOL_GetStatusCondition(q), i);
    BTLV_GAUGE_PlaceSlot((char *)p, i, 0);
    BTLV_GAUGE_SetSlotBarsVisible((W *)p, i, 1);
    func_0220793C((char *)((S *)&p->rows[i]));
    func_0220785C((struct O *)p, mode, i, q);
}
