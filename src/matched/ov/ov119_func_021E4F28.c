/*
 * function: func_021E4F28
 * address:  0x021E4F28
 * packet:   pkt_ov119_021E4F28
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * lever:    the hoisted column sum is written inside the else arm as two statements.
 * symbols:
 *   func_021E5158 0x021E5158 thumb ov119
 *   func_021DF6B4 0x021DF6B4 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj05334.h"
#include "../include/Obj08071.h"
typedef short s16;
typedef unsigned char u8;
typedef struct Pt { s16 x, y; } Pt;
extern int func_021E5158(int);
extern int func_021DF6B4(char *, int, int);
extern u8 func_020355C4(void);
extern void CLACT_SetActorDrawPriority(int, u8);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021E4F28(char *p)
{
    char *q;
    int i, off, y, row, j, x, ty, col;
    Pt b, a;
    off = 0;
    y = ((struct Obj05334 *)p)->f1080;
    for (i = 0; i < 12; i++) {
        row = func_021E5158(((struct Obj05334 *)p)->f1080 + i);
        if (y >= ((struct Obj05334 *)p)->f634) {
            y -= ((struct Obj05334 *)p)->f634;
            off = ((struct Obj05334 *)p)->f63C;
        }
        for (j = 0; j < 5; j++) {
            ty = j * 24 + 0x20;
            if (y == 0) x = 0x1c;
            else if (y == 1) x = 0x3c;
            else {
                col = (y - 2) / 6 * 160;
                col += (y - 2) % 6 * 24 + 0x14;
                x = col + 0x60;
            }
            b.x = off + (x - ((struct Obj05334 *)p)->f107C);
            b.y = ty;
            a = b;
            if (func_021DF6B4(p, y, j) && func_020355C4() == 1) {
                b.y -= 8;
                q = p + row * 20 + j * 4;
                CLACT_SetActorDrawPriority(((struct Obj08071 *)q)->fAC0, 11);
            } else {
                q = p + row * 20 + j * 4;
                CLACT_SetActorDrawPriority(((struct Obj08071 *)q)->fAC0, 0x1c - i);
            }
            func_0204B404((struct Obj *)(((struct Obj08071 *)q)->fAC0), (const struct Vec2 *)(&b), 1);
            if (*(u8 *)(p + row * 5 + j + 0xebc)) {
                *(Pt *)(q + 0xdcc) = a;
            }
            b.y = ty + 3;
            func_0204B404((struct Obj *)(((struct Obj08071 *)q)->fBB0), (const struct Vec2 *)(&b), 1);
        }
        y++;
    }
}
