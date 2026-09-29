/*
 * function: func_02189684
 * address:  0x02189684
 * packet:   pkt_ov021_02189684
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013FA8  0x02013FA8  thumb
 *   func_02013C80  0x02013C80  thumb
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_021AB868  0x021AB868  thumb  ov021
 *   func_021AB840  0x021AB840  thumb  ov021
 *   func_021AB880  0x021AB880  thumb  ov021
 *   func_021AB884  0x021AB884  thumb  ov021
 *   func_021AB888  0x021AB888  thumb  ov021
 *   func_021AB634  0x021AB634  thumb  ov021
 */

typedef unsigned short u16;

extern int func_02013FA8(u16 id);
extern int func_02013C80(u16 id);
extern void func_021AB650(void *p);
extern void func_021AB868(void *p);
extern void func_021AB840(void *p, int a, int b, int c);
extern int func_021AB880(void *p);
extern int func_021AB884(void *p);
extern int func_021AB888(void *p);
extern void func_021AB634(void *p, int a, int b, int c);

void func_02189684(char *p, unsigned int id)
{
    int k;
    int a;
    int b;

    k = func_02013FA8(id);
    if (k != 0xFFFF) {
        func_021AB650(*(void **)(p + 0x40));
        func_021AB868(*(void **)(p + 0x44));
        func_021AB840(*(void **)(p + 0x44), 1, k, 0x96);
        a = func_021AB880(*(void **)(p + 0x44));
        b = func_021AB884(*(void **)(p + 0x44));
        func_021AB634(*(void **)(p + 0x40), a, b, func_021AB888(*(void **)(p + 0x44)));
        return;
    }
    if (func_02013C80(id) == 0) {
        func_021AB650(*(void **)(p + 0x40));
        func_021AB868(*(void **)(p + 0x44));
    }
}
