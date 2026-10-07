/*
 * function: func_021B6254
 * address: 0x021B6254
 * packet: pkt_ov180_021B6254
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02051E74 0x02051E74 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_02041FB0 0x02041FB0 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02040EBC 0x02040EBC arm
 *   d_021B80E8 0x021B80E8 data ov180 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct {u32 w[8];} Template;
typedef struct {int m[4];} Mtx;
extern const Template d_021B80E8;
struct BgTemplate;
struct Mtx22;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void func_0207D59C(void *,Mtx *,u32,u32,u32,u32);
extern void func_02041EE4(u32,u32,u32);
extern void func_02041FB0(u32,u32,u16);
extern void func_020434DC(u32,u32),func_02043598(u32,u32),func_02040EBC(u32,u32);
void func_021B6254(void)
{
    Template t=d_021B80E8;
    Mtx m;
    func_0203FCA0(3,(const struct BgTemplate *)(&t),2);func_0203FCA0(7,(const struct BgTemplate *)(&t),2);
    func_02051E74((struct Mtx22 *)(&m),0,(void *)4096,(void *)4096,0);
    func_0207D59C((void *)0x04000030,&m,0,0,0,0);
    func_0207D59C((void *)0x04001030,&m,0,0,0,0);
    func_02041EE4(3,0,160);func_02041EE4(3,3,112);
    func_02041EE4(7,0,160);func_02041EE4(7,3,-152);
    func_02041FB0(3,9,160);func_02041FB0(3,12,160);
    func_02041FB0(7,9,160);func_02041FB0(7,12,160);
    func_020434DC(8,1);func_02043598(8,1);
    func_02040EBC(0,0);func_02040EBC(4,0);
}
