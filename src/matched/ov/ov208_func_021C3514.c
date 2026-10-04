/*
 * function: ov208_func_021C3514
 * address: 0x021C3514
 * packet: pkt_ov208_021C3514
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   ov208_func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_0200CA1C 0x0200CA1C thumb
 *   ov208_func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_0200CC40 0x0200CC40 thumb
 *   func_02006984 0x02006984 thumb
 *   func_020870D0 0x020870D0 arm
 *   ov208_func_021C3840 0x021C3840 thumb ov208
 *   ov208_func_021C31CC 0x021C31CC thumb ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int ov208_func_021BC3A4(int key);
extern void *func_0200CA1C(void *a);
extern u16 ov208_func_021BC3C0(int key);
extern void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u64 func_020870D0(void);
extern void ov208_func_021C3840(u16 *heap, u8 *p, int key, u16 species, u16 form);
extern void ov208_func_021C31CC(u16 *heap, u8 *p, int key);

void ov208_func_021C3514(u16 *heap, u8 *p, int key)
{
    u32 hit;
    u16 species;
    u32 x;
    u32 y;
    u32 form;
    u32 o1;
    u32 o2;
    void *pd;
    hit = 0;
    if (*(u32 *)(p + 0xd0) != 0) {
        if (func_020362DC() & 1) {
            func_020355D8(0);
            hit = 1;
        } else if (func_02035D20(&x, &y) != 0) {
            if (x < 0x100 && y < 0xa8) {
                hit = 1;
                func_020355D8(1);
            }
        }
    }
    if (hit != 0) {
        pd = func_0200CA1C((void *)ov208_func_021BC3A4(key));
        species = ov208_func_021BC3C0(key);
        func_0200CC40(pd, species, &o1, &o2, &form, *heap);
        *(u32 *)(p + 0x64) = func_02006984(species, form, 0x40, 0, 0, 0, 0, 0);
        *(u16 *)(p + 0x74) = 0;
        *(u64 *)(p + 0x6c) = func_020870D0();
        *(u32 *)(p + 0x68) = 1;
        ov208_func_021C3840(heap, p, key, species, form);
        ov208_func_021C31CC(heap, p, key);
    }
}
