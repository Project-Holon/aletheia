/*
 * function: func_021BB954
 * address:  0x021BB954
 * packet:   pkt_ov099_021BB954
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C3A70  0x021C3A70  data  a4
 *   d_021C3B68  0x021C3B68  data  a4
 *   d_021C3AD0  0x021C3AD0  data  a4
 *   func_021BAC24  0x021BAC24  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Desc;
struct Pair { u32 a, b; };
extern char d_021C3A70[];
extern char d_021C3B68[];
extern struct Pair d_021C3AD0[];
extern void func_021BAC24(char *, struct Desc *, struct Pair *, int, int, u32);

void func_021BB954(char *p, int flag)
{
    if (flag) {
        char *q = *(char **)(p + 0x248);
        ((u32 *)d_021C3A70)[0x18] = *(u8 *)(q + 0x21) + 0x83;
        ((u32 *)d_021C3A70)[0x1A] = *(u8 *)(q + 0x22) + 0x87;
        ((u32 *)d_021C3A70)[0x1C] = 0x8A - *(u8 *)(q + 0x20);
    } else {
        ((u32 *)d_021C3A70)[0x18] = *(u16 *)(p + 0x134C) + 0x83;
        ((u32 *)d_021C3A70)[0x1A] = *(u16 *)(p + 0x134E) + 0x87;
        ((u32 *)d_021C3A70)[0x1C] = 0x8A - *(u8 *)(*(char **)(p + 0x248) + 0x48);
    }
    func_021BAC24(p, (struct Desc *)d_021C3B68, d_021C3AD0, 6, 0, 0x1E);
}
