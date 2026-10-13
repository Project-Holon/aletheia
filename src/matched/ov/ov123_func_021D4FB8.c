/*
 * function: func_021D4FB8
 * address: 0x021D4FB8
 * packet: pkt_ov123_021D4FB8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: integrator-owned ARM9 0x02045CAC lacks outside witness because unit_02045C44.c omits it from function:.
 * blocker: Verified EXACT, 344 bytes, from existing owner unit using fixed flags --arm; C copied from ov070_func_021BAFC4.c below.
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
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
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
 *   func_021D4D40 0x021D4D40 thumb ov123
 *   func_02041570 0x02041570 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021D4FAC 0x021D4FAC thumb ov123
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D50F8 0x021D50F8 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D4D40(char *,int);
struct MsgBank;
extern void func_02041570(int channel, u16 val);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021D4FAC(char *);
extern void func_021D4244(char *,void *,int);
extern void func_021D50F8(char *);
void func_021D4FB8(char *p) { func_021D4D40(p,1); func_02041570(5,0); func_02045CAC(*(void **)(p+36),3,*(void **)(p+56)); func_021D4FAC(p); func_021D4244(p,func_021D50F8,0x4d0); }
