/*
 * function: DWCi_DivideFullApinfo
 * address:  0x0205CCE4
 * packet:   pkt_0205CCE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_DivideFullApinfo (dwc_connectinet.o)
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */

typedef struct {
    int aptype;
    int area;
    int security;
    char spotinfo[10];
    char essid[33];
    unsigned char bssid[6];
} DWCApInfo;

extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);

void DWCi_DivideFullApinfo(char *fullapinfo, DWCApInfo *apinfo)
{
    int isdigit = 0;

    if (fullapinfo[0] >= '0' && fullapinfo[0] <= '9') {
        isdigit = 1;
    }
    apinfo->area = isdigit ? fullapinfo[0] - '0' : 0xff;
    MI_CpuCopy8(fullapinfo + 1, apinfo->spotinfo, 9);
}
