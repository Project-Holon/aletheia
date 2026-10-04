/*
 * function: func_021F21F8
 * address:  0x021F21F8
 * packet:   pkt_ov029_021F21F8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F1010  0x021F1010  thumb  ov029
 *   func_021F0370  0x021F0370  thumb  ov029
 *   func_021F1A64  0x021F1A64  thumb  ov029
 *   func_021F0D48  0x021F0D48  thumb  ov029
 *   func_021F1B50  0x021F1B50  thumb  ov029
 *   func_021F1B30  0x021F1B30  thumb  ov029
 *   func_021F1BE4  0x021F1BE4  thumb  ov029
 *   func_021F0F70  0x021F0F70  thumb  ov029
 *   func_021F2BF0  0x021F2BF0  thumb  ov029
 *   func_021F0FF0  0x021F0FF0  thumb  ov029
 *   func_021F1BBC  0x021F1BBC  thumb  ov029
 *   func_021F0E70  0x021F0E70  thumb  ov029
 *   func_021F11B4  0x021F11B4  thumb  ov029
 *   func_021F122C  0x021F122C  thumb  ov029
 *   func_021F1A44  0x021F1A44  thumb  ov029
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F21B4  0x021F21B4  thumb  ov029
 *   func_021F0AA0  0x021F0AA0  thumb  ov029
 */

typedef unsigned char u8;

extern void func_021F1010(void *p);
extern void func_021F0370(void *p);
extern void func_021F1A64(char *p, int a);
extern int func_021F0D48(char *p);
extern void func_021F1B50(char *p);
extern void func_021F1B30(char *p, int a);
extern int func_021F1BE4(char *p);
extern void func_021F0F70(char *p);
extern int func_021F2BF0(char *p);
extern void func_021F0FF0(char *p);
extern void func_021F1BBC(char *p);
extern void func_021F0E70(char *p);
extern int func_021F11B4(char *p);
extern void func_021F122C(char *p);
extern void func_021F1A44(char *p, int a);
extern void func_021EFEF8(char *p, void (*f)(void), int a);
extern void func_021F21B4(char *p);
extern void func_021F0AA0(char *p);

void func_021F21F8(char *p)
{
    switch (*(u8 *)(p + 0x455)) {
    case 0:
        func_021F1010(p);
        func_021F0370(p);
        func_021F1A64(p, 0);
        (*(u8 *)(p + 0x455))++;
        return;
    case 1:
        if (func_021F0D48(p)) {
            func_021F1B50(p);
            func_021F1B30(p, 1);
            (*(u8 *)(p + 0x455))++;
            return;
        }
        break;
    case 2:
        if (func_021F1BE4(p)) {
            func_021F0F70(p);
            *(u8 *)(p + 0x456) = 0;
            (*(u8 *)(p + 0x455))++;
            return;
        }
        break;
    case 3:
        if (func_021F2BF0(p)) {
            func_021F0FF0(p);
            *(u8 *)(p + 0x455) = 7;
            return;
        }
        if (*(u8 *)(p + 0x456) < 8) {
            (*(u8 *)(p + 0x456))++;
            return;
        }
        func_021F1B30(p, 0);
        func_021F1BBC(p);
        func_021F0E70(p);
        (*(u8 *)(p + 0x455))++;
        *(u8 *)(p + 0x456) = 0;
        return;
    case 4:
        if (func_021F2BF0(p)) {
            *(u8 *)(p + 0x455) = 7;
            return;
        }
        if (func_021F11B4(p) == 1) {
            *(u8 *)(p + 0x456) = 0;
            (*(u8 *)(p + 0x455))++;
            return;
        }
        break;
    case 5:
        if (func_021F2BF0(p)) {
            *(u8 *)(p + 0x455) = 7;
            return;
        }
        (*(u8 *)(p + 0x456))++;
        if (*(u8 *)(p + 0x456) >= 8) {
            func_021F122C(p);
            *(u8 *)(p + 0x456) = 0;
            (*(u8 *)(p + 0x455))++;
            return;
        }
        break;
    case 6:
        (*(u8 *)(p + 0x456))++;
        if (*(u8 *)(p + 0x456) >= 8) {
            func_021F1A64(p, 1);
            func_021F1A44(p, 0);
            func_021EFEF8(p, (void (*)(void))func_021F21B4, 0x100b);
            return;
        }
        break;
    case 7:
        func_021F1BBC(p);
        func_021F0E70(p);
        func_021F0AA0(p);
        func_021F122C(p);
        *(u8 *)(p + 0x456) = 8;
        *(u8 *)(p + 0x455) = 6;
        break;
    }
}
