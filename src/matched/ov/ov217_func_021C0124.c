/*
 * function: func_021C0124
 * address: 0x021C0124
 * packet: pkt_ov217_021C0124
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 00 00 at 021C016E is two-byte alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct ArcFile;
extern void *func_020490F4(void *, u32);
extern void *func_02049250(struct ArcFile *, u32, u32);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_020409B4(u32);
extern u32 func_020307B0(u32);
extern void func_02049238(void *);
void func_021C0124(char *p)
{
    void *out;
    void *h;
    void *blob;
    h = func_020490F4((void *)192, *(u16 *)(p + 4));
    blob = func_02049250((struct ArcFile *)h, 7, *(u16 *)(p + 4));
    func_02062B30(blob, &out);
    func_02041090(2, (u32)((char *)out + 12), 0, 0, 32, 32);
    func_020409B4(2);
    func_020307B0((u32)blob);
    func_02049238(h);
}
