/*
 * function: FRAME_LIST_DrawRowA
 * address:  0x021B91D0
 * packet:   pkt_ov067_021B91D0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FRAME_LIST_UploadRowTiles  0x021B8FE4  thumb
 *   FRAME_LIST_ScrollBgRows  0x021B90B8  thumb
 *   FRAME_LIST_ClearBgRows  0x021B9138  thumb
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Ops {
    void (*fn)(void *a, int b, u8 *c, s16 d, int e);
};

struct S {
    u8 f0;
    u8 _1[0x20 - 1];
    struct Ops *f20;
    void *f24;
    u8 _28[0x38 - 0x28];
    u8 *f38;
    u8 _3c[0x46 - 0x3c];
    s8 f46;
    u8 _47[0x4c - 0x47];
    u16 f4c;
    u8 _4e[0x66 - 0x4e];
    s8 f66;
};

extern void FRAME_LIST_UploadRowTiles(struct S *s, u32 a1, u32 a2);
extern void FRAME_LIST_ScrollBgRows(struct S *p, int a1, int a2);
extern void FRAME_LIST_ClearBgRows(struct S *p, int a1, int a2);

void FRAME_LIST_DrawRowA(struct S *p, int i, int a2)
{
    if (i >= 0 && i < p->f4c) {
        FRAME_LIST_UploadRowTiles(p, i, p->f46);
        FRAME_LIST_ScrollBgRows(p, p->f46, a2);
        p->f20->fn(p->f24, i, p->f38 + p->f46 * 8, a2 * 8 - p->f66, 1);
    } else {
        FRAME_LIST_ClearBgRows(p, p->f0, a2);
    }
}
