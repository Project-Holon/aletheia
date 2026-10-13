/*
 * function: func_021FFFF8
 * address: 0x021FFFF8
 * packet: pkt_ov186_021FFFF8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02045CAC arm; unresolved sole call, no witness outside
 *   021FFFF8..022000D0. Singleton tu --suggest-split confirms no viable cut.
 *   Existing integrator-owned unit_02045C44.c function verified EXACT344 with
 *   read-only fixed-flag one (ARM9-45CAC.log). No ARM9 file/shard writes.
 *   Its function: header lists only MSGDATA_CreateFromMemory, omitting MSGDATA_ReadString.
 *   Verified C follows, using that unit's declarations:
 *   void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest) {
 *     u32 size; struct MsgEntry *e;
 *     if (index >= bank->file->count) { STRBUF_Clear(dest); return; }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *       u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *       func_0204960C(bank->stream, pos + (index * 8 + 4));
 *       ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache); e = &bank->cache;
 *     } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *     if (bank->resident == 0) {
 *       void *buf; size = e->len * 2;
 *       buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                         size, 0, MSGDATA_AllocSite, 0xd6);
 *       if (buf != 0) {
 *         func_0204960C(bank->stream, e->off + (bank->origin
 *                       + bank->file->langOff[bank->langIndex]));
 *         ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *         STRBUF_SetChars(dest, buf, e->len); func_020307B0(buf);
 *       }
 *     } else { STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len); }
 *     func_02045E04(dest, index);
 *   }
 * symbols:
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_02034714 0x02034714 arm
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   d_02200DAC 0x02200DAC data
 *   gSpeciesNameBank 0x020A7370 data
 *   d_02200CA8 0x02200CA8 data
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { const void *str; u32 param; } Slot;
typedef struct { u32 v[10]; } Config;
extern char d_02200DAC[];
extern void *gSpeciesNameBank;
extern const Config d_02200CA8;
struct Slot;
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
struct MsgBank;
struct U16Vec;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern Slot *BMP_MENUWORK_Create(u32,u32);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void BMP_MENUWORK_AddStrItem(struct Slot *table, u32 a, u32 b, u32 tag);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_021FC8C8(Config *,u32);
void func_021FFFF8(char *p)
{
    Config cfg;
    void *str;
    u32 i;
    *(u32 *)(p+0x70)=1;
    func_021FB964((void *)(*(int *)(p+0x28)),21,*(u16 *)(p+0x24));
    if (*(void **)(p+0x64)) func_02034714(d_02200DAC,0,d_02200DAC);
    if (*(void **)(p+0x68)) func_02034714(d_02200DAC,0,d_02200DAC);
    *(Slot **)(p+0x64)=BMP_MENUWORK_Create(*(u32 *)(p+0x8c),*(u16 *)(p+0x24));
    str=STRBUF_Create(11,*(u16 *)(p+0x24));
    for(i=0;i<*(u32 *)(p+0x8c);i++) {
        MSGDATA_ReadString(gSpeciesNameBank,(*(u16 **)(p+0x88))[i],str);
        BMP_MENUWORK_AddStrItem((struct Slot *)(*(Slot **)(p+0x64)+i),(u32)str,(*(u16 **)(p+0x88))[i],*(u16 *)(p+0x24));
    }
    STRBUF_Delete(str);
    cfg=d_02200CA8;
    cfg.v[0]=*(u32 *)(p+0x64);
    cfg.v[1]=*(u32 *)(p+0x8c);
    cfg.v[5]=*(u32 *)(p+0x28);
    cfg.v[6]=*(u32 *)(p+0x34);
    cfg.v[7]=*(u32 *)(p+0x74);
    cfg.v[8]=*(u32 *)(p+0x78);
    *(void **)(p+0x68)=func_021FC8C8(&cfg,*(u16 *)(p+0x24));
}
