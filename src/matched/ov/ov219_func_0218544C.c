/*
 * function: func_0218544C
 * address: 0x0218544C
 * packet: pkt_ov219_0218544C
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02045CAC at +0036 lacks a code-start witness; integrator-owned unit_02045C44.c omits func_02045CAC from function:. Required singleton TU finds no viable cut. No overlay leaves filed while ARM9 blocked.
 * lever: distinct outer buffer and block-scoped first/second buffers settle the eight-byte r4/r6 swap.
 * blocker-C: 02045CAC verified EXACT, 344B, scratch arm9-blocker.log;
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

 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02184D30 0x02184D30 thumb ov219
 *   func_02045808 0x02045808 arm
 *   func_0218532C 0x0218532C thumb ov219
 *   func_02185C84 0x02185C84 thumb ov219
 *   func_02045334 0x02045334 arm
 * prototype: caller narrows allocation heap to u16 immediately before each call.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct U16Vec;struct Descriptor;struct CharBuf;struct MsgBank;struct Record;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void func_02184D30(char *,struct Record *,struct Descriptor *,void *,u8,u8);
extern void func_02045808(struct U16Vec *);
extern int func_0218532C(char *,u32 *);
extern int func_02185C84(u32,u32,void *,void *,u32);
extern void func_02045334(struct Descriptor *);
void func_0218544C(char *p)
{
    struct U16Vec *buffer;
    u32 selected;
    if(*(u32 *)(p+0xC350)==0) {
        buffer=func_020457B0(1024,(u16)(*(u32 *)p));
        func_02043B5C(func_02045770(*(struct Descriptor **)(p+0xC01C)),15);
        func_02045CAC(*(struct MsgBank **)(p+0xC070),15,buffer);
        func_02184D30(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),buffer,0,0);
        func_02045808(buffer);
    } else {
        struct U16Vec *first,*second;
        if(func_0218532C(p,&selected)) {
            first=func_020457B0(64,(u16)(*(u32 *)p));
            second=func_020457B0(64,(u16)(*(u32 *)p));
            func_02043B5C(func_02045770(*(struct Descriptor **)(p+0xC01C)),15);
            func_02185C84(*(u16 *)(p+selected*48+66),*(u16 *)(p+selected*48+68),first,second,*(u32 *)p);
            if(*(u16 *)(p+selected*48+68)!=0)
                func_02184D30(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),second,0,16);
            func_02184D30(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),first,0,0);
            func_02045808(second);
            func_02045808(first);
            *(int *)(p+0xC2F4)=*(s16 *)(p+selected*48+24);
            *(int *)(p+0xC2F8)=*(s16 *)(p+selected*48+26);
        } else *(u32 *)(p+0xC350)=0;
    }
    func_02045334(*(struct Descriptor **)(p+0xC01C));
}
