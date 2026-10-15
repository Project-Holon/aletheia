/*
 * function: MYSTERY_NET_StartIrc
 * address: 0x021DE830
 * packet: pkt_ov121_021DE830
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   DELIVERY_IRC_Create 0x02157DD8 thumb ov010
 *   DELIVERY_IRC_Start 0x02157E34 thumb ov010
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   MYSTERY_NET_SetHandler 0x021DEEA4 thumb ov121
 *   MYSTERY_NET_RunIrc 0x021DE910 thumb ov121
 *   GAME_LANGUAGE_Code 0x0209DF0C data a1
 */
#include "../include/Obj06455.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Descriptor {
    int kind;
    u16 zero, heap;
    int size;
    void *data;
    int setting;
    int flags;
    u8 pad[0x60];
    int enabled;
} Descriptor;
extern void MI_CpuFill8(void *, int, int);
extern void *DELIVERY_IRC_Create(u8 *p);
extern int DELIVERY_IRC_Start(void *);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned, unsigned);
typedef unsigned int   u32;
extern void MYSTERY_NET_SetHandler(u32 *p, void *f);
extern void MYSTERY_NET_RunIrc(void *, int *, char *);
extern u8 GAME_LANGUAGE_Code;
void MYSTERY_NET_StartIrc(void *a, int *state, char *p)
{
    Descriptor d;
    switch (*state) {
    case 0:
        MI_CpuFill8(&d, 0, 0x7c);
        d.kind = 9;
        d.size = 0x2d0;
        d.data = p + 0x7a4;
        d.zero = 0;
        d.heap = ((struct Obj06455 *)p)->f58;
        d.setting = GAME_LANGUAGE_Code;
        d.enabled = 1;
        d.flags = 0x200000;
        ((struct Obj06455 *)p)->f79C = DELIVERY_IRC_Create((u8 *)(&d));
        DELIVERY_IRC_Start(((struct Obj06455 *)p)->f79C);
        ((struct Obj06455 *)p)->f17A4 = 0;
        *state = 1;
        break;
    case 1:
        if (GFL_NET_GetRunState()) {
            GFL_NET_RestartWithDefaultTimeout(1, ((struct Obj06455 *)p)->f58);
            *state = 2;
        }
        break;
    case 2:
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_RunIrc);
        break;
    }
}
