/*
 * function: func_021B9928
 * address: 0x021B9928
 * packet: pkt_ov205_021B9928
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203115C 0x0203115C arm
 *   func_02031140 0x02031140 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B99D8 0x021B99D8 thumb ov205
 */
struct Descriptor;
struct Rec;
struct S02031140;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern void func_0203115C(struct Tcbl *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201F7A8(void *,unsigned);
extern void func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);
extern void func_020403F4(unsigned);
extern void func_0201D83C(void *);
extern void func_021B99D8(void);
void func_021B9928(char *p)
{
    func_0203115C(*(void **)(p+36));
    func_02031140(*(void **)(p+36));
    *(void **)(p+36)=0;
    func_0201F7A8(*(void **)(p+28),0);
    func_020452E8(*(void **)(p+28));
    func_02045808(*(void **)(p+12));
    func_0201ED04(*(void **)(p+24));
    func_02045C04(*(void **)(p+20));
    func_020403F4(0);
    func_0201D83C(*(void **)(p+16));
    func_021B99D8();
}
