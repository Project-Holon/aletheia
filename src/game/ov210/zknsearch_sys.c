/*
 * file:     zknsearch_sys.c
 * unit:     yes
 * function: ZKNSEARCH_SYS_Create, ZKNSEARCH_SYS_IsReady, ZKNSEARCH_SYS_Delete, ZKNSEARCH_SYS_RegisterVBlank, ZKNSEARCH_SYS_UnregisterVBlank, ZKNSEARCH_SYS_VBlankHandler, ZKNSEARCH_SYS_RegisterHBlank, ZKNSEARCH_SYS_UnregisterHBlank, ZKNSEARCH_SYS_HBlankHandler, ZKNSEARCH_SYS_SetVramBanks, ZKNSEARCH_SYS_GetVramBanks
 * address:  0x021BC240
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   ZKNSEARCH_MAIN_RunState  0x021BCF50  thumb  ov210
 *   TCB_DeleteTask  0x02030EAC  arm
 *   d_02FE0000 0x02FE0000 data a4
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021C0754  0x021C0754  data  a4
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm  arm9
 *   GFL_USE_AddMainTask  0x020056A0  thumb  arm9
 *   PROCSYS_FreeProcWork  0x020315D4  arm  arm9
 */
#include "zknsearch_types.h"







extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(void *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern u32 ZKNSEARCH_MAIN_RunState(u8 *p);
extern void PROCSYS_FreeProcWork(void *p);
extern void GFL_HEAP_DeleteChecked(u32);
extern u32 GFL_USE_AddMainTask(void (*)(void), u8 *, u32);
extern u32 TCB_DeleteTask(u32 a);
extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);
extern void PALANM_TransferPalettes(void *p);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned,unsigned);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void BG_SYS_ClearGraphicsMemory(u32 a);
extern void BG_SYS_SetVramBanks(const void *c);
u32 ZKNSEARCH_SYS_Create(void *man, u32 b, u32 arg);
u32 ZKNSEARCH_SYS_IsReady(u32 a, u32 b, u32 c, u32 d);
u32 ZKNSEARCH_SYS_Delete(void *p);
void ZKNSEARCH_SYS_RegisterVBlank(u8 *p);
u32 ZKNSEARCH_SYS_UnregisterVBlank(u8 *p);
void ZKNSEARCH_SYS_VBlankHandler(void *unused,unsigned char *p);
void ZKNSEARCH_SYS_RegisterHBlank(u8 *p);
u32 ZKNSEARCH_SYS_UnregisterHBlank(u8 *p);
void ZKNSEARCH_SYS_HBlankHandler(void *ctx, unsigned char *p);
void ZKNSEARCH_SYS_SetVramBanks(void);
void *ZKNSEARCH_SYS_GetVramBanks(void);
extern unsigned d_02FE0000[];
extern u8 d_021C0754[];


u32 ZKNSEARCH_SYS_Create(void *man, u32 b, u32 arg)
{
    u32 *p;
    GFL_HEAP_CreateChildHeap(1, 0x7b, 0x60000);
    p = PROCSYS_AllocProcWork(man, 0x2d4, 0x7b);
    MI_CpuFill8(p, 0, 0x2d4);
    *p = arg;
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
u32 ZKNSEARCH_SYS_IsReady(u32 a, u32 b, u32 c, u32 d)
{
    return ZKNSEARCH_MAIN_RunState((u8 *)d) == 0;
}


u32 ZKNSEARCH_SYS_Delete(void *p)
{
    PROCSYS_FreeProcWork(p);
    GFL_HEAP_DeleteChecked(0x7b);
    return 1;
}


void ZKNSEARCH_SYS_RegisterVBlank(u8 *p)
{
    ((ZknSearchWork *)p)->vblank = GFL_USE_AddMainTask((void (*)(void))ZKNSEARCH_SYS_VBlankHandler, p, 0);
}


u32 ZKNSEARCH_SYS_UnregisterVBlank(u8 *p)
{
    return TCB_DeleteTask(((ZknSearchWork *)p)->vblank);
}

void ZKNSEARCH_SYS_VBlankHandler(void *unused,unsigned char *p)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes(((ZknSearchWork *)p)->palAnm);
    if (p[0x2b8]==1) {
        BG_SYS_SetMainPlaneVisible(10,1);
        BG_SYS_SetSubPlaneVisible(2,1);
        p[0x2b8]=0;
    } else if (p[0x2b8]==2) {
        BG_SYS_SetMainPlaneVisible(10,0);
        BG_SYS_SetSubPlaneVisible(2,0);
        p[0x2b8]=0;
    }
    *(volatile unsigned *)((unsigned)d_02FE0000+0x3ff8) |= 1;
}


void ZKNSEARCH_SYS_RegisterHBlank(u8 *p)
{
    ((ZknSearchWork *)p)->hblank = (u32)func_02005624((u32)ZKNSEARCH_SYS_HBlankHandler, (u32)p, 0);
}


u32 ZKNSEARCH_SYS_UnregisterHBlank(u8 *p)
{
    return TCB_DeleteTask(((ZknSearchWork *)p)->hblank);
}

/*
 * Unlabelled leaf in ov210 directly after ZKNSEARCH_SYS_RegisterHBlank (which ends at
 * 0x021BC328, pool at 0x021BC32C); it saves nothing, so disasm.py prints it
 * inside a .word run.  It is the function-pointer blocker target of
 * ZKNSEARCH_SYS_RegisterHBlank (pkt_021BC318).  Reads a mode byte from [p+0x2b9] and a
 * halfword from the IO register at 0x04000006, then writes one of six packed
 * halfwords to the register at 0x04001052.
 */
void ZKNSEARCH_SYS_HBlankHandler(void *ctx, unsigned char *p)
{
    int v = *(volatile unsigned short *)0x04000006;
    int b = p[0x2b9];

    if (b == 4) {
        if (v >= 0x98)
            *(volatile unsigned short *)0x04001052 = 0x050B;
        else if (v >= 0x70)
            *(volatile unsigned short *)0x04001052 = 0x060A;
        else if (v >= 0x48)
            *(volatile unsigned short *)0x04001052 = 0x0709;
        else if (v >= 0x20)
            *(volatile unsigned short *)0x04001052 = 0x0808;
        else
            *(volatile unsigned short *)0x04001052 = 0x0A06;
    } else {
        if (v >= 0xa8)
            *(volatile unsigned short *)0x04001052 = 0x050B;
        else if (v >= 0x90)
            *(volatile unsigned short *)0x04001052 = 0x060A;
        else if (v >= 0x78)
            *(volatile unsigned short *)0x04001052 = 0x0709;
        else if (v >= 0x60)
            *(volatile unsigned short *)0x04001052 = 0x0808;
        else if (v >= 0x48)
            *(volatile unsigned short *)0x04001052 = 0x0A06;
        else
            *(volatile unsigned short *)0x04001052 = 0x0C04;
    }
}


void ZKNSEARCH_SYS_SetVramBanks(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const void *)d_021C0754);
}


void *ZKNSEARCH_SYS_GetVramBanks(void)
{
    return d_021C0754;
}
