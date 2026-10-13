/*
 * function: COMM_ENTRY_PollParentList
 * address:  0x021CEDA0
 * packet:   pkt_ov021_021CEDA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_MenuFuncMain  0x021909E4  thumb  ov021
 *   GFL_NET_ConnectMacAddressChild  0x0203D000  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"

typedef unsigned char  u8;
typedef short          s16;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  name[0x20];
    u8  mac[6];
    u8  used;
    u8  pad;
    s16 timer;
    u8  pad2[2];
} Ent;

typedef struct {
    u32  f0;
    u32  f4;
    Ent  e[16];
    Ent *cur;
    u8   pad[5];
    u8   f2d1;
    u8   pad2[2];
    u16  f2d4;
} N;

struct Handle;
struct WordSet;
extern int FIELD_MSGBG_MenuFuncMain(struct Handle *h);
extern void GFL_NET_ConnectMacAddressChild(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void COMM_ENTRY_MENU_PrintMessage(u8 *p, u32 m);

int COMM_ENTRY_PollParentList(u8 *p)
{
    N *n = (N *)(p + 0x13c);
    int r;

    r = FIELD_MSGBG_MenuFuncMain((struct Handle *)n->f4);
    switch (r) {
    case -2:
        return 0;
    case -1:
        break;
    default:
        if (n->e[r].used == 1) {
            n->cur = &n->e[r];
            GFL_NET_ConnectMacAddressChild(n->cur->name + 0x20);
            func_0201F02C((struct WordSet *)(((struct Obj00011 *)p)->f4), 0, (void *)((int)n->cur));
            COMM_ENTRY_MENU_PrintMessage(p, 0x20);
            n->f2d4 = 0;
        }
        break;
    }
    return 1;
}
