/*
 * function: func_0205A1EC
 * address:  0x0205A1EC
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The ARM9 listing labels this address func_0205A1EC; it is dwc_memfunc.o's DWC_Realloc, forcing align 32 (the SDK table's CTRDG_DmaCopy32 attribution here does not match the linked bytes).
 */
extern void *DWC_ReallocEx(int name, void *ptr, unsigned long oldsize, unsigned long newsize, int align);

void *func_0205A1EC(int name, void *ptr, unsigned long oldsize, unsigned long newsize)
{
    return DWC_ReallocEx(name, ptr, oldsize, newsize, 32);
}
