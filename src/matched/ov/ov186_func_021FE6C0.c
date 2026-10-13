/*
 * function: func_021FE6C0
 * address: 0x021FE6C0
 * packet: pkt_ov186_021FE6C0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   d_02200D6C 0x02200D6C data a1
 */
extern const char d_02200D6C[];
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj02021EE4;
struct PalAnmSlot;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void *PALANM_Create(unsigned);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
int *func_021FE6C0(unsigned heap)
{
    int *p = func_02030734(heap, 0x40, 0, d_02200D6C, 0x62);
    MI_CpuFill8(p, 0, 0x40);
    p[15] = 0xFFFF;
    p[8] = (int)PALANM_Create(heap);
    PALANM_AllocSlotBuffers((void *)p[8], 0, 0x200, heap);
    PALANM_AllocSlotBuffers((void *)p[8], 2, 0x1C0, heap);
    PALANM_AllocSlotBuffers((void *)p[8], 1, 0x200, heap);
    PALANM_AllocSlotBuffers((void *)p[8], 3, 0x1C0, heap);
    PALANM_SetAutoTransfer((void *)p[8], 1);
    return p;
}
