/*
 * function: BTL_MAIN_StepChild
 * address:  0x021B84D8
 * packet:   pkt_ov093_021B84D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_NET_HasCommError  0x021D4270  thumb  ov093
 *   BTL_MAIN_MarkClientsDisconnected  0x021B8548  thumb  ov093
 *   BTL_CLIENT_RunTick  0x021CD97C  thumb  ov093
 *   BTL_CLIENT_GetCursor  0x021CDD94  thumb  ov093
 *   BTLV_CORE_Update  0x021E908C  thumb  ov093
 */
#include "../include/Obj20950.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
} B;

extern int BTL_NET_HasCommError(void);
extern void BTL_MAIN_MarkClientsDisconnected(u8 *);
extern int BTL_CLIENT_RunTick(int);
extern void BTL_CLIENT_GetCursor(char *p, int *o);
extern void BTLV_CORE_Update(char *p);

int BTL_MAIN_StepChild(u8 *p)
{
    int r, i;
    if (((B *)p)->a == 0) {
        if (BTL_NET_HasCommError()) {
            ((B *)p)->a = 1;
            BTL_MAIN_MarkClientsDisconnected(p);
        }
    } else if (((B *)p)->b != 0) {
        return 1;
    }
    r = 0;
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 &&
            BTL_CLIENT_RunTick(*(int *)(p + i * 4 + 0x10)) != 0) {
            BTL_CLIENT_GetCursor((char *)(*(int *)(p + i * 4 + 0x10)), (int *)(p + 0x448));
            r = 1;
        }
    }
    BTLV_CORE_Update((char *)(((struct Obj20950 *)p)->f4));
    return r;
}
