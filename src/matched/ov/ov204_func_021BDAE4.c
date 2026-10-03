/*
 * function: func_021BDAE4
 * address: 0x021BDAE4
 * packet: pkt_ov204_021BDAE4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BFCD0 0x021BFCD0 thumb ov204
 *   func_021BF5E0 0x021BF5E0 thumb ov204
 *   func_021BF9D0 0x021BF9D0 thumb ov204
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_021BEF74 0x021BEF74 thumb ov204
 *   func_021BDCF0 0x021BDCF0 thumb ov204
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
struct Rec; struct S020315D4;
extern void func_021BFCD0(char *);
extern void func_021BF5E0(char *);
extern void func_021BF9D0(char *);
extern void func_02045C04(struct Rec *);
extern void func_0201D83C(void *);
extern void func_021BEF74(char *);
extern void func_021BDCF0(unsigned char *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(void *);
typedef signed int     s32;
extern void func_02034A5C(s32 handle);
extern const char ov067_id[];
int func_021BDAE4(struct S020315D4 *owner, int unused1, int unused2, char *p)
{
    unsigned short heap;
    func_021BFCD0(*(char **)(p + 0x20));
    func_021BF5E0(*(char **)(p + 0x18));
    func_021BF9D0(*(char **)(p + 0x1C));
    func_02045C04(*(struct Rec **)(p + 0x10));
    func_0201D83C(*(void **)(p + 0xC));
    func_021BEF74(*(char **)(p + 0x14));
    func_021BDCF0(*(unsigned char **)(p + 8));
    heap = *(unsigned short *)p;
    func_020315D4(owner);
    func_020306F0((void *)(unsigned)heap);
    func_02034A5C((unsigned)ov067_id);
    return 1;
}
