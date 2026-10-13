/*
 * function: func_021BF384
 * address: 0x021BF384
 * packet: pkt_ov204_021BF384
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02045CAC at +0044 lacks an outside code-start witness.
 * Owner unit_02045C44.c omits func_02045CAC from function:; singleton TU
 * --suggest-split leaves this caller out. the integrator owns that unit.
 * blocker: verified EXACT344 C copied from ov186_func_021FFFF8.c header,
 * prior fixed-flag ARM9-45CAC.log, using the owner's unit declarations:
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *   u32 size; struct MsgEntry *e;
 *   if (index >= bank->file->count) { STRBUF_Clear(dest); return; }
 *   func_02046180(bank);
 *   if (bank->resident == 0) {
 *     u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *     func_0204960C(bank->stream, pos + (index * 8 + 4));
 *     ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache); e = &bank->cache;
 *   } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *   if (bank->resident == 0) {
 *     void *buf; size = e->len * 2;
 *     buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                       size, 0, MSGDATA_AllocSite, 0xd6);
 *     if (buf != 0) {
 *       func_0204960C(bank->stream, e->off + (bank->origin
 *                     + bank->file->langOff[bank->langIndex]));
 *       ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *       STRBUF_SetChars(dest, buf, e->len); func_020307B0(buf);
 *     }
 *   } else { STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len); }
 *   func_02045E04(dest, index);
 * }
 * lever: u16 heap local places its word home at sp+8; u32 swaps it with
 * the entry pointer at sp+12, leaving seven differing concrete bytes.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   func_02045CAC 0x02045CAC arm
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   func_021BF374 0x021BF374 thumb ov204
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02020D10 0x02020D10 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    void *arr,*b,*c,*obj;
    u16 count,rows;
    u8 f14,f15,f16;
    u8 f17lo:4,f17hi:4;
    u8 f18lo:4,f18hi:4;
    u8 f19;
    u16 f1Alo:3,f1Amid:4,f1Apad:2,f1Amid2:6,f1Atop:1;
    u32 f1c;
    u16 f20,f22;
    u32 f24;
    void *f28,*f2c,*f30;
} Config;
extern void *func_02082BCC(void *,int,u32);
extern void *BMP_MENUWORK_Create(u32,u32);
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Obj;
struct Slot;
struct Src;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void BMP_MENUWORK_AddStrItem(struct Slot *table, u32 a, u32 b, u32 tag);
extern int *func_021BF374(char *,int);
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *p, int heap);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_0201F73C(void *,int,int,int);
extern void func_02020D10(u8 *p, u32 v);
void func_021BF384(char *p,u32 *entries,u32 count,int flag)
{
    Config config;
    char *state;
    void *obj;
    u16 heap;
    u32 i;
    state=p+36;
    heap=*(u16 *)p;
    obj=*(void **)(p+56);
    func_02082BCC(state,0,12);
    *(void **)(state+4)=BMP_MENUWORK_Create(count,heap);
    for(i=0;i<count;i++){
        func_02045CAC(*(void **)(p+12),*(u32 *)((char *)entries+i*8),*(void **)(p+60));
        BMP_MENUWORK_AddStrItem((struct Slot *)((char *)*(void **)(state+4)+i*8),*(u32 *)(p+60),*(u32 *)((char *)entries+i*8+4),heap);
    }
    func_02082BCC(&config,0,52);
    config.arr=*(void **)(state+4);config.obj=obj;
    config.count=count;config.rows=5;config.f14=0;config.f15=16;config.f16=0;
    config.f17lo=2;config.f17hi=1;config.f18lo=15;config.f18hi=2;
    config.f1Alo=0;config.f1Amid=0;config.f1Apad=1;config.f1Amid2=0;config.f1Atop=0;
    config.f1c=0;config.f20=16;config.f22=16;config.f24=0;
    config.f28=func_021BF374(p,(int)obj);config.f2c=*(void **)(p+4);config.f30=*(void **)(p+16);
    *(void **)state=BMP_MENULIST_Create((struct Src *)(&config),0,0,heap);
    func_02020CF8(*(void **)state,(u32)heap);
    BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4((u8)func_02045730(obj));
    func_0201F73C(obj,1,7,9);
    if(flag)func_02020D10(*(void **)state,0);
    else func_02020D10(*(void **)state,1);
}
