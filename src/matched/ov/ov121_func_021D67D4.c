/*
 * function: func_021D67D4
 * address: 0x021D67D4
 * packet: pkt_ov121_021D67D4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9228 0x021D9228 thumb ov121
 *   func_021DE2F0 0x021DE2F0 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021DA890 0x021DA890 thumb ov121
 *   func_021D6C28 0x021D6C28 thumb ov121
 *   func_021D6948 0x021D6948 thumb ov121
 *   func_021D96C4 0x021D96C4 thumb ov121
 *   func_02045C04 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02087BCC 0x02087BCC arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000072 data
 */
extern void func_021D9228(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
struct Rec;
struct S020315D4;
struct WordSet;
extern void func_021DE2F0(u8 *p);
extern void func_021D9E04(u8 *p);
extern void func_021DA890(void *);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201D83C(void *);
extern void func_021D6C28(void *);
extern void func_021D6948(void *);
extern void func_021D96C4(u8 *p);
extern void func_0200A338(void *);
extern void func_02012704(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(int);
extern void func_02087BCC(u32 parameter);
extern void func_02034A5C(int);
extern void func_02005D28(void);
extern char ov_id[];
int func_021D67D4(void *a, int b, int c, char *p)
{
    func_021D9228(p + 0x138);
    func_021DE2F0(*(void **)(p + 0x3b0));
    if (*(void **)(p + 0x284)) func_021D9E04(*(void **)(p + 0x284));
    func_021DA890(*(void **)(p + 0x290));
    func_0201ED04(*(void **)(p + 0x3a8));
    func_02045C04(*(void **)(p + 0x3a0));
    func_02045C04(*(void **)(p + 0x3a4));
    func_0201C4C0(*(void **)(p + 0x39c));
    func_0201D83C(*(void **)(p + 0x398));
    func_021D6C28(p + 0x294);
    func_021D6948(p + 0x390);
    func_021D96C4(*(void **)(p + 0x394));
    func_0200A338(*(void **)(p + 0x3bc));
    func_02012704(*(void **)(p + 0x3b8));
    func_020315D4(a);
    func_020306F0(29);
    func_02087BCC(0);
    func_02034A5C((int)ov_id);
    func_02005D28();
    return 1;
}
