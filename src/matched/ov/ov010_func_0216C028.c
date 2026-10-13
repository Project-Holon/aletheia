/*
 * function: NAMEIN_SETUP_CreateMonArgs
 * address:  0x0216C028
 * packet:   pkt_ov010_0216C028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The heap id is a u16, as in NAMEIN_SETUP_CreateArgs; that keeps its entry spill
 * at the front of the prologue.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   STRBUF_Copy  0x02045838  arm
 *   d_02172A60     0x02172A60  data  ov010  a1
 */
#include "../include/Obj02352.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, int);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern char d_02172A60[];

int *NAMEIN_SETUP_CreateMonArgs(unsigned short a0, int a1, int a2, int a3, int s0)
{
    int *p = (int *)func_02030734(a0, 0x2c, 0, d_02172A60, 0x59);
    MI_CpuFill8(p, 0, 0x2c);
    p[0] = 1;
    p[6] = a2;
    p[2] = a1;
    p[10] = s0;
    if (a1) {
        int t;
        ((struct Obj02352 *)p)->f4 = func_02017E1C((void *)a1, 5, 0);
        t = func_02017E1C((void *)a1, 0x6f, 0);
        ((struct Obj02352 *)p)->f6 = (func_02017E1C((void *)a1, 0x6e, 0) << 8) | t;
    }
    p[8] = (int)STRBUF_Create(0xb, a0);
    if (a3)
        STRBUF_Copy((struct U16Vec *)p[8], (struct U16Vec *)a3);
    return p;
}
