/*
 * function: SCRCMD_RESEARCH_GetTallyTotal
 * address: 0x0216B970
 * packet: pkt_ov010_0216B970
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MISC_SAVEDATA_GetHalfword 0x0200E458 thumb
 *   MISC_SAVEDATA_GetTallyWord 0x0200E47C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 MISC_SAVEDATA_GetHalfword(const u16 *, int);
extern u32 MISC_SAVEDATA_GetTallyWord(u8 *p, int i);
u32 SCRCMD_RESEARCH_GetTallyTotal(const u16 *p, int index)
{
    u32 x = MISC_SAVEDATA_GetHalfword(p, index);
    x += MISC_SAVEDATA_GetTallyWord((u8 *)p, index);
    if (x > 999999) x = 999999;
    return x;
}
