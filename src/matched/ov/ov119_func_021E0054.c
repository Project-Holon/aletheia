/*
 * function: func_021E0054
 * address: 0x021E0054
 * packet: pkt_ov119_021E0054
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a 40-byte struct with unnamed bit and alignment padding reproduces the packet RMW; func_0200960C needs an explicit Thumb symbols line to use its existing matched witness.
 * initialization: MYSTATUS_Copy fills all 32 prefix bytes; every named tail field is assigned before sending. The five unnamed bits at +0x26 and implicit +0x27 padding are unspecified, as in the original. No named member is read before assignment.
 * padding: c12 handler func_021D9248 copies the 40-byte object to func_0202EB7C/EB9C; func_0202ED90 replaces bits 3 and 4 before record getters can use them. unit_020095C8 getters use only bits 0..4, never bits 5..7 or +0x27.
 * symbols:
 *   func_0200960C 0x0200960C thumb
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0030 0x021E0030 thumb ov119
 *   func_021E0C78 0x021E0C78 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Packet {
    u32 prefix[8];
    u16 first,second;
    u8 a,b;
    u8 mode:3;
    u8 :5;
};
typedef char PacketMustBe40[sizeof(struct Packet)==40?1:-1];
struct Big;
struct Entry;
struct Sub02009470Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MYSTATUS_Copy(void *,void *);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern u8 func_02009584(const struct Sub02009470Obj *obj);
extern u8 func_0200960C(const struct Sub02009470Obj *obj);
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *,int);
extern int func_021D8A24(void *);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *,u32,u32);
extern void func_021D8E84(void *,int);
extern void func_021E0030(void *);
extern void func_021E0C78(char *p);
void func_021E0054(char *p)
{
    struct Packet packet;
    void *saved,*first,*second;
    saved=func_02009470(GAME_DATA_GetSaveControl(((struct Obj00001 *)p)->f82C));
    if(func_021D8AA8(p)) {
        first=func_021D8FA4(p,0);
        second=func_021D8FA4(p,1);
    } else {
        first=func_021D8FA4(p,1);
        second=func_021D8FA4(p,0);
    }
    MYSTATUS_Copy(GAME_DATA_GetMyStatus(((struct Obj00001 *)p)->f82C),&packet);
    packet.first=POKE_TOOL_GetPartyValue(first,5,0);
    packet.second=POKE_TOOL_GetPartyValue(second,5,0);
    packet.a=func_02009628(saved);
    packet.b=func_02009584(saved);
    packet.mode=func_0200960C(saved);
    if(func_021D8A24(p)) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc12,40,(u32)(&packet))) {
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),23,8);
            func_021D8E84(p,(int)func_021E0030);
            return;
        }
    } else func_021D8E84(p,(int)func_021E0C78);
}
