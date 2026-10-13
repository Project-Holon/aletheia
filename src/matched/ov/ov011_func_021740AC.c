/*
 * function: INTRUDE_CMD_SendProposalReply
 * address:  0x021740AC
 * packet:   pkt_ov011_021740AC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handed as 0x021740AE; the function starts at the push {r0-r3} at 0x021740AC.
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
typedef unsigned int   u32;
u32 func_0203D1C0(u32 index);
struct Entry;
struct Entry *func_020399A8(void);
int func_0203D3F8(int a, unsigned char b, int c, int d, void *e, int f, int g, int h);

int INTRUDE_CMD_SendProposalReply(int a, int b, int c, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    if ((int)func_0203D1C0((unsigned char)c) == 0) {
        return 1;
    }
    return func_0203D3F8((int)func_020399A8(), c, 0x217, 4, &b, 0, 0, 0);
}
