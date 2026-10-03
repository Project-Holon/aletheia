/*
 * function: func_021B71C4
 * address: 0x021B71C4
 * packet: pkt_ov173_021B71C4
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x02045CAC has no code-start witness; unit_02045C44.c omits func_02045CAC in its function list. Three own sites unresolved; tu --suggest-split leaves caller out.
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
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * abi: 6BF8 font extern widened to u32: the original forwards the full p+0x60 word without narrowing.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0201BD28 0x0201BD28 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_021B6C84 0x021B6C84 thumb ov173
 *   func_021B6BF8 0x021B6BF8 thumb ov173
 *   func_0201C1F4 0x0201C1F4 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 *   func_021B79E0 0x021B79E0 thumb ov173
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020456F8 0x020456F8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u8);
extern void func_0204B3DC(void *,u32);
extern u32 func_0201BD28(u16,u32);
extern void func_02045CAC(void *,u32,void *);
extern void func_021B6C84(char *,u32,u32,u32,u8);
extern u32 func_021B6BF8(char *,int,u32,u16,int,u8);
extern u32 func_0201C1F4(u16);
extern void *func_02045B38(u32,u32,u32,u32);
extern void func_02045C04(void *);
extern void func_021B79E0(char *,u16);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u8 func_02045730(void *);
extern void func_02041B6C(u32);
extern void func_020456F8(void *);
static inline void flush(void *win)
{
    func_02045334(win);
    func_02045374(win);
    func_02041B6C(func_02045730(win));
}
static inline void clear(void *win)
{
    func_020456F8(win);
    func_02041B6C(func_02045730(win));
}
void func_021B71C4(char *p,int move)
{
    u32 value;
    void *bank;
    int zero;
    zero=0;
    func_02043B5C(func_02045770(*(void **)(p+0x1c)),0);
    func_02043B5C(func_02045770(*(void **)(p+0x14)),0);
    func_02043B5C(func_02045770(*(void **)(p+0x18)),0);
    func_0204B3DC(*(void **)(p+0x110),0);
    if(move!=zero-2) {
        value=func_0201BD28(move,3);
        if(value<=1) func_02045CAC(*(void **)(p+0x44),0x21,*(void **)(p+0x4c));
        else func_021B6C84(p,0x1d,value,3,0);
        func_021B6BF8(p,4,*(u32 *)(p+0x60),0x440,1,0);
        value=func_0201BD28(move,4);
        if(value==0 || func_0201C1F4(move)!=0) func_02045CAC(*(void **)(p+0x44),0x21,*(void **)(p+0x4c));
        else func_021B6C84(p,0x1e,value,3,0);
        func_021B6BF8(p,5,*(u32 *)(p+0x60),0x440,1,0);
        bank=func_02045B38(0,2,0xca,79);
        func_02045CAC(bank,move,*(void **)(p+0x4c));
        func_021B6BF8(p,6,*(u32 *)(p+0x60),0x440,0,0);
        func_02045C04(bank);
        func_021B79E0(p,move);
        func_0204B3DC(*(void **)(p+0x110),1);
        flush(*(void **)(p+0xc));
        flush(*(void **)(p+0x10));
    } else {
        clear(*(void **)(p+0xc));
        clear(*(void **)(p+0x10));
    }
    flush(*(void **)(p+0x1c));
    flush(*(void **)(p+0x14));
    flush(*(void **)(p+0x18));
}
