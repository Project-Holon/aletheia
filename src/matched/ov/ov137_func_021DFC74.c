/*
 * function: func_021DFC74
 * address: 0x021DFC74
 * packet: pkt_ov137_021DFC74
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E1634 0x021E1634 thumb ov137
 *   func_02062A98 0x02062A98 arm
 *   func_020215BC 0x020215BC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02022004 0x02022004 thumb
 *   func_02062A00 0x02062A00 arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021E1634(char *,u32,int);
extern int func_02062A98(void *,void **);
extern void func_020215BC(void *,const void *,u32,u32,u16);
extern void func_020307B0(void *);
extern void func_02022004(u32,u32,u16,u32,u32);
extern int func_02062A00(void *,void **);
extern void func_02040B1C(u8,const void *,u32,u32);
extern int func_02062B30(void *,void **);
extern void func_02040AE0(u32,const void *,u32);
extern void func_020409B4(u32);
void func_021DFC74(char *p)
{
    void *buf;
    u8 *data;
    buf=func_021E1634(p,17,0);
    func_02062A98(buf,(void **)(p+0xd64));
    func_020215BC(*(void **)(p+0xd78),*(void **)(*(u8 **)(p+0xd64)+12),0,0,64);
    func_020307B0(buf);
    buf=func_021E1634(p,20,0);
    func_02062A98(buf,(void **)(p+0xd64));
    func_020215BC(*(void **)(p+0xd78),*(void **)(*(u8 **)(p+0xd64)+12),1,0,64);
    func_020307B0(buf);
    func_02022004(*(u32 *)(p+0xd78),1,65535,8,0);
    buf=func_021E1634(p,16,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 **)(p+0xd60);
    func_02040B1C(3,*(void **)(data+20),*(u32 *)(data+16),0);
    func_020307B0(buf);
    buf=func_021E1634(p,22,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 **)(p+0xd60);
    func_02040B1C(6,*(void **)(data+20),*(u32 *)(data+16),0);
    func_020307B0(buf);
    buf=func_021E1634(p,21,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 **)(p+0xd60);
    func_02040B1C(7,*(void **)(data+20),*(u32 *)(data+16),0);
    func_020307B0(buf);
    buf=func_021E1634(p,19,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 **)(p+0xd5c);
    func_02040AE0(2,data+12,*(u32 *)(data+8));
    func_020409B4(2);
    func_020307B0(buf);
    buf=func_021E1634(p,18,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 **)(p+0xd5c);
    func_02040AE0(3,data+12,*(u32 *)(data+8));
    func_020409B4(3);
    func_020307B0(buf);
    buf=func_021E1634(p,24,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 **)(p+0xd5c);
    func_02040AE0(6,data+12,*(u32 *)(data+8));
    func_020409B4(6);
    func_020307B0(buf);
    buf=func_021E1634(p,23,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 **)(p+0xd5c);
    func_02040AE0(7,data+12,*(u32 *)(data+8));
    func_020409B4(7);
    func_020307B0(buf);
}
