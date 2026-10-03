/*
 * function: func_021D7278
 * address: 0x021D7278
 * packet: pkt_ov116_021D7278
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6A4C 0x021D6A4C thumb ov116
 *   func_021D6A48 0x021D6A48 thumb ov116
 *   func_0202E4EC 0x0202E4EC thumb
 *   func_020120B4 0x020120B4 thumb
 *   d_021D8560 0x021D8560 data ov116 a4
 *   d_021D8568 0x021D8568 data ov116 a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   ov129_id 0x81 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D6A4C(u8 *);
extern u16 func_021D6A48(u8 *);
struct IcaAnime;
struct Param;
extern struct Param *func_0202E4EC(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 d_021D8560[],d_021D8568[],d_021DA62C[];
extern u8 ov129_id[];
void func_021D7278(u8 *p,int a) {
    void *obj;
    d_021D8560[2]=(u32)func_021D6A4C(p+0xb74);
    obj=func_0202E4EC(a,1,func_021D6A48(p+0xb74),3,d_021D8568);
    *(void **)(p+0x1840)=obj;
    func_020120B4(*(void **)(*(u8 **)p+4),(u32)ov129_id,d_021DA62C,obj);
}
