/*
 * function: func_02005B74
 * address:  0x02005B74
 * packet:   pkt_02005B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02074A54
 * symbols:
 *   g_020AA260      0x020AA260  data
 *    */

extern char g_020AA260[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020754C4(u32 a);
extern void func_020057DC(u32 **a);
extern void *func_02074518(int index);
extern void func_02074A54(int a, int b);
extern void func_02006118(void);
extern void func_02005888(u16 a);
extern void func_02005F5C(void);
void func_02005B74(int a0)
{
    func_020754C4(*(int *)(g_020AA260 + 0x10));
    func_020057DC((u32 **)(g_020AA260 + 0x10));
    if (a0 != 0) {
        func_02074518(0);
        func_02074A54(0, *(int *)(g_020AA260 + 0x10));
        *(int *)(g_020AA260 + 0x18) = 0;
    }
    func_02006118();
    func_02005888(0);
    func_02005F5C();
    *(short *)(g_020AA260 + 0) = 0;
    *(int *)(g_020AA260 + 8) = 0;
    *(int *)(g_020AA260 + 0x14) = 0;
    *(int *)(g_020AA260 + 4) = 0;
}
