/*
 * function: WIH_Initialize
 * address:  0x021790E4
 * packet:   pkt_ov014_021790E4
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWihWork     0x021797A8  data   ov014  a4
 *   sWihFileName     0x02179794  data   ov014  a1
 *   WIH_StateInInitialize  0x021791A0  thumb  ov014
 *   GFL_NET_AllocAligned  0x0203D7C8  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

extern u8 *gWihWork;
extern char sWihFileName[];

extern BOOL WIH_StateInInitialize(int a, int b);
extern void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);
extern void MI_CpuFill8(void *p, int v, u32 n);

BOOL WIH_Initialize(u32 heap, int a, int b)
{
    BOOL ok;

    if (gWihWork != 0)
        return 0;
    gWihWork = GFL_NET_AllocAligned(heap, 0x1F00, sWihFileName, 0xC33);
    MI_CpuFill8(gWihWork, 0, 0x1EE0);
    *(u16 *)(gWihWork + 0x1EC2) = 1;
    *(u16 *)(gWihWork + 0x1EAA) = 1;
    *(int *)(gWihWork + 0x1E98) = 0;
    *(u16 *)(gWihWork + 0x1EC0) = heap;
    ok = 1;
    if (!WIH_StateInInitialize(a, b))
        ok = 0;
    return ok;
}
