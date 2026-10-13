/*
 * function: EVENT_COMM_COMMON_ChangeTalkedTypeEvent
 * address:  0x0218034C
 * packet:   pkt_ov018_0218034C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034714  0x02034714  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   EVENT_COMM_COMMON_StartMsgEvent110Alt  0x021829F8  thumb ov018
 *   EVENT_COMM_COMMON_ChangeTalkedMsgEvent  0x02180978  thumb ov018
 *   d_02183B30  0x02183B30  data ov018 a1
 *   d_02183B44  0x02183B44  data ov018 a1
 *   d_021837C4  0x021837C4  data ov018 a4
 */
#include "../include/Obj12503.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern char d_02183B30[];
extern char d_02183B44[];
extern void (*d_021837C4[])(int, void *);

typedef unsigned int   u32;
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 func_020307B0(void *p);
void func_02034714(const char *expr, u32 line, const char *file);
void MI_CpuCopy8(const void *src, void *dst, unsigned int n);
void EVENT_COMM_COMMON_StartMsgEvent110Alt(void *a, void *b);
void EVENT_COMM_COMMON_ChangeTalkedMsgEvent(int x, void *p);

void EVENT_COMM_COMMON_ChangeTalkedTypeEvent(int x, u8 *y)
{
    void *p = func_02030734((u16)((((struct Obj12503 *)y)->f0 & 0x7fff) | 0x8000), 0x98, 1, d_02183B30, 0x354);
    unsigned int c;

    MI_CpuCopy8(y, p, 0x98);
    c = y[0x41];
    if (c == 0) {
        EVENT_COMM_COMMON_ChangeTalkedMsgEvent(x, p);
    } else if (c == 1) {
        EVENT_COMM_COMMON_StartMsgEvent110Alt((void *)x, p);
    } else if (c == 2) {
        EVENT_COMM_COMMON_ChangeTalkedMsgEvent(x, p);
    } else if (c >= 3) {
        if (d_021837C4[c - 8] == 0) {
            func_02034714(d_02183B44, 0, d_02183B44);
        }
        d_021837C4[y[0x41] - 8](x, p);
    } else {
        EVENT_COMM_COMMON_ChangeTalkedMsgEvent(x, p);
    }
    func_020307B0(p);
}
