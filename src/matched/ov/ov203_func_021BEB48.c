/*
 * function: DEMO3D_DATA_StartCapture
 * address: 0x021BEB48
 * packet: pkt_ov203_021BEB48
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: SDK GX_SetCapture write to DISPCAPCNT 04000064 at 021BEBB4.
 * symbols:
 *   MIi_CpuClearFast 0x02082AC0 arm
 */
typedef enum {GX_CAPTURE_SIZE_128x128=0,GX_CAPTURE_SIZE_256x64=1,GX_CAPTURE_SIZE_256x128=2,GX_CAPTURE_SIZE_256x192=3} GXCaptureSize;
typedef enum {GX_CAPTURE_MODE_A=0,GX_CAPTURE_MODE_B=1,GX_CAPTURE_MODE_AB=2} GXCaptureMode;
typedef enum {GX_CAPTURE_SRCA_2D3D=0,GX_CAPTURE_SRCA_3D=1} GXCaptureSrcA;
typedef enum {GX_CAPTURE_SRCB_VRAM_0x00000=0,GX_CAPTURE_SRCB_MRAM=1,GX_CAPTURE_SRCB_VRAM_0x08000=2,GX_CAPTURE_SRCB_VRAM_0x10000=4,GX_CAPTURE_SRCB_VRAM_0x18000=6} GXCaptureSrcB;
typedef enum {GX_CAPTURE_DEST_VRAM_A_0x00000=0,GX_CAPTURE_DEST_VRAM_D_0x18000=15} GXCaptureDest;
typedef struct CaptureConfig {int bank,pad[2];GXCaptureSize size;GXCaptureMode mode;GXCaptureSrcA a;GXCaptureSrcB b;GXCaptureDest dest;} CaptureConfig;
extern void MIi_CpuClearFast(unsigned,void *,unsigned);
static inline void GX_SetCapture(GXCaptureSize sz,GXCaptureMode mode,GXCaptureSrcA a,GXCaptureSrcB b,GXCaptureDest dest,int eva,int evb)
{
    *(volatile unsigned *)0x04000064=(0x80000000|(mode<<29)|(b<<25)|(a<<24)|(sz<<20)|(dest<<16)|(evb<<8)|eva);
}
void DEMO3D_DATA_StartCapture(CaptureConfig *s)
{
    switch(s->bank){
    case 2:MIi_CpuClearFast(0,(void *)0x06800000,0x20000);break;
    case 6:MIi_CpuClearFast(0,(void *)0x06820000,0x20000);break;
    case 10:MIi_CpuClearFast(0,(void *)0x06840000,0x20000);break;
    case 14:MIi_CpuClearFast(0,(void *)0x06860000,0x20000);break;
    }
    GX_SetCapture(s->size,s->mode,s->a,s->b,s->dest,16,0);
}
