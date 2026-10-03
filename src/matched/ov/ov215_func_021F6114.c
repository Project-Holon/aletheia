/*
 * function: func_021F6114
 * address: 0x021F6114
 * packet: pkt_ov215_021F6114
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02031140(struct S02031140 *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020452E8(struct Descriptor *d);
void func_021F6114(void *unused,char *p)
{
    if(*(void **)(p+80)) func_0201CE48(*(void **)(p+80));
    if(*(void **)(p+104)) func_02045808(*(void **)(p+104));
    func_02031140(*(void **)(p+84));
    func_02045C04(*(void **)(p+100));
    func_0203FB44(1,(u16)*(unsigned *)(p+96),(u16)(*(unsigned *)(p+96)>>16));
    func_020452E8(*(void **)(p+88));
    func_020452E8(*(void **)(p+92));
}
