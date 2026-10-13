/*
 * function: FRAME_LIST_UpdateInit
 * address:  0x021B7A64
 * packet:   pkt_ov067_021B7A64
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FRAME_LIST_ClampScroll  0x021B7B7C  thumb  ov067
 *   FRAME_LIST_Redraw  0x021B7BE0  thumb  ov067
 *   func_0201C6B4  0x0201C6B4  thumb
 *   FRAME_LIST_UpdateWindows  0x021B9344  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct S {
    u8 pad00[0x34];
    u32 f34;
    u8 pad38[0x4e - 0x38];
    u16 f4e;
} S;

extern void FRAME_LIST_ClampScroll(S *p);
extern void FRAME_LIST_Redraw(struct S *p, int a1);
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void FRAME_LIST_UpdateWindows(S *p);

int FRAME_LIST_UpdateInit(S *p)
{
    switch (p->f4e) {
    case 0:
        FRAME_LIST_ClampScroll(p);
        FRAME_LIST_Redraw(p, 0);
        p->f4e = p->f4e + 1;
        break;
    case 1:
        if (func_0201C6B4((const struct PrintSys *)p->f34) == 1) {
            p->f4e = 0;
            return 0;
        }
        break;
    }
    FRAME_LIST_UpdateWindows(p);
    return 1;
}
