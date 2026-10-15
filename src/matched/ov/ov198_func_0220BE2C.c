/*
 * function: B_PLIST_DRAW_DrawModePage
 * address:  0x0220BE2C
 * packet:   pkt_0220BE2C
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_PLIST_DRAW_PrintHeader  0x0220C60C  thumb  ov198
 *   B_PLIST_DRAW_DrawRows  0x0220D884  thumb  ov198
 *   B_PLIST_DRAW_DrawMode1  0x0220D9B4  thumb  ov198
 *   B_PLIST_DRAW_DrawMode2  0x0220DCA8  thumb  ov198
 *   B_PLIST_DRAW_DrawMode3  0x0220DC04  thumb  ov198
 *   B_PLIST_DRAW_DrawMode4  0x0220DD78  thumb  ov198
 *   B_PLIST_DRAW_DrawMode6  0x0220DE4C  thumb  ov198
 *   B_PLIST_DRAW_DrawMode7  0x0220DF20  thumb  ov198
 *   B_PLIST_DRAW_DrawMode5  0x0220E088  thumb  ov198
 */
#include "../include/Obj00507.h"

extern int B_PLIST_DRAW_PrintHeader(char *, int);
typedef unsigned char  u8;
extern void B_PLIST_DRAW_DrawRows(u8 *p);
extern int B_PLIST_DRAW_DrawMode1(char *);
extern int B_PLIST_DRAW_DrawMode2(char *);
extern int B_PLIST_DRAW_DrawMode3(char *);
extern int B_PLIST_DRAW_DrawMode4(char *);
extern int B_PLIST_DRAW_DrawMode6(char *);
extern int B_PLIST_DRAW_DrawMode7(char *);
extern int B_PLIST_DRAW_DrawMode5(char *);

int B_PLIST_DRAW_DrawModePage(char *a, int idx)
{
    switch (idx) {
    case 0: {
        unsigned char c;
        B_PLIST_DRAW_DrawRows((u8 *)a);
        c = *(unsigned char *)(*(int *)&((struct Obj00507 *)a)->f0 + 0x1f);
        if (c == 3)
            return B_PLIST_DRAW_PrintHeader(a, 7);
        if (c == 2)
            return B_PLIST_DRAW_PrintHeader(a, 9);
        return B_PLIST_DRAW_PrintHeader(a, 6);
    }
    case 8:
        B_PLIST_DRAW_DrawRows((u8 *)a);
        return B_PLIST_DRAW_PrintHeader(a, 0xa);
    case 1:
        return B_PLIST_DRAW_DrawMode1(a);
    case 2:
        return B_PLIST_DRAW_DrawMode2(a);
    case 3:
        return B_PLIST_DRAW_DrawMode3(a);
    case 4:
        return B_PLIST_DRAW_DrawMode4(a);
    case 5:
        return B_PLIST_DRAW_DrawMode5(a);
    case 6:
        return B_PLIST_DRAW_DrawMode6(a);
    case 7:
        return B_PLIST_DRAW_DrawMode7(a);
    }
}
