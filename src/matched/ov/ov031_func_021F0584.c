/*
 * function: func_021F0584
 * address:  0x021F0584
 * packet:   pkt_ov031_021F0584
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035D20  0x02035D20  arm
 *   func_0204B454  0x0204B454  arm
 *   func_021F0628  0x021F0628  thumb  ov031
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct { s16 x, y; } Pt;

extern u32 func_02035D20(u32 *outA, u32 *outB);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_021F0628(char *p, int sel);
extern void func_020061E4(u32 se);

int func_021F0584(int *p, u8 *flag)
{
    u32 w;
    u32 h;
    Pt t;
    int i;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;

    if (func_02035D20(&w, &h) == 0)
        return 0;
    for (i = 0; i <= 4; i++) {
        func_0204B454((struct Actor *)p[6 + i], (struct PtS *)&t, 1);
        y0 = t.y - 10;
        y1 = t.y + 10;
        x1 = t.x + 10;
        x0 = t.x - 10;
        if (x0 < w && x1 > w && y0 < h && y1 > h) {
            if (i == 0 && flag != 0) {
                flag[0x282E] = 1;
                return 0;
            }
            func_021F0628((char *)p, i);
            func_020061E4(0x54B);
            return 1;
        }
    }
    return 0;
}
