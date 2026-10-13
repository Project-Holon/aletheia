/*
 * function: GAME_BEACON_ACCESSOR_GetPmVersion
 * address:  0x02165C48
 * packet:   pkt_02165C48
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of func_021BCDC0 (ov216) +0002. Coherent
 * Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes that site
 * attest as `matched`.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 _pad0;
    u32 _pad1;
    u32 _pad2;
    u32 field : 6;
} S;

u32 GAME_BEACON_ACCESSOR_GetPmVersion(S *a0)
{
    return a0->field;
}
