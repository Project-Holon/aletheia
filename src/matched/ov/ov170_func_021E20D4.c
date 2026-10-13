/*
 * function: func_021E20D4
 * address: 0x021E20D4
 * packet: pkt_ov170_021E20D4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   KEY_SetRepeatSpeed 0x02036270 arm
 *   d_021EFA4C 0x021EFA4C data a4
 */
extern void func_02027974(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern int KEY_SetRepeatSpeed(int a0, int a1);
typedef struct { int (*a)(char *); int (*b)(char *); } Pair;
extern const Pair d_021EFA4C[];
#define W(p) (*(char **)((p) + 0x2C))
int func_021E20D4(char *p)
{
    func_02027974(*(void **)(W(p) + 0x1A0));
    if (func_020279E8(*(void **)(W(p) + 0x1A0)) == 1) {
        int r = func_02027A04(*(void **)(W(p) + 0x1A0));
        func_02027858(*(void **)(W(p) + 0x1A0));
        KEY_SetRepeatSpeed(6, 6);
        if (r == 0)
            return d_021EFA4C[*(unsigned short *)(W(p) + 0x1A4)].a(p);
        else
            return d_021EFA4C[*(unsigned short *)(W(p) + 0x1A4)].b(p);
    }
    return 7;
}
