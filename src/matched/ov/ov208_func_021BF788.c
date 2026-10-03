/*
 * function: func_021BF788
 * address: 0x021BF788
 * packet: pkt_ov208_021BF788
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_021BC32C 0x021BC32C thumb ov208
 *   func_021BC3A8 0x021BC3A8 thumb ov208
 *   func_021BCF4C 0x021BCF4C thumb ov208
 *   func_021BC3AC 0x021BC3AC thumb ov208
 *   func_021C0048 0x021C0048 thumb ov208
 *   func_021BFFEC 0x021BFFEC thumb ov208
 *   func_021C06C8 0x021C06C8 thumb ov208
 *   func_021BC448 0x021BC448 thumb ov208
 *   func_021BC518 0x021BC518 thumb ov208
 *   func_021BC508 0x021BC508 thumb ov208
 *   func_021BC560 0x021BC560 thumb ov208
 *   func_021BBB24 0x021BBB24 thumb ov072
 *   func_02012984 0x02012984 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020490F4 0x020490F4 arm
 *   func_020056A0 0x020056A0 thumb
 *   ov072_id 0x00000048 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 ov072_id[];
extern int func_021BC3A4(int);
struct Ov208Buf;
extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern char *func_021BC3A8(int);
extern int func_021BCF4C(char *);
extern u32 func_021BC3AC(int);
extern int func_02034AC4(int);
extern void func_02082BCC(void *,int,u32);
extern u8 func_02012984(int);
extern int func_021BBB24(int);
extern void func_021C0048(u16 *,char *,int);
extern void func_021C06C8(u16 *,char *,int);
extern void func_021BFFEC(void *,char *);
extern void *func_020490F4(u32,u16);
extern void *func_020056A0(u32,u32,u32);
extern void *func_021BC448(u32);
extern void func_021BC518(u32 *);
extern void func_021BC508(int,u32 *);
extern void *func_021BC560(u32,u16);
/* Caller explicitly loads r2 for setup helpers whose filed bodies omit it. */
u32 func_021BF788(void *a0,u32 a1,u16 *heap,u32 a3,int key)
{
    u8 *p;
    int save;
    u8 i;
    save = func_021BC3A4(key);
    func_02034AC4((int)ov072_id);
    p = (u8 *)func_021BC32C(a0,0x438,*heap);
    i = 0;
    func_02082BCC(p,0,0x438);
    *(u32 *)(p+0) = func_021BCF4C(func_021BC3A8(key));
    *(u32 *)(p+4) = func_021BC3AC(key);
    for (;i<2;i++) *(u32 *)(p+i*4+0x5c)=0;
    *(u32 *)(p+0x64)=0;
    *(u32 *)(p+0x8c)=0;
    *(u32 *)(p+0x90)=1;
    *(u32 *)(p+0x94)=0;
    *(u32 *)(p+0x6c)=0;
    *(u32 *)(p+0x70)=0;
    *(u32 *)(p+0x74)=0;
    p[0x78]=func_02012984(save);
    p[0x79]=0xff;
    *(u32 *)(p+0x84)=0;
    *(u32 *)(p+0x88)=1;
    *(int *)(p+0x3c8)=func_021BBB24(*heap);
    func_021C0048(heap,(char *)p,key);
    *(void **)(p+0x40c)=func_020490F4(0xb2,*heap);
    *(void **)(p+0x410)=func_020056A0((u32)func_021BFFEC,(u32)p,1);
    p[0x414]=0;
    func_021C06C8(heap,(char *)p,key);
    *(void **)(p+0x418)=func_021BC448(*heap);
    *(void **)(p+0x41c)=func_021BC448(*heap);
    func_021BC518(*(u32 **)(p+0x418));
    func_021BC518(*(u32 **)(p+0x41c));
    func_021BC508(0,*(u32 **)(p+0x418));
    func_021BC508(1,*(u32 **)(p+0x41c));
    *(void **)(p+0x420)=func_021BC560(*heap,0xa);
    *(u32 *)(p+0x424)=0;
    *(u32 *)(p+0x428)=1;
    *(u32 *)(p+0x42c)=0;
    *(u32 *)(p+0x430)=1;
    *(u32 *)(p+0x434)=1;
    return 1;
}
