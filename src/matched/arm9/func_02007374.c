/*
 * function: func_02007374
 * address:  0x02007374
 * packet:   pkt_02007374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A7064     0x020A7064  data
 *   func_02034714  0x02034714  arm
 *   func_020087A8  0x020087A8  thumb
 *   func_020087D4  0x020087D4  thumb
 *   func_02031C10  0x02031C10  arm
 *
 * Release slot `a1` of the 0x14-stride handle table: the zero test on the
 * slot is a debug/guard call that passes the same pointer as argument 1 and
 * argument 3 (the compiler loads the pool word once and copies it twice, so
 * the source really did name it twice).  The object pointer at +0x10 is the
 * first argument of the final call and the table entry the second; the third
 * is the raw pointer func_020087D4 returns, not its target.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02007374.c \
 *       --func func_02007374 --addr 0x02007374 --cc 1.1p1 --thumb
 */
#include "../include/Obj15568.h"

typedef unsigned int u32;
typedef unsigned char u8;

extern char  g_020A7064[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_020087A8(void *sys, u32 index);
extern u32 *func_020087D4(void *sys, u32 index);
extern void  func_02031C10(u8 *a, u8 *b, u32 c);

void func_02007374(char *a0, u32 a1)
{
    u32 *slot = (u32 *)(a0 + 0x14);

    if (slot[a1] == 0) {
        func_02034714(g_020A7064, 0, g_020A7064);
    }
    func_020087A8(a0, a1);
    func_02031C10((u8 *)((struct Obj15568 *)a0)->f10, (u8 *)slot[a1], (u32)func_020087D4(a0, a1));
}
