/*
 * function: POKETRADE_PROC_StepBeginBrowse
 * address: 0x021DBA38
 * packet: pkt_ov119_021DBA38
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_ClearSideMon 0x021D94A0 thumb ov119
 *   POKETRADE_PROC_StepNone 0x021D8E80 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepEnterBrowsing 0x021DBAF8 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
typedef unsigned short u16;

extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_ClearSideMon(void *,int);
extern void POKETRADE_PROC_StepNone(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
typedef unsigned int   u32;
struct Entry;
extern void POKETRADE_PROC_StepEnterBrowsing(char *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
void POKETRADE_PROC_StepBeginBrowse(void *p)
{
    if (POKETRADE_PROC_IsNetSession(p)==0) {
        POKETRADE_PROC_ClearSideMon(p,1);
        POKETRADE_PROC_StepNone(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepEnterBrowsing);
        return;
    }
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc06,0,0)!=0)
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepEnterBrowsing);
}
