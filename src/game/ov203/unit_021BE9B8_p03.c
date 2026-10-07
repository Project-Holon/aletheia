/*
 * file:     unit_021BE9B8_p03.c
 * unit:     yes
 * function: func_021BEAF8, func_021BEB48
 * address:  0x021BEAF8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0208068C 0x0208068C arm
 *   func_0207D4B0 0x0207D4B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02082AC0 0x02082AC0 arm
 */
struct Node;
typedef enum {GX_CAPTURE_SIZE_128x128=0,GX_CAPTURE_SIZE_256x64=1,GX_CAPTURE_SIZE_256x128=2,GX_CAPTURE_SIZE_256x192=3} GXCaptureSize;

typedef enum {GX_CAPTURE_MODE_A=0,GX_CAPTURE_MODE_B=1,GX_CAPTURE_MODE_AB=2} GXCaptureMode;

typedef enum {GX_CAPTURE_SRCA_2D3D=0,GX_CAPTURE_SRCA_3D=1} GXCaptureSrcA;

typedef enum {GX_CAPTURE_SRCB_VRAM_0x00000=0,GX_CAPTURE_SRCB_MRAM=1,GX_CAPTURE_SRCB_VRAM_0x08000=2,GX_CAPTURE_SRCB_VRAM_0x10000=4,GX_CAPTURE_SRCB_VRAM_0x18000=6} GXCaptureSrcB;

typedef enum {GX_CAPTURE_DEST_VRAM_A_0x00000=0,GX_CAPTURE_DEST_VRAM_D_0x18000=15} GXCaptureDest;

typedef struct CaptureConfig {int bank,pad[2];GXCaptureSize size;GXCaptureMode mode;GXCaptureSrcA a;GXCaptureSrcB b;GXCaptureDest dest;} CaptureConfig;

extern void func_0208068C(int);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_02030EAC(struct Node *n);
extern void func_02082AC0(unsigned,void *,unsigned);
void func_021BEAF8(void *node,int *s);
void func_021BEB48(CaptureConfig *s);

void func_021BEAF8(void *node,int *s)
{
    int bank;
    switch(s[1]){case 2:bank=1;break;case 6:bank=2;break;case 10:bank=4;break;case 14:bank=8;break;default:bank=0;break;}
    func_0208068C(bank);func_0207D4B0(s[1],s[2],s[3]);s[12]=1;func_02030EAC(node);
}

static inline void GX_SetCapture(GXCaptureSize sz,GXCaptureMode mode,GXCaptureSrcA a,GXCaptureSrcB b,GXCaptureDest dest,int eva,int evb)
{
    *(volatile unsigned *)0x04000064=(0x80000000|(mode<<29)|(b<<25)|(a<<24)|(sz<<20)|(dest<<16)|(evb<<8)|eva);
}

/*
 * volatile: SDK GX_SetCapture write to DISPCAPCNT 04000064 at 021BEBB4.
 */
void func_021BEB48(CaptureConfig *s)
{
    switch(s->bank){
    case 2:func_02082AC0(0,(void *)0x06800000,0x20000);break;
    case 6:func_02082AC0(0,(void *)0x06820000,0x20000);break;
    case 10:func_02082AC0(0,(void *)0x06840000,0x20000);break;
    case 14:func_02082AC0(0,(void *)0x06860000,0x20000);break;
    }
    GX_SetCapture(s->size,s->mode,s->a,s->b,s->dest,16,0);
}
