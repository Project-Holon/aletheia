/*
 * function: func_021BC228
 * address:  0x021BC228
 * packet:   pkt_ov099_021BC228
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 */

typedef unsigned short u16;

struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D1E8(int a, int b);
extern int func_0203D378(int a);
struct Link;
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern void func_021BA874(void *p, int id);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(void *p);

int func_021BC228(char *p, int r)
{
    if (func_0203D378(func_0203D1E8((int)func_020399A8(), 0)) != 0) {
        *(int *)(p + 0x135C) = 3;
        func_021BA874(p, *(u16 *)(p + 0x242) - 1);
        func_021BAAB8(p, 0x60, 0);
        *(int *)(p + 0x1CC) = 0x45;
    } else {
        *(int *)(p + 0x135C) = 4;
        func_021BAAB8(p, 0x4C, 0);
        func_021BC090(p);
        func_02039C68((struct Link *)func_020399A8(), 0x1B, 0xA);
        *(int *)(p + 0x1CC) = 0x49;
    }
    return r;
}
