/*
 * function: GURU2_RECEIPT_PrintMemberList
 * address: 0x021DE248
 * packet: pkt_ov137_021DE248
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two-byte alignment padding at 0x021DE34E.
 * lever: Struct members avoid cached element addresses; block scopes and expanding the first y argument settle the two spill slots.
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_UpdateMemberSlots 0x021DE388 thumb ov137
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02008534 0x02008534 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02008500 0x02008500 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { void *current; void *previous; } Entry;
typedef struct { char pad[0x38]; void *font; void *formatter; void *bank; void *names[5]; char pad58[0xe0]; Entry entries[5]; } Context;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int GURU2_RECEIPT_UpdateMemberSlots(char *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02008500(void *,void *);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
int GURU2_RECEIPT_PrintMemberList(void *window,int unused,u16 color,Context *p) {
    int player;
    void *format;
    u16 value;
    void *text;
    int i;
    u16 ink;
    player=GFL_NET_SYSTEM_GetCurrentAid();
    if (!GURU2_RECEIPT_UpdateMemberSlots((char *)p)) return 0;
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    for(i=0;i<5;i++) {
      do {
        if (p->entries[i].current) {
            int y;
            value=func_02008534(p->entries[i].current);
            text=STRBUF_Create(16,0x72);
            func_02008500(p->entries[i].current,p->names[i]);
            WORDSET_SetSlotNumber(p->formatter,0,value,5,2,1);
            format=func_02045EC0(p->bank,1);
            WORDSET_CopyTaggedText(p->formatter,text,format);
            if (player==i) ink=0x860; else ink=color;
            y=18*i+1;
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(window),5,18*i+1,p->names[i],p->font,ink);
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(window),70,y,text,p->font,ink);
            STRBUF_Delete(text);
            do { STRBUF_Delete(format); } while (0);
        }
      } while (0);
    }
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_020409B4(BMP_WIN_GetBgLayer(window));
    return 1;
}
