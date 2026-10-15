/*
 * function: GIMMICK_OBJ_ELBOARD_AddDateMessage
 * address:  0x021F3E6C
 * packet:   pkt_ov048_021F3E6C
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_AddDateMessage  0x021F3E6C  thumb  ov048
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   RTC_GetDate  0x02088864  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F230  0x0201F230  thumb
 *   GIMMICK_OBJ_ELBOARD_AddMessage  0x021F3D38  thumb  ov048
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   gElboardLayout     0x021F50C0  data  a4
 */

#include "../include/G_T.h"

typedef unsigned int u32;
typedef unsigned short u16;
struct WordSet;
struct Date { int a, b, c, d; };
struct Rec { u16 h; u32 f4, f8, fc, f10, f14, f18; };
struct Tab { u16 pad[2]; u16 h4; };
extern struct T gElboardLayout;

extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
struct RTCDate;
extern int RTC_GetDate(struct RTCDate *date);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F230(struct WordSet *p, u32 i, u32 v);
extern void GIMMICK_OBJ_ELBOARD_AddMessage(int *p, int a, int b, int *c);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

void GIMMICK_OBJ_ELBOARD_AddDateMessage(int *p)
{
    struct { struct Date d; struct Rec r; } L;
    struct WordSet *w;

    w = GF_FONT_Create_EC64(*(u16 *)p);
    RTC_GetDate((struct RTCDate *)(&L.d));
    func_0201EFA4(w, 2, L.d.a, 2, 2, 1);
    func_0201F230(w, 0, L.d.b);
    func_0201EFA4(w, 1, L.d.c, 2, 0, 1);
    L.r.h = gElboardLayout.h;
    L.r.f4 = gElboardLayout.f2c;
    L.r.f8 = gElboardLayout.f48;
    L.r.fc = 2;
    L.r.f10 = 0x26;
    L.r.f14 = *(u32 *)(*(u32 *)((u32)p + 0x1c) + 0x18);
    L.r.f18 = (u32)w;
    GIMMICK_OBJ_ELBOARD_AddMessage(p, (int)(&L.r), 1, 0);
    WORDSET_DeleteStrbufED04(w);
}
