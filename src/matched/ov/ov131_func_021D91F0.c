/*
 * function: func_021D91F0
 * address: 0x021D91F0
 * packet: pkt_ov131_021D91F0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020437D4 0x020437D4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021DBCF4 0x021DBCF4 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_020437D4(const void *);
extern void func_02082D44(const void *,void *,u32);
extern void *func_02045EC0(void *,u32);
extern void *func_020457B0(u32,u32);
extern void *func_0201EC64(u32);
extern void func_0201EFA4(void *,u32,u32,u32,u32,u32);
extern void func_0201F250(void *,void *,void *);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_0201DD68(void);
extern void func_02045808(void *);
extern void func_0201ED04(void *);
extern void func_021DBCF4(void *);
void func_021D91F0(u8 *a,u8 *p,u8 *entry)
{
    u8 *record;
    u8 *pixels;
    void *text;
    void *buffer;
    void *object;
    void *source;
    record=p+0x138+*(u16 *)entry*8;
    if (*(u32 *)record!=1) return;
    pixels=*(u8 **)(*(u8 **)(p+0x48)+0x14);
    source=func_020437D4(*(void **)(entry+12));
    if (*(u16 *)entry==p[0x59]) pixels+=0x660;
    func_02082D44(pixels,source,0x660);
    text=func_02045EC0(*(void **)(p+0x50),record[5]+160);
    buffer=func_020457B0(32,*(u16 *)a);
    object=func_0201EC64(*(u16 *)a);
    func_0201EFA4(object,0,record[6],2,2,1);
    func_0201F250(object,buffer,text);
    func_0201DD78(1,2,0);
    func_0201C7A4(*(void **)(entry+12),10,6,buffer,*(void **)(a+0x80));
    func_0201DD68();
    func_02045808(text);
    func_02045808(buffer);
    func_0201ED04(object);
    func_021DBCF4(*(void **)(entry+16));
}
