/*
 * function: MONOLITH_TOOL_CreateBlink
 * address:  0x021B7070
 * packet:   pkt_ov071_021B7070
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   d_021BA84C     0x021BA84C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);
extern const Rect d_021BA84C;

void MONOLITH_TOOL_CreateBlink(int *p, int *out)
{
    Rect r;
    int h;

    r = d_021BA84C;
    h = (int)CLACT_CreateActor((void *)p[0x14 / 4], p[0x54 / 4], p[0x50 / 4], p[0x58 / 4], &r, 1, 0x61);
    CLACT_SetActorAutoAnim((struct Obj *)h, 1);
    *out = h;
}
