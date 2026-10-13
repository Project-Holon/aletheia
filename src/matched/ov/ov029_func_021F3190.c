/*
 * function: C_GEAR_LoadSkinMember
 * address:  0x021F3190
 * packet:   pkt_021F3190
 * region:   ov029
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020091FC  0x020091FC  thumb
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 */

int func_020091FC(int a0);
typedef unsigned int   u32;
struct ArcFile;
void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);

void C_GEAR_LoadSkinMember(int a0, int a1, int a2, int d)
{
    int x = func_020091FC(a0);

    ARC_TOOL_ReadHandleMember((struct ArcFile *)a1, a2 + 0x19, (void *)x);
}
