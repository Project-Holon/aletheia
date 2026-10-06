/*
 * function: func_021B80D0
 * address: 0x021B80D0
 * packet: pkt_ov106_021B80D0
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (final push G8L9): closed. The two zero stores at +0x556/+0x558 are written with
 *   literal 0 and `m = 0;` comes after them, just before the clamp. With `m = 0;` before the calls the
 *   zero joins the clamp's phi web, so -40 was derived from the held 1 (`subs r7,#0x29`) and 1 won the
 *   block-constant register over 0x20. With the literal zero stores the zero stays a plain constant
 *   and -40 is built fresh (`movs r1,#0; subs r1,#0x28`) while 0x20 keeps r7.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B8D8C 0x021B8D8C thumb ov106
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_021B8AD0 0x021B8AD0 thumb ov106
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 *   func_021B87B0 0x021B87B0 thumb ov106
 *   func_020450F0 0x020450F0 arm
 *   func_02040618 0x02040618 arm
 *   func_021B8524 0x021B8524 thumb ov106
 *   func_021B8648 0x021B8648 thumb ov106
 *   func_021B8690 0x021B8690 thumb ov106
 *   func_020056A0 0x020056A0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct GfFont;
struct WordSet;
extern void func_02082BCC(void *,int,int);
extern u32 func_021B8D8C(u8 *);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_021B8AD0(u8 *,u8 *,u16);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *);
extern void func_021B87B0(u8 *,const u8 *,void *,u32,u32,void *,u32,void *,void *,s16,s16,u16);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_021B8524(u8 *);
extern void func_021B8648(u8 *);
extern void func_021B8690(void *unused, u8 *p);
extern u32 func_020056A0(void (*)(void),void *,u32);
void func_021B80D0(u8 *p,u32 a1,u8 a2,u8 a3,u8 s0,u32 s1,void *s2,void *s3,u8 *s4,u16 heap) {
    void *arc;
    int i;
    int m;
    i = 0;
    func_02082BCC(p,0,0x59C);
    *(u32 *)(p+0x54C) = s1;
    *(u8 *)(p+0x548) = a1;
    *(u8 *)(p+0x549) = a2;
    *(u8 *)(p+0x54A) = a3;
    *(u8 *)(p+0x54B) = s0;
    *(u8 **)(p+0x550) = s4;
    *(u16 *)(p+0x554) = func_021B8D8C(s4);
    *(struct GfFont **)(p+0x570) = func_0201D7EC(23,0,0,1,heap);
    *(void **)(p+0x574) = s3;
    *(struct WordSet **)(p+0x588) = func_0201EC64(heap);
    func_021B8AD0(p+8,(u8 *)s1,heap);
    arc = func_020490F4(7,heap);
    *(int *)p = func_0204ACEC(arc,func_0201BC3C(),0,0x20,heap);
    *(int *)(p+4) = func_0204ACEC(arc,func_0201BC3C(),1,0x20,heap);
    func_02049238(arc);
    for (i = 0; i < func_021B8D8C(s4); i++) {
        func_021B87B0(p+0x188+i*32,s4+4+i*16,s2,*(u32 *)p,*(u32 *)(p+4),*(void **)(p+0x574),*(u32 *)(p+0x570),*(void **)(p+0x588),p+8,i*24+0x52,i*24-0x70,heap);
    }
    *(u32 *)(p+0x568) = func_020450F0(a2,0,0,0x20,0x20,14,1);
    *(u32 *)(p+0x56C) = func_020450F0(s0,0,0,0x20,0x20,14,1);
    *(s16 *)(p+0x564) = -40;
    *(s16 *)(p+0x566) = 24;
    func_02040618(*(u8 *)(p+0x548),3,*(s16 *)(p+0x564));
    func_02040618(*(u8 *)(p+0x549),3,*(s16 *)(p+0x564));
    func_02040618(*(u8 *)(p+0x54A),3,*(s16 *)(p+0x566));
    func_02040618(*(u8 *)(p+0x54B),3,*(s16 *)(p+0x566));
    *(u16 *)(p+0x556) = 0;
    *(u16 *)(p+0x558) = 0;
    m = 0;
    *(u16 *)(p+0x55A) = *(u16 *)(p+0x554) * 24 - 0x120;
    if (*(s16 *)(p+0x55A) > 0) m = *(s16 *)(p+0x55A);
    *(u16 *)(p+0x55A) = m;
    func_021B8524(p);
    func_021B8648(p);
    *(u32 *)(p+0x58C) = func_020056A0((void (*)(void))func_021B8690,p,0);
}
