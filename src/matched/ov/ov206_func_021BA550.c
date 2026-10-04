/*
 * unit: yes
 * function: func_021BA550
 * address: 0x021BA550
 * packet: pkt_ov206_021BA550
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_021BB160 0x021BB160 thumb ov206
 *   func_021BA4F4 0x021BA4F4 thumb ov206
 *   func_021BB0FC 0x021BB0FC thumb ov206
 *   func_021BBC38 0x021BBC38 thumb ov206
 *   func_021BB13C 0x021BB13C thumb ov206
 *   func_021BBE34 0x021BBE34 thumb ov206
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0201ADE4(u32 a, int b, u32 c);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern void func_021BB160(char *p, int i);
extern void func_021BA4F4(char *p);
extern void func_021BB0FC(void *obj);
extern void func_021BBC38(char *p);
extern void func_021BB13C(char *p, int a, u16 b, int c);
extern void func_021BBE34(char *p, int v);
void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6)
{
    int x;
    u32 h;
    int y;
    if (*(void **)(p+0x26c) != 0) func_0201AE14(*(void **)(p+0x26c));
    *(void **)(p+0x26c) = func_0201ADE4(a1, a2, *(u16 *)p);
    if (*(int *)(p+0xb4) != 0) *(int *)(p+0xb4) = 0; else *(int *)(p+0xb4) = 1;
    if (*(int *)(p+0xe0) != 0) *(int *)(p+0xe0) = 0; else *(int *)(p+0xe0) = 1;
    if (*(int *)(p+0x190) != 0) *(int *)(p+0x190) = 0; else *(int *)(p+0x190) = 1;
    func_021BB160(p, *(int *)(p+0xb4));
    func_021BA4F4(p);
    *(u16 *)(p+0xc) = a1;
    *(u16 *)(p+0xe) = a2;
    *(u16 *)(p+0x10) = a3;
    *(u16 *)(p+0x12) = a4;
    *(int *)(p+0x14) = a5;
    *(int *)(p+8) = a6;
    h = (u16)func_0201AE1C(*(void **)(p+0x26c), 0x20);
    if (*(u16 *)(p+0xe) >= h) *(u16 *)(p+0xe) = 0;
    func_021BB0FC(p);
    func_021BBC38(p);
    switch (*(int *)(p+0x18)) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    func_021BB13C(p, x, (u16)(y + *(int *)(p+0x1b4)), *(int *)(p+0xb4));
    func_021BBE34(p, (*(int *)(p+0x44) != 0) ? 0 : 1);
}
