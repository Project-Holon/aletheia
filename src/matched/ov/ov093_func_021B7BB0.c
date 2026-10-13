/*
 * function: BTL_MAIN_SeqExchangePerapVoice
 * address: 0x021B7BB0
 * packet: pkt_ov093_021B7BB0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_NET_HasCommError 0x021D4270 thumb ov093
 *   BTL_NET_ResetAfterParty 0x021D4500 thumb ov093
 *   BTL_NET_BeginSync 0x021D4AF4 thumb ov093
 *   BTL_NET_PollSync 0x021D4B18 thumb ov093
 *   BTL_NET_SendPerapVoice 0x021D450C thumb ov093
 *   BTL_NET_IsPerapVoiceReceived 0x021D45FC thumb ov093
 *   BTL_NET_GetPerapVoice 0x021D4648 thumb ov093
 *   BTL_NET_ResetAfterPerapVoice 0x021D4674 thumb ov093
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 *   BTL_MAIN_IsTrainerSlotNpc 0x021B9F70 thumb ov093
 *   BTL_MAIN_StoreClientVoiceFlag 0x021BA698 thumb ov093
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02007B44 0x02007B44 thumb
 *   func_02007B20 0x02007B20 thumb
 *   func_02007B00 0x02007B00 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj07743.h"
#include "../include/Obj20949.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;
extern int BTL_NET_HasCommError(void);
extern void BTL_NET_ResetAfterParty(void);
extern void BTL_NET_BeginSync(int);
extern int BTL_NET_PollSync(int);
extern u32 BTL_NET_SendPerapVoice(u32 *);
extern int BTL_NET_IsPerapVoiceReceived(void);
struct Sub02007AC8Entry;
extern u32 BTL_NET_GetPerapVoice(u32 a);
extern void BTL_NET_ResetAfterPerapVoice(void);
struct Big;
extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);
extern int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
extern void BTL_MAIN_StoreClientVoiceFlag(u8 *p, int k);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern void *func_02007B20(u32 heap);
extern u32 func_02007B00(void);
extern void MI_CpuCopy8(const void *,void *,u32);
int BTL_MAIN_SeqExchangePerapVoice(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    void *src;
    q = *(u8 * *)&((struct Obj07743 *)p)->f0;
    if (BTL_NET_HasCommError()) {
        ((B *)p)->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        BTL_NET_ResetAfterParty();
        BTL_NET_BeginSync(3);
        ++*state;
        break;
    case 1:
        if (BTL_NET_PollSync(3)) ++*state;
        break;
    case 2:
        if (BTL_NET_SendPerapVoice((u32 *)func_02007B44(GAME_DATA_GetSaveControl(((struct Obj20949 *)q)->f58)))) ++*state;
        break;
    case 3:
        if (BTL_NET_IsPerapVoiceReceived()) {
            for (i = 0; i < 4; ++i) {
                if (BTL_MAIN_IsClientUsed(p,i) && !BTL_MAIN_IsTrainerSlotNpc(p,(u8)i)) {
                    src = (void *)BTL_NET_GetPerapVoice((u8)i);
                    if (src) {
                        *(void **)(p + i * 4 + 0x3e0) = func_02007B20(((struct Obj07743 *)p)->f468);
                        MI_CpuCopy8(src, *(void **)(p + i * 4 + 0x3e0),func_02007B00());
                    }
                }
                BTL_MAIN_StoreClientVoiceFlag(p,(u8)i);
            }
            BTL_NET_ResetAfterPerapVoice();
            ++*state;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
