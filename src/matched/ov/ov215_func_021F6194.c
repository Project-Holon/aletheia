/*
 * function: func_021F6194
 * address: 0x021F6194
 * packet: pkt_ov215_021F6194
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * evidence: CCE4 return widened because original stores live r0 after call.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 */
typedef unsigned short u16;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
typedef unsigned int   u32;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201ED04(struct WordSet *p);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,unsigned,unsigned,void *,unsigned,unsigned,void *,unsigned,u16,u16);
void func_021F6194(char *object,char *p,unsigned entry)
{
    void *text,*words,*buffer;
    func_02043B5C(func_02045770(*(void **)(p+88)),15);
    if(*(void **)(p+80)) func_0201CE48(*(void **)(p+80));
    if(*(void **)(p+104)) func_02045808(*(void **)(p+104));
    text=func_02045EC0(*(void **)(p+100),entry);
    words=func_0201EC64(*(u16 *)p);
    func_0201EE84(words,0,*(void **)(object+4));
    buffer=func_020457B0(256,*(u16 *)p);
    *(void **)(p+104)=buffer;
    func_0201F250(words,buffer,text);
    func_0201ED04(words);
    func_02045808(text);
    *(void **)(p+80)=func_0201CCE4(*(void **)(p+88),0,0,*(void **)(p+104),*(unsigned *)(p+8),func_02012FFC(),*(void **)(p+84),2,*(u16 *)p,15);
}
