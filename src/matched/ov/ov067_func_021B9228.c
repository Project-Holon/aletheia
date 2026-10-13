/*
 * function: FRAME_LIST_DrawRowB
 * address:  0x021B9228
 * packet:   pkt_ov067_021B9228
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
    u8 f1;
    u8 _2[0x20 - 2];
    struct Ops *f20;
    void *f24;
    u8 _28[0x38 - 0x28];
    u8 *f38;
    u8 _3c[0x45 - 0x3c];
    u8 f45;
    s8 f46;
    s8 f47;
    u8 _48[0x66 - 0x48];
    s8 f66;
};

extern void FRAME_LIST_UploadRowTiles(struct S *s, u32 a1, u32 a2);
extern void FRAME_LIST_ScrollBgRows(struct S *p, int a1, int a2);
extern void FRAME_LIST_ClearBgRows(struct S *p, int a1, int a2);

void FRAME_LIST_DrawRowB(struct S *p, int i, int a2)
{
    int k;

    if (p->f1 != 0xff) {
        if (i >= 0) {
            k = p->f47 + p->f45;
            FRAME_LIST_UploadRowTiles(p, i, k);
            FRAME_LIST_ScrollBgRows(p, k, (int)a2);
            p->f20->fn(p->f24, i, p->f38 + k * 8, a2 * 8 - p->f66, 0);
        } else {
            FRAME_LIST_ClearBgRows(p, p->f1, a2);
        }
    }
}
