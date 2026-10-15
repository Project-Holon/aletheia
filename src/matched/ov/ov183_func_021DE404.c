/*
 * function: func_021DE404
 * address: 0x021DE404
 * packet: pkt_ov183_021DE404
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declaring text before i/flag restores the original stack slots.
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   d_021E3574 0x021E3574 data a4
 */
#include "../include/Obj00440.h"
#include "../include/Obj00785.h"
#include "../include/Obj10739.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record {u8 a,b,c,d; u32 value;} Record;
typedef u16 Row[3];
struct MsgBank; struct U16Vec; struct WordSet;
extern const Record d_021E3574[];
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetWordSet(char *);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void *BR_UTIL_Create(u16,u32,u16,u16,u8,u8,void *,u16);
extern void BR_UTIL_SetTextLayout(u8 *p, u32 a, u32 b, u32 c);
extern u16 BSUBWAY_SAVEDATA_GetStat(Row *,int,int);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void STRBUF_Delete(struct U16Vec *);
extern void BR_UTIL_SetTextFromBuffer(char *,void *,void *,u16);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0201F02C(struct WordSet *,u32,void *);
void func_021DE404(char *p,char *q)
{
    int font, bank, words;
    struct U16Vec *text;
    int i, flag;
    const Record *rec;
    char *slot;
    void *base;
    font=BR_RES_GetFont(*(char * *)&((struct Obj00440 *)q)->f8);
    bank=BR_RES_GetMsgData(*(char * *)&((struct Obj00440 *)q)->f8);
    words=BR_RES_GetWordSet(*(char * *)&((struct Obj00440 *)q)->f8);
    BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj00440 *)q)->f8),16,((struct Obj00785 *)p)->f6C);
    for(i=0;i<12;i++) {
        flag=1;
        rec=&d_021E3574[i];
        slot=p+i*4;
        ((struct Obj10739 *)slot)->f1C=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00785 *)p)->f4,((struct Obj00785 *)p)->f6C);
        BR_UTIL_SetTextLayout(((struct Obj10739 *)slot)->f1C,0,1,0);
        switch(i) {
        case 0: func_0201F02C((struct WordSet *)words,0,GAME_DATA_GetMyStatus(((struct Obj00440 *)q)->f10)); break;
        case 7: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct Obj00440 *)q)->f14,5,0),4,1,1); break;
        case 8: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct Obj00440 *)q)->f14,6,0),4,1,1); break;
        case 9: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct Obj00440 *)q)->f14,7,0),4,1,1); break;
        case 10: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct Obj00440 *)q)->f14,8,0),4,1,1); break;
        case 11: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct Obj00440 *)q)->f14,9,0),4,1,1); break;
        default: text=func_02045EC0((struct MsgBank *)bank,rec->value); flag=0; break;
        }
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,((struct Obj00785 *)p)->f6C);
            func_0201F250((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        BR_UTIL_SetTextFromBuffer(*(char * *)&((struct Obj10739 *)slot)->f1C,text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}
