/*
 * function: IRCBATTLEMATCH_PrintRetryMessage
 * address: 0x021BA530
 * packet: pkt_ov100_021BA530
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 veneer 0x0203D170 points to unlabelled 0x0203E590;
 *   veneer evidence cannot attest the target. the integrator owns the ARM9 fix.
 * blocker: 0x0203E590 ARM, verified EXACT with one in blocker-1.log.
 *   symbols: d_021469F0 0x021469F0 data a4
 *   extern unsigned char *d_021469F0;
 *   int GFL_NET_IRC_WIRELESS_GetRetryCountValue(void) {
 *     unsigned char *p=d_021469F0;
 *     if(p==0) return 0;
 *     return p[0x108];
 *   }
 * note 2026-10-04 (wD2 lane18): still MATCH, only unresolved relocations remain: callee GFL_NET_IRC_WIRELESS_GetRetryCount (veneer to 0x0203E590) still has no witness; GFL_NET_IRC_WIRELESS_GetRetryCountValue filed EXACT as src/matched/arm9/GFL_NET_IRC_WIRELESS_GetRetryCountValue.c, integrator must regenerate labels/manifest so the veneer resolves.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   GFL_NET_IRC_WIRELESS_GetRetryCount 0x0203D170 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 */
typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern int GFL_NET_IRC_WIRELESS_GetRetryCount(void);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
void IRCBATTLEMATCH_PrintRetryMessage(int b,int a) {
 if(*(int *)(a+0x280)==0) *(int *)(a+0x280)=(int)BMP_WIN_Create((int)5,(int)1,(int)8,(int)23,4,13,0);
 BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)(*(int *)(a+0x280))),(int)255);
 BMP_WIN_MakeScreen((struct Cfg *)(*(int *)(a+0x280)));
 BMP_WIN_TransferChars((struct Descriptor *)(*(int *)(a+0x280)));
 BMP_MENUWORK_DrawWindow((void *)(*(int *)(a+0x280)),0,(unsigned short)(*(int *)(a+0x304)),14);
 MSGDATA_ReadString((struct MsgBank *)(*(int *)(a+0x288)),(int)b,(void *)(*(int *)(a+0x294)));
 WORDSET_SetSlotNumber((struct WordSet *)(*(int *)(a+0x28c)),(int)0,(int)GFL_NET_IRC_WIRELESS_GetRetryCount(),(int)2,(int)1,(int)1);
 WORDSET_CopyTaggedText((struct WordSet *)(*(int *)(a+0x28c)),(void *)(*(int *)(a+0x298)),(void *)(*(int *)(a+0x294)));
 PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)(*(int *)(a+0x280))),0,2,(void *)(*(int *)(a+0x298)),(void *)(*(int *)(a+0x290)));
 BMP_WIN_TransferChars((struct Descriptor *)(*(int *)(a+0x280)));
}
