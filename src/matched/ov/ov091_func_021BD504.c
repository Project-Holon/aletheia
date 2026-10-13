/*
 * function: PLIST_BATTLE_PrintOpponentMessage
 * address:  0x021BD504
 * packet:   pkt_ov091_021BD504
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PLIST_MESSAGE_IsWindowOpen  0x021BB7D8  thumb  ov091
 *   PLIST_MESSAGE_OpenWindow  0x021BB714  thumb  ov091
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb  ov091
 *   PLIST_MESSAGE_SetWordSetString  0x021BBA0C  thumb  ov091
 *   PLIST_MESSAGE_PrintText  0x021BB7E8  thumb  ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb  ov091
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetString  0x02045924  arm
 *   STRBUF_Delete  0x02045808  arm
 */
#include "../include/Obj00009.h"
#include "../include/Obj20922.h"
#include "../include/Obj20923.h"
#include "../include/Obj20924.h"
#include "../include/Obj20925.h"
#include "../include/Obj20926.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern int PLIST_MESSAGE_IsWindowOpen(void *unused, u32 p);
struct Strbuf;
struct U16Vec;
extern void PLIST_MESSAGE_OpenWindow(void *a, u32 *s, u32 k);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetString(int a, int b, int c, const void *d, int e);
extern void PLIST_MESSAGE_PrintText(u8 *a, u32 *s, u32 x);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void STRBUF_Delete(struct U16Vec *vec);

void PLIST_BATTLE_PrintOpponentMessage(char *a)
{
    int t;
    if (((struct Obj20922 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 == 0)
        return;
    if (PLIST_MESSAGE_IsWindowOpen(a, *(int *)&((struct Obj00009 *)a)->f150) == 0)
        PLIST_MESSAGE_OpenWindow(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), 1);
    if (((struct Obj20923 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f64 == 1) {
        t = (int)STRBUF_Create(0x10, ((struct Obj00009 *)a)->f0);
        STRBUF_SetString((struct Strbuf *)t, (const u16 *)(((struct Obj20924 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f78));
        PLIST_MESSAGE_CreateWordSet((u16 *)a, *(int *)&((struct Obj00009 *)a)->f150);
        PLIST_MESSAGE_SetWordSetString((int)a, *(int *)&((struct Obj00009 *)a)->f150, 0, (const void *)t, ((struct Obj20925 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f7C);
        PLIST_MESSAGE_PrintText((u8 *)a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), 0xA9);
        PLIST_MESSAGE_DestroyWordSet(a, *(int *)&((struct Obj00009 *)a)->f150);
        STRBUF_Delete((struct U16Vec *)t);
    } else {
        PLIST_MESSAGE_PrintText((u8 *)a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), ((struct Obj20926 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 + 0xA9);
    }
}
