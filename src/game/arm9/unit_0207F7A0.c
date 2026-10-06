/*
 * file:     unit_0207F7A0.c
 * unit:     yes
 * function: GX_BeginLoadTex, GX_LoadTex, GX_EndLoadTex, GX_BeginLoadTexPltt, GX_LoadTexPltt, func_0207FADC, func_0207FB2C, GX_LoadClearImageColor, GX_LoadClearImageDepth, GX_EndLoadClearImage
 * address:  0x0207F7A0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GX_ResetBankForTex     0x02080964  arm
 *   sClrImg                0x02150E2C  data
 *   sTexStartAddrTable     0x020A5C4C  data
 *   GXi_DmaId              0x020A84C0  data
 *   MI_NDmaCopy            0x0272FB78  arm
 *   MIi_DmaCopy32          0x02082244  arm
 *   MIi_CpuCopy32          0x02082A90  arm
 *   MI_NDmaCopyAsync       0x0272FC2C  arm
 *   MIi_DmaCopy32Async     0x02082498  arm
 *   GX_SetBankForTex       0x02080294  arm
 *   MI_WaitNDma            0x0272FCB0  arm
 *   MI_WaitDma             0x02082594  arm
 *   GX_ResetBankForTexPltt 0x02080978  arm
 *   sTexPlttStartAddrTable 0x020A5C3C  data
 *   GX_SetBankForTexPltt   0x0208040C  arm
 *   func_0208098C 0x0208098C arm
 *   g_02150E2C 0x02150E2C data
 *   GX_SetBankForClearImage 0x020804E8  arm
 */
typedef unsigned long u32;

typedef unsigned short u16;

typedef int BOOL;

typedef void (*MIDmaCallback)(void *);

/* gx_load3d.o's .bss statics, in their laid-out order */
typedef struct {
    int clrImg;
    u32 texLCDCBlk1;
    u32 texPlttLCDCBlk;
    int texPltt;
    u32 clrImgLCDCBlk;
    int tex;
    u32 texLCDCBlk2;
    u32 szTexBlk1;
} GXLoad3DState;

typedef struct {
    u16 blk1;
    u16 blk2;
    u16 szBlk1;
} GXTexStartAddr;

extern int GX_ResetBankForTex(void);
extern int GX_ResetBankForTexPltt(void);
extern void GX_SetBankForTex(int tex);
extern void GX_SetBankForTexPltt(int texPltt);
extern void GX_SetBankForClearImage(int clrImg);
extern void MI_NDmaCopy(u32 ndmaNo, const void *src, void *dest, u32 size);
extern void MI_NDmaCopyAsync(u32 ndmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
extern void MIi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable);
extern void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);
extern void MI_WaitNDma(u32 ndmaNo);
extern void MI_WaitDma(u32 dmaNo);
extern void func_0208098C(int a0, int a1, int a2, int a3);
void GX_BeginLoadTex(void);
void GX_LoadTex(void *pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadTex(void);
void GX_BeginLoadTexPltt(void);
void GX_LoadTexPltt(void *pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadTexPltt(void);
asm void GX_BeginLoadClearImage(void);
void GX_LoadClearImageColor(void *pSrc, u32 szByte);
void GX_LoadClearImageDepth(void *pSrc, u32 szByte);
void GX_EndLoadClearImage(void);
extern GXLoad3DState sClrImg;
extern u32 GXi_DmaId;
extern const GXTexStartAddr sTexStartAddrTable[16];
extern const u16 sTexPlttStartAddrTable[8];
extern int g_02150E2C;









#define GX_DMA_NOT_USE ((u32)-1)









static inline void MI_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo > 3) {
        MI_NDmaCopy(dmaNo - 4, src, dest, size);
    } else {
        MIi_DmaCopy32(dmaNo, src, dest, size, 1);
    }
}









static inline void MI_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg)
{
    if (dmaNo > 3) {
        MI_NDmaCopyAsync(dmaNo - 4, src, dest, size, callback, arg);
    } else {
        MIi_DmaCopy32Async(dmaNo, src, dest, size, callback, arg, 1);
    }
}









static inline void MI_WaitDmaAny(u32 dmaNo)
{
    if (dmaNo > 3) {
        MI_WaitNDma(dmaNo - 4);
    } else {
        MI_WaitDma(dmaNo);
    }
}









static inline void GXi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo != GX_DMA_NOT_USE && size > 0x30) {
        MI_DmaCopy32(dmaNo, src, dest, size);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}









