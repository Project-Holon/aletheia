/*
 * function: REPORT_UpdateWindows
 * address:  0x021EFFB4
 * packet:   pkt_ov034_021EFFB4
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     `h = p[2]` must be assigned before `s` in the second loop; the
 *           other order swaps p and the second counter between r5 and r6.
 *           EXACT* for the unlabelled follower at 0x021F0044.
 *
 * symbols:
 *   REPORT_UpdateWindows 0x021EFFB4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   func_02040588 0x02040588 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj07644.h"

struct PrintSys;
extern unsigned int PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);

void REPORT_UpdateWindows(int *p)
{
    unsigned int i;
    char *s;
    int h;

    if (!(p[0x4A] & 2) && PRINTSYS_QUE_IsFinished((const struct PrintSys *)p[2]) == 1) {
        func_02040588(4, 1);
        func_02040588(5, 1);
        func_02040588(6, 1);
        for (i = 0; i < 8; i++)
            BMP_WIN_MakeScreen((struct Cfg *)p[3 + i * 2]);
        func_02041B6C(5);
        p[0x4A] |= 2;
    }
    PRINTSYS_QUE_Main((struct PrintSys *)p[2]);
    for (i = 0; i < 8; i++) {
        h = p[2];
        s = (char *)p + i * 8;
        if (((struct Obj07644 *)s)->f10) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)h, (void *)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj07644 *)s)->fC)) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((struct Obj07644 *)s)->fC);
                ((struct Obj07644 *)s)->f10 = 0;
            }
        }
    }
}
