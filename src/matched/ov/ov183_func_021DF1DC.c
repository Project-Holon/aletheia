/*
 * function: BR_CODEIN_SearchCreateList
 * address: 0x021DF1DC
 * packet: pkt_ov183_021DF1DC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BR_UTIL_CreateListMenu 0x021FC8C8 thumb ov186
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_Clear 0x02043B5C arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BR_UTIL_SetListItemBitmap 0x021FCDAC thumb ov186
 *   STRBUF_Delete 0x02045808 arm
 *   BR_UTIL_RefreshList 0x021FCE50 thumb ov186
 *   BR_CODEIN_SearchCreateActor 0x021DF428 thumb ov183
 *   BR_CODEIN_SearchUpdateActor 0x021DF620 thumb ov183
 *   d_021E3700 0x021E3700 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {void *text;int id;} Item;
typedef struct {Item *list;u32 count;u8 x,y,width,height,palette,bg,spacing,pad;int mode;char *resources;u32 manager,cursor,other;u16 *selection;} Config;
typedef struct {u32 w[10];} CfgTpl;
typedef struct {u32 a,b;} Slot;
typedef struct {Slot *list;void *view;void *words;u32 c,d;u8 pad[0xbc];char *base;} Menu;
extern const CfgTpl d_021E3700;
typedef signed short   s16;
struct Bmp;
struct CharBuf;
struct MsgBank;
struct State;
struct StrObj;
struct Strbuf;
struct U16Vec;
struct WordSet;
extern unsigned BR_RES_GetFont(char *);
extern int BR_RES_GetMsgData(char *p);
extern void MI_CpuFill8(void *,u32,u32);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern Slot *BMP_MENUWORK_Create(u32,u32);
extern void *BR_UTIL_CreateListMenu(const Config *,u16);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void BR_UTIL_SetListItemBitmap(u8 *p, u16 i, u32 v);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BR_UTIL_RefreshList(char *p);
extern void BR_CODEIN_SearchCreateActor(struct State *p, u32 mgr, u16 heap);
extern void BR_CODEIN_SearchUpdateActor(struct State *p, int first, short step, u16 heap);
void BR_CODEIN_SearchCreateList(Menu *p,char *base,char *res,u32 mgr,u32 a5,u32 a6,u16 *sel,u16 heap)
{
    unsigned first,second;
    int i;
    void *bmp;
    void *buf1,*msg,*buf2;
    Config cfg;
    first=BR_RES_GetFont(res);
    second=BR_RES_GetMsgData(res);
    MI_CpuFill8(p,0,0xd4);
    p->base=base;
    p->words=WORDSET_CreateDefault(heap);
    p->c=a5;
    p->d=a6;
    p->list=BMP_MENUWORK_Create(*(u32 *)(base+0x1718),heap);
    for(i=0;i<*(int *)(base+0x1718);i++)p->list[i].b=i;
    *(CfgTpl *)&cfg=d_021E3700;
    cfg.list=(Item *)p->list;
    cfg.count=*(u32 *)(base+0x1718);
    cfg.resources=res;
    cfg.manager=mgr;
    cfg.cursor=p->c;
    cfg.other=p->d;
    cfg.selection=sel;
    p->view=BR_UTIL_CreateListMenu(&cfg,heap);
    buf1=STRBUF_Create(0xff,heap);
    msg=func_02045EC0((struct MsgBank *)second,0x7a);
    buf2=STRBUF_Create(0xff,heap);
    for(i=0;i<*(int *)(base+0x1718);i++){
        bmp=BMP_Create(cfg.width,cfg.spacing,0x20,heap);
        BMP_Clear(bmp,0);
        WORDSET_SetSlotNumber(p->words,0,i+1,2,0,1);
        WORDSET_CopyTaggedText(p->words,buf1,msg);
        STRBUF_SetString(buf2,(const u16 *)(base+i*0xc4));
        PRINTSYS_PrintColor(bmp,(short)(16-func_0201D304(buf1,first,0)),4,buf1,(void *)first,0x3DA0);
        PRINTSYS_PrintColor(bmp,0x14,4,buf2,(void *)first,0x3DA0);
        BR_UTIL_SetListItemBitmap(p->view,(u16)i,(u32)bmp);
    }
    STRBUF_Delete(buf2);
    STRBUF_Delete(buf1);
    STRBUF_Delete(msg);
    BR_UTIL_RefreshList(p->view);
    BR_CODEIN_SearchCreateActor((struct State *)p,mgr,heap);
    for(i=0;i<*sel;i++)BR_CODEIN_SearchUpdateActor((struct State *)p,i+1,1,heap);
}
