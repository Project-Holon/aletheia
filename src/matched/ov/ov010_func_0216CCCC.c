/*
 * function: FLDMMDL_ClearObjCodeParamCache
 * address:  0x0216CCCC
 * packet:   pkt_ov010_0216CCCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * clears the 0x310-byte buffer at +0x44, a tail call through a pool word.
 * Callee of ov020 EVENT_MAPCHANGE_ApplyLocation.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Obj {
    char pad[0x44];
    void *f44;
} Obj;

void MI_CpuFill8(void *dst, u8 val, u32 size);

void FLDMMDL_ClearObjCodeParamCache(Obj *o)
{
    MI_CpuFill8(o->f44, 0, 0x310);
}
