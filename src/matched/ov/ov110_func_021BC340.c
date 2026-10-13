/*
 * function: PMSIV_EDIT_DrawFreeText
 * address: 0x021BC340
 * packet: pkt_ov110_021BC340
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding at 0x021BC456.
 * lever: struct-indexed fields and id,running,font declaration order.
 * prototype: 021BF708 leaves returned r0 live and forwards the caller's r1 heap input to 0202441C.
 * symbols:
 *   PMS_INPUT_GetSentenceString 0x021BF708 thumb ov110
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   PMSIV_EDIT_ParserInit 0x021BC458 thumb ov110
 *   PMSIV_EDIT_ParserNext 0x021BC490 thumb ov110
 *   PMSIV_EDIT_ClearSlotBox 0x021BC58C thumb ov110
 *   PMS_INPUT_GetWord 0x021BF6F0 thumb ov110
 *   PMSIV_EDIT_DrawSlotWord 0x021BC5BC thumb ov110
 *   PMSIV_EDIT_ParserFree 0x021BC484 thumb ov110
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   func_0201D304 0x0201D304 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned u32;
typedef struct { s16 x,y; } Pair;
typedef struct { void *root; u8 *state; u8 pad[0x14]; void *items[2][2]; u8 gap[12]; Pair pos[2]; u16 ids[2]; int count; u8 parser[12]; u16 id; } Obj;
extern void *PMS_INPUT_GetSentenceString(u8 *,u32);
extern u32 PMS_INPUT_VIEW_GetFont(u8 *);
struct Descriptor;
struct StrObj;
struct U16Vec;
extern void PMSIV_EDIT_ParserInit(u8 *p, u8 *a);
struct Cursor;
struct Obj;
struct Strbuf;
struct Vec2;
extern int PMSIV_EDIT_ParserNext(struct Cursor *p, struct Strbuf *out);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PMSIV_EDIT_ClearSlotBox(void *,Pair *);
extern u32 PMS_INPUT_GetWord(u8 *p, u32 i);
extern void PMSIV_EDIT_DrawSlotWord(u8 *p, struct Descriptor *window, const struct Vec2 *input, u32 id, struct Obj *sprite);
extern void PMSIV_EDIT_ParserFree(u8 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
int PMSIV_EDIT_DrawFreeText(Obj *p,void *desc,u8 bank)
{
    void *str;
    u16 id;
    int running,count,x,y;
    u32 font;
    str=PMS_INPUT_GetSentenceString(p->state,42);
    font=PMS_INPUT_VIEW_GetFont(p->root);
    running=1;
    count=0; y=0; x=0;
    PMSIV_EDIT_ParserInit(p->parser,(u8 *)p);
    do {
        switch(PMSIV_EDIT_ParserNext((struct Cursor *)p->parser,str)) {
        case 0:
            GF_FONT_SetTextColor(1,2,15);
            PRINTSYS_Print(BMP_WIN_GetBmp(desc),x,y,str,(void *)font);
            x+=func_0201D304(str,font,0);
            break;
        case 1: {
            id=p->id;
            p->ids[count]=id;
            p->pos[count].x=x+50;
            p->pos[count].y=y+8;
            PMSIV_EDIT_ClearSlotBox(desc,&p->pos[count]);
            PMSIV_EDIT_DrawSlotWord((u8 *)p,desc,(const struct Vec2 *)(&p->pos[count]),PMS_INPUT_GetWord(p->state,id),p->items[count][bank]);
            count++;
            x+=100;
            break;
        }
        case 2: y+=16; x=0; break;
        case 3: running=0; break;
        }
    } while(running);
    PMSIV_EDIT_ParserFree(p->parser);
    STRBUF_Delete(str);
    return count;
}
