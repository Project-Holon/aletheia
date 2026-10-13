/*
 * function: UNION_SUBDISP_Delete
 * address:  0x021EFFE8
 * packet:   pkt_ov031_021EFFE8
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_02026474  0x02026474  thumb
 *   PMS_DRAW_Delete  0x0202DC08  thumb
 *   UNION_SUBDISP_FreeFrameBgChar  0x021F0420  thumb  ov031
 *   UNION_SUBDISP_DeleteActors  0x021F056C  thumb  ov031
 *   UNION_SUBDISP_DeleteActorRes  0x021F04D4  thumb  ov031
 *   UNION_SUBDISP_DeleteLineWindows  0x021F0478  thumb  ov031
 *   UNION_SUBDISP_ExitBgs  0x021F0348  thumb  ov031
 *   UNION_SUBDISP_DeleteSystems  0x021F022C  thumb  ov031
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOff  0x02037190  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 func_02026474(void *obj);
struct Obj;
extern void PMS_DRAW_Delete(struct Obj *p);
extern void UNION_SUBDISP_FreeFrameBgChar(char *p);
extern void UNION_SUBDISP_DeleteActors(char *p);
extern void UNION_SUBDISP_DeleteActorRes(char *p);
extern void UNION_SUBDISP_DeleteLineWindows(char *p);
extern void UNION_SUBDISP_ExitBgs(void *p);
extern void UNION_SUBDISP_DeleteSystems(char *p);
extern u32 func_020307B0(void *p);
extern void GFL_NET_WM_ICON_EasyObjWindowOff(void);

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

void UNION_SUBDISP_Delete(u32 *p)
{
    u8 *q;

    q = (u8 *)func_02026474((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)p[0]));
    if (q != 0)
        q[0x282E] = 0;
    PMS_DRAW_Delete((void *)p[0x1F]);
    UNION_SUBDISP_FreeFrameBgChar((char *)p);
    UNION_SUBDISP_DeleteActors((char *)p);
    UNION_SUBDISP_DeleteActorRes((char *)p);
    UNION_SUBDISP_DeleteLineWindows((char *)p);
    UNION_SUBDISP_ExitBgs(p);
    UNION_SUBDISP_DeleteSystems((char *)p);
    func_020307B0(p);
    REG_DB_BLDCNT_SUB = 0;
    GFL_NET_WM_ICON_EasyObjWindowOff();
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}
