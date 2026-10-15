/*
 * function: MANUAL_CATEGORY_CreateDetailList
 * address: 0x021BB854
 * packet: pkt_ov225_021BB854
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD6 lane16): EXACT. Fixes: arm A flag is an enum-valued ternary (ra != 0) ? FLAG_FALSE : FLAG_TRUE
 *   (the int ternary is normalised to bne/movs 1); `int g` declared first, then `u16 ca, cb` (slots cb 8, ca 0xc, g 0x10);
 *   the f14/f16 stores written at the end of each arm (tail-merged), so the data reload stays after them.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   MANUAL_COMMON_GetEntryCount 0x021B9C20 thumb ov225
 *   MANUAL_COMMON_GetGroupValue1 0x021B9C34 thumb ov225
 *   MANUAL_COMMON_GetGroupValue2 0x021B9C40 thumb ov225
 *   MANUAL_COMMON_GetEntryValue1 0x021B9BD4 thumb ov225
 *   MANUAL_COMMON_CheckUnlocked 0x021B9C58 thumb ov225
 *   MANUAL_COMMON_GetEntryValue2 0x021B9BE0 thumb ov225
 *   MANUAL_COMMON_GetSaveValue 0x021B9C98 thumb ov225
 *   MANUAL_COMMON_GetEntryValue0 0x021B9BC8 thumb ov225
 *   MANUAL_COMMON_CreateListWork 0x021BA65C thumb ov225
 *   MANUAL_CATEGORY_DetailTaskNoop 0x021BBA70 thumb ov225
 *   gManualCategoryDetailAllocFile 0x021BC05C data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void *func_020056A0(unsigned, unsigned, unsigned);
struct Data;
extern u16 MANUAL_COMMON_GetEntryCount(const char *p);
extern u16 MANUAL_COMMON_GetGroupValue1(char *, int);
extern u16 MANUAL_COMMON_GetGroupValue2(char *, int, int);
extern u16 MANUAL_COMMON_GetEntryValue1(char *, int);
extern int MANUAL_COMMON_CheckUnlocked(void *, int, void *);
extern u16 MANUAL_COMMON_GetEntryValue2(char *, int);
extern int MANUAL_COMMON_GetSaveValue(void *, int, int);
extern u16 MANUAL_COMMON_GetEntryValue0(char *, int);
extern void *MANUAL_COMMON_CreateListWork(char *owner, struct Data *data);
extern void MANUAL_CATEGORY_DetailTaskNoop(void);
extern const char gManualCategoryDetailAllocFile[];
typedef struct Owner { u32 f0; u16 f4; u16 f6; u16 f8; } Owner;
typedef struct Data { void *f0; u16 f4; char pad6[0x26]; char *f2C; } Data;
typedef struct Q { Owner *f0; Data *f4; u32 f8; u16 fC; char padE[2]; char *f10; u16 f14; u16 f16; char pad18[4]; char *f1C; void *f20; } Q;
typedef enum { FLAG_FALSE, FLAG_TRUE } Flag;
Q *MANUAL_CATEGORY_CreateDetailList(Owner *p, Data *data)
{
    Q *q;
    u32 t, t0;
    int g;
    u16 ca, cb;
    int ra, rb;
    q = func_02030734(data->f4, 0x24, 1, gManualCategoryDetailAllocFile, 0x61);
    q->f0 = p;
    *(u32 *)((char *)p + 0xC) = 0;
    *(u16 *)((char *)q->f0 + 0x10) = 0;
    q->f4 = data;
    t0 = q->f0->f0;
    if (t0 == 0) {
        q->f8 = 1;
        g = q->f0->f4;
        ca = MANUAL_COMMON_GetGroupValue1(q->f4->f2C, g);
        q->fC = 0;
        q->f10 = func_02030734(q->f4->f4, ca * 8, 1, gManualCategoryDetailAllocFile, 0x79);
        {
            u16 i;
        for (i = 0; i < ca; i++) {
            u16 id;
            int id2;
            id = MANUAL_COMMON_GetGroupValue2(q->f4->f2C, g, i);
            id2 = MANUAL_COMMON_GetEntryValue1(q->f4->f2C, id);
            if (MANUAL_COMMON_CheckUnlocked(q->f4->f2C, id2, q->f4->f0)) {
                t = MANUAL_COMMON_GetEntryValue2(q->f4->f2C, id);
                ra = MANUAL_COMMON_GetSaveValue(q->f4->f2C, t, (int)q->f4->f0);
                *(u16 *)(q->f10 + q->fC * 8) = id;
                *(u16 *)(q->f10 + q->fC * 8 + 2) = MANUAL_COMMON_GetEntryValue0(q->f4->f2C, id);
                *(u32 *)(q->f10 + q->fC * 8 + 4) = (ra != 0) ? FLAG_FALSE : FLAG_TRUE;
                q->fC += 1;
            }
        }
        }
        q->f14 = *(u16 *)((char *)q->f0 + 6);
        q->f16 = *(u16 *)((char *)q->f0 + 8);
    } else {
        q->f8 = 1;
        cb = MANUAL_COMMON_GetEntryCount(q->f4->f2C);
        q->fC = 0;
        q->f10 = func_02030734(q->f4->f4, cb * 8, 1, gManualCategoryDetailAllocFile, 0xB2);
        {
            u16 i;
        for (i = 0; i < cb; i++) {
            int id;
            id = MANUAL_COMMON_GetEntryValue1(q->f4->f2C, i);
            if (MANUAL_COMMON_CheckUnlocked(q->f4->f2C, id, q->f4->f0)) {
                t = MANUAL_COMMON_GetEntryValue2(q->f4->f2C, i);
                rb = MANUAL_COMMON_GetSaveValue(q->f4->f2C, t, (int)q->f4->f0);
                *(u16 *)(q->f10 + q->fC * 8) = i;
                *(u16 *)(q->f10 + q->fC * 8 + 2) = MANUAL_COMMON_GetEntryValue0(q->f4->f2C, i);
                {
                    u32 fl = 0;
                    if (rb == 0)
                        fl = 1;
                    *(u32 *)(q->f10 + q->fC * 8 + 4) = fl;
                }
                q->fC += 1;
            }
        }
        }
        q->f14 = *(u16 *)((char *)q->f0 + 6);
        q->f16 = *(u16 *)((char *)q->f0 + 8);
    }
    q->f1C = MANUAL_COMMON_CreateListWork((char *)q + 8, (struct Data *)data);
    q->f20 = func_020056A0((unsigned)MANUAL_CATEGORY_DetailTaskNoop, (unsigned)q, 1);
    return q;
}
