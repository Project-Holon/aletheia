/*
 * function: func_021E5D84
 * address: 0x021E5D84
 * packet: pkt_ov119_021E5D84
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: byte-pointer base keeps counter in r4, element base in r5.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02040618 0x02040618 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned int   u32;
extern void func_02040588(u32 which, u32 enable);
extern void func_02040618(u32 layer, u32 a, u32 b);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020456F8(int);
extern void func_0201F7A8(int, int);
extern void func_020452E8(int);
extern void func_02041B6C(u32 bit);
void func_021E5D84(char *p)
{
    unsigned i;
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    func_02040618(6, 0, 0);
    if (*(int *)(p + 0xf04)) func_0204B3DC((struct Obj *)*(int *)(p + 0xf04), 1);
    if (*(int *)(p + 0xf18)) func_0204B3DC((struct Obj *)*(int *)(p + 0xf18), 1);
    for (i = 0; i < 26; i++) {
        if (*(int *)(p + i * 4 + 0x750)) {
            func_020456F8(*(int *)(p + i * 4 + 0x750));
            func_0201F7A8(*(int *)(p + i * 4 + 0x750), 2);
            func_020452E8(*(int *)(p + i * 4 + 0x750));
            *(int *)(p + i * 4 + 0x750) = 0;
        }
    }
    func_02041B6C(6);
}
