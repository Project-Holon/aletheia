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
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
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
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 func_020307B0(void *p);
void func_0220B6E4(unsigned *p)
{
    func_0220B9B0((char *)p);
    func_02030EAC((void *)p[18]);
    PRINTSYS_PrintStreamDelete((void *)p[10]);
    func_0203FB44((int)3, (u16)p[12], (u16)(p[12] >> 16));
    BMP_WIN_Delete((void *)p[9]);
    STRBUF_Delete((void *)p[11]);
    TCBL_Destroy((void *)p[13]);
    BMP_WIN_Delete((void *)p[14]);
    func_020307B0(p);
}
