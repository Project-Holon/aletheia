/*
 * function: DWCi_AC_SetStealthChannel
 * address:  0x0205DF6C
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_SetStealthChannel (search.o)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 */

typedef struct tagACWORK {
    unsigned char before[0x14C6];
    unsigned short stealthChannel;
    long rwin;
    unsigned char wontExecuteEULACheck;
    unsigned short maxChannel;
} tagACWORK;

extern void *DWCi_AC_GetMemPtr(unsigned long name);

void DWCi_AC_SetStealthChannel(unsigned short channel)
{
    tagACWORK *wk = (tagACWORK *)DWCi_AC_GetMemPtr(0x10);

    if (channel > wk->maxChannel) {
        channel = wk->maxChannel;
    }
    wk->stealthChannel = (unsigned short)(wk->stealthChannel | (1 << (channel - 1)));
}
