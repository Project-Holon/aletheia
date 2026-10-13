/*
 * function: GAME_BEACON_ACCESSOR_GetPlayerName
 * address:  0x02165C34
 * packet:   pkt_ov010_02165C34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copy the eight-character name at +0x12 into a string buffer.
 *
 * symbols:
 *   STRBUF_SetStringN  0x02045994  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);

typedef struct Rec {
    u8 pad00[0x12];
    u16 name[8];        /* 0x12 */
} Rec;

void GAME_BEACON_ACCESSOR_GetPlayerName(Rec *r, void *buf)
{
    STRBUF_SetStringN(buf, r->name, 8);
}
