/*
 * function: func_0220D6DC
 * address: 0x0220D6DC
 * packet: pkt_ov197_0220D6DC
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * caller-width: constructor heap parameter is u16 because caller truncates before blx.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020216B4 0x020216B4 thumb
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021640 0x02021640 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_020216B4(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern void func_020216D4(struct PalAnmSlot *, u32, u32, u32);
extern void func_02021640(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16);
void func_0220D6DC(char *p)
{
    void *handle = func_020490F4(99,(*(u16 *)(*(char **)p + 0xc) & 0x7fff) | 0x8000);
    func_02049658(handle, 0, 6, 0, 0, 1, *(u16 *)(*(char **)p + 0xc));
    func_020498F4(handle, 3, 6, 0, 0, 1, *(u16 *)(*(char **)p + 0xc));
    func_020498F4(handle, 2, 7, 0, 0, 1, *(u16 *)(*(char **)p + 0xc));
    func_020216B4(*(struct PalAnmSlot **)(p + 8), (u32)handle, 1, *(u16 *)(*(char **)p + 0xc), 1, 224, 0);
    func_02049238(handle);
    func_0201F5BC(4, 1, 11, 0, *(u16 *)(*(char **)p + 0xc));
    func_020216D4(*(struct PalAnmSlot **)(p + 8), 1, 176, 32);
    func_02021640(*(struct PalAnmSlot **)(p + 8), 23, 5, *(u16 *)(*(char **)p + 0xc), 1, 32, 192);
}
