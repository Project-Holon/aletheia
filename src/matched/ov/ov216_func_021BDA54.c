/*
 * function: func_021BDA54
 * address: 0x021BDA54
 * packet: pkt_ov216_021BDA54
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 c moves its r3 spill before the handle load and restores call setup; u32 leaves 24 concrete bytes different.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   sub_0201C724 0x0201C724 thumb
 *   func_021BDAA0 0x021BDAA0 thumb ov216
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void sub_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern void func_021BDAA0(char *, char *, int *);
void func_021BDA54(char *owner, char *record, u32 b, u16 c, u32 d, u16 f)
{
    void *handle;
    handle = *(void **)(owner + 0x12c);
    sub_0201C724(handle, (u32)func_02045770((struct Descriptor *)*(int *)(record + 8)), b, c, d, *(u32 *)(owner + 0x128), f);
    *(u8 *)(record + 12) = 1;
    func_021BDAA0(owner, record, (int *)(owner + 12));
}
