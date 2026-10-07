/*
 * file:     draw_system_p01.c
 * unit:     yes
 * function: func_021B6A00, func_021B6A18, func_021B6A30, func_021B6A88, func_021B6ADC, func_021B6B68, func_021B6BE0
 * address:  0x021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021C88E8     0x021C88E8  data
 *   d_021C4D20 0x021C4D20 data a4
 *   d_021C4D10 0x021C4D10 data a1
 *   func_02030734 0x02030734 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   d_021C71D0 0x021C71D0 data a4
 */
#include "../../matched/include/Obj08255.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 heap; u8 kind, pad; u16 count, a, b, c, d; } Params;

typedef struct { u8 kind, pad; u16 count, x, y, a, b, c, d; void *data; } Object;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_0203D7C8(u32, u32, const char *, u16);
int func_021B6A00(void *a0, unsigned a1, void *a2);
int func_021B6A18(int a, int b, int c);
void func_021B6A30(short *src, unsigned char *dst, int n, int ctx);
void func_021B6A88(char *input, s16 *output, int size, char *state);
s8 func_021B6ADC(int sample, char *p);
s16 func_021B6B68(u8 code, const char *p);
Object *func_021B6BE0(Params *p);
extern u32 g_021C88E8[];
extern const int d_021C4D20[];
extern const s8 d_021C4D10[];
extern const char d_021C71D0[];


int func_021B6A00(void *a0, unsigned a1, void *a2)
{
    func_021B6A30((short *)a0, (unsigned char *)a2, (int)(a1 >> 1), (int)g_021C88E8);
    return (int)((a1 + 3) >> 2);
}


int func_021B6A18(int a, int b, int c)
{
    func_021B6A88((char *)a, (s16 *)c, b * 2, (void *)0x021C88E4);
    return b * 4;
}


/*
 * Packs the halfwords of src[0..n) into nibble pairs through func_021B6ADC and
 * writes the pair bytes to dst.
 *
 * Addresses are Black-image addresses.
 */
void func_021B6A30(short *src, unsigned char *dst, int n, int ctx)
{
    int i;
    int out = 0;
    int pend = 0;
    int have = 0;

    for (i = 0; i < n; i++) {
        unsigned char v = (unsigned char)func_021B6ADC(src[i], (char *)ctx);

        if (have == 0) {
            pend = v;
            have = 1;
        } else {
            have = 0;
            dst[out] = (unsigned char)(pend + ((v & 0xf) << 4));
            pend = 0;
            out++;
        }
    }

    if (have == 1)
        dst[out] = (unsigned char)pend;
}

void func_021B6A88(char *input, s16 *output, int size, char *state)
{
    int i, count;
    char code;
    count = size / 2;
    for (i = 0; i < count; i++) {
        code = input[i];
        output[i * 2] = func_021B6B68(code & 15, state);
        output[i * 2 + 1] = func_021B6B68((code & 240) >> 4, state);
    }
}

s8 func_021B6ADC(int sample, char *p)
{
    int code, delta, step, value, index;
    code = 0;
    index = ((struct Obj08255 *)p)->f2;
    value = ((struct Obj08255 *)p)->f0;
    step = d_021C4D20[index];
    sample -= value;
    if (sample < 0) { code = 8; sample = -sample; }
    delta = step >> 3;
    if (sample >= step) { code |= 4; sample -= step; delta += step; }
    step >>= 1;
    if (sample >= step) { code |= 2; sample -= step; delta += step; }
    step >>= 1;
    if (sample >= step) { code |= 1; delta += step; }
    if (code & 8) value -= delta;
    else value += delta;
    if (value > 32767) value = 32767;
    else if (value < -32767) value = -32767;
    index += d_021C4D10[code];
    if (index < 0) index = 0;
    if (index > 88) index = 88;
    ((struct Obj08255 *)p)->f0 = value;
    ((struct Obj08255 *)p)->f2 = index;
    return code & 15;
}

s16 func_021B6B68(u8 code, const char *p)
{
  int step;
  int value;
  int index;
  int delta;
  value = *((s16 *) p);
  index = *((s8 *) (p + 2));
  step = d_021C4D20[index];
  delta = step >> 3;
  if (code & 4)
    delta += step;
  if (code & 2)
    delta += step >> 1;
  if (code & 1)
    delta += step >> 2;
  if (code & 8)
  {
    value -= delta;
    if (value < (-32767))
      value = -32767;
  }
  else
  {
    value += delta;
    if (value > 32767)
      value = 32767;
  }
  index += d_021C4D10[code];
  if (index < 0)
    index = 0;
  else
    if (index > 88)
    index = 88;
  *((s16 *) p) = (s16) value;
  *((s8 *) (p + 2)) = index;
  return (s16) value;
}

Object *func_021B6BE0(Params *p)
{
    Object *q;
    q = func_02030734(p->heap, 20, 1, d_021C71D0, 64);
    q->data = func_0203D7C8(p->heap, p->count * 8, d_021C71D0, 65);
    q->kind = p->kind;
    q->count = p->count;
    q->a = p->a;
    q->b = p->b;
    q->c = p->c;
    q->d = p->d;
    q->x = 0;
    q->y = 0;
    return q;
}
