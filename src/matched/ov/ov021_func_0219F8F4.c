/*
 * function: FLDMMDL_DRAW_DrawWalking
 * address:  0x0219F8F4
 * packet:   pkt_ov021_0219F8F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetDrawOffset  0x0216D8B0  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FLDMMDL_DRAW_UpdateWalkOffset  0x0219F990  thumb  ov021
 *   FLDMMDL_DRAW_AddHeightOffset  0x0219FFBC  thumb  ov021
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FLDMMDL_DRAW_UpdateBlactFlags  0x021A000C  thumb  ov021
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 x, y, z;
} V3;

typedef struct {
    u16 id;
    u8 f2;
    u8 f3;
    u8 pad[4];
    u32 f8;
} St;

typedef signed int     s32;
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int FLDMMDL_GetBlActCont(int a0);
struct Trip;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_GetDrawOffset(u8 *p, u8 *q);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern void FLDMMDL_DRAW_UpdateWalkOffset(u32 a, u8 *p, u8 b);
extern void FLDMMDL_DRAW_AddHeightOffset(u32, u32 *);
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern void FLDMMDL_DRAW_UpdateBlactFlags(u32, u32, u32, u32, u32);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);

void FLDMMDL_DRAW_DrawWalking(u32 a)
{
    St *p;
    u8 flag;
    u32 h;
    u32 n;
    u32 buf[3];
    u32 v[3];

    p = FLDMMDL_GetDrawProcWork((void *)a);
    if (p->id != 0xFFFF) {
        flag = 0;
        h = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
        n = FLDMMDL_GetDirDisp((void *)a);
        if (n != p->f2) {
            flag = 1;
            p->f2 = n;
            p->f3 = 0;
            p->f8 = 0;
            BILLBOARD_ACT_SetEntryList((void *)h, p->id, p->f2);
            {
                V3 *pv = (V3 *)v;
                pv->x = 0;
                pv->y = 0;
                pv->z = 0;
                FLDMMDL_GetDrawOffset((u8 *)a, (u8 *)pv);
            }
        }
        FLDMMDL_DRAW_UpdateWalkOffset(a, (u8 *)p, n);
        FLDMMDL_ACMD_GetDrawPos((u8 *)a, (s32 *)buf);
        FLDMMDL_DRAW_AddHeightOffset(a, buf);
        BILLBOARD_SetElemPos((u8 *)BILLBOARD_ACT_GetBoard((u32 *)h), p->id, (struct Trip *)buf);
        FLDMMDL_DRAW_UpdateBlactFlags(a, h, p->id, flag, 0);
    }
}
