/*
 * function: func_021DE7C0
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
 * extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
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
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
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
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_020457B0 0x020457B0 arm
 *   func_02012944 0x02012944 thumb
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_02045808 0x02045808 arm
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
extern void func_021FBE54(char *,u32,u32);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC21C(char *);
extern void func_02082BCC(void *,int,int);
extern int func_021FC124(void *,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern struct U16Vec *func_020457B0(u32,u32);
extern u8 *func_02012944(void *p);
extern void *func_021FC6A4(u16,u32,u16,u16,u8,u8,void *,u16);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_021FC7C4(char *,void *,void *,u16);
extern void func_02045808(struct U16Vec *);
void func_021DE7C0(char *p,char *q)
{
    int font,words,bank,i;
    Config config;
    Triple triple;
    struct U16Vec *base,*text;
    void *value;
    const Record *rec;
    char *slot;
    func_021FBE54(*(char **)(q+8),6,*(u16 *)(p+0x6c));
    func_021FB964((void *)(*(int *)(q+8)),15,*(u16 *)(p+0x6c));
    font=func_021FC20C(*(char **)(q+8));
    bank=func_021FC214(*(char **)(q+8));
    words=func_021FC21C(*(char **)(q+8));
    func_02082BCC(&config,0,8);
    config.left=80; config.right=168; config.top=0; config.flag=1;
    func_021FC124(*(void **)(q+8),6,&triple);
    *(void **)(p+0xc)=func_021FB378(&config,4,96,1,*(int *)q,*(int *)p,font,bank,&triple,*(u16 *)(p+0x6c));
    base=func_020457B0(128,*(u16 *)(p+0x6c));
    text=func_020457B0(128,*(u16 *)(p+0x6c));
    value=func_02012944(*(void **)(q+0x10));
    for(i=0;i<3;i++) {
        rec=&d_021E351C[i];
        slot=p+i*4;
        *(void **)(slot+0x10)=func_021FC6A4(4,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x6c));
        if(i==0) {
            func_02045CAC((struct MsgBank *)bank,rec->value,base);
            func_0201F02C((struct WordSet *)words,0,value);
            func_0201F250((struct WordSet *)words,text,base);
        } else func_02045CAC((struct MsgBank *)bank,rec->value,text);
        func_021FC7C4(*(char **)(slot+0x10),text,(void *)font,0x3da0);
    }
    func_02045808(base);
    func_02045808(text);
}
