/*
 * function: func_021D5644
 * address: 0x021D5644
 * packet: pkt_ov123_021D5644
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: low and high halves of packed words pass to u16 callee parameters; no explicit high-half cast.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D54E0 0x021D54E0 thumb ov123
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_020450C8 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D584C(char *);
extern void func_021D54E0(char *);
struct Descriptor;
struct PrintSys;
struct Rec;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void func_020452E8(struct Descriptor *d);
extern void func_0203FB44(int,u16,u16);
extern void func_02028604(void *);
extern void func_0201ED04(struct WordSet *p);
extern void func_0201DD68(void);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02031140(struct S02031140 *p);
extern void func_020450C8(void);
extern void func_020307B0(void *);
void func_021D5644(char *p)
{
    int i;
    u32 a;
    func_021D584C(p);
    if (*(void **)(p+0x44)) func_020452E8(*(void **)(p+0x44));
    if (*(void **)(p+0x48)) func_020452E8(*(void **)(p+0x48));
    for(i=0;i<12;i++) {
        if (*(void **)(p+0x4c+i*4)) func_020452E8(*(void **)(p+0x4c+i*4));
    }
    a=*(u32 *)(p+8)>>16;
    func_0203FB44(5,*(u32 *)(p+8),a);
    a=*(u32 *)(p+4)>>16;
    func_0203FB44(6,*(u32 *)(p+4),a);
    func_021D54E0(p);
    func_02028604(*(void **)(p+0x40));
    func_0201ED04(*(void **)(p+0x24));
    func_0201DD68();
    func_02045C04(*(void **)(p+0x20));
    func_0201D83C(*(void **)(p+0x28));
    func_02045808(*(void **)(p+0x2c));
    func_02045808(*(void **)(p+0x30));
    func_02027FD8(*(void **)(p+0xa4));
    func_0201C6EC(*(void **)(p+0x88));
    func_0201C4C0(*(void **)(p+0x88));
    func_02031140(*(void **)(p+0x84));
    func_020450C8();
    func_020307B0(p);
}
