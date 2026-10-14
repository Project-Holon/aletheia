/*
 * function: ZUKAN_DETAIL_VOICE_DrawWaveform
 * address: 0x021C3840
 * packet: pkt_ov208_021C3840
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PM_VOICE_GetData 0x02006B5C thumb
 *   PM_VOICE_GetSampleRate 0x02006B94 thumb
 *   PM_VOICE_GetFrequency 0x02006B3C thumb
 *   PM_VOICE_GetDataSize 0x02006B78 thumb
 *   PM_VOICE_GetVolume 0x02006B20 thumb
 *   BMP_Clear 0x02043B5C arm
 *   BMP_FillRect 0x02043AF4 arm
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fadd 0x0209C95C arm
 *   _fmul 0x0209C77C arm
 *   _ffixu 0x0209C4C8 arm
 */
#include "../include/Obj01010.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef signed char    s8;
typedef unsigned int   u32;

struct Bmp;

extern u32 PM_VOICE_GetData(u32 i);
extern u32 PM_VOICE_GetSampleRate(u32 i);
extern u32 PM_VOICE_GetFrequency(u32 i);
extern u32 PM_VOICE_GetDataSize(u32 i);
extern s8 PM_VOICE_GetVolume(u32 i);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_FillRect(struct Bmp *b, u32 x, u32 y, u32 w, u32 h, u32 color);

void ZUKAN_DETAIL_VOICE_DrawWaveform(u16 *heap, u8 *p, int key, u16 a, u16 b)
{
    u32 ca;
    u32 cb;
    u32 k;
    u32 i;
    u32 end;
    int lo;
    int hi;
    int v;
    s16 w;
    int t;
    *(s8 * *)&((struct Obj01010 *)p)->f34 = (s8 *)PM_VOICE_GetData(((struct Obj01010 *)p)->f64);
    ((struct Obj01010 *)p)->f32 = 0;
    if (a == ((struct Obj01010 *)p)->f26 && b == ((struct Obj01010 *)p)->f28)
        return;
    ((struct Obj01010 *)p)->f26 = a;
    ((struct Obj01010 *)p)->f28 = b;
    ca = PM_VOICE_GetSampleRate(((struct Obj01010 *)p)->f64);
    cb = PM_VOICE_GetFrequency(((struct Obj01010 *)p)->f64);
    ((struct Obj01010 *)p)->f38 = (u32)(1000.0f * (32768.0f * (float)PM_VOICE_GetDataSize(((struct Obj01010 *)p)->f64)
                                           / (float)(int)ca
                                           / (float)(int)cb) + 0.5f);
    BMP_Clear((struct CharBuf *)(*(struct Bmp * *)&((struct Obj01010 *)p)->f2C), 0);
    k = 0;
    i = 0;
    while (i < PM_VOICE_GetDataSize(((struct Obj01010 *)p)->f64)) {
        cb = PM_VOICE_GetFrequency(((struct Obj01010 *)p)->f64);
        ca = PM_VOICE_GetSampleRate(((struct Obj01010 *)p)->f64);
        end = (u32)((float)(k + 1) * ((float)(int)ca * (float)(int)cb / 32768.0f / 60.0f / 2.0f));
        if (end > PM_VOICE_GetDataSize(((struct Obj01010 *)p)->f64))
            end = PM_VOICE_GetDataSize(((struct Obj01010 *)p)->f64);
        if (k < 0x3c0) {
            lo = 500;
            hi = -500;
            for (; i < end; i++) {
                t = (*(s8 **)(p + 0x34))[i] * 0x2f * PM_VOICE_GetVolume(((struct Obj01010 *)p)->f64) / 128;
                v = (s16)(t / 128);
                if (v > 500)
                    v = 500;
                else if (v < -500)
                    v = -500;
                w = v;
                if (w < lo)
                    lo = w;
                if (w > hi)
                    hi = w;
            }
            if (lo <= hi) {
                if (lo < -55)
                    lo = -55;
                if (hi > 0x37)
                    hi = 0x37;
                BMP_FillRect(*(struct Bmp * *)&((struct Obj01010 *)p)->f2C, (s16)k, (s16)(0x37 - hi), 1, (u16)(hi - lo + 1), 0xf);
            }
        }
        k++;
        i = end + 1;
    }
    if (k > 0x3c0)
        k = 0x3c0;
    ((struct Obj01010 *)p)->f30 = k;
}

