/*
 * unit:     no
 * function: func_0203B0C4
 * address:  0x0203B0C4
 * packet:   pkt_0203B0C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   s_020A7BA8     0x020A7BA8  data
 *   s_020A7BC8     0x020A7BC8  data
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_0203B084  0x0203B084  arm
 *   func_0203B038  0x0203B038  arm
 *
 * The two guards and the load/store pair: 0x021469DC holds a pointer whose
 * +0x40 address is both bit-tested (with the file/line/message triple at
 * 0x020A7BA8) and handed to func_02082D44 together with a length of 6,
 * then the two entry points func_0203B084 and func_0203B038 are registered
 * at sizes 400 and 403.
 */

extern int  g_021469DC;
extern char s_020A7BA8[];
extern char s_020A7BC8[];
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082D44(int a0, int a1, int a2);
extern void func_0203AD80(int a0, int a1, int a2, int a3);
extern void func_0203B084(void);
extern void func_0203B038(u8 *a0);

void func_0203B0C4(int a0, int a1)
{
    if ((g_021469DC + 0x40) & 1) {
        func_02034714(s_020A7BA8, 395, s_020A7BC8);
    }
    if (a0 != 0) {
        func_02082D44(a0, g_021469DC + 0x40, 6);
    }
    if (a1 != 0) {
        func_0203AD80(g_021469DC, (int)func_0203B084, 0, 400);
    } else {
        func_0203AD80(g_021469DC, (int)func_0203B038, 0, 403);
    }
}
