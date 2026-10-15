/*
 * function: GAMESYSTEM_ProbeHeapCreate
 * address:  0x02011D60
 * packet:   pkt_02011D60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GAMESYSTEM_GetWorkSize  0x02011F24  thumb
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */

extern void GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int b, unsigned int c);
typedef unsigned int   u32;
extern u32 GAMESYSTEM_GetWorkSize(void);
extern void GFL_HEAP_DeleteChecked(unsigned int a);

void GAMESYSTEM_ProbeHeapCreate(void)
{
    GFL_HEAP_CreateChildHeap(9, 5, 5 << 10);
    GAMESYSTEM_GetWorkSize();
    GFL_HEAP_DeleteChecked(5);
}
