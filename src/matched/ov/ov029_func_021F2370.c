/*
 * function: func_021F2370
 * address:  0x021F2370
 * packet:   pkt_ov029_021F2370
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0E70  0x021F0E70  thumb  ov029
 *   func_021F1A64  0x021F1A64  thumb  ov029
 *   func_021F1A44  0x021F1A44  thumb  ov029
 *   func_021F1BBC  0x021F1BBC  thumb  ov029
 *   func_021F1010  0x021F1010  thumb  ov029
 *   func_021F0370  0x021F0370  thumb  ov029
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F21B4  0x021F21B4  thumb  ov029
 */

extern void func_021F0E70(char *p);
extern void func_021F1A64(char *p, int a);
extern void func_021F1A44(char *p, int a);
extern void func_021F1BBC(char *p);
extern void func_021F1010(void *p);
extern void func_021F0370(void *p);
extern void func_021EFEF8(char *p, void (*f)(void), int a);
extern void func_021F21B4(char *p);

void func_021F2370(char *p)
{
    if (*(unsigned char *)(p + 0x456) == 0) {
        func_021F0E70(p);
        func_021F1A64(p, 1);
        func_021F1A44(p, 0);
        func_021F1BBC(p);
        func_021F1010(p);
        func_021F0370(p);
    }
    *(unsigned char *)(p + 0x456) += 1;
    if (*(unsigned char *)(p + 0x456) >= 0x10) {
        *(unsigned char *)(p + 0x456) = 0;
        func_021EFEF8(p, (void (*)(void))func_021F21B4, 0x1041);
    }
}
