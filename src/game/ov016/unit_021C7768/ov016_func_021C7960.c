/*
 * function: func_021C7960
 * address:  0x021C7960
 * packet:   pkt_ov016_021C7960
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispCaret (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * notes:    the OAM update is an inlined position setter (y term before x);
 *           the open-coded expression swaps r1 and r2.
 *
 * symbols:
 *   g_021DE5E4     0x021DE5E4  data
 *   g_021DA5D4     0x021DA5D4  data
 */

#include "../../../matched/include/G_MemSsea.h"

typedef struct GXOamAttr {
    union {
        struct {
            unsigned short attr0;
            unsigned short attr1;
        } h;
        unsigned int attr01;
    } u;
    unsigned short attr2;
    unsigned short attr3;
} GXOamAttr;

typedef struct MemSsea MemSsea;

extern struct MemSsea *g_021DE5E4;
extern unsigned char g_021DA5D4[];

static inline void SetObjPosition(GXOamAttr *oam, int x, int y)
{
    oam->u.attr01 = (oam->u.attr01 & ~(0x01FF0000 | 0x000000FF)) | (y & 0xFF) | ((x & 0x1FF) << 16);
}

void func_021C7960(void)
{
    int x = g_021DE5E4->pos;

    if (x > 3)
        x = 3;
    SetObjPosition(g_021DE5E4->caret, g_021DA5D4[x * 3 + 2], 0x28);
}
