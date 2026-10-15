/*
 * function: INTRUDE_COMM_VIEW_InitStatusText
 * address: 0x021D5004
 * packet: pkt_ov122_021D5004
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02045CAC has no outside witness; integrator-owned unit_02045C44.c omits it from function:.
 * blocker: Verified C below copied from ov070_func_021BAFC4.c header; prior fixed-flag EXACT, 344 bytes.
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
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
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
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
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
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);extern void MSGDATA_ReadString(void *,int,void *);extern void STRBUF_Delete(void *);
void INTRUDE_COMM_VIEW_InitStatusText(char *p) {void *t;t=STRBUF_Create(100,*(u16 *)(p+12));*(void **)(p+0x328)=t;MSGDATA_ReadString(*(void **)(p+0x44),9,t);*(u16 *)(p+0x32c)=0x39e3;*(u32 *)(p+0x330)=1;STRBUF_Delete(*(void **)(p+0x328));}
