/*
 * function: BR_CODEIN_ResultSetupButtons
 * address: 0x021DE7C0
 * packet: pkt_ov183_021DE7C0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bank/words declaration order selects their original stack slots.
 * blocker: ARM9 0x02045CAC at caller +0xEC/+0x10C; unit_02045C44.c
 * omits func_02045CAC from its function header. Existing C verified EXACT
 * (344 bytes, 12/12 relocations; ARM9-45CAC-one.log, terminal exit 0).
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 * 
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 * 
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 * 
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 * 
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void func_020307B0(void *p);
 * extern void ARC_TOOL_ReadHandle(void *stream, u32 size, void *dest);
 * extern void func_0204960C(void *stream, u32 pos);
 * extern void STRBUF_Clear(void *dest);
 * extern void STRBUF_SetChars(void *dest, const void *src, u16 len);
 * extern void func_02045E04(void *dest, u32 index);
 * extern u8 func_020461B8(const void *file);
 * extern void MSGDATA_LoadBank(struct MsgBank *bank);
 * extern void func_02046180(struct MsgBank *bank);
 * 
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 * 
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 * 
 *     func_02046180(bank);
 * 
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 * 
 *         func_0204960C(bank->stream, pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 * 
 *     if (bank->resident == 0) {
 *         void *buf;
 * 
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, MSGDATA_AllocSite, 0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *             STRBUF_SetChars(dest, buf, e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 * 
 *     func_02045E04(dest, index);
 * }
 * symbols:
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   STRBUF_Create 0x020457B0 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   func_02045CAC 0x02045CAC arm
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   STRBUF_Delete 0x02045808 arm
 *   d_021E351C 0x021E351C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record {u8 a,b,c,d; u32 value;} Record;
typedef struct Config {u16 left,right,top;u8 flag,pad;} Config;
typedef struct Triple {u32 a,b,c;} Triple;
struct U16Vec;struct WordSet;struct MsgBank;
extern const Record d_021E351C[];
extern void BR_RES_LoadSprite(char *,u32,u32);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetWordSet(char *);
extern void MI_CpuFill8(void *,int,int);
extern int BR_RES_GetSprite(void *,int,Triple *);
extern void *BR_BTN_CreateFromMessage(void *,int,int,int,int,int,int,int,void *,u16);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *BR_UTIL_Create(u16,u32,u16,u16,u8,u8,void *,u16);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void WORDSET_SetSlotMyStatus(struct WordSet *,u32,void *);
extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
extern void BR_UTIL_SetTextFromBuffer(char *,void *,void *,u16);
extern void STRBUF_Delete(struct U16Vec *);
void BR_CODEIN_ResultSetupButtons(char *p,char *q)
{
    int font,words,bank,i;
    Config config;
    Triple triple;
    struct U16Vec *base,*text;
    void *value;
    const Record *rec;
    char *slot;
    BR_RES_LoadSprite(*(char **)(q+8),6,*(u16 *)(p+0x6c));
    BR_RES_LoadBgGraphics((void *)(*(int *)(q+8)),15,*(u16 *)(p+0x6c));
    font=BR_RES_GetFont(*(char **)(q+8));
    bank=BR_RES_GetMsgData(*(char **)(q+8));
    words=BR_RES_GetWordSet(*(char **)(q+8));
    MI_CpuFill8(&config,0,8);
    config.left=80; config.right=168; config.top=0; config.flag=1;
    BR_RES_GetSprite(*(void **)(q+8),6,&triple);
    *(void **)(p+0xc)=BR_BTN_CreateFromMessage(&config,4,96,1,*(int *)q,*(int *)p,font,bank,&triple,*(u16 *)(p+0x6c));
    base=STRBUF_Create(128,*(u16 *)(p+0x6c));
    text=STRBUF_Create(128,*(u16 *)(p+0x6c));
    value=GAME_DATA_GetMyStatus(*(void **)(q+0x10));
    for(i=0;i<3;i++) {
        rec=&d_021E351C[i];
        slot=p+i*4;
        *(void **)(slot+0x10)=BR_UTIL_Create(4,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x6c));
        if(i==0) {
            func_02045CAC((struct MsgBank *)bank,rec->value,base);
            WORDSET_SetSlotMyStatus((struct WordSet *)words,0,value);
            WORDSET_CopyTaggedText((struct WordSet *)words,text,base);
        } else func_02045CAC((struct MsgBank *)bank,rec->value,text);
        BR_UTIL_SetTextFromBuffer(*(char **)(slot+0x10),text,(void *)font,0x3da0);
    }
    STRBUF_Delete(base);
    STRBUF_Delete(text);
}
