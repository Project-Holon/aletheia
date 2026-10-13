/*
 * function: FLD_BTL_INST_TOOL_DrawTrainerParty
 * address:  0x02168924
 * packet:   pkt_ov010_02168924
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws `count` distinct battle-facility Pokemon from an a/2/1/5 group
 * list (FLD_BTL_INST_TOOL_LoadTrainerGroup's record): no repeated species, none of the
 * excluded species, and for the first 50 tries no repeated or excluded
 * held item. Builds each one with FLD_BTL_INST_TOOL_BuildBattleMon under one random trainer
 * id and optionally reports the first two draws. Returns 1 when the
 * item rule had to be dropped.
 *
 * Levers: locals declared in reverse of their frame order (the arrays
 * after natures, the scalars from otId down), the IV step as u8 (its
 * reader returns only constants up to 31), and a 16-bit `rank` parameter,
 * which moves the r1 spill ahead of the r3 copy (u8 matches equally; int
 * and u32 are 4 bytes out).
 *
 * symbols:
 *   FLD_BTL_INST_TOOL_GetRandomU16  0x02168824  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   FLD_BTL_INST_TOOL_ReadMonData  0x02168800  thumb  ov010
 *   FLD_BTL_INST_TOOL_GetIvForRank  0x0216883C  thumb  ov010
 *   FLD_BTL_INST_TOOL_BuildBattleMon  0x021684E8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct FacRec {
    u16 species;        /* 0x00 */
    u16 moves[4];       /* 0x02 */
    u8 evMask;          /* 0x0A */
    u8 nature;          /* 0x0B */
    u16 item;           /* 0x0C */
    u16 form;           /* 0x0E */
} FacRec;

typedef struct FacGroup {
    u16 id;             /* 0x00 */
    u16 count;          /* 0x02 */
    u16 members[1];     /* 0x04 */
} FacGroup;

typedef struct FacDraw {
    u32 otId;           /* 0x00 */
    u16 ids[2];         /* 0x04 */
    u32 pids[2];        /* 0x08 */
    u8 natures[2];      /* 0x10 */
} FacDraw;

typedef struct BattleMon {
    u8 data[0x3C];
} BattleMon;

extern int FLD_BTL_INST_TOOL_GetRandomU16(void);
extern void FLD_BTL_INST_TOOL_ReadMonData(void *dst, u32 member);
extern u8 FLD_BTL_INST_TOOL_GetIvForRank(u32 n);
extern u32 FLD_BTL_INST_TOOL_BuildBattleMon(BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);

int FLD_BTL_INST_TOOL_DrawTrainerParty(FacGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, FacDraw *draw, u16 heap)
{
    u8 natures[4];
    int ids[4];
    u32 pids[4];
    FacRec other;
    FacRec rec;
    u32 otId;
    u8 iv;
    int id;
    int tries;
    int fail;
    int i;
    int n;

    fail = 0;
    tries = 0;
    n = 0;
    while (n != count) {
        id = group->members[(u8)(FLD_BTL_INST_TOOL_GetRandomU16() % group->count)];
        FLD_BTL_INST_TOOL_ReadMonData(&rec, id);
        for (i = 0; i < n; i++) {
            FLD_BTL_INST_TOOL_ReadMonData(&other, ids[i]);
            if (other.species == rec.species)
                break;
        }
        if (i != n)
            continue;
        if (exclSpecies != 0) {
            for (i = 0; i < count; i++) {
                if (rec.species == exclSpecies[i])
                    break;
            }
            if (i != count)
                continue;
        }
        if (tries < 50) {
            for (i = 0; i < n; i++) {
                FLD_BTL_INST_TOOL_ReadMonData(&other, ids[i]);
                if (other.item != 0 && other.item == rec.item)
                    break;
            }
            if (i != n) {
                tries++;
                continue;
            }
            if (exclItems != 0) {
                for (i = 0; i < count; i++) {
                    if (rec.item == exclItems[i] && exclItems[i] != 0)
                        break;
                }
                if (i != count) {
                    tries++;
                    continue;
                }
            }
        }
        ids[n] = id;
        natures[n] = rec.nature;
        n++;
    }

    iv = FLD_BTL_INST_TOOL_GetIvForRank(rank);
    otId = FLD_BTL_INST_TOOL_GetRandomU16() | (FLD_BTL_INST_TOOL_GetRandomU16() << 16);
    if (tries >= 50)
        fail = 1;
    for (i = 0; i < n; i++)
        pids[i] = FLD_BTL_INST_TOOL_BuildBattleMon(&mons[i], (u16)ids[i], otId, 0, iv, i, fail, heap);
    if (draw == 0)
        return fail;
    draw->otId = otId;
    for (i = 0; i < 2; i++) {
        draw->ids[i] = ids[i];
        draw->pids[i] = pids[i];
        draw->natures[i] = natures[i];
    }
    return fail;
}
