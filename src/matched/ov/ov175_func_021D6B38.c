/*
 * function: WIFIBATTLEMATCH_NET_CompMain
 * address: 0x021D6B38
 * packet: pkt_ov175_021D6B38
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback 0x021E8A80 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull 0x021E8A90 thumb ov177
 *   WIFIBATTLEMATCH_NET_Noop 0x021D9ED0 thumb ov175
 *   WIFIBATTLEMATCH_GRAPHIC_Draw 0x021E5534 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_Main 0x021E867C thumb ov177
 *   WIFIBATTLEMATCH_VIEW_Noop 0x021E7E08 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdateAnimation 0x021E5980 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList 0x021E64C0 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdateRecordWindow 0x021E7774 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdatePartyWindow 0x021E84F8 thumb ov177
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
typedef unsigned char  u8;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void WIFIBATTLEMATCH_UTIL_InvokeCallback(unsigned);
extern int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **p);
extern void WIFIBATTLEMATCH_NET_Noop(int);
extern void WIFIBATTLEMATCH_GRAPHIC_Draw(u8 *p);
extern void WIFIBATTLEMATCH_UTIL_Main(char *p);
extern void WIFIBATTLEMATCH_VIEW_Noop(int);
extern void WIFIBATTLEMATCH_VIEW_UpdateAnimation(int);
extern int WIFIBATTLEMATCH_VIEW_UpdatePokeList(unsigned char *,void *);
extern int WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(void *p, void *mgr);
extern int WIFIBATTLEMATCH_VIEW_UpdatePartyWindow(char *p, void *q);
int WIFIBATTLEMATCH_NET_CompMain(unsigned sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(FADE_IsActive()==0) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_InvokeCallback(p[14]); if(WIFIBATTLEMATCH_UTIL_IsCallbackNull((int **)p[14])) *state=3; break;
    case 3: FADE_Start(3,0,16,0); *state=4; break;
    case 4: if(FADE_IsActive()==0) return 1; break;
    }
    WIFIBATTLEMATCH_GRAPHIC_Draw((u8 *)p[0]); PRINTSYS_QUE_Main((struct PrintSys *)p[4]); WIFIBATTLEMATCH_UTIL_Main((char *)p[11]);
    WIFIBATTLEMATCH_VIEW_Noop(p[10]); WIFIBATTLEMATCH_VIEW_UpdateAnimation(p[1]); WIFIBATTLEMATCH_NET_Noop(p[13]);
    if(p[7]) WIFIBATTLEMATCH_VIEW_UpdatePokeList((unsigned char *)p[7],(void *)p[4]);
    if(p[8]) WIFIBATTLEMATCH_VIEW_UpdateRecordWindow((void *)p[8],(void *)p[4]);
    if(p[9]) WIFIBATTLEMATCH_VIEW_UpdatePartyWindow((char *)p[9],(void *)p[4]);
    return 0;
}
