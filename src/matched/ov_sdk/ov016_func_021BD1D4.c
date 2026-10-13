/*
 * function: DWCi_CMNlLoadResource
 * address:  0x021BD1D4
 * packet:   pkt_ov016_021BD1D4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CMNlLoadResource (libdwcutil.TWL.HYB.a(common.o))
 *
 * symbols:
 *   DWCi_Char  0x021bd170  arm  ov016
 *   DWCi_ARClReadEx  0x021d4b68  arm  ov016
 *   DWCi_ScreenDC_FlushRange  0x020862f0  arm
 *   DWCi_ARClRelease  0x021d4c68  arm  ov016
 */

extern unsigned char *DWCi_Char(unsigned char *name);
extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern void DWCi_ScreenDC_FlushRange(void *startAddr, unsigned long nBytes);
extern void DWCi_ARClRelease(void *file);

void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long))
{
    char *n;
    unsigned long size;
    void *data;

    n = (char *)DWCi_Char((unsigned char *)file);
    data = DWCi_ARClReadEx(n, &size, 4);
    DWCi_ScreenDC_FlushRange(data, size);
    func(data, 0, size);
    DWCi_ARClRelease(data);
}
