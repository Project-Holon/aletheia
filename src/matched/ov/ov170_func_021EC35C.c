/*
 * function: BOX2_SEQ_LoadMonIcon
 * address:  0x021EC35C
 * packet:   pkt_ov170_021EC35C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020079BC 0x020079BC thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_SEQ_LoadGraphicResource 0x021EC338 thumb
 *   MIi_CpuCopy32 0x02082A90 arm
 *   func_020307B0 0x020307B0 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 */
#include "../include/Obj24001.h"
#include "../include/Obj24002.h"

typedef unsigned int   u32;
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern void *BOX2_SEQ_LoadGraphicResource(char *p, void *b, void *c);
extern void MIi_CpuCopy32(const void *src, void *dst, unsigned size);
extern u32 func_020307B0(void *p);
extern int POKE_TOOL_GetIconPalette(void *a0);

void BOX2_SEQ_LoadMonIcon(char **p, int box)
{
    unsigned i;
    void *m;
    void *r;
    void *buf;
    for (i = 0; i < 0x1E; i++) {
        if (func_020079BC(((void **)p[0])[1], box, i, 0xA9, 0) == 0) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else if (((struct Obj24001 *)(p[0]))->f24 != 3 && ((unsigned char *)p)[0x14] == ((unsigned char *)p)[0x17]
                   && ((unsigned char *)p)[0x16] == i) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else {
            m = (void *)BOX2_MAIN_GetMonAt((void ***)p, box, i);
            r = BOX2_SEQ_LoadGraphicResource(p[11], m, &buf);
            MIi_CpuCopy32(((struct Obj24002 *)buf)->f14, p[11] + 0x1B4 + i * 0x200, 0x200);
            func_020307B0(r);
            *(unsigned char *)(p[11] + i + 0x3DB4) = POKE_TOOL_GetIconPalette(m);
            *(int *)(p[11] + i * 4 + 0x3DF8) = 1;
        }
    }
}
