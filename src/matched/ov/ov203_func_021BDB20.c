/*
 * function: func_021BDB20
 * address: 0x021BDB20
 * packet: pkt_ov203_021BDB20
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021BDD18 0x021BDD18 thumb ov203
 *   func_021BE4B4 0x021BE4B4 thumb ov203
 *   func_021BDE98 0x021BDE98 thumb ov203
 *   ov067_id 0x00000043 data a1
 */
extern void func_02023F98(int);
extern void func_021BDD18(char *);
extern void func_02045C04(void *);
extern void func_0201C4C0(void *);
extern void func_021BE4B4(void *);
extern void func_021BDE98(void *);
extern void func_020315D4(void *);
extern void func_020306F0(int);
extern void func_02034A5C(const void *);
extern const char ov067_id[];
int func_021BDB20(void *a, void *b, void *c, char *work)
{
    func_02023F98(3);
    func_021BDD18(*(char **)(work + 0x1c));
    func_02045C04(*(void **)(work + 0x14));
    func_0201C4C0(*(void **)(work + 0x10));
    func_021BE4B4(*(void **)(work + 0x18));
    func_021BDE98(*(void **)(work + 0xc));
    func_020315D4(a);
    func_020306F0(0x6c);
    func_02034A5C(ov067_id);
    return 1;
}
