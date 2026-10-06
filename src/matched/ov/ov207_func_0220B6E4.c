/*
 * function: func_0220B6E4
 * address: 0x0220B6E4
 * packet: pkt_ov207_0220B6E4
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero alignment bytes at 0x0220B72A before 0x0220B72C.
 * symbols:
 *   func_0220B9B0 0x0220B9B0 thumb ov207
 *   func_02030EAC 0x02030EAC arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0220B9B0(char *p);
struct Descriptor;
struct Node;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_02030EAC(struct Node *n);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern void func_02031140(struct S02031140 *p);
extern void func_020307B0(void *);
void func_0220B6E4(unsigned *p)
{
    func_0220B9B0((char *)p);
    func_02030EAC((void *)p[18]);
    func_0201CE48((void *)p[10]);
    func_0203FB44((int)3, (u16)p[12], (u16)(p[12] >> 16));
    func_020452E8((void *)p[9]);
    func_02045808((void *)p[11]);
    func_02031140((void *)p[13]);
    func_020452E8((void *)p[14]);
    func_020307B0(p);
}
