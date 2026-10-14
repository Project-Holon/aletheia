/*
 * function: PDWACC_MESSAGE_OpenYesNoMenu
 * address: 0x021D9670
 * packet: pkt_ov123_021D9670
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02045CAC at +0x58/+0x7C has no outside witness;
 * unit_02045C44.c omits MSGDATA_ReadString from function:. the integrator owns it.
 * blocker: Verified C copied from ov122_func_021D5004.c header;
 * prior fixed-flag EXACT, 344 bytes, originally ov070 arm9-blocker.log.
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
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_0207D658 0x0207D658 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x,y,z,w; } Config;
struct MsgBank;
struct TaskMenu;
struct TaskMenuTmpl;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_0207D658(u32 addr, int plane, int brightness);
int PDWACC_MESSAGE_OpenYesNoMenu(char *p,int mode) {
    Config c;
    int result;
    c.size=*(u16 *)(p+0xb0);
    c.flag=2;
    c.target=p+0x94;
    switch (mode) {
    case 0: c.x=32; c.y=14; c.mode=1; break;
    case 1: c.x=32; c.y=24; c.mode=1; break;
    }
    c.z=13;
    c.w=3;
    *(void **)(p+0x94)=STRBUF_Create(100,*(u16 *)(p+0xb0));
    MSGDATA_ReadString(*(void **)(p+0x20),4,*(void **)(p+0x94));
    *(u16 *)(p+0x98)=0x39e0;
    *(void **)(p+0xa0)=STRBUF_Create(100,*(u16 *)(p+0xb0));
    MSGDATA_ReadString(*(void **)(p+0x20),5,*(void **)(p+0xa0));
    *(u16 *)(p+0xa4)=0x39e0;
    result=(int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&c),*(void **)(p+0xac));
    STRBUF_Delete(*(void **)(p+0x94));
    STRBUF_Delete(*(void **)(p+0xa0));
    func_0207D658(0x04001050,17,-8);
    return result;
}
