/*
 * function: DWC_SVLProcess
 * address:  0x02168040
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls DWC_Svl_Cleanup when DWC_Svl_Process returns 3 to 5.
 *
 * symbols:
 *   DWC_Svl_Process  0x0217C384  arm  ov009
 *   DWC_Svl_Cleanup  0x0217C104  arm  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int DWC_SVLProcess(void)
{
    int DWC_Svl_Process(void);
    void DWC_Svl_Cleanup(void);
    int v = DWC_Svl_Process();
    if ((u32)(v - 3) <= 2) DWC_Svl_Cleanup();
    return v;
}
