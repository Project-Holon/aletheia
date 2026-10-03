/*
 * function: func_021BAFC4
 * address: 0x021BAFC4
 * packet: pkt_ov070_021BAFC4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: 0x02045CAC arm9, two call sites have no outside witness.
 * Existing unit src/matched/arm9/unit_02045C44.c contains its body but
 * lists only func_02045C44 in function:, omitting func_02045CAC.
 * Lever: unsigned long win and distinct pointer/u32/unsigned-long address
 * expressions reproduce recomputation and colours; enum win leaves 10B.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C274 0x0200C274 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021BB6E0 0x021BB6E0 thumb ov070
 *   func_021BB724 0x021BB724 thumb ov070
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
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Descriptor;struct CharBuf;struct MsgBank;struct Blk34;struct WordSet;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void *func_02012F08(int *);
extern u32 func_0200C274(struct Blk34 *);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_021BB6E0(int,u32 *,u32,u16,s16,u16);
extern void func_021BB724(void **);
#define P(k) (*(void **)((u32)p+(k)))
#define W(k) (*(u32 *)((u32)p+(k)))
void func_021BAFC4(u8 *p)
{
 unsigned long win = 0x764;
 func_02043B5C(func_02045770(P(win)),0);
 func_02043B5C(func_02045770(*(void **)(p+(win-8))),0);
 func_02045CAC(P(0x51C),0x51,P(0x524));
 func_021BB6E0((int)p,(u32 *)((u32)p+(win-8)),W(0x524),0,4,0x3C40);
 func_021BB724((void **)((unsigned long)p+(win-8)));
 func_02045CAC(P(0x51C),0x52,P(0x524));
 func_0201EFA4(P(0x520),0,func_0200C274(func_02012F08(P(0))),7,1,1);
 func_0201F250(P(0x520),P(0x528),P(0x524));
 func_021BB6E0((int)p,(u32 *)((u32)p+win),W(0x528),0,4,0x3C40);
 func_021BB724((void **)((u32)p+win));
}
