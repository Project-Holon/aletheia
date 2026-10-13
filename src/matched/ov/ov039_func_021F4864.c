/*
 * function: GIMMICK39_FindStopAtFrame
 * address: 0x021F4864
 * packet: pkt_ov039_021F4864
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sStopFrames 0x021F4D78 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 sStopFrames[][2];
int GIMMICK39_FindStopAtFrame(u32 a, u32 b, u8 *out) { u8 i; for (i = 0; i < 2; i++) { if (sStopFrames[a][i] == b) { *out = i; return 1; } } return 0; }
