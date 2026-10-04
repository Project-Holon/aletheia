/*
 * function: func_021D46BC
 * address: 0x021D46BC
 * packet: pkt_ov124_021D46BC
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 text; u16 color; u16 pad; u32 flag; } Request;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct R;
struct U16Vec;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0201DD78(u32, u32, u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern u8 func_0201F548(int);
extern void func_0201DD68(void);
extern u32 func_0201C440(void *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d), func_02045374(u32);
extern void func_0201F73C(void *, int, int, int);
extern void func_020409B4(u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02027FEC(u32, u32, u32, u32, u8, u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202843C(u8 *);
void func_021D46BC(char *p)
{
    Request req;
    *(void **)(p + 0x28) = func_0201D7EC(23, 0, 0, 0, *(u16 *)p);
    func_0201DD78(15, 2, 0);
    *(void **)(p + 0x2c) = func_02045B38(0, 2, 21, *(u16 *)p);
    func_02049B40(23, 5, 4, 480, 32, *(u16 *)p);
    func_0201F5BC(5, 1, 13, 0, *(u16 *)p);
    func_02049B40(5, func_0201F548(0), 4, 416, 64, *(u16 *)p);
    func_0201DD68();
    *(u32 *)(p + 0x30) = func_0201C440((void *)(u32)*(u16 *)p);
    *(void **)(p + 0x34) = func_02027F60(4, 11, *(u32 *)(p + 0x28), *(u32 *)(p + 0x30), *(u16 *)p);
    *(u32 *)(p + 0x24) = func_020450F0(5, 2, 4, 28, 4, 15, 1);
    *(u32 *)(p + 0x20) = func_020450F0(5, 2, 9, 28, 12, 15, 1);
    func_02043B5C(func_02045770(*(void **)(p + 0x24)), 1);
    func_02045334((struct Descriptor *)*(u32 *)(p + 0x24));
    func_02045374(*(u32 *)(p + 0x24));
    func_0201F73C(*(void **)(p + 0x24), 1, 1, 14);
    func_02043B5C(func_02045770(*(void **)(p + 0x20)), 0);
    func_02045334((struct Descriptor *)*(u32 *)(p + 0x20));
    func_02045374(*(u32 *)(p + 0x20));
    func_020409B4(5);
    func_020409B4(4);
    *(int *)(p + 0x1c) = 0;
    req.text = (u32)func_02045EC0(*(void **)(p + 0x2c), 24);
    req.color = 0x39e3;
    req.flag = 0;
    *(u32 *)(p + 0x3c) = func_02027FEC(*(u32 *)(p + 0x34), (u32)&req, 11, 21, 11, *(u16 *)p);
    func_02045808((void *)req.text);
    req.text = (u32)func_02045EC0(*(void **)(p + 0x2c), 26);
    *(u32 *)(p + 0x38) = func_02027FEC(*(u32 *)(p + 0x34), (u32)&req, 0, 21, 11, *(u16 *)p);
    func_02045808((void *)req.text);
    req.text = (u32)func_02045EC0(*(void **)(p + 0x2c), 25);
    req.flag = 1;
    *(u32 *)(p + 0x40) = func_02027FEC(*(u32 *)(p + 0x34), (u32)&req, 22, 21, 10, *(u16 *)p);
    func_02045808((void *)req.text);
    func_0202843C(*(u8 **)(p + 0x38));
    *(u16 *)0x050005e2 = 0;
}
