/*
 * function: func_021D7898
 * address: 0x021D7898
 * packet: pkt_ov120_021D7898
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021D79F2.
 * lever: decode the high halfword, retain u16 payload arguments, remove
 * the p+16 address temporary and declare every Thumb callee explicitly.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_021D7710 0x021D7710 thumb ov120
 *   func_021D846C 0x021D846C thumb ov120
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_021D7710(char *);
extern void func_0201DD68(void);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_021D846C(char *);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201ED04(struct WordSet *p);
extern void func_02028148(u8 *p);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_020307B0(void *);
static inline u16 decode(u32 value)
{
    u32 n=value >> 16;
    return (u16)n;
}
void func_021D7898(char *p)
{
    int i;
    u32 t;
    t=*(u32 *)(p+4);
    func_0203FB44(1,(u16)t,decode(t));
    t=*(u32 *)p;
    func_0203FB44(6,(u16)t,decode(t));
    func_021D7710(p);
    func_0201DD68();
    func_02045C04(*(void **)(p+12));
    func_0201D83C(*(void **)(p+20));
    func_02045808(*(void **)(p+24));
    func_02045808(*(void **)(p+28));
    func_02045808(*(void **)(p+32));
    func_021D846C(p);
    if(*(void **)(p+0x9c)) {func_0201CE48(*(void **)(p+0x9c));*(void **)(p+0x9c)=0;}
    func_0201ED04(*(void **)(p+16));
    if(*(void **)(p+0xc4)) {func_02028148(*(void **)(p+0xc4));*(void **)(p+0xc4)=0;}
    func_02027FD8(*(void **)(p+0xc0));
    func_02031140(*(void **)(p+0xa0));
    func_0201C6EC(*(void **)(p+0xa4));
    func_0201C4C0(*(void **)(p+0xa4));
    if(*(void **)(p+0x30)) func_020452E8(*(void **)(p+0x30));
    if(*(void **)(p+0x84)) func_020452E8(*(void **)(p+0x84));
    if(*(void **)(p+0x98)) func_020452E8(*(void **)(p+0x98));
    if(*(void **)(p+0x90)) func_020452E8(*(void **)(p+0x90));
    if(*(void **)(p+0x8c)) func_020452E8(*(void **)(p+0x8c));
    if(*(void **)(p+0x94)) func_020452E8(*(void **)(p+0x94));
    if(*(void **)(p+0x88)) func_020452E8(*(void **)(p+0x88));
    if(*(void **)(p+0x34)) func_020452E8(*(void **)(p+0x34));
    if(*(void **)(p+0x68)) func_020452E8(*(void **)(p+0x68));
    for(i=0;i<12;i++) if(*(void **)(p+i*4+0x38)) func_020452E8(*(void **)(p+i*4+0x38));
    for(i=0;i<6;i++) if(*(void **)(p+i*4+0x6c)) func_020452E8(*(void **)(p+i*4+0x6c));
    func_020450C8();
    func_020307B0(p);
}
