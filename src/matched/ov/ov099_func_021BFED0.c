/*
 * function: WIFICLUB_StateErrorMessageWait
 * address: 0x021BFED0
 * packet: pkt_ov099_021BFED0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 GFL_NET_STATE_IsFatalError at +0006; concrete bytes match, no ARM9 source written.
 * blocker: scratch one --arm (no region), dsi/1.1p1 -O4,p: MATCH 52 bytes;
 *   _pNetState 0x021469DC data resolves, GFL_NET_STATE_FatalError 0x0203CADC arm remains unresolved.
 *   typedef struct { int pad[2]; void (*callback)(void); } Object;
 *   extern Object *_pNetState;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if(_pNetState && _pNetState->callback==GFL_NET_STATE_FatalError)return 1;
 *       return 0;
 *   }
 * blocker: nested scratch one --arm, same compiler/flags: GFL_NET_STATE_FatalError EXACT 36 bytes;
 *   file_020A7BA8 0x020A7BA8 data; message_020A7C7C 0x020A7C7C data;
 *   func_02034714 0x02034714 arm.
 *   extern const char file_020A7BA8[];
 *   extern const char message_020A7C7C[];
 *   extern void func_02034714(const char *,unsigned,const char *);
 *   void GFL_NET_STATE_FatalError(void) {
 *       func_02034714(file_020A7BA8,0x8d8,message_020A7C7C);
 *   }
 * diagnosis: caller-only tu --suggest-split MATCH 204 bytes; no viable split.
 * symbols:
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   WIFICLUB_OnFatalError 0x021BE900 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   WIFICLUB_StartNetSession 0x021BDD0C thumb ov099
 *   WIFICLUBACTOR_IsReady 0x021B96CC thumb ov099
 *   WIFICLUB_ResetOwnSeatStatus 0x021C19A8 thumb ov099
 *   WIFICLUB_DrawPlayerInfoWindow 0x021BAEDC thumb ov099
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   WIFICLUBACTOR_RestoreActorUpdate 0x021B9AE0 thumb ov099
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 */
extern int GFL_NET_STATE_IsFatalError(void);
extern void WIFICLUB_OnFatalError(char *);
extern unsigned WIFICLUB_GetStatusKind(char *,void *);
extern void WIFICLUB_SetOwnStatusAndPublish(char *,int,int);
extern int WIFICLUB_UpdateTalkStream(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void WIFICLUB_StartNetSession(void *p, int on);
extern int WIFICLUBACTOR_IsReady(int *p);
extern void WIFICLUB_ResetOwnSeatStatus(char *);
extern void WIFICLUB_DrawPlayerInfoWindow(char *);
extern int WIFICLUBACTOR_GetPickResult(char *);
extern void *WIFICLUB_FindPeerActor(char *,int);
extern void WIFICLUBACTOR_RestoreActorUpdate(void *w, u8 *s);
extern void WIFICLUB_DisableTouchBar(char *);
int WIFICLUB_StateErrorMessageWait(char *p,int ret)
{
    if(GFL_NET_STATE_IsFatalError()){WIFICLUB_OnFatalError(p);return ret;}
    if(WIFICLUB_GetStatusKind(p,*(void **)(p+8))!=1)WIFICLUB_SetOwnStatusAndPublish(p,1,2);
    if(!WIFICLUB_UpdateTalkStream(p)){*(int *)(p+0x1e0)=30;return ret;}
    --*(int *)(p+0x1e0);
    if((KEY_GetTrg()&3)||!*(int *)(p+0x1e0)){
        WIFICLUB_ClearTalkWindow(p);
        GFL_NET_STATE_WifiDisconnect(1);
        WIFICLUB_StartNetSession(p,0);
        if(!WIFICLUBACTOR_IsReady((int *)(p+0x274))){
            *(int *)(p+0x1e0)=20;
            *(int *)(p+0x1cc)=57;
        }else{
            WIFICLUB_ResetOwnSeatStatus(p);
            WIFICLUB_DrawPlayerInfoWindow(p);
            *(int *)(p+0x1f0)=-1;
            *(int *)(p+0x1cc)=11;
            WIFICLUBACTOR_RestoreActorUpdate(p+0x274,WIFICLUB_FindPeerActor(p,WIFICLUBACTOR_GetPickResult(p+0x274)));
            WIFICLUB_DisableTouchBar(p);
        }
    }
    return ret;
}
