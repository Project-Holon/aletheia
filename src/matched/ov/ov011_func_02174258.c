/*
 * function: func_02174258
 * address:  0x02174258
 * packet:   pkt_ov011_02174258
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   INTRUDE_COMM_SetNoticeState  0x02175C58  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
void INTRUDE_COMM_SetNoticeState(void *a, int b);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned int   u32;
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_02174258(char *a)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    INTRUDE_COMM_SetNoticeState(a + 0x1ac, 0);
    return func_0203D3F8((u32)func_020399A8(), 0, 0x219, 0, 0, 0, 0, 0);
}
