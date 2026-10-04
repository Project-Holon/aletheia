/*
 * function: func_021BCD58
 * address:  0x021BCD58
 * packet:   pkt_ov099_021BCD58
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BCB70  0x021BCB70  thumb  ov099
 *   func_021BBEB4  0x021BBEB4  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern int func_021BA928(char *p, int v);
extern u32 func_020362DC(void);
extern void func_021BA8EC(char *p);
struct BigObj;
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32 *mask);
extern void func_021BBEB4(char *p, int a, u8 b, int c);

int func_021BCD58(char *p, int v)
{
    int out;

    if (func_021BA928(p, v) == 0) {
        return v;
    }
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        func_021BCB70((void *)(*(int *)(p + 0x1348)), (const struct BigObj *)(*(int *)(p + 0xC4)), (u32 *)(&out));
        func_021BBEB4(p, out, *(u8 *)(*(u8 **)(p + 0x248) + 0x48), 2);
        *(u32 *)(p + 0x1CC) = 0x77;
    }
    return v;
}
