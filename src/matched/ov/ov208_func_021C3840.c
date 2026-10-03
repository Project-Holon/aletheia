/*
 * function: ov208_func_021C3840
 * address: 0x021C3840
 * packet: pkt_ov208_021C3840
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02006B5C 0x02006B5C thumb
 *   func_02006B94 0x02006B94 thumb
 *   func_02006B3C 0x02006B3C thumb
 *   func_02006B78 0x02006B78 thumb
 *   func_02006B20 0x02006B20 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02043AF4 0x02043AF4 arm
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fadd 0x0209C95C arm
 *   _fmul 0x0209C77C arm
 *   _ffixu 0x0209C4C8 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef signed char    s8;
typedef unsigned int   u32;

struct Bmp;

extern s8 *func_02006B5C(u32 i);
extern u32 func_02006B94(u32 i);
extern u32 func_02006B3C(u32 i);
extern u32 func_02006B78(u32 i);
extern s8 func_02006B20(u32 i);
extern void func_02043B5C(struct Bmp *b, u8 v);
extern void func_02043AF4(struct Bmp *b, u32 x, u32 y, u32 w, u32 h, u32 color);

void ov208_func_021C3840(u16 *heap, u8 *p, int key, u16 a, u16 b)
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
    *(s8 **)(p + 0x34) = func_02006B5C(*(u32 *)(p + 0x64));
    *(u16 *)(p + 0x32) = 0;
    if (a == *(u16 *)(p + 0x26) && b == *(u16 *)(p + 0x28))
        return;
    *(u16 *)(p + 0x26) = a;
    *(u16 *)(p + 0x28) = b;
    ca = func_02006B94(*(u32 *)(p + 0x64));
    cb = func_02006B3C(*(u32 *)(p + 0x64));
    *(u32 *)(p + 0x38) = (u32)(1000.0f * (32768.0f * (float)func_02006B78(*(u32 *)(p + 0x64))
                                           / (float)(int)ca
                                           / (float)(int)cb) + 0.5f);
    func_02043B5C(*(struct Bmp **)(p + 0x2c), 0);
    k = 0;
    i = 0;
    while (i < func_02006B78(*(u32 *)(p + 0x64))) {
        cb = func_02006B3C(*(u32 *)(p + 0x64));
        ca = func_02006B94(*(u32 *)(p + 0x64));
        end = (u32)((float)(k + 1) * ((float)(int)ca * (float)(int)cb / 32768.0f / 60.0f / 2.0f));
        if (end > func_02006B78(*(u32 *)(p + 0x64)))
            end = func_02006B78(*(u32 *)(p + 0x64));
        if (k < 0x3c0) {
            lo = 500;
            hi = -500;
            for (; i < end; i++) {
                t = (*(s8 **)(p + 0x34))[i] * 0x2f * func_02006B20(*(u32 *)(p + 0x64)) / 128;
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
                func_02043AF4(*(struct Bmp **)(p + 0x2c), (s16)k, (s16)(0x37 - hi), 1, (u16)(hi - lo + 1), 0xf);
            }
        }
        k++;
        i = end + 1;
    }
    if (k > 0x3c0)
        k = 0x3c0;
    *(u16 *)(p + 0x30) = k;
}

