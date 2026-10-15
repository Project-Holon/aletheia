/*
 * function: UNION_CHAT_LOG_GetLine
 * address:  0x021BBC2C
 * packet:   pkt_ov021_021BBC2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *   gUnionChatEmptyMac     0x021D9AE0  data  a4
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm  arm9
 */

typedef struct {
    char pad[0x1A];
    char s1A[10];
} Entry;

extern char gUnionChatEmptyMac[];

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

Entry *UNION_CHAT_LOG_GetLine(Entry *tab, unsigned int i)
{
    Entry *e = &tab[i % 30];

    if (GF_STANDARD_CompareBytes((const u8 *)e->s1A, (const u8 *)gUnionChatEmptyMac, 6) == 0) {
        e = 0;
    }
    return e;
}
