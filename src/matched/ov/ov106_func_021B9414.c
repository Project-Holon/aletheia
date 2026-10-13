/*
 * function: func_021B9414
 * address:  0x021B9414
 * packet:   pkt_ov106_021B9414
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Computes a two-word source position into out[] from the mode at o->f14:
 *   0: plain copy of the o->fc / o->f10 pair (an 8-byte struct assignment,
 *      which is why the image loads both words before either store);
 *   1: half of both BMP_GetWidth and BMP_GetHeight minus half of the
 *      func_0201D304 / func_0201D42C probes of o->f18, added to o->fc / o->f10;
 *   2: only the second axis (BMP_GetHeight vs func_0201D42C), o->fc passes.
 *
 * symbols:
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 */

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
} Obj_021B9414;

typedef unsigned short u16;
struct Bmp;
extern u16 BMP_GetWidth(const struct Bmp *bmp);
struct Bmp;
extern u16 BMP_GetHeight(const struct Bmp *bmp);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);

void func_021B9414(Obj_021B9414 *o, int b, int *out)
{
    switch (o->f14) {
    case 0: {
        Pair *p = (Pair *)out;
        Pair *s = (Pair *)((char *)o + 0xc);
        *p = *s;
        return;
    }
    case 1: {
        u32 x = (u32)BMP_GetWidth((const struct Bmp *)o->f0) >> 1;
        u32 y = (u32)BMP_GetHeight((const struct Bmp *)o->f0) >> 1;
        x -= func_0201D304((struct StrObj *)o->f18, b, 0) >> 1;
        y -= func_0201D42C((struct StrObj *)o->f18, (void *)b) >> 1;
        out[0] = x + o->fc;
        out[1] = y + o->f10;
        return;
    }
    case 2: {
        u32 y = (u32)BMP_GetHeight((const struct Bmp *)o->f0) >> 1;
        u32 ny = y - (func_0201D42C((struct StrObj *)o->f18, (void *)b) >> 1);
        out[0] = o->fc;
        out[1] = ny + o->f10;
        return;
    }
    }
}
