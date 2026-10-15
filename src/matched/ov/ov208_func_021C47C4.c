/*
 * function: ZUKAN_DETAIL_FORM_BuildFormLabelText
 * address:  0x021C47C4
 * packet:   pkt_ov208_021C47C4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_Callback  0x0201EE60  thumb
 *   func_0201F250  0x0201F250  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   func_02045EC0  0x02045EC0  arm
 */
#include "../include/Obj06686.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16  ZUKAN_DETAIL_COMMON_GetCurrentEntry(int key);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);

void ZUKAN_DETAIL_FORM_BuildFormLabelText(u16 *heap, u8 *p, int key, u32 *outStr, u32 *outB, int *outC, int *outD,
                         u16 idx)
{
    u32 str = 0;
    u32 b = 0;
    int c = 0;
    int d = 0;
    u16 k;
    u32 ws;
    u32 src;
    u16 n;
    u16 i;

    k = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    switch (*(u32 *)(p + 0x148 + idx * 16)) {
    case 0:
        ws = (u32)GF_FONT_Create_EC64(*heap);
        src = ((struct Obj06686 *)p)->f5A4;
        str = (u32)STRBUF_Create(0x40, *heap);
        WORDSET_Callback((struct WordSet *)ws, 0, k);
        func_0201F250((struct WordSet *)ws, (void *)str, (void *)src);
        WORDSET_DeleteStrbufED04((struct WordSet *)ws);
        c = 1;
        break;
    case 1:
        switch (*(u16 *)(p + 0x150 + idx * 16)) {
        case 0:
            str = ((struct Obj06686 *)p)->f5A8;
            break;
        case 1:
            str = ((struct Obj06686 *)p)->f5AC;
            break;
        }
        break;
    case 2:
        n = *(u16 *)(p + 0x150 + idx * 16);
        for (i = 0; i != n; i++) {
            k = (*(u16 **)(p + 0x594))[k];
            if (k == 0)
                break;
        }
        str = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06686 *)p)->f598), k);
        c = 1;
        break;
    }
    switch (*(u32 *)(p + 0x14c + idx * 16)) {
    case 0:
    case 1:
        break;
    case 2:
        b = ((struct Obj06686 *)p)->f5B0;
        d = 0;
        break;
    }
    *outStr = str;
    *outB = b;
    *outC = c;
    *outD = d;
}
