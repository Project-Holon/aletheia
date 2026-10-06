/*
 * function: func_021C0898
 * address: 0x021C0898
 * packet: pkt_ov208_021C0898
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6EC 0x0201C6EC thumb
 */
typedef unsigned char u8;
struct Rec;
struct Descriptor;
struct PrintSys;
extern unsigned int func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201C6EC(struct PrintSys *);
void func_021C0898(void *unused, char *p, void *a2)
{
    u8 i;
    for (i = 0; i < 2; i++) func_02045C04(*(struct Rec **)(p + i * 4 + 0xc));
    for (i = 0; i < 4; i++) {
        *(unsigned *)(p + i * 4 + 0x24) = 0;
        func_0201C6EC(*(struct PrintSys **)(p + i * 4 + 0x34));
        func_020452E8(*(struct Descriptor **)(p + i * 4 + 0x14));
    }
    for (i = 0; i < 2; i++) func_020452E8(*(struct Descriptor **)(p + i * 4 + 0x44));
}
