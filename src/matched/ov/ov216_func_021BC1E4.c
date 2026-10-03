/*
 * function: func_021BC1E4
 * address: 0x021BC1E4
 * packet: pkt_ov216_021BC1E4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_02049238 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct ArcFile;struct NitroFileHeader;
extern struct ArcFile *func_020490F4(u32,u16);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u16);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern void func_020409B4(u32);
extern void *func_02049250(struct ArcFile *,u32,u32);
extern int func_02062A98(struct NitroFileHeader *,void **);
extern void func_02049238(void *);
extern void func_0207D63C(u32 *,u32,u32,int,int);
void func_021BC1E4(char *p,u16 heap)
{
    struct ArcFile *arc;
    arc=func_020490F4(85,heap);
    func_02049B68(arc,0,0,0,512,heap);
    func_02049B68(*(void **)(p+84),28,4,0,512,heap);
    func_02049658(*(void **)(p+84),30,4,0,0,1,heap);
    func_02049658(*(void **)(p+84),30,5,0,0,1,heap);
    func_02049658(*(void **)(p+84),30,7,0,0,1,heap);
    func_020498F4(*(void **)(p+84),32,4,0,0,1,heap);
    func_020498F4(*(void **)(p+84),32,5,0,0,1,heap);
    func_020498F4(*(void **)(p+84),33,7,0,0,1,heap);
    func_020413B0(5,0,0,32,24,1);
    func_020409B4(5);
    func_02049658(*(void **)(p+84),31,1,0,0,1,heap);
    func_020498F4(*(void **)(p+84),34,1,0,2048,1,heap);
    func_02049658(arc,5,2,0,0,0,heap);
    func_020498F4(arc,17,2,0,2048,0,heap);
    func_02049658(arc,7,3,0,0,0,heap);
    func_020498F4(arc,16,3,0,2048,0,heap);
    *(void **)(p+288)=func_02049250(*(struct ArcFile **)(p+84),29,*(u16 *)p);
    func_02062A98(*(struct NitroFileHeader **)(p+288),(void **)(p+280));
    *(void **)(p+284)=*(void **)(*(char **)(p+280)+12);
    func_02049238(arc);
    func_0207D63C((u32 *)0x04000050,2,30,11,5);
    func_0207D63C((u32 *)0x04001050,3,31,13,3);
}
