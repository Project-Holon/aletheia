/*
 * function: WIFICLUB_StatePollMenuChoicePrompt
 * address: 0x021C04D0
 * packet: pkt_ov099_021C04D0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   WIFICLUBACTOR_TickBlink 0x021B9B64 thumb ov099
 *   WIFICLUB_AddNetCommandsAndCheckFriend 0x021C23C8 thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_EnableTouchBar 0x021C23D8 thumb ov099
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUBACTOR_TickBlink(char *);
extern int WIFICLUB_AddNetCommandsAndCheckFriend(void *a, void *b);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void WIFICLUB_EnableTouchBar(char *,int);
extern void WIFICLUB_DisableTouchBar(char *);
extern void WIFICLUB_ClearTalkWindow(char *);
typedef enum { K274=0x274 } Off;
int WIFICLUB_StatePollMenuChoicePrompt(char *p,int ret) {
    int r;
    Off o;
    r=WIFICLUB_PollYesNoMenu(p);
    o=K274;
    WIFICLUBACTOR_TickBlink(p+o);
    if(r==-1)return ret;
    if(r==0){
        WIFICLUB_AddNetCommandsAndCheckFriend(p,(void *)(-1));
        WIFICLUB_SetOwnStatusAndPublish(p,2,5);
        WIFICLUB_EnableTouchBar(p,1);
        *(int *)(p+(o-0xa8))=158;
    } else {
        WIFICLUB_DisableTouchBar(p);
        WIFICLUB_ClearTalkWindow(p);
        *(int *)(p+(o-0xa8))=11;
    }
    return ret;
}
