/*
 * function: func_021BCEA4
 * address: 0x021BCEA4
 * packet: pkt_ov216_021BCEA4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * blocker: ARM9 02045CAC +0010 lacks a code-start witness; the integrator owns src/matched/arm9/unit_02045C44.c, whose function header and shard omit func_02045CAC. Its C verifies EXACT individually (344 bytes).
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
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet;
struct MsgBank;
extern void func_02045CAC(struct MsgBank*,u32,void*);
extern void func_0201F250(struct WordSet*,void*,void*);
void func_021BCEA4(u8*p, u8 n){func_02045CAC(*(struct MsgBank**)(p+0x130),n,*(void**)(p+0x13c));func_0201F250(*(struct WordSet**)(p+0x138),*(void**)(p+0x140),*(void**)(p+0x13c));}
