/*
 * function: BTL_MAIN_SeqCreateView
 * address:  0x021B835C
 * packet:   pkt_ov093_021B835C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_NET_HasCommError  0x021D4270  thumb  ov093
 *   BTL_MAIN_IsCommCompetitor  0x021B6818  thumb  ov093
 *   BTLV_CORE_Create  0x021E8F20  thumb  ov093
 *   BTL_CLIENT_SetView  0x021CD95C  thumb  ov093
 *   BTL_SERVER_Restart  0x021BAB40  thumb  ov093
 *   BTL_MAIN_StepParent  0x021B8434  thumb  ov093
 *   BTL_MAIN_StepChild  0x021B84D8  thumb  ov093
 */
#include "../include/Obj03685.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
} B;

extern int BTL_NET_HasCommError(void);
extern unsigned int BTL_MAIN_IsCommCompetitor(unsigned int *p);
struct QA;
struct Scene;
extern struct Scene *BTLV_CORE_Create(void *a, void *b, u32 c, int d, u16 heap);
extern void BTL_CLIENT_SetView(struct QA *p, u32 v);
extern void BTL_SERVER_Restart(char *p);
extern int BTL_MAIN_StepParent(u8 *);
extern int BTL_MAIN_StepChild(u8 *);

int BTL_MAIN_SeqCreateView(u8 *p, int *q)
{
    int r, t;
    if (BTL_NET_HasCommError()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (*q == 0) {
        r = BTL_MAIN_IsCommCompetitor((unsigned int *)(*(int * *)&((struct Obj03685 *)p)->f0));
        t = (int)BTLV_CORE_Create(p, (void *)(*(int *)(p + p[0x46c] * 4 + 0x10)), (u32)(p + 0xc8), r, 0x13);
        ((struct Obj03685 *)p)->f4 = t;
        BTL_CLIENT_SetView((struct QA *)(*(int *)(p + p[0x46c] * 4 + 0x10)), t);
        if (p[0x46e]) {
            ((struct Obj03685 *)p)->f464 = (u32)BTL_MAIN_StepParent;
            BTL_SERVER_Restart((char *)(((struct Obj03685 *)p)->f8));
        } else {
            ((struct Obj03685 *)p)->f464 = (u32)BTL_MAIN_StepChild;
        }
        *q = *q + 1;
    } else {
        return 1;
    }
    return 0;
}
