/*
 * function: func_021BB540
 * address: 0x021BB540
 * packet: pkt_ov223_021BB540
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_02061CA4 0x02061CA4 arm
 *   d_021BC73C 0x021BC73C data a1
 *   d_021BC6FC 0x021BC6FC data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent { u8 a, b, c, d, e; };
extern const struct Ent d_021BC73C[3];
extern const u8 d_021BC6FC[];
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, unsigned);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern int func_02061CA4(void *, unsigned, unsigned, int);
void func_021BB540(u8 *p)
{
    void *object = func_020490F4(205, *(u16 *)p);
    u8 i;
    for (i = 0; i < 3; i++) {
        u8 *out;
        void *buffer = func_02049F78(object, d_021BC73C[i].b, (u32)&out, *(u16 *)p);
        func_02082D44(*(u8 **)(out + 0xC), p + 0x74 + i * 0x94, 0x20);
        func_020307B0(buffer);
        buffer = func_02049F78(object, d_021BC73C[i].e, (u32)&out, *(u16 *)p);
        func_02082D44(*(u8 **)(out + 0xC), p + 0x94 + i * 0x94, 0x20);
        func_020307B0(buffer);
    }
    func_02049238(object);
    for (i = 0; i < 3; i++) {
        *(u16 *)(p + 0xD4 + i * 0x94) = 2;
        *(u16 *)(p + 0xD6 + i * 0x94) = 0x10;
    }
    for (i = 0; i < 3; i++) {
        func_02082D44(p + 0x94 + i * 0x94, p + 0xB4 + i * 0x94, 0x20);
        func_02061CA4((void *)0x1E, d_021BC6FC[i] << 5, (u32)(p + 0xB4 + i * 0x94), 0x20);
    }
}
