/*
 * function: DSP_StopDSPComponent
 * address:  0x027052B4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   DSP_SendDataCore  0x0270502C  arm
 *   DSP_RecvDataCore  0x0270505C  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef struct Sys {
    u32 pad0[0x1a];
    u32 mask;
} Sys;
extern s32 func_02085D3C(void);
extern void DSP_SendDataCore(u32 ch, u32 v);
extern u16 DSP_RecvDataCore(u32 ch);
void DSP_StopDSPComponent(void)
{
    (*(Sys **)0x027344AC)->mask = 0;
    if (func_02085D3C() == 1) {
        DSP_SendDataCore(2, 0x8000);
    }
    if (func_02085D3C() == 1) {
        DSP_RecvDataCore(2);
    }
}
