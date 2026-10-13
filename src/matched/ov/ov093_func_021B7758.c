/*
 * function: BTL_MAIN_SeqExchangeRegulation
 * address: 0x021B7758
 * packet: pkt_ov093_021B7758
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: k starts at 1 and is conditionally assigned 3; ternary reverses the short branch.
 * symbols:
 *   BTL_NET_HasCommError 0x021D4270 thumb ov093
 *   BTL_NET_BeginSync 0x021D4AF4 thumb ov093
 *   BTL_NET_PollSync 0x021D4B18 thumb ov093
 *   BTL_NET_SendParty 0x021D4438 thumb ov093
 *   BTL_NET_IsPartyReceived 0x021D44CC thumb ov093
 *   BTL_NET_AllocRelayPacket 0x021D4D24 thumb ov093
 *   BTL_NET_FillRelayPacket 0x021D4D64 thumb ov093
 *   BTL_NET_SendRelayedParty 0x021D4680 thumb ov093
 *   BTL_NET_IsRelayedPartyReceived 0x021D4784 thumb ov093
 *   BTL_NET_FreeRelayPacket 0x021D4D5C thumb ov093
 *   BTL_NET_GetParty 0x021D47A4 thumb ov093
 *   BTL_NET_FreeAfterPartyUse 0x021D4800 thumb ov093
 *   BTL_SIDE_Init 0x021B93E0 thumb ov093
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 *   BTL_MAIN_SetClientParty 0x021BA128 thumb ov093
 *   BTL_MAIN_CopyClientParty 0x021BA648 thumb ov093
 *   BTL_SIDE_SetupClientParty 0x021B9460 thumb ov093
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 */
#include "../include/Obj00764.h"
#include "../include/Obj20948.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;
extern int BTL_NET_HasCommError(void);
struct S;
extern void BTL_NET_BeginSync(int a);
extern int BTL_NET_PollSync(int a);
extern u8 BTL_NET_SendParty(u32 a);
extern int BTL_NET_IsPartyReceived(void);
extern void *BTL_NET_AllocRelayPacket(u32,u16);
extern void BTL_NET_FillRelayPacket(u32 *p, const void *src, u32 a);
extern u32 BTL_NET_SendRelayedParty(u32 *a);
extern int BTL_NET_IsRelayedPartyReceived(u32 a);
extern void BTL_NET_FreeRelayPacket(void *);
extern void *BTL_NET_GetParty(u8);
extern void BTL_NET_FreeAfterPartyUse(void);
extern void BTL_SIDE_Init(char *p, u32 a, u32 b);
extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);
extern void BTL_MAIN_SetClientParty(struct S *p, int i, void *x);
extern void BTL_MAIN_CopyClientParty(char *p, u8 k, void *dst);
extern void BTL_SIDE_SetupClientParty(char *a, char *b, u8 c);
extern int POKE_REGULATION_GetDataSize(void);
int BTL_MAIN_SeqExchangeRegulation(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    u8 *desc;
    int k;
    q = *(u8 * *)&((struct Obj00764 *)p)->f0;
    if (BTL_NET_HasCommError()) {
        ((B *)p)->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        BTL_NET_BeginSync((u8)2);
        ++*state;
        break;
    case 1:
        if (BTL_NET_PollSync((u8)2)) ++*state;
        break;
    case 2:
        if (BTL_NET_SendParty((u32)(((struct Obj20948 *)q)->f24))) ++*state;
        break;
    case 3:
        if (BTL_NET_IsPartyReceived()) {
            if (!p[0x471]) *state = 10;
            else {
                if (p[0x46e]) {
                    ((struct Obj00764 *)p)->f2C4 = BTL_NET_AllocRelayPacket(POKE_REGULATION_GetDataSize(), (((struct Obj00764 *)p)->f468 & 0x7fff) | 0x8000);
                }
                p[0x470] = 0;
                ++*state;
            }
        }
        break;
    case 4:
        k = 1;
        if (p[0x470]) k = 3;
        p[0x472] = k;
        if (p[0x46e]) BTL_NET_FillRelayPacket(((struct Obj00764 *)p)->f2C4, *(void **)(q + p[0x472] * 4 + 0x24),p[0x472]);
        BTL_NET_BeginSync((u8)(p[0x470] + 6));
        ++*state;
        break;
    case 5:
        if (BTL_NET_PollSync((u8)(p[0x470] + 6))) ++*state;
        break;
    case 6:
        if (!p[0x46e] || BTL_NET_SendRelayedParty(((struct Obj00764 *)p)->f2C4)) ++*state;
        break;
    case 7:
        if (BTL_NET_IsRelayedPartyReceived(p[0x472])) {
            ++p[0x470];
            if (p[0x470] >= p[0x471]) {
                if (p[0x46e]) {
                    BTL_NET_FreeRelayPacket(((struct Obj00764 *)p)->f2C4);
                    ((struct Obj00764 *)p)->f2C4 = 0;
                }
                *state = 10;
            } else *state = 4;
        }
        break;
    case 10:
        BTL_SIDE_Init((char *)(p + 0xc8),(u32)p,(int)0);
        desc = p + 0xc8;
        for (i = 0; i < 4; ++i) {
            if (BTL_MAIN_IsClientUsed(p,i)) {
                BTL_MAIN_SetClientParty((struct S *)p,(u8)i,BTL_NET_GetParty(i));
                BTL_MAIN_CopyClientParty((char *)p,i,BTL_NET_GetParty(i));
                BTL_SIDE_SetupClientParty((char *)desc,(char *)p,i);
            }
        }
        ++*state;
        break;
    case 11:
        BTL_SIDE_Init((char *)(p + 0x1b0),(u32)p,(int)1);
        for (i = 0; i < 4; ++i) {
            if (BTL_MAIN_IsClientUsed(p,i)) BTL_SIDE_SetupClientParty((char *)(p + 0x1b0),(char *)p,i);
        }
        ++*state;
        break;
    case 12:
        BTL_NET_FreeAfterPartyUse();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}
