/*
 * function: UNION_SUBDISP_Draw
 * address:  0x021F0054
 * packet:   pkt_ov031_021F0054
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GFL_NET_WM_ICON_EasyObjWindowOn  0x02037174  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 GAME_COMM_GetWork(void *obj);
extern void GFL_NET_WM_ICON_EasyObjWindowOn(void);
extern void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void PMS_DRAW_Main(u8 *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *a);

#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

struct Obj {
    u32 w0;
    char pad0[0x40 - 4];
    u32 w40;
    char pad1[0x58 - 0x44];
    u32 b[3];
    struct Slot s[3];
    u32 w7c;
};

void UNION_SUBDISP_Draw(struct Obj *p, int mode)
{
    int i;

    GAME_COMM_GetWork((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)p->w0));
    GFL_NET_WM_ICON_EasyObjWindowOn();
    if (mode == 1)
        REG_DB_BLDCNT_SUB = 0;
    else
        G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
    PRINTSYS_QUE_Main((struct PrintSys *)p->w40);
    PMS_DRAW_Main((void *)p->w7c);
    for (i = 0; i < 3; i++) {
        if (p->b[i] == 1) {
            u32 q = p->w40;
            if (p->s[i].f != 0) {
                if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->s[i].h))) == 0) {
                    BMP_WIN_TransferChars((struct Descriptor *)p->s[i].h);
                    p->s[i].f = 0;
                }
            }
        }
    }
}
