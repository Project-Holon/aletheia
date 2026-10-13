/*
 * function: BTL_MAIN_StepParent
 * address:  0x021B8434
 * packet:   pkt_ov093_021B8434
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
 *   BTL_SERVER_Update  0x021BAB9C  thumb  ov093
 *   BTL_SERVER_GetFinalData  0x021BABDC  thumb  ov093
 *   BTL_CLIENT_RunTick  0x021CD97C  thumb  ov093
 *   BTL_MAIN_CheckAllClientsReady  0x021B8564  thumb  ov093
 *   func_021CDD94  0x021CDD94  thumb  ov093
 *   func_021E908C  0x021E908C  thumb  ov093
 */
#include "../include/Obj05185.h"

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
extern int BTL_SERVER_Update(int);
extern void BTL_SERVER_GetFinalData(int, u8 *);
extern u8 BTL_CLIENT_RunTick(int);
extern int BTL_MAIN_CheckAllClientsReady(u8 *);
extern void func_021CDD94(char *p, int *o);
extern void func_021E908C(char *p);

int BTL_MAIN_StepParent(u8 *p)
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
    r = BTL_SERVER_Update(((struct Obj05185 *)p)->f8);
    if (r) {
        BTL_SERVER_GetFinalData(((struct Obj05185 *)p)->f8, p + 0x448);
    }
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 && p[i + 0xc4] == 0) {
            p[i + 0xc4] = BTL_CLIENT_RunTick(*(int *)(p + i * 4 + 0x10));
        }
    }
    if (BTL_MAIN_CheckAllClientsReady(p)) {
        func_021CDD94((char *)(*(int *)(p + p[0x46c] * 4 + 0x10)), (int *)(p + 0x448));
        r = 1;
    }
    func_021E908C((char *)(((struct Obj05185 *)p)->f4));
    return r;
}
