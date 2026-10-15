/*
 * function: MUSICAL_SHOT_Init
 * address:  0x0200A848
 * packet:   pkt_0200A848
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 16: promoted.  02161EEC is the unlabelled ov010 leaf now
 *           matched in src/matched/EVENT_FIELD_PROCLINK_InitIdList.c (shard ov010/pkt_02161EEC),
 *           which attests the call as `matched, overlay` under the ov010
 *           hint below; 02161F00 resolves as sole-ref/code (overlay).
 * symbols:
 *   EVENT_FIELD_PROCLINK_InitEventdataSystem    0x02161D98  thumb  ov010
 *   EVENT_FIELD_PROCLINK_InitIdList    0x02161EEC  thumb  ov010
 *   EVENT_FIELD_PROCLINK_InitReturnHeader    0x02161F00  thumb  ov010
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void EVENT_FIELD_PROCLINK_InitEventdataSystem(char *p);
extern void EVENT_FIELD_PROCLINK_InitIdList(u16 *p);
extern void EVENT_FIELD_PROCLINK_InitReturnHeader(void *p);

void MUSICAL_SHOT_Init(void **a0)
{
    EVENT_FIELD_PROCLINK_InitEventdataSystem((char *)a0);
    EVENT_FIELD_PROCLINK_InitIdList((u16 *)&a0[0x7a]);
    EVENT_FIELD_PROCLINK_InitReturnHeader(&a0[0x7f]);
}
