/*
 * function: POKE_SUMMARY_MAIN_SetTextByKind
 * address: 0x021B7378
 * packet: pkt_ov173_021B7378
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   POKE_SUMMARY_MAIN_GetRecordWord 0x021B7438 thumb ov173
 *   POKE_SUMMARY_MAIN_GetMoveWord 0x021B7448 thumb ov173
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   d_021B8350 0x021B8350 data a4
 */
#include "../include/Obj00544.h"
#include "../include/Obj24172.h"
#include "../include/Obj24173.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u16 POKE_SUMMARY_MAIN_GetRecordWord(char **);
extern unsigned short POKE_SUMMARY_MAIN_GetMoveWord(int *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern const u32 d_021B8350[][11];
void POKE_SUMMARY_MAIN_SetTextByKind(char *p, u32 kind)
{
    void *str;
    switch (kind) {
    case 0: func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0); break;
    case 1: func_0201EF34(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 2: func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0); break;
    case 3:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 4:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 5:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetMoveWord((int *)p)); break;
    case 6:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 7: func_0201EF34(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 8:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 9: func_0201F02C(((struct Obj00544 *)p)->f48, 2, (void *)(((struct Obj24172 *)(*(char * *)&((struct Obj00544 *)p)->f0))->f4)); break;
    case 10: func_0201EF34(((struct Obj00544 *)p)->f48, 0, POKE_SUMMARY_MAIN_GetMoveWord((int *)p)); break;
    }
    str = func_02045EC0(((struct Obj00544 *)p)->f44, d_021B8350[((struct Obj24173 *)(*(char * *)&((struct Obj00544 *)p)->f0))->f19][kind]);
    func_0201F250(((struct Obj00544 *)p)->f48, ((struct Obj00544 *)p)->f4C, str);
    STRBUF_Delete(str);
}