static inline void GXi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg)
{
    if (dmaNo != GX_DMA_NOT_USE) {
        MI_DmaCopy32Async(dmaNo, src, dest, size, callback, arg);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}









static inline void GXi_WaitDma(u32 dmaNo)
{
    if (dmaNo != GX_DMA_NOT_USE) {
        MI_WaitDmaAny(dmaNo);
    }
}









void GX_BeginLoadTex(void)
{
    int tex = GX_ResetBankForTex();

    sClrImg.tex = tex;
    sClrImg.texLCDCBlk1 = (u32)sTexStartAddrTable[tex].blk1 << 12;
    sClrImg.texLCDCBlk2 = (u32)sTexStartAddrTable[tex].blk2 << 12;
    sClrImg.szTexBlk1 = (u32)sTexStartAddrTable[tex].szBlk1 << 12;
}









#define GX_DMA_NOT_USE ((u32)-1)









void GX_LoadTex(void *pSrc, u32 destSlotAddr, u32 szByte)
{
    void *pLCDC;
    void *pLCDC2;
    u32 sz;

    if (sClrImg.texLCDCBlk2 == 0) {
        pLCDC = (void *)(sClrImg.texLCDCBlk1 + destSlotAddr);
    } else if (destSlotAddr + szByte < sClrImg.szTexBlk1) {
        pLCDC = (void *)(sClrImg.texLCDCBlk1 + destSlotAddr);
    } else if (destSlotAddr >= sClrImg.szTexBlk1) {
        pLCDC = (void *)(sClrImg.texLCDCBlk2 + destSlotAddr - sClrImg.szTexBlk1);
    } else {
        sz = sClrImg.szTexBlk1 - destSlotAddr;
        pLCDC2 = (void *)sClrImg.texLCDCBlk2;
        GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(sClrImg.texLCDCBlk1 + destSlotAddr), sz);
        GXi_DmaCopy32Async(GXi_DmaId, (void *)((u32)pSrc + sz), pLCDC2, szByte - sz, 0, 0);
        return;
    }
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, pLCDC, szByte, 0, 0);
}








#define GX_DMA_NOT_USE ((u32)-1)








void GX_EndLoadTex(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForTex(sClrImg.tex);
    sClrImg.szTexBlk1 = 0;
    sClrImg.texLCDCBlk2 = 0;
    sClrImg.texLCDCBlk1 = 0;
    sClrImg.tex = 0;
}







#define GX_DMA_NOT_USE ((u32)-1)







void GX_BeginLoadTexPltt(void)
{
    int texPltt = GX_ResetBankForTexPltt();

    sClrImg.texPltt = texPltt;
    sClrImg.texPlttLCDCBlk = (u32)sTexPlttStartAddrTable[texPltt >> 4] << 12;
}






#define GX_DMA_NOT_USE ((u32)-1)






void GX_LoadTexPltt(void *pSrc, u32 destSlotAddr, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)(sClrImg.texPlttLCDCBlk + destSlotAddr), szByte, 0, 0);
}






#define GX_DMA_NOT_USE ((u32)-1)






void GX_EndLoadTexPltt(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForTexPltt(sClrImg.texPltt);
    sClrImg.texPltt = 0;
    sClrImg.texPlttLCDCBlk = 0;
}






asm void GX_BeginLoadClearImage(void)
{
    stmfd sp!, {r3, lr}
    bl func_0208098C
    ldr r1, =g_02150E2C
    cmp r0, #0xc
    str r0, [r1]
    addls pc, pc, r0, lsl #2
    ldmfd sp!, {r3, pc}

    ldmfd sp!, {r3, pc}
    b case_1
    b case_2
    b case_3
    b case_4
    ldmfd sp!, {r3, pc}
    ldmfd sp!, {r3, pc}
    ldmfd sp!, {r3, pc}
    b case_8
    ldmfd sp!, {r3, pc}
    ldmfd sp!, {r3, pc}
    ldmfd sp!, {r3, pc}
    b case_12

case_2:
case_3:
    mov r0, #0x06800000
    str r0, [r1, #0x10]
    ldmfd sp!, {r3, pc}

case_8:
case_12:
    ldr r0, =0x06840000
    str r0, [r1, #0x10]
    ldmfd sp!, {r3, pc}

case_1:
    ldr r0, =0x067E0000
    str r0, [r1, #0x10]
    ldmfd sp!, {r3, pc}

case_4:
    ldr r0, =0x06820000
    str r0, [r1, #0x10]
    ldmfd sp!, {r3, pc}
}




#define GX_DMA_NOT_USE ((u32)-1)




void GX_LoadClearImageColor(void *pSrc, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)sClrImg.clrImgLCDCBlk, szByte, 0, 0);
}



#define GX_DMA_NOT_USE ((u32)-1)



void GX_LoadClearImageDepth(void *pSrc, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)(sClrImg.clrImgLCDCBlk + 0x20000), szByte, 0, 0);
}


#define GX_DMA_NOT_USE ((u32)-1)


void GX_EndLoadClearImage(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForClearImage(sClrImg.clrImg);
    sClrImg.clrImg = 0;
    sClrImg.clrImgLCDCBlk = 0;
}
