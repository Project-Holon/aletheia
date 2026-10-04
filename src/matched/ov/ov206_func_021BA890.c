/*
 * unit: yes
 * function: func_021BA890
 * address: 0x021BA890
 * packet: pkt_ov206_021BA890
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A39C 0x0204A39C arm
 *   func_02049B68 0x02049B68 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   d_021BC174 0x021BC174 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tab16 { u8 b[16]; };
extern const struct Tab16 d_021BC174;
extern int func_0204A39C(void *a, int b, int c, u32 d, int *e);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_020450F0(u32 frame, u32 x, u32 y, u32 w, u32 h, u32 pal, u32 chr);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 a, u32 b);
void func_021BA890(char *p)
{
    struct Tab16 tab;
    int out;
    int r6;
    int i;
    *(int *)(p+0x2b0) = func_0204A39C(*(void **)(p+0x1c8), 0, 0, *(u16 *)p, &out);
    r6 = 0;
    if (*(int *)(p+0x1c) != 0) r6 = 4;
    func_02049B68(*(void **)(p+0x1cc), 5, r6, 0x60, 0x20, *(u16 *)p);
    tab = d_021BC174;
    for (i = 0; i < 4; i++) {
        *(void **)(p+i*4+0x6c) = func_020450F0(*(u8 *)(p+0x4c), tab.b[i*4], tab.b[i*4+1], tab.b[i*4+2], tab.b[i*4+3], 3, 1);
        func_02043B5C((u32)func_02045770(*(void **)(p+i*4+0x6c)), 0);
    }
    for (i = 0; i < 4; i++) {
        *(int *)(p+i*4+0x7c) = 1;
    }
}
