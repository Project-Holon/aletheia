/*
 * function: SCRIPT_WORK_SetParams
 * address:  0x02159058
 * packet:   pkt_ov010_02159058
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_SetWorkValue  0x02159030  thumb  ov010
 */

typedef unsigned short u16;

extern int SCRIPT_WORK_SetWorkValue(int a0, int a1, int a2);

int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e)
{
    SCRIPT_WORK_SetWorkValue(a, 0x8000, b);
    SCRIPT_WORK_SetWorkValue(a, 0x8001, c);
    SCRIPT_WORK_SetWorkValue(a, 0x8002, d);
    return SCRIPT_WORK_SetWorkValue(a, 0x8003, e);
}
