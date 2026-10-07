/*
 * function: func_021CD018
 * address:  0x021CD018
 * packet:   pkt_ov016_021CD018
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      moveFocus (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD018.c \n *       --func func_021CD018 --addr 0x021CD018 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021C0EF0  0x021C0EF0  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021BD4C8  0x021BD4C8  arm  ov016
 *   g_021DE614     0x021DE614  data
 *   g_021DA7DF     0x021DA7DF  data
 *   g_021DA858     0x021DA858  data
 *   g_021DA85A     0x021DA85A  data
 *   g_021DA85C     0x021DA85C  data
 *   g_021DA85E     0x021DA85E  data
 */

#include "../include/G_FocusState.h"

typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;
typedef struct { unsigned short left, top, right, bottom; } Rect;

extern struct FocusState g_021DE614;
extern signed char g_021DA7DF[2][4][4];
extern Rect g_021DA858[2][4];
extern int func_021C0EF0(unsigned long flag);
extern void func_021CFFAC(unsigned int v);
extern void func_021BD4C8(int x0, int x1, int y0, int y1);

void func_021CD018(int dir)
{
    signed char prev = g_021DE614.cur;
    signed char next = g_021DA7DF[func_021C0EF0(1)][prev][dir];
    if (next == -1)
        return;
    if (next == 0)
        g_021DE614.last = prev;
    if (next == -2)
        g_021DE614.cur = g_021DE614.last;
    else
        g_021DE614.cur = next;
    func_021CFFAC(8);
    func_021BD4C8(g_021DA858[func_021C0EF0(1)][g_021DE614.cur].left,
                  g_021DA858[func_021C0EF0(1)][g_021DE614.cur].right,
                  g_021DA858[func_021C0EF0(1)][g_021DE614.cur].top,
                  g_021DA858[func_021C0EF0(1)][g_021DE614.cur].bottom);
}
