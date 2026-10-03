/*
 * function: func_021BC7B4
 * address:  0x021BC7B4
 * packet:   pkt_ov099_021BC7B4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Both 0x4c and 0x4d spell the shared call/store/result tail in full.
 * Cross-jumping retains 0x4c's bare branch over 0x4d's initial call;
 * a goto directly to that shared tail threads the stub away (152 vs156).
 *
 * symbols:
 *   func_021C282C  0x021C282C  thumb  ov099
 *   func_021BC104  0x021BC104  thumb  ov099
 *   func_021BAADC  0x021BAADC  thumb  ov099
 *   func_021C18C8  0x021C18C8  thumb  ov099
 *   func_021C24A4  0x021C24A4  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern int func_021C282C(u8 *p);
extern void func_021BC104(char *p);
extern void func_021BAADC(char *p, int a, int b);
extern void func_021C18C8(char *p, int a, int b);
extern void func_021C24A4(char *p, int v);
extern void func_021BA8EC(char *p);

int func_021BC7B4(char *p, int v)
{
    int r4;
    int sel;

    func_021C282C(*(u8 **)(p + 8));
    *(u8 *)(p + 0x1351) = 0;
    sel = *(u16 *)(p + 0x132c);
    switch (sel) {
    case 0x4b:
        r4 = 4;
        break;
    case 0x4c:
        r4 = 5;
        break;
    case 0x4d:
        r4 = 6;
        break;
    }
    switch (sel) {
    case 0x4b:
        func_021BC104(p);
        func_021BAADC(p, 0x7b, 0);
        func_021C18C8(p, 4, 4);
        func_021C24A4(p, 0);
        *(u8 *)(p + 0x1355) = 0;
        *(u32 *)(p + 0x1CC) = 0x10;
        break;
    case 0x4c:
        func_021BA8EC(p);
        *(u32 *)(p + 0x1D0) = r4;
        v = 2;
        break;
    case 0x4d:
        func_021BC104(p);
        func_021BA8EC(p);
        *(u32 *)(p + 0x1D0) = r4;
        v = 2;
        break;
    }
    func_021C18C8(p, 4, r4);
    return v;
}
