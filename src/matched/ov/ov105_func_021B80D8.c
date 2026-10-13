/*
 * function: IRC_RESULT_StateStart
 * address: 0x021B80D8
 * packet: pkt_ov105_021B80D8
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: parent SDK/assignment/source/unit/shard audit cleared 16-byte stub.
 * Original overwrites r1 with callback80E8, tail-forwards r0 to80BC;
 * 80BC stores callback at18c and zeros halfword190, reads no other input.
 * symbols:
 *   IRC_RESULT_SetState 0x021B80BC thumb ov105
 *   IRC_RESULT_StateShowScore 0x021B80E8 thumb ov105
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void IRC_RESULT_SetState(unsigned char *p, unsigned int v);
extern void IRC_RESULT_StateShowScore(u8 *,u16 *);
void IRC_RESULT_StateStart(u8 *p)
{
    IRC_RESULT_SetState(p,(unsigned int)IRC_RESULT_StateShowScore);
}
