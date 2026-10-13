/*
 * function: FLDMMDL_SysLoadObjCodeParamCache
 * address:  0x0216E29C
 * packet:   pkt_ov010_0216E29C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 EVENT_MAPCHANGE_ApplyLocation.
 *
 * symbols:
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 */

typedef struct Obj {
    char pad[0x44];
    void *f44;
} Obj;

typedef unsigned int   u32;
void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

void FLDMMDL_SysLoadObjCodeParamCache(Obj *o, int v)
{
    ARC_TOOL_ReadMember(o->f44, 0x3a, v);
}
