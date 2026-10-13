/*
 * function: func_021BAD14
 * address: 0x021BAD14
 * packet: pkt_ov214_021BAD14
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: row before layer declarations correct their register pair; non-const
 *   resource table keeps each outgoing stack store ahead of its table load (55 bytes out before).
 * volatile: hardware 0x04001050 write at 021BAD2E; 0x04001000 re-read at 021BAD32,021BAD3A.
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BB498 0x021BB498 data a4
 *   d_021BB640 0x021BB640 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate;
extern const u32 d_021BB498[][11];
extern u32 d_021BB640[][3];
extern u8 *func_02012944(void *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0207D518(u32);
extern void BG_SYS_ClearSubBgPlanes(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_02043598(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_020409B4(u32);
void func_021BAD14(void **a,char *p)
{
    u8 gender;
    int i,which;
    const u32 *row;
    u32 layer;
    u16 heap;
    void *arc;
    gender=(u8)(u32)func_02008550((const struct Sub0200852CObj *)func_02012944(*a));
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04001000 &=0xFFFF1FFF;
    *(volatile u32 *)0x04001000 |=0x10000;
    BG_SYS_ClearSubPlanes();
    func_0207D518(0);
    BG_SYS_ClearSubBgPlanes();
    for (i=0;i<1U;i++) {
        row=d_021BB498[i];
        layer=row[0];
        func_0203FCA0((u8)layer,(const struct BgTemplate *)(row+1),(u8)row[9]);
        func_020414AC(layer);
        func_02040588(layer,row[10]);
    }
    func_02043598(16,1);
    heap=*(u16 *)p;
    which=1;
    if (gender!=1) which=0;
    arc=func_020490F4(30,heap);
    func_02049B68(arc,d_021BB640[which][0],4,0,0,heap);
    func_02049658(arc,d_021BB640[which][1],4,0,0,0,heap);
    func_020498F4(arc,d_021BB640[which][2],4,0,0,0,heap);
    func_02049238(arc);
    func_020409B4(4);
}
