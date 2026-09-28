/*
 * function: DWCi_HLlLoad
 * address:  0x021BD674
 * packet:   pkt_ov016_021BD674
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HLlLoad (libdwcutil.TWL.HYB.a headline.o)
 *
 * symbols:
 *   DWCi_Char        0x021BD170  arm
 *   DWCi_ARClReadEx  0x021D4B68  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   DWCi_ARClRelease 0x021D4C68  arm
 *   DWCi_TSKlForm    0x021D7680  arm
 *   FILE_NAME        0x021DAE04  data  a4
 *   Buffer           0x021DE554  data  a4
 *   taskLoad         0x021BD704  arm
 */

char *DWCi_Char(char *name);
void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
void MIi_CpuCopyFast(void *srcp, void *destp, unsigned long size);
void DWCi_ARClRelease(void *file);
void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern char *FILE_NAME[20];
extern unsigned short *Buffer;
void taskLoad(void *task);

void DWCi_HLlLoad(int idx)
{
    char *n = DWCi_Char(FILE_NAME[idx]);
    void *file = DWCi_ARClReadEx(n, 0, 4);
    MIi_CpuCopyFast(file, Buffer, 0xc0);
    DWCi_ARClRelease(file);
    DWCi_TSKlForm(1, (void (*)(void *, void *))taskLoad, 0, 0x78);
}
