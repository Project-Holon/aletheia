/*
 * function: FIELD_WFBC_DATA_LOCAL_LoadNpcData
 * address: 0x02186818
 * packet: pkt_ov020_02186818
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 */

typedef unsigned int u32;
struct ArcFile;
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
void FIELD_WFBC_DATA_LOCAL_LoadNpcData(u32 *p, u32 member) { ARC_TOOL_ReadHandleMember((struct ArcFile *)p[0], member, p + 2); p[1] = member; }
