/*
 * function: func_02006368
 * address:  0x02006368
 * packet:   pkt_02006368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020AA260     0x020AA260  data
 *   g_020AA354     0x020AA354  data
 *   func_0208574C  0x0208574C  arm
 *   func_020855BC  0x020855BC  arm
 *
 * Deactivates background task: checks g_020AA260.active, verifies status
 * via func_0208574C(&g_020AA354), terminates via func_020855BC, and resets active flag.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006368.c \
 *       --func func_02006368 --addr 0x02006368 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct StructA {
    u8 pad[0x14];
    u32 active;
};

extern struct StructA g_020AA260;
extern u8 g_020AA354[];

extern int func_0208574C(void *arg);
extern void func_020855BC(void *arg);

void func_02006368(void)
{
    if (g_020AA260.active != 0) {
        if (func_0208574C(g_020AA354) == 0) {
            func_020855BC(g_020AA354);
            g_020AA260.active = 0;
        }
    }
}
