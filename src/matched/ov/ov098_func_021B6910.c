/*
 * unit:     yes
 * address:  0x021B6910
 * packet:   pkt_ov098_021B6910
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PDC_MSG_PrintMessage0, PDC_MSG_PrintMessage3, PDC_MSG_PrintMessage1, PDC_MSG_PrintMessage2
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   PDC_GetMon  0x021B6140  thumb  ov098
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PDC_MSG_StartPrint  0x021B6B8C  thumb  ov098
 *   STRBUF_Delete  0x02045808  arm
 *   PDC_GetMyStatus  0x021B6148  thumb  ov098
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 */
#include "../include/Obj07932.h"
#include "../include/Obj07933.h"
#include "../include/Obj07934.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int PDC_GetMon(void *p);
extern u32 PDC_GetMyStatus(u8 *p);
struct WordSet;
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PDC_MSG_StartPrint(char *a, int b);
extern void STRBUF_Delete(struct U16Vec *vec);

void PDC_MSG_PrintMessage0(int a, int b) {
    int r;
    int t;
    r = (int)func_02045EC0((struct MsgBank *)(((struct Obj07932 *)a)->f20), 0);
    t = PDC_GetMon((void *)b);
    WORDSET_SetSlotMonNickname(((struct Obj07932 *)a)->f30, 0, (void *)t);
    WORDSET_CopyTaggedText((struct WordSet *)(*(int *)&((struct Obj07932 *)a)->f30), (void *)(((struct Obj07932 *)a)->f2C), (void *)r);
    PDC_MSG_StartPrint((char *)a, 0x50);
    STRBUF_Delete((struct U16Vec *)r);
}

void PDC_MSG_PrintMessage3(int a, int b) {
    int r;
    int t;
    r = (int)func_02045EC0((struct MsgBank *)(((struct Obj07933 *)a)->f20), 3);
    t = PDC_GetMyStatus((u8 *)b);
    WORDSET_SetSlotMyStatus((struct WordSet *)(((struct Obj07933 *)a)->f30), 0, (void *)t);
    WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj07933 *)a)->f30), (void *)(((struct Obj07933 *)a)->f2C), (void *)r);
    PDC_MSG_StartPrint((char *)a, 0);
    STRBUF_Delete((struct U16Vec *)r);
}

void PDC_MSG_PrintMessage1(int a, int b) {
    int r;
    int t;
    r = (int)func_02045EC0((struct MsgBank *)(((struct Obj07934 *)a)->f20), 1);
    t = PDC_GetMon((void *)b);
    WORDSET_SetSlotMonNickname(((struct Obj07934 *)a)->f30, 0, (void *)t);
    WORDSET_CopyTaggedText((struct WordSet *)(*(int *)&((struct Obj07934 *)a)->f30), (void *)(((struct Obj07934 *)a)->f2C), (void *)r);
    PDC_MSG_StartPrint((char *)a, 0x50);
    STRBUF_Delete((struct U16Vec *)r);
}

void PDC_MSG_PrintMessage2(int a, int b) {
    int r;
    int t;
    r = (int)func_02045EC0((struct MsgBank *)(((struct Obj07934 *)a)->f20), 2);
    t = PDC_GetMon((void *)b);
    WORDSET_SetSlotMonNickname(((struct Obj07934 *)a)->f30, 0, (void *)t);
    WORDSET_CopyTaggedText((struct WordSet *)(*(int *)&((struct Obj07934 *)a)->f30), (void *)(((struct Obj07934 *)a)->f2C), (void *)r);
    PDC_MSG_StartPrint((char *)a, 0x50);
    STRBUF_Delete((struct U16Vec *)r);
}
