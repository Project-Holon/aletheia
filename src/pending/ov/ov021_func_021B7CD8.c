/*
 * function: func_021B7CD8
 * address:  0x021B7CD8
 * packet:   pkt_ov021_021B7CD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF (Rect4 copy: last two halfword loads paired in the image; same residue as func_021B7DC0; see docs/notes/pkt_ov021_021B7DC0.c.txt)
 *
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021B7DC0  0x021B7DC0  thumb
 *   func_021B7DE0  0x021B7DE0  thumb
 *   func_021B7EE4  0x021B7EE4  thumb
 *   func_021B80E0  0x021B80E0  thumb
 *   func_021B810C  0x021B810C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;
typedef struct { u16 a, b, c, d; } Rect4;

struct Cam {
    u8 pad00[0x50];
    VecFx32 f50;
    Rect4 f5C;
    u8 pad64[8];
    Rect4 f6C;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 pad77;
    void *f78;
};

struct Mgr { u8 pad00[0x1C]; void *f1C; };

extern void func_021B7EE4(void *p, Rect4 *r);
extern void func_021B80E0(void *p, int a, u8 key);
extern void func_021B810C(void *p);
extern void func_021B7DC0(void *p, Rect4 *out);
extern int func_0203EFC8(const void *a, const void *b, u32 n);
extern u8 func_021B7DE0(void *p, Rect4 *r);

u8 func_021B7CD8(struct Mgr *m, Rect4 *r, u8 key, Rect4 *out)
{
    Rect4 old = *r;

    func_021B7EE4(m->f1C, r);
    func_021B80E0(m->f1C, 4, key);
    func_021B810C(m->f1C);
    func_021B7DC0(m->f1C, out);
    if (func_0203EFC8(&old, out, 8) == 0)
        return 0;
    return func_021B7DE0(m->f1C, out);
}
