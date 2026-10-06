/*
 * function: func_021B9964
 * address: 0x021B9964
 * packet: pkt_ov221_021B9964
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * note: 2026-10-05 (wP6 U2): twin of ov222 021B9964 without window table, string widths and 437DC calls.
 *
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200873C 0x0200873C thumb
 *   func_020083E4 0x020083E4 thumb
 *   func_02049B90 0x02049B90 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045780 0x02045780 arm
 *   func_02045788 0x02045788 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021B9B18 0x021B9B18 thumb ov221
 *   d_021BA174 0x021BA174 data a1
 * */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj {
    u16 heap; u16 pad2; void **info; u32 pad8;
    void *str; void *bmp; u8 pad14[4];
    void *bank; void *ptr[5]; u32 done[5];
};
extern const u8 d_021BA174[];
extern char *func_02012944(void *);
extern void func_02049B90(u32,u32,u32,u32,u32,u32,u16);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_021B9B18(unsigned char *p);
void func_021B9964(struct Obj *p)
{
    u8 i;
    char *msg;
    u32 ws, x, t;
    msg = func_02012944(*p->info);
    p->bank = 0;
    for (i = 0; i < 5; i++) {
        p->ptr[i] = 0;
        p->done[i] = 0;
    }
    p->done[0] = 1;
    p->done[1] = 1;
    func_02049B90(0x17, 5, 0, 0, 0x1e0, 0x20, p->heap);
    p->bank = func_02045B38(0, 3, 1, p->heap);
    for (i = 0; i < 5; i++) {
        p->ptr[i] = (void *)func_020450F0(d_021BA174[i*9], d_021BA174[i*9+1], d_021BA174[i*9+2], d_021BA174[i*9+3], d_021BA174[i*9+4], d_021BA174[i*9+5], d_021BA174[i*9+6]);
        func_02043B5C(func_02045770(p->ptr[i]), 0);
        func_02045334(p->ptr[i]);
    }
    ws = (u32)func_0201EC64(p->heap);
    t = (u32)func_02045EC0(p->bank, 0);
    x = (u32)func_020457B0(0x20, p->heap);
    func_0201F02C((struct WordSet *)ws, 0, msg);
    func_0201F250((struct WordSet *)ws, (void *)x, (void *)t);
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[2]), 0, 0, x, (u32)p->str, 0x440);
    func_02045808((struct U16Vec *)x);
    func_02045808((struct U16Vec *)t);
    func_0201ED04((struct WordSet *)ws);
    t = (u32)func_02045EC0(p->bank, 1);
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[3]), 0, 0, t, (u32)p->str, 0x440);
    func_02045808((struct U16Vec *)t);
    t = (u32)func_02045EC0(p->bank, 3);
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[4]), 0, 0, t, (u32)p->str, 0x440);
    func_02045808((struct U16Vec *)t);
    for (i = 1; i < 5; i++) {
        void *d = p->ptr[i];
        func_02045334(d);
        func_02045374(d);
        func_02041B6C(func_02045730(d));
    }
    func_021B9B18((unsigned char *)p);
}
