/*
 * function: func_021B9DB8
 * address: 0x021B9DB8
 * packet: pkt_ov205_021B9DB8
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 02045CAC is inside Ilias-owned src/matched/arm9/unit_02045C44.c, whose function: lists only func_02045C44; the missing func_02045CAC entry leaves the call at +0x42 unwitnessed. TU suggest-split found no viable piece.
 * extent: intended function ends at 021B9E50 (152 bytes); the rest of the handed 392-byte extent is rodata, not follower code.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
struct U16Vec;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct WordSet;
extern struct U16Vec *func_020457B0(u32,u32);
extern struct CharBuf *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(struct U16Vec *);
extern void func_02045334(struct Descriptor *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021B9DB8(char *p,u32 index,s16 x,s16 y)
{
    struct U16Vec *a,*b;
    a=func_020457B0(0x400,*(u16 *)p);
    b=func_020457B0(0x400,*(u16 *)p);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p+20)),0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p+20)),15);
    func_02045CAC(*(struct MsgBank **)(p+12),index,a);
    func_0201F02C(*(struct WordSet **)(p+16),1,*(void **)(p+8));
    func_0201F250(*(struct WordSet **)(p+16),b,a);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(*(struct Descriptor **)(p+20)),x,y,b,*(void **)(p+24));
    func_02045808(a);
    func_02045808(b);
    func_02045334(*(struct Descriptor **)(p+20));
    func_02041B6C(func_02045730(*(struct Descriptor **)(p+20)));
}
