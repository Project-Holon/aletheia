/*
 * function: EVENT_WIFI_PROC_LoadOv020Task
 * address:  0x0215FA1C
 * packet:   pkt_ov010_0215FA1C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_OVERLAY_Load   0x02034AC4  arm
 *   EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent  0x0218571C  thumb  ov020
 *   abs_id_14      0x00000014  data
 *
 * Loads overlay 20 (GF_OVERLAY_Load with the pooled id abs_id_14) and returns
 * the task that ov020 EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent creates for the owner.  The bytes are
 * the same as the TWL DSPi_WaitForPipe (dsp_pipe.o, at twl 0x02706CB4),
 * which named this function before; the callees are game code.
 */

extern int GF_OVERLAY_Load(int id);
extern void *EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent(void *owner);
extern unsigned char abs_id_14[];

void *EVENT_WIFI_PROC_LoadOv020Task(void *owner)
{
    GF_OVERLAY_Load((int)abs_id_14);
    return EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent(owner);
}
