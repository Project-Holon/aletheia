/*
 * function: func_021BB7A4
 * address: 0x021BB7A4
 * packet: pkt_ov223_021BB7A4
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_02061CA4 0x02061CA4 arm
 *   d_021BC708 0x021BC708 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_02049F78(void *, unsigned, void *, unsigned);
extern void func_02082D44(const void *, void *, unsigned);
extern void func_020307B0(void *);
extern void func_02049238(void *);
extern int func_02061CA4(void *, unsigned, unsigned, int);
extern const u8 d_021BC708[];
void func_021BB7A4(char *p)
{
    void *object = func_020490F4(205, *(u16 *)p);
    u8 i;
    for (i = 0; i < 4; i++) {
        char *out;
        void *buffer = func_02049F78(object, d_021BC708[i], &out, *(u16 *)p);
        func_02082D44(*(char **)(out + 0xC) + 256, p + 0x26A + i * 256, 256);
        func_020307B0(buffer);
    }
    func_02049238(object);
    *(int *)(p + 0x86C) = 0;
    *(u8 *)(p + 0x870) = 16;
    *(u8 *)(p + 0x871) = 3;
    func_02082D44(p + 0x56A, p + 0x76A, 256);
    func_02061CA4((void *)31, 256, (unsigned)(p + 0x76A), 256);
}
