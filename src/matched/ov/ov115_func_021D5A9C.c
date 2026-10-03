/*
 * function: func_021D5A9C
 * address: 0x021D5A9C
 * packet: pkt_ov115_021D5A9C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5FA0 0x021D5FA0 thumb ov115
 *   func_021D5FC4 0x021D5FC4 thumb ov115
 *   func_0203FB44 0x0203FB44 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void func_0202F038(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_021D5D3C(u8 *p);
extern u32 func_021D5FA0(u32);
extern u32 func_021D5FC4(u32);
extern void func_0203FB44(u32,u16,u16);
extern void func_0201DD68(void);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_020307B0(void *);
void func_021D5A9C(u8 *p) {
    u32 n;
    if (*(void **)(p+0x80)) { func_0202F038(*(void **)(p+0x80)); *(void **)(p+0x80)=0; }
    if (*(void **)(p+0x38)) { func_0201CE48(*(void **)(p+0x38)); *(void **)(p+0x38)=0; }
    func_021D5D3C(p);
    n=*(u32 *)p;
    func_0203FB44(func_021D5FA0(*(u32 *)(p+0x50)),n,n>>16);
    n=*(u32 *)(p+4);
    func_0203FB44(func_021D5FC4(*(u32 *)(p+0x50)),n,n>>16);
    func_0201DD68();
    func_0201ED04(*(void **)(p+0x20));
    func_02045C04(*(void **)(p+0x1c));
    func_0201D83C(*(void **)(p+0x24));
    func_02045808(*(void **)(p+0x28));
    func_02027FD8(*(void **)(p+0x70));
    func_02031140(*(void **)(p+0x44));
    func_0201C6EC(*(void **)(p+0x48));
    func_0201C4C0(*(void **)(p+0x48));
    if (*(void **)(p+0x2c)) { func_020452E8(*(void **)(p+0x2c)); *(void **)(p+0x2c)=0; }
    if (*(void **)(p+0x30)) { func_020452E8(*(void **)(p+0x30)); *(void **)(p+0x30)=0; }
    func_020450C8();
    func_020307B0(p);
}
