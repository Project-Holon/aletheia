/*
 * function: BTL_CLIENT_FindSupportItem
 * address: 0x021CE8F0
 * packet: pkt_ov093_021CE8F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Six ordinary int offsets each receive 0x19a then 0x112;
 * a cached row pointer preserves their distinct stack homes and r5 base.
 * Reverse declarations and a full-word k local restore the spill order.
 * note 2026-10-05 (wave D9r lane 131): removed the 6 dead first assignments
 * (`invalid=0x19a;` before `invalid=0x112;`; `ok3=0x19a;` before
 * `ok3=0x112;` and 4 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetOwnOpponentClient 0x021B904C thumb ov093
 *   BTL_MAIN_GetTrainerId 0x021BA004 thumb ov093
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SIDE_GetClientPokeParam 0x021B990C thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_MAIN_GetPositionsPerClientThunk 0x021B99B8 thumb ov093
 *   TPOKE_DATA_FindRecord 0x0202A298 thumb
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_CALC_DivideMaxHp 0x021D7B60 thumb ov093
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_CountLiving 0x021B9B98 thumb ov093
 *   gBtlClientSupportItemKeys 0x021EFF78 data ov093 a2
 */
#include "../include/Obj03689.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { OFFSET = 0x19a } Off;
struct Offsets { Off skip,ok0,ok1,ok2,ok3,invalid; };
static inline void init_offset(Off *value)
{
    *value = OFFSET;
    *value -= 0x88;
}
extern void *BTL_MAIN_GetCompetitor(void ***);
struct Q1;
extern u8 BTL_MAIN_GetOwnOpponentClient(u8 *p, int k);
extern u16 BTL_MAIN_GetTrainerId(char *p, int i);
extern char *BTL_SIDE_GetSlotOfClient(char *,int);
extern void *BTL_SIDE_GetClientPokeParam(char *p, unsigned int i, unsigned int j);
extern int BTL_POKEPARAM_IsFainted(void *);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
extern u32 TPOKE_DATA_FindRecord(u32,u32,u32);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u32 BTL_CALC_DivideMaxHp(void *p, u32 b);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 BTL_SLOT_CountLiving(u8 *p);
extern const u16 gBtlClientSupportItemKeys[4];
u32 BTL_CLIENT_FindSupportItem(const u8 *p, u16 *out)
{
    u32 entry;
    int result;
    u32 count;
    u32 k;
    u32 key;
    u32 id, i;
    int a, b;
    u8 *mon;
    u8 *row;
    int skip,ok0,ok1,ok2,ok3,invalid;
    if ((u32)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj03689 *)p)->f0) != 1) goto fail;
    id = BTL_MAIN_GetOwnOpponentClient(((struct Obj03689 *)p)->f0,0);
    k = BTL_MAIN_GetTrainerId(((struct Obj03689 *)p)->f0,id);
    if (!k) goto fail;
    entry = (u32)BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj03689 *)p)->f4,id);
    mon = BTL_SIDE_GetClientPokeParam(((struct Obj03689 *)p)->f4,id,(u8)0);
    if (BTL_POKEPARAM_IsFainted(mon)) {
        count = BTL_MAIN_GetPositionsPerClientThunk(((struct Obj03689 *)p)->f0,id);
        for (i=1;i<count;i++) {
            mon = BTL_SIDE_GetClientPokeParam(((struct Obj03689 *)p)->f4,id,(u8)i);
            if (!BTL_POKEPARAM_IsFainted(mon)) break;
        }
    }
    result = -1;
    invalid=0x112;
    ok3=0x112;
    ok2=0x112;
    ok1=0x112;
    ok0=0x112;
    skip=0x112;
    for (i=0;i<4;i++) {
        row = (u8 *)p + i;
        if (!row[skip]) {
            key = gBtlClientSupportItemKeys[i];
            if (TPOKE_DATA_FindRecord(k,key,((struct Obj03689 *)p)->f19A)) {
                switch (key - 0x11) {
                case 1:
                    a = BTL_POKEPARAM_GetValue(mon,13);
                    if ((u32)a <= BTL_CALC_DivideMaxHp(mon,2)) { result = i; row[ok0] = 1; }
                    break;
                case 0:
                    if (!BTL_POKEPARAM_IsHpFull(mon)) { result = i; row[ok1] = 1; }
                    break;
                case 2:
                    if (BTL_SLOT_GetCount((void *)entry) > 1 && BTL_SLOT_CountLiving((u8 *)entry) == 1) { result = i; row[ok2] = 1; }
                    break;
                case 3:
                    if (BTL_SLOT_GetCount((void *)entry) > 1 && BTL_SLOT_CountLiving((u8 *)entry) == 1) {
                        b = BTL_POKEPARAM_GetValue(mon,13);
                        if ((u32)b <= BTL_CALC_DivideMaxHp(mon,2)) { result = i; row[ok3] = 1; }
                    }
                    break;
                }
            } else row[invalid] = 1;
        }
    }
    if (result >= 0) { *out = gBtlClientSupportItemKeys[result]; return 1; }
fail:
    return 0;
}
