/*
 * function: func_021FE6A0
 * address: 0x021FE6A0
 * packet: pkt_ov135_021FE6A0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C8B18 0x021C8B18 arm ov114
 *   func_021C8BC4 0x021C8BC4 arm ov114
 *   func_02082BCC 0x02082BCC arm
 */
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short id; s8 a, b, c, d; u8 mode, flag; } Request;
extern void func_021C8B18(void *, int, void *);
extern void func_021C8BC4(void *, void *);
extern void func_02082BCC(void *, int, u32);
int func_021FE6A0(u8 *p)
{
    Request q;
    if (*(int *)(p + 0xf84) == 0) {
        func_021C8B18(p + 0xb56, 7, p + 0x20c);
    } else {
        func_02082BCC(&q, 0, 8);
        q.id = *(short *)(p + 0xb56);
        q.a = *(s8 *)(p + 0xb58);
        q.b = *(s8 *)(p + 0xb59);
        q.c = *(s8 *)(p + 0xb5a);
        q.d = *(s8 *)(p + 0xb5b);
        q.mode = 7;
        q.flag = *(int *)(p + 0xf84);
        func_021C8BC4(&q, p + 0x20c);
    }
    *(u16 *)(p + 0xb5c) = *(u16 *)(p + 0xb56);
    *(u16 *)(p + 0xb5e) = *(u16 *)(p + 0xb58);
    *(u16 *)(p + 0xb60) = *(u16 *)(p + 0xb5a);
    *(u32 *)(p + 0xb64) = *(u32 *)(p + 0xf84);
    *(int *)(p + 0xf8c) = 0;
    *(int *)(p + 0x28) = 18;
    *(u16 *)(p + 0xe1a) = 0;
    return 2;
}
