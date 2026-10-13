/*
 * function: FLDMMDL_DRAW_DrawWalkAnime
 * address:  0x0219F354
 * packet:   pkt_ov021_0219F354
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
 *   FLDMMDL_GetDrawStatus  0x0216D678  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FLDMMDL_DRAW_GetDirIndex  0x0219FFD4  thumb  ov021
 *   FLDMMDL_DRAW_UpdateDirAnime  0x0219FEB0  thumb  ov021
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
    u16 id;
    u8 pad[2];
    u8 f4;
    u8 f5;
    u8 f6;
} St;

typedef signed int     s32;
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int FLDMMDL_GetBlActCont(int a0);
struct Trip;
extern u16 FLDMMDL_GetDrawStatus(void *p);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern u32 FLDMMDL_DRAW_GetDirIndex(u32);
extern void FLDMMDL_DRAW_UpdateDirAnime(u8 *s, u32 a, u32 r, u16 id);
extern void FLDMMDL_DRAW_AddHeightOffset(u32, u32 *);
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern void FLDMMDL_DRAW_UpdateBlactFlags(u32, u32, u32, u32, u32);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);

void FLDMMDL_DRAW_DrawWalkAnime(u32 a)
{
    St *p;
    u32 h;
    u32 n;
    u32 v;
    u8 flag;
    u32 buf[3];

    p = FLDMMDL_GetDrawProcWork((void *)a);
    if (p->id != 0xFFFF) {
        h = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
        n = FLDMMDL_GetDrawStatus((void *)a);
        if (n >= 10) {
            flag = 0;
            v = FLDMMDL_DRAW_GetDirIndex(a);
            if (n != p->f5) {
                flag = 1;
                p->f4 = v;
                p->f5 = n;
                p->f6 = 0;
                BILLBOARD_ACT_SetEntryList((void *)h, p->id, (u16)(n + 30));
            }
            FLDMMDL_DRAW_UpdateBlactFlags(a, h, p->id, flag, 0);
        } else {
            FLDMMDL_DRAW_UpdateDirAnime(&p->f4, a, h, p->id);
        }
        FLDMMDL_ACMD_GetDrawPos((u8 *)a, (s32 *)buf);
        FLDMMDL_DRAW_AddHeightOffset(a, buf);
        BILLBOARD_SetElemPos((u8 *)BILLBOARD_ACT_GetBoard((u32 *)h), p->id, (struct Trip *)buf);
    }
}
