/*
 * function: func_022052E8
 * address: 0x022052E8
 * packet: pkt_ov195_022052E8
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028604 0x02028604 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 */
extern int func_02028604(int);
struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
struct Rec;
extern void func_02045C04(struct Rec *rec);
extern void func_0203FB44(unsigned, unsigned short, unsigned short);
extern void func_020452E8(struct Descriptor *d);
void func_022052E8(int task, char *p)
{
    func_02028604(*(int *)(p + 0x84));
    if (*(int *)(p + 0x64)) func_0201CE48((struct Rec3 *)(*(int *)(p + 0x64)));
    func_02031140((struct S02031140 *)(*(int *)(p + 0x68)));
    if (*(int *)(p + 0x80)) func_02045808((struct U16Vec *)(*(int *)(p + 0x80)));
    func_02045C04(*(void **)(p + 0x78));
    func_02045C04(*(void **)(p + 0x7c));
    func_0203FB44(1, *(unsigned *)(p + 0x74), *(unsigned *)(p + 0x74) >> 16);
    func_020452E8((struct Descriptor *)(*(int *)(p + 0x6c)));
    func_020452E8((struct Descriptor *)(*(int *)(p + 0x70)));
}
