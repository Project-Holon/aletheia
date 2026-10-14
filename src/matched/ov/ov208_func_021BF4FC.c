/*
 * function: ZUKAN_DETAIL_INFO_GetPanelParams
 * address: 0x021BF4FC
 * packet: pkt_ov208_021BF4FC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Species local and CC40/CED4 species arguments are u32: this caller has no u16 truncation before either call.
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb ov208
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry 0x021BC3C0 thumb ov208
 *   ZUKAN_SAVE_GetViewGenderAndForm 0x0200CC40 thumb
 *   ZUKAN_SAVE_GetSpindaPersonality 0x0200D288 thumb
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_HasLanguageFlag 0x0200D3C0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37;
extern int ZUKAN_DETAIL_COMMON_GetSource(int *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern u16 ZUKAN_DETAIL_COMMON_GetCurrentEntry(int);
extern void ZUKAN_SAVE_GetViewGenderAndForm(u8 *, u32, u32 *, u32 *, u32 *, u16);
extern u32 ZUKAN_SAVE_GetSpindaPersonality(struct Blk37 *, u32);
extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *, u32);
extern u32 ZUKAN_SAVE_HasLanguageFlag(struct Blk37 *, u32, u32);
void ZUKAN_DETAIL_INFO_GetPanelParams(const u16 *heap, u8 *p, int key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7)
{
    u32 values[6];
    u32 a, b, c, special, value;
    struct Blk37 *ctx;
    u32 id;
    u8 i;
    ctx = ZUKAN_SAVE_GetFromGameData((void *)ZUKAN_DETAIL_COMMON_GetSource((int *)key));
    id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    special = 0;
    ZUKAN_SAVE_GetViewGenderAndForm((u8 *)ctx, id, &b, &c, &a, *heap);
    if (id == 327) special = ZUKAN_SAVE_GetSpindaPersonality(ctx, special);
    value = ZUKAN_SAVE_IsCaught(ctx, id);
    for (i = 0; i < 6; i++) values[i] = ZUKAN_SAVE_HasLanguageFlag(ctx, id, p[i * 20 + 0x28]);
    *out1 = id;
    *out2 = a;
    *out3 = b;
    *out4 = c;
    *out5 = special;
    *out6 = value;
    for (i = 0; i < 6; i++) out7[i] = values[i];
}
