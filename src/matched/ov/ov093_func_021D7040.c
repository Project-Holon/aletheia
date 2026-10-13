/*
 * function: BTL_EVENT_RemoveFactor
 * address:  0x021D7040
 * packet:   pkt_ov093_021D7040
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlEventFactorList     0x021F3CB0  data
 *   BTL_EVENT_DebugPrintFactorList  0x021D6F08  thumb  ov093
 *   BTL_EVENT_FreeFactor  0x021D7494  thumb  ov093
 */

#include "../include/G_NodeList.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct {
    u32 lo : 24;
    u32 b24 : 1;
    u32 b25 : 1;
    u32 b26 : 1;
    u32 b27 : 1;
    u32 b28 : 1;
    u32 b29 : 1;
    u32 top : 2;
} Flags;

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    u8 pad8[0x10];
    Flags f18;
} Node;

extern struct NodeList gBtlEventFactorList;
extern void BTL_EVENT_DebugPrintFactorList(void);
extern void BTL_EVENT_FreeFactor(void *p);

void BTL_EVENT_RemoveFactor(Node *n)
{
    if (n != 0) {
        if (n->f18.b29) {
            if (n->f18.b24) {
                n->f18.b27 = 1;
                return;
            }
            if (n == gBtlEventFactorList.head)
                gBtlEventFactorList.head = n->next;
            if (n->prev != 0)
                n->prev->next = n->next;
            if (n->next != 0)
                n->next->prev = n->prev;
            BTL_EVENT_DebugPrintFactorList();
            BTL_EVENT_FreeFactor(n);
        }
    }
}
