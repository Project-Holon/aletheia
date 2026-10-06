/*
 * file:     time_icon_p07.c
 * unit:     yes
 * function: func_0202F3AC, func_0202F41C
 * address:  0x0202F3AC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E88   0x02017E88  thumb
 *   func_0202F358   0x0202F358  thumb
 */
typedef unsigned char u8;

typedef unsigned int  u32;

extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void func_0202F358(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
void func_0202F3AC(void *a0, u32 a1);
int func_0202F41C(int a0, int a1, int a2);


/*
 * Reads the four resource slots of one variant and hands them, with the
 * opposite flag, to func_0202F358.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F3AC.c \
 *       --func func_0202F3AC --addr 0x0202F3AC --cc 1.1p1 --thumb
 */
void func_0202F3AC(void *a0, u32 a1)
{
    u8 base = (a1 == 1);
    u32 x, y, z, flag, w;

    x = func_02017E88(a0, base + 0x95, 0);
    base = (u8)(base * 3);
    y = func_02017E88(a0, base + 0x8F, 0);
    z = func_02017E88(a0, base + 0x90, 0);
    w = func_02017E88(a0, base + 0x91, 0);

    flag = (a1 == 0);
    func_0202F358(a0, x, y, z, w, flag);
}

int func_0202F41C(int a0, int a1, int a2){ int t0 = func_02008510((int)((a1 + 0) + 0), (int)(a2 + 0)); int t1 = func_02008530((int)((a1 + 0) + 0)); int t2 = func_02008550((int)((a1 + 0) + 0)); int t3 = func_02017E64((int)((a0 + 0) + 0), (int)0x8d, (int)((t0 + 0) + 0)); int t4 = func_02017E64((int)((a0 + 0) + 0), (int)0x9a, (int)((t2 + 0) + 0)); int t5 = func_02017E64((int)((a0 + 0) + 0), (int)7, (int)((t1 + 0) + 0)); int t6 = func_02045808((int)((t0 + 0) + 0)); return t6; }
