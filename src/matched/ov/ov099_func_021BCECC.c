/*
 * function: func_021BCECC
 * address:  0x021BCECC
 * packet:   pkt_ov099_021BCECC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_021BCC4C  0x021BCC4C  thumb  ov099
 *   func_021BBEB4  0x021BBEB4  thumb  ov099
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BA978  0x021BA978  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern u32 func_0203D378(void);
extern void func_021BCC4C(void *a);
extern void func_021BBEB4(char *p, int a, u8 b, int c);
extern void func_021BA874(char *p, int id);
extern void func_021BA978(char *p, int a, int b, int c);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(char *p);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *h, unsigned int a, unsigned int b);

int func_021BCECC(char *p, int v)
{
    if (func_0203D378() == 0) {
        func_021BCC4C(p);
        func_021BBEB4(p, 0, *(u8 *)(*(u8 **)(p + 0x248) + 0x48), 1);
        func_021BA874(p, *(u16 *)(p + 0x242) - 1);
        func_021BA978(p, *(u16 *)(p + 0x134C) + 0x69 + (*(u16 *)(p + 0x134E) << 2), 0, 1);
        *(u32 *)(p + 0x1CC) = 0x7A;
    } else {
        func_021BAAB8(p, 0x4C, 0);
        func_021BC090(p);
        func_02039C68((struct Link *)func_020399A8(), 0x1B, 0xA);
        *(u32 *)(p + 0x1CC) = 0x49;
    }
    return v;
}
