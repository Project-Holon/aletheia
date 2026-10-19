/*
 * function: dispFocus
 * address:  0x021C03F0
 * packet:   pkt_021C03F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_CELLlGetObj  0x021D4FE0  arm
 *   DWCi_CEINlSet  0x021D52D4  arm
 *   DWCi_CELLlSetPriority  0x021D51F0  arm
 *   DWCi_CELLlSetPosition  0x021D5118  arm
 *   gKeyboard10Work     0x021DE560  data
 *   sKeyboard10CellPosX     0x021DA3D8  data
 *   sKeyboard10CellPosY     0x021DA3DA  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

struct G {
    u8  pad00[0x58];
    int f58;
    u8  pad5c[7];
    s8  f63;
};

extern char *DWCi_CELLlGetObj(char *p, unsigned int i);
extern void  DWCi_CEINlSet(int a, int b, int c);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern struct G *gKeyboard10Work;
extern u16   sKeyboard10CellPosX[][2];
extern u16   sKeyboard10CellPosY[][2];

void dispFocus(void)
{
    struct G *g;
    int sel = 0x44;
    int v;

    g = gKeyboard10Work;
    if (g->f63 > 0xb)
        sel = 0x45;
    v = (int)DWCi_CELLlGetObj((char *)g->f58, 0);
    DWCi_CEINlSet(0, sel, v);
    g = gKeyboard10Work;
    DWCi_CELLlSetPriority((void *)g->f58, -1, 2);
    g = gKeyboard10Work;
    DWCi_CELLlSetPosition((void *)g->f58, -1, sKeyboard10CellPosX[g->f63][0], sKeyboard10CellPosY[g->f63][0]);
}
