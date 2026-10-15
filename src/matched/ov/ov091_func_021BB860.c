/*
 * function: PLIST_MESSAGE_StartStream
 * address:  0x021BB860
 * packet:   pkt_ov091_021BB860
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   PLIST_MESSAGE_RedrawWindow  0x021BBA28  thumb  ov091
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   PLIST_MESSAGE_StreamCallback  0x021BB910  thumb  ov091
 */
#include "../include/Obj06213.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef signed int     s32;
struct MsgBank;
struct Rec;
struct Rec3;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PLIST_MESSAGE_RedrawWindow(int a, int b);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_CTRL_Init(u8 *p, u32 v);
extern signed char MSG_SPEED_GetWait(void);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern int PLIST_MESSAGE_StreamCallback(int k);

void PLIST_MESSAGE_StartStream(u8 *a, u32 *s, u32 x, u32 y)
{
    u32 t;
    u32 n;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06213 *)a)->f134), x);
    if (s[11] != 0) {
        n = (u32)STRBUF_Create(0x100, ((struct Obj06213 *)a)->f0);
        WORDSET_CopyTaggedText((struct WordSet *)s[11], (void *)n, (void *)t);
        STRBUF_Delete((struct U16Vec *)t);
        t = n;
    }
    PLIST_MESSAGE_RedrawWindow((int)a, (int)s);
    if (s[3] != 0) {
        PRINTSYS_PrintStreamDelete((struct Rec3 *)s[3]);
        STRBUF_Delete((struct U16Vec *)s[4]);
    }
    s[8] = y;
    s[4] = t;
    PRINTSYS_CTRL_Init((u8 *)(s + 6), 6);
    s[3] = (u32)PRINTSYS_PrintStreamCallBack(s[1], 0, 0, s[4], ((struct Obj06213 *)a)->f138, MSG_SPEED_GetWait(), s[2], 0,
                         ((struct Obj06213 *)a)->f0, 0xf, (u32)PLIST_MESSAGE_StreamCallback);
}
