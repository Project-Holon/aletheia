/*
 * function: func_021B6CC0
 * address: 0x021B6CC0
 * packet: pkt_ov173_021B6CC0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02045CAC has no code-start witness; unit_02045C44.c omits MSGDATA_ReadString in its function list. Seven own sites unresolved; tu --suggest-split leaves caller out.
 * lever: temp,bank,mon declarations restore stack homes; derived wide coord=y+16 restores both narrowing sites and the early coordinate update (existing derived-wide-local idiom).
 * blocker-C: 02045CAC verified EXACT, 344B, prior ov070 header arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * abi: 6BF8 font widened to u32 because original forwards a full word without truncation; 185F4 bare return preserves the visibly loaded pointer argument and live r0 result.
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021B6BF8 0x021B6BF8 thumb ov173
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045B38 0x02045B38 arm
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B78CC 0x021B78CC thumb ov173
 *   func_02045770 0x02045770 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Obj;
struct Rec;
struct U16Vec;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_021B6BF8(char *,int,u32,u16,int,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *POKE_TOOL_GetBoxParam(void *);
extern u32 func_02017E88(void *,u32,u32);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021B78CC(u8 *p, u16 id, u16 i);
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_Delete(struct U16Vec *vec);
static inline void flush(void *win)
{
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(func_02045730(win));
}
void func_021B6CC0(char *p)
{
    u32 i;
    u16 move;
    int y;
    int coord;
    void *temp;
    void *bank;
    void *mon;
    MSGDATA_ReadString(*(void **)(p+0x44),0x23,*(void **)(p+0x4c));
    func_021B6BF8(p,9,*(u32 *)(p+0x60),0x3c40,2,4);
    MSGDATA_ReadString(*(void **)(p+0x44),0x17,*(void **)(p+0x4c));
    func_021B6BF8(p,2,*(u32 *)(p+0x60),0x440,0,0);
    flush(*(void **)(p+0xc));
    MSGDATA_ReadString(*(void **)(p+0x44),0x18,*(void **)(p+0x4c));
    func_021B6BF8(p,3,*(u32 *)(p+0x60),0x440,0,0);
    flush(*(void **)(p+0x10));
    temp=STRBUF_Create(256,79);
    MSGDATA_ReadString(*(void **)(p+0x44),0x27,temp);
    func_0201EEF4(*(void **)(p+0x48),0,**(void ***)p);
    func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),temp);
    func_021B6BF8(p,13,*(u32 *)(p+0x60),0x3c40,0,4);
    flush(*(void **)(p+0x38));
    bank=func_02045B38(0,2,0xcb,79);
    mon=POKE_TOOL_GetBoxParam(**(void ***)p);
    for(i=0;i<4;i++) {
        move=func_02017E88(mon,0x36+i,0);
        if(move==0) func_0204B3DC(*(void **)(p+i*4+0x124),0);
        else {
            func_0204B3DC(*(void **)(p+i*4+0x124),1);
            func_021B78CC((u8 *)p,move,i);
            MSGDATA_ReadString(bank,move,*(void **)(p+0x4c));
            y=i*32;
            func_021B6BF8(p,14,*(u32 *)(p+0x60),0x3c40,0,y);
            coord=y+16;
            PRINTSYS_PrintColor(func_02045770(*(void **)(p+0x3c)),8,coord,*(void **)(p+0x50),*(void **)(p+0x60),0x440);
            flush(*(void **)(p+0x3c));
            func_0201EFA4(*(void **)(p+0x48),0,func_02017E88(mon,0x3a+i,0),2,1,1);
            func_0201EFA4(*(void **)(p+0x48),1,func_02017E88(mon,0x42+i,0),2,0,1);
            func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),*(void **)(p+0x54));
            PRINTSYS_PrintColor(func_02045770(*(void **)(p+0x3c)),32,coord,*(void **)(p+0x4c),*(void **)(p+0x60),0x440);
            flush(*(void **)(p+0x3c));
        }
    }
    flush(*(void **)(p+0x3c));
    MSGDATA_ReadString(*(void **)(p+0x44),0x25,temp);
    func_0201EE84(*(void **)(p+0x48),0,**(void ***)p);
    func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),temp);
    PRINTSYS_PrintColor(func_02045770(*(void **)(p+0x40)),0,0,*(void **)(p+0x4c),*(void **)(p+0x60),0x440);
    flush(*(void **)(p+0x40));
    MSGDATA_ReadString(*(void **)(p+0x44),0x26,temp);
    func_0201EFA4(*(void **)(p+0x48),0,func_02017E88(mon,0x9e,0),3,1,1);
    func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),temp);
    func_021B6BF8(p,15,*(u32 *)(p+0x60),0x440,1,16);
    flush(*(void **)(p+0x40));
    MSGDATA_Delete(bank);
    STRBUF_Delete(temp);
}
