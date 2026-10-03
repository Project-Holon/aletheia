/*
 * function: func_02213850
 * address: 0x02213850
 * packet: pkt_ov199_02213850
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034A5C 0x02034A5C arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   ov093_id 0x0000005D data a1
 */
extern void func_02034A5C(int handle);
extern const char ov093_id[];
typedef unsigned int   u32;
struct S020314B8;
struct S020315D4;
extern void func_0203A5E4(u32 key);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(int);
int func_02213850(void *a, void *b, void *c, char *work)
{
    if (*(int *)(work + 8)) {
        func_02034A5C((int)ov093_id);
        *(int *)(work + 8) = 0;
    }
    if (*(int *)(work + 0xc)) {
        func_0203A5E4(0x100);
        *(int *)(work + 0xc) = 0;
    }
    func_0203133C(*(void **)work);
    func_020315D4(a);
    func_020306F0(0x58);
    return 1;
}
