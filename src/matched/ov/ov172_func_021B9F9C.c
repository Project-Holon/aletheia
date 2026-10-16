/*
 * function: CTVT_MIC_Create
 * address: 0x021B9F9C
 * packet: pkt_ov172_021B9F9C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MIC_Init 0x0208B24C arm
 *   PM_Init 0x0208B8B0 arm
 *   PM_SetAmp 0x0208BEF0 arm
 *   PM_SetAmpGainLevel 0x0208BF54 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_021BA014 0x021BA014 arm ov172
 *   CTVT_MIC_InitChannel 0x021BA1B4 thumb ov172
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   func_02005654 0x02005654 thumb
 *   gCtvtMicAllocSite 0x021C7218 data a4
 *   gCtvtMicIirFilter 0x021C720C data a4
 *   gCtvtMic 0x021C88EC data a4
 *   CTVT_MIC_OnVBlank 0x021BA098 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void MIC_Init(void);
extern void PM_Init(void);
extern u32 PM_SetAmp(u32);
extern u32 PM_SetAmpGainLevel(u8);
extern int OS_IsRunOnTwl(void);
extern void func_021BA014(int, void *);
extern void CTVT_MIC_InitChannel(char *, u32);
extern void *GFL_NET_AllocAligned(u32, u32, const char *, u16);
extern int func_02005654(int, int);
extern const char gCtvtMicAllocSite[], gCtvtMicIirFilter[];
extern void *gCtvtMic;
extern void CTVT_MIC_OnVBlank(void);
void *CTVT_MIC_Create(u32 heap)
{
    u32 *p = func_02030734(heap, 36, 1, gCtvtMicAllocSite, 87);
    MIC_Init();
    PM_Init();
    PM_SetAmp(1);
    PM_SetAmpGainLevel(80);
    if (OS_IsRunOnTwl() == 1) func_021BA014(0, (void *)gCtvtMicIirFilter);
    CTVT_MIC_InitChannel((char *)p, heap);
    p[1] = (u32)GFL_NET_AllocAligned(heap, 51200, gCtvtMicAllocSite, 134);
    p[0] = 0;
    p[2] = 0;
    *((u8 *)p + 16) = 0;
    gCtvtMic = p;
    func_02005654((int)CTVT_MIC_OnVBlank, 0);
    return p;
}
