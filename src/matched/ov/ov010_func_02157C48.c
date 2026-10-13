/*
 * function: DELIVERY_IRC_StepSearchEntry
 * address:  0x02157C48
 * packet:   pkt_ov010_02157C48
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * levers: the RNG result is the third argument to func_0203F328, kept live
 *   in r2 across its preceding store. The bound is read as p->n in the for
 *   condition rather than through n; expanding that one use changes the
 *   hoisted bound/far-word allocation from r7/r6 to the original r6/r7.
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02039C68  0x02039C68  arm
 *   func_0203F328  0x0203F328  arm
 *   func_020056EC  0x020056EC  thumb
 *   DELIVERY_IRC_SetStepAtLine  0x02157960  thumb
 *   DELIVERY_IRC_StepSendData  0x02157AF0  thumb
 *   DELIVERY_IRC_StepSendCrc  0x02157B88  thumb
 */
#include "../include/Obj01831.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Object {
    u32 f00;
    u8 pad04[0x74];
    u32 n;
} Object;

struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 func_02039CB4(struct Link *, u32, u32);
extern void func_02039C68(struct Link *, u32, u32);
extern void func_0203F328(u16 *, u32, u32);
extern u32 func_020056EC(u32 range);
extern void DELIVERY_IRC_SetStepAtLine(int, int, int);
extern void DELIVERY_IRC_StepSendData(int *);
extern void DELIVERY_IRC_StepSendCrc(int *);

void DELIVERY_IRC_StepSearchEntry(Object *p)
{
    u8 *b = (u8 *)p;
    int *e;
    u32 i;
    unsigned long n;
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, (u8)p->f00) == 0)
        return;
    if (b[0x675] != 0) {
        e = 0;
        b[0x676] = 0;
        n = p->n;
        for (i = 0; i < p->n; i++) {
            e = (int *)(b + 8 + i * 16);
            if (e[2] == ((struct Obj01831 *)b)->f67C && (e[3] & ((struct Obj01831 *)b)->f680)) {
                b[0x677] = i;
                b[0x676] = 1;
                break;
            }
        }
        DELIVERY_IRC_SetStepAtLine((int)p, (int)DELIVERY_IRC_StepSendCrc, 0x188);
        if (b[0x676] == 1) {
            u32 t = func_020056EC(0);
            ((struct Obj01831 *)b)->f668 = t;
            func_0203F328((u16 *)e[1], e[0], t);
            *(int * *)&((struct Obj01831 *)b)->f664 = e;
        }
        return;
    }
    func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)p->f00);
    DELIVERY_IRC_SetStepAtLine((int)p, (int)DELIVERY_IRC_StepSendData, 0x193);
}
