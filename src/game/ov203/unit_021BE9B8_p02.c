/*
 * file:     unit_021BE9B8_p02.c
 * unit:     yes
 * function: func_021BEA48, func_021BEAB8
 * address:  0x021BEA48
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
 *   func_0207D4B0 0x0207D4B0 arm
 *   func_0208068C 0x0208068C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02031194 0x02031194 arm
 */
struct TcblNode;
typedef enum { CaptureSize0 = 0, CaptureSize3 = 3 } GXCaptureSize;

typedef enum { CaptureMode0 = 0, CaptureMode2 = 2 } GXCaptureMode;

typedef enum { CaptureSrcA0 = 0, CaptureSrcA1 = 1 } GXCaptureSrcA;

typedef enum { CaptureSrcB0 = 0, CaptureSrcB6 = 6 } GXCaptureSrcB;

typedef enum { CaptureDest0 = 0, CaptureDest15 = 15 } GXCaptureDest;

extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0208068C(int);
extern void func_02082AC0(unsigned,void *,unsigned);
extern void func_02031194(struct TcblNode *);
void func_021BEA48(int *s,unsigned a,unsigned b,unsigned c);
void func_021BEAB8(void *task, const int *ctx);

void func_021BEA48(int *s,unsigned a,unsigned b,unsigned c)
{
    func_0207D4B0(a,b,c);func_0208068C(s[0]);
    switch(s[1]){
    case 2:func_02082AC0(0,(void *)0x06800000,0x20000);break;
    case 6:func_02082AC0(0,(void *)0x06820000,0x20000);break;
    case 10:func_02082AC0(0,(void *)0x06840000,0x20000);break;
    case 14:func_02082AC0(0,(void *)0x06860000,0x20000);break;
    default:func_0208068C(0);break;
    }
    func_02031194((struct TcblNode *)s[13]);
}

static inline void GX_SetCapture(GXCaptureSize sz, GXCaptureMode mode, GXCaptureSrcA a, GXCaptureSrcB b, GXCaptureDest dest, int eva, int evb)
{
    *(volatile unsigned *)0x04000064 = 0x80000000 | (mode << 29) | (b << 25) | (a << 24) | (sz << 20) | (dest << 16) | (evb << 8) | eva;
}

void func_021BEAB8(void *task, const int *ctx)
{
    if (ctx[12]) {
        GX_SetCapture(ctx[4], ctx[5], ctx[6], ctx[7], ctx[8], ctx[9], ctx[10]);
    }
}
