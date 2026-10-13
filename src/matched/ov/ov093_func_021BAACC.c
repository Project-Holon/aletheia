/*
 * function: BTL_SERVER_CreateClientAdapter
 * address:  0x021BAACC
 * packet:   pkt_ov093_021BAACC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   BTL_ADAPTER_Create  0x021EEA58  thumb  ov093
 *   BTL_SERVER_SetClientAdapterSlot  0x021BB840  thumb  ov093
 *   BTL_SERVER_SetClientParty  0x021BB848  thumb  ov093
 */
#include "../include/Obj13288.h"

typedef unsigned char u8;
typedef unsigned short u16;

char *func_021B9AEC(char *p, int i);
int BTL_ADAPTER_Create(int, int, int, int);
struct Q4;
void BTL_SERVER_SetClientAdapterSlot(struct Q4 *p, int a, int b, int c);
void BTL_SERVER_SetClientParty(u8 *p, void *q, u8 v);

void BTL_SERVER_CreateClientAdapter(char *p, int a, int b, int c, u8 d)
{
    char *x;
    int y;
    char *q;
    int off;

    x = func_021B9AEC(*(char * *)&((struct Obj13288 *)p)->f10, c);
    y = BTL_ADAPTER_Create(b, c, 1, ((struct Obj13288 *)p)->fCC0);
    q = p + 0x14;
    off = c * 12;
    BTL_SERVER_SetClientAdapterSlot((struct Q4 *)(q + off), c, y, 0);
    BTL_SERVER_SetClientParty((u8 *)(q + off), x, d);
}
