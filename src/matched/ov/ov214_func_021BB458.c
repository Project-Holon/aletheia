/*
 * function: func_021BB458
 * address:  0x021BB458
 * packet:   pkt_021BB458
 * region:   ov214
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 14-byte leaf: bracket two SDK calls around a call on the pointed-to word.
 * The lane enumerator reports 552 bytes because the next func_ label is far;
 * the disassembly ends at the pop and the rest is data.
 *
 * symbols:
 *   G3D_SYSTEM_DrawStart  0x02047964  arm  arm9
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm  arm9
 *   G3D_CAMERA_Reset  0x02048AD0  arm  arm9
 */

extern void G3D_SYSTEM_DrawStart(void);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);

void func_021BB458(unsigned int *p)
{
    G3D_SYSTEM_DrawStart();
    G3D_CAMERA_Reset((struct Light *)(*p));
    G3D_SYSTEM_ApplyLookAt();
}
