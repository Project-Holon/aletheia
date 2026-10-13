/*
 * function: IRC_COMPATIBLE_MENU_InitButtons
 * address: 0x021B8464
 * packet: pkt_ov102_021B8464
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Separate fifth object pointer and sixth u16 heap reproduce the incoming pointer home store and halfword slot at +4; byte-correct caller 021B7560 supplies the same two slots. Struct-typed state and const Row input preserve loads across bounds stores.
 * symbols:
 * MI_CpuFill8 0x02082BCC arm
 * BUTTON_MAN_Create 0x02051B84 arm
 * IRC_COMPATIBLE_MENU_ButtonCallback 0x021B8794 thumb ov102
 * BMP_WIN_Create 0x020450F0 arm
 * BMP_WIN_GetBmp 0x02045770 arm
 * BMP_Clear 0x02043B5C arm
 * BMP_WIN_TransferChars 0x02045334 arm
 * BMP_WIN_MakeScreen 0x02045374 arm
 * BMP_WIN_GetBgLayer 0x02045730 arm
 * func_020409B4 0x020409B4 arm
 * IRC_COMPATIBLE_MENU_TextGetMsgData 0x021B7CC4 thumb ov102
 * func_02045EC0 0x02045EC0 arm
 * GF_FONT_SetTextColor 0x0201DD78 thumb
 * IRC_COMPATIBLE_MENU_TextGetFont 0x021B7CBC thumb ov102
 * func_0201D304 0x0201D304 thumb
 * func_0201D42C 0x0201D42C thumb
 * PRINTSYS_Print 0x0201C7A4 thumb
 * STRBUF_Delete 0x02045808 arm
 * func_0201DD68 0x0201DD68 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Pair { int object; u16 heap,pad; } Pair;
typedef struct Row { u16 id,x,y,w,h,color; } Row;
typedef struct State { void *bank; u32 windows[4]; u8 bounds[20]; const Row *rows; u16 count,bg,index,done,state,ticks; u32 enable; } State;
extern void MI_CpuFill8(void *,u8,u32);
extern void *BUTTON_MAN_Create(u8 *,int,int,int);
extern void IRC_COMPATIBLE_MENU_ButtonCallback(u16,int,u8 *);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct CharBuf;
struct StrObj;
struct U16Vec;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
struct Cfg;
struct MsgBank;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32);
extern int IRC_COMPATIBLE_MENU_TextGetMsgData(void *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern int IRC_COMPATIBLE_MENU_TextGetFont(void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201DD68(void);
void IRC_COMPATIBLE_MENU_InitButtons(State *p, int bg, const Row *rows, int count, void *object, u16 heap)
{
    int i;
    const Row *row;
    u32 win,width,height;
    void *text,*target;
    MI_CpuFill8(p,0,60);
    p->count=count;
    p->rows=rows;
    p->bg=bg;
    p->enable=1;
    for(i=0;i<p->count;i++) {
        row=rows+i;
        p->bounds[i*4]=row->y*8+1;
        p->bounds[i*4+1]=(row->y+row->h)*8-1;
        p->bounds[i*4+2]=row->x*8+1;
        p->bounds[i*4+3]=(row->x+row->w)*8-1;
    }
    p->bounds[i*4]=255;
    p->bank=BUTTON_MAN_Create(p->bounds,(int)IRC_COMPATIBLE_MENU_ButtonCallback,(int)p,heap);
    for(i=0;i<p->count;i++) {
        row=rows+i;
        p->windows[i]=BMP_WIN_Create(bg,(u8)(row->x+4),(u8)(row->y+1),(u8)(row->w-8),row->h-2,row->color,1);
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)p->windows[i]),4);
        win=p->windows[i];
        BMP_WIN_TransferChars((struct Descriptor *)win);
        BMP_WIN_MakeScreen((struct Cfg *)win);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)win));
        text=func_02045EC0((struct MsgBank *)IRC_COMPATIBLE_MENU_TextGetMsgData(object),rows[i].id);
        GF_FONT_SetTextColor(15,14,4);
        width=func_0201D304(text,IRC_COMPATIBLE_MENU_TextGetFont(object),0);
        height=func_0201D42C(text,(void *)IRC_COMPATIBLE_MENU_TextGetFont(object));
        target=BMP_WIN_GetBmp((struct Descriptor *)p->windows[i]);
        PRINTSYS_Print(target,(row->w-8)*4-(width>>1),(row->h-2)*4-(height>>1),text,(void *)IRC_COMPATIBLE_MENU_TextGetFont(object));
        STRBUF_Delete(text);
        BMP_WIN_TransferChars((struct Descriptor *)p->windows[i]);
    }
    func_0201DD68();
}
