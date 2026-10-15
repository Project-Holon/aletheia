/*
 * function: WIFICLUB_SyncPresenceLists
 * address: 0x021BF084
 * packet: pkt_ov099_021BF084
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: duplicated calls in the final if/else-if preserve the branch-to-branch tail.
 * symbols:
 *   WIFICLUB_RefreshVisibleList 0x021BE788 thumb ov099
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   WIFICLUBACTOR_StartDespawn 0x021B99F4 thumb ov099
 *   WIFICLUB_RemovePeerActor 0x021BE244 thumb ov099
 *   WIFICLUB_ClearSlotState 0x021C203C thumb ov099
 *   WIFICLUB_ClosePanelIfSlotSelected 0x021C1A14 thumb ov099
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUBACTOR_SpawnSlotActor 0x021B9968 thumb ov099
 *   WIFICLUB_SetSlotState 0x021C2028 thumb ov099
 *   WIFICLUB_AddPeerActor 0x021BE21C thumb ov099
 *   MI_CpuCopy8 0x02082D44 arm
 *   WIFICLUB_RequestPanelRedraw 0x021C207C thumb ov099
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj22049.h"
typedef unsigned char u8;
extern int WIFICLUB_RefreshVisibleList(char *);
typedef signed int     s32;
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, unsigned int n);
extern void *WIFICLUB_FindPeerActor(char *,int);
extern void WIFICLUBACTOR_StartDespawn(char *,void *);
extern void WIFICLUB_RemovePeerActor(char *,void *);
extern void WIFICLUB_ClearSlotState(char *,int);
extern void WIFICLUB_ClosePanelIfSlotSelected(char *p, int b, void *c);
extern int WIFICLUB_GetFriendStatus(int i);
extern void *WIFICLUBACTOR_SpawnSlotActor(char *,int,int);
typedef unsigned int   u32;
extern void WIFICLUB_SetSlotState(char *p, int i, u8 v);
extern void WIFICLUB_AddPeerActor(char *,void *);
extern void MI_CpuCopy8(void *,void *,int);
extern void WIFICLUB_RequestPanelRedraw(char *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int WIFICLUB_SyncPresenceLists(char *p)
{
    int ret=WIFICLUB_RefreshVisibleList(p);
    int removed=0;
    int added=0;
    int i,j,found;
    void *v;
    char *s;
    if(GF_STANDARD_CompareBytes((const u8 *)(p+0x10),(const u8 *)(p+0x30),32)){
        for(i=0;i<32;i++){
            found=0;
            for(j=0;j<32;j++){
                if(*(u8 *)(p+j+0x10)==*(u8 *)(p+i+0x30)){found=1;break;}
            }
            if(!found && *(u8 *)(p+i+0x30)){
                v=WIFICLUB_FindPeerActor(p,*(u8 *)(p+i+0x30));
                if(v){
                    WIFICLUBACTOR_StartDespawn(p+0x274,v);
                    WIFICLUB_RemovePeerActor(p,v);
                    WIFICLUB_ClearSlotState(p,*(u8 *)(p+i+0x30));
                    WIFICLUB_ClosePanelIfSlotSelected(p,*(u8 *)(p+i+0x30),(void *)33);
                    added=1;
                }else{
                    WIFICLUB_ClearSlotState(p,*(u8 *)(p+i+0x30));
                }
            }
            found=0;
            for(j=0;j<32;j++){
                if(*(u8 *)(p+i+0x10)==*(u8 *)(p+j+0x30)){found=1;break;}
            }
            if(!found && *(u8 *)(p+i+0x10)){
                s=(char *)WIFICLUB_GetFriendStatus(*(u8 *)(p+i+0x10)-1);
                v=WIFICLUBACTOR_SpawnSlotActor(p+0x274,((struct Obj22049 *)s)->f14,*(u8 *)(p+i+0x10));
                if(v){
                    WIFICLUB_SetSlotState(p,*(u8 *)(p+i+0x10),2);
                    WIFICLUB_AddPeerActor(p,v);
                    removed=1;
                }else{
                    WIFICLUB_SetSlotState(p,*(u8 *)(p+i+0x10),1);
                }
            }
        }
        MI_CpuCopy8(p+0x10,p+0x30,32);
        if(removed || added)WIFICLUB_RequestPanelRedraw(p);
        if(removed==1){GFL_USE_PlaySeDefaultVolume(0x676);}
        else if(added==1){GFL_USE_PlaySeDefaultVolume(0x676);}
    }
    return ret;
}
