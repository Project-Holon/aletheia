/*
 * function: func_021D941C
 * address: 0x021D941C
 * packet: pkt_ov123_021D941C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: inline the first high-half argument; a separate first assignment colours the word r1.
 * symbols:
 *   func_021D92B8 0x021D92B8 thumb ov123
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_020450C8 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D92B8(u8 *);
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32,u16,u16);
extern void func_0201DD68(void);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *p);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0202F038(u8 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_020450C8(void);
extern void func_020307B0(void *);
void func_021D941C(u8 *p)
{
    u32 a;
    int i;
    func_0203FB44(1,*(u32 *)p,*(u32 *)p>>16);
    a=*(u32 *)(p+8)>>16;
    func_0203FB44(5,*(u32 *)(p+8),a);
    a=*(u32 *)(p+4)>>16;
    func_0203FB44(6,*(u32 *)(p+4),a);
    func_021D92B8(p);
    func_0201DD68();
    func_02045C04(*(void **)(p+0x20));
    func_0201D83C(*(void **)(p+0x28));
    func_02045808(*(void **)(p+0x2c));
    func_02045808(*(void **)(p+0x30));
    func_0201ED04(*(void **)(p+0x24));
    func_02027FD8(*(void **)(p+0xac));
    func_0201C6EC(*(void **)(p+0x8c));
    func_0201C4C0(*(void **)(p+0x8c));
    if (*(void **)(p+0x80)) func_0201CE48(*(void **)(p+0x80));
    if (*(void **)(p+0x90)) {
        func_0202F038(*(void **)(p+0x90));
        *(void **)(p+0x90)=0;
    }
    if (*(void **)(p+0x40)) func_020452E8(*(void **)(p+0x40));
    if (*(void **)(p+0x44)) func_020452E8(*(void **)(p+0x44));
    if (*(void **)(p+0x48)) func_020452E8(*(void **)(p+0x48));
    if (*(void **)(p+0x4c)) func_020452E8(*(void **)(p+0x4c));
    for(i=0;i<12;i++) if (*(void **)(p+i*4+0x50)) func_020452E8(*(void **)(p+i*4+0x50));
    func_02031140(*(void **)(p+0x88));
    func_020450C8();
    func_020307B0(p);
}
