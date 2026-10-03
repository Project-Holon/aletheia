/*
 * function: func_021FFFF8
 * address: 0x021FFFF8
 * packet: pkt_ov186_021FFFF8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 02045CAC arm; unresolved sole call, no witness outside
 *   021FFFF8..022000D0. Singleton tu --suggest-split confirms no viable cut.
 *   Existing Ilias-owned unit_02045C44.c function verified EXACT344 with
 *   read-only fixed-flag one (ARM9-45CAC.log). No ARM9 file/shard writes.
 *   Its function: header lists only func_02045C44, omitting func_02045CAC.
 *   Verified C follows, using that unit's declarations:
 *   void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *     u32 size; struct MsgEntry *e;
 *     if (index >= bank->file->count) { func_0204581C(dest); return; }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *       u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *       func_0204960C(bank->stream, pos + (index * 8 + 4));
 *       func_020495F4(bank->stream, 8, &bank->cache); e = &bank->cache;
 *     } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *     if (bank->resident == 0) {
 *       void *buf; size = e->len * 2;
 *       buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                         size, 0, g_020A7E8C, 0xd6);
 *       if (buf != 0) {
 *         func_0204960C(bank->stream, e->off + (bank->origin
 *                       + bank->file->langOff[bank->langIndex]));
 *         func_020495F4(bank->stream, size, buf);
 *         func_02045A00(dest, buf, e->len); func_020307B0(buf);
 *       }
 *     } else { func_02045A00(dest, (u8 *)bank->base + e->off, e->len); }
 *     func_02045E04(dest, index);
 *   }
 * symbols:
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F898 0x0201F898 thumb
 *   func_02045808 0x02045808 arm
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   d_02200DAC 0x02200DAC data
 *   d_020A7370 0x020A7370 data
 *   d_02200CA8 0x02200CA8 data
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { const void *str; u32 param; } Slot;
typedef struct { u32 v[10]; } Config;
extern char d_02200DAC[];
extern void *d_020A7370;
extern const Config d_02200CA8;
extern void func_021FB964(int,int,u16);
extern void func_02034714(const char *,int,const char *);
extern Slot *func_0201F81C(u32,u32);
extern void *func_020457B0(u32,u32);
extern void func_02045CAC(void *,u32,void *);
extern void func_0201F898(Slot *,u32,u32,u32);
extern void func_02045808(void *);
extern void *func_021FC8C8(Config *,u32);
void func_021FFFF8(char *p)
{
    Config cfg;
    void *str;
    u32 i;
    *(u32 *)(p+0x70)=1;
    func_021FB964(*(int *)(p+0x28),21,*(u16 *)(p+0x24));
    if (*(void **)(p+0x64)) func_02034714(d_02200DAC,0,d_02200DAC);
    if (*(void **)(p+0x68)) func_02034714(d_02200DAC,0,d_02200DAC);
    *(Slot **)(p+0x64)=func_0201F81C(*(u32 *)(p+0x8c),*(u16 *)(p+0x24));
    str=func_020457B0(11,*(u16 *)(p+0x24));
    for(i=0;i<*(u32 *)(p+0x8c);i++) {
        func_02045CAC(d_020A7370,(*(u16 **)(p+0x88))[i],str);
        func_0201F898(*(Slot **)(p+0x64)+i,(u32)str,(*(u16 **)(p+0x88))[i],*(u16 *)(p+0x24));
    }
    func_02045808(str);
    cfg=d_02200CA8;
    cfg.v[0]=*(u32 *)(p+0x64);
    cfg.v[1]=*(u32 *)(p+0x8c);
    cfg.v[5]=*(u32 *)(p+0x28);
    cfg.v[6]=*(u32 *)(p+0x34);
    cfg.v[7]=*(u32 *)(p+0x74);
    cfg.v[8]=*(u32 *)(p+0x78);
    *(void **)(p+0x68)=func_021FC8C8(&cfg,*(u16 *)(p+0x24));
}
