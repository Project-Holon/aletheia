/*
 * function: func_0203C3B4
 * address:  0x0203C3B4
 * packet:   pkt_0203C304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   func_0203AD80  0x0203AD80  arm
 *   str_0203C238   0x0203C238  data
 */

typedef unsigned char u8;
typedef signed char   s8;
typedef unsigned int  u32;

struct Sys {
    u8 pad[0x48];
    s8 flag;
};

extern struct Sys *g_021469DC;
extern const char str_0203C238[];

extern void func_0203AD80(struct Sys *sys, const char *file, u32 tag, u32 line);

void func_0203C3B4(void)
{
    g_021469DC->flag = -1;
    func_0203AD80(g_021469DC, str_0203C238, 0, 0x60d);
}
